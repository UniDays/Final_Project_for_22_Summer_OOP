#include "TestTube.hpp"
#include "TubeLabel.hpp"
#include "User.hpp"

//-----------------------------------------------------------------------------
//                              static members
//-----------------------------------------------------------------------------

unsigned int TestTube::MAXCAPACITY = 10;
vector<shared_ptr<TestTube> > TestTube:: s_AllTubes; //use default constructors

//-----------------------------------------------------------------------------
bool TestTube::SetMaxCapacity(unsigned int inuMax) {
    MAXCAPACITY = inuMax;
    return true;
}
//-----------------------------------------------------------------------------
//Error: SerialNumberRepeat
TestTube* TestTube::GetInstance(const SerialNumber &inSerialNumber) {
    //if serial number has existed, throw error SerialNumberRepeat
    TestTube* pTemp = new TestTube(inSerialNumber);
    // add this tube to allTubes
    s_AllTubes.push_back(shared_ptr<TestTube> (pTemp));
    return pTemp;
}
//-----------------------------------------------------------------------------
//Error: TubeFull, IDNotExist
bool TestTube::SetTestedInfo(const MessageSamplingInfo &inUserIDAndSampingTime) {
    //if ID number is illegal, it would throw error
    SetTestedInfo(inUserIDAndSampingTime.m_IDNumber, inUserIDAndSampingTime.m_SamplingTime);
    return true;
}
//-----------------------------------------------------------------------------
// No Error
TestTube* TestTube::IsExist(const SerialNumber &inSerialNumber) {
    for (auto& n: s_AllTubes) {
        if(inSerialNumber == n->m_SerialNumber) {
            // if exist, return pointer which point to this Tube
            return n.get();
        }
    }
    return nullptr;
}
//-----------------------------------------------------------------------------
//Error: InvalidResultSetting
void TestTube::SetTubeTestResult(const DateTime &inEntryTime, const TestResult inTestResult) {
    // if test tube's reult is Unknown, throw error,
    if (inTestResult == TestResult::UNKNOWN) {
        throw MyException:: InvalidResultSetting;
    }
    // set
    m_EntryTime = inEntryTime;
    m_TestResult = inTestResult;
    // set all related tested person's result
    for (auto& n: m_RelatedUsers) {
        n.first->SetTestResult(m_TestResult);
        // set sampling time and entry time
        n.first->SetSamplingTime(n.second);
        n.first->SetEntryTime(m_EntryTime);
    }
}
//-----------------------------------------------------------------------------
// No Error
vector<MessageTubeOutput> TestTube::PackageTubeInfo() {
    vector<MessageTubeOutput> Package;
    for (auto& n: s_AllTubes) {
        Package.push_back(MessageTubeOutput(n.get()));
    }
    return Package;
}
//-----------------------------------------------------------------------------
// Error: TubeFull, IDNotExist
bool TestTube::SetTestedInfo(const string& inIDNumber, const DateTime& inSamplingTime) {
    // whether tube is full
    if(m_uCounter > MAXCAPACITY) {
        throw MyException::TubeFull;
    }
    User* pTested = User::IsExist(inIDNumber);
    
    // Judge whether ID exists
    if (pTested == nullptr) {
        throw MyException:: IDNotExist;
    }
    
    // set tested person related to this tube
    m_RelatedUsers.push_back(make_pair(pTested, inSamplingTime));
    m_uCounter++;
    return true;
}
//-----------------------------------------------------------------------------
// Error: SerialNumberRepeat
TestTube::TestTube(const SerialNumber& inSerialNumber) {
    if (IsExist(inSerialNumber) != nullptr) {
        throw MyException::SerialNumberRepeat;
    }
    m_SerialNumber = inSerialNumber;
    m_TestResult = TestResult::UNKNOWN;
    m_uCounter = 0;
    // m_RelatedUSers call default parameter constructor -- empty
    // m_EntryTime call default parameter constructor -- 1900.1.1 0:0:0
}
//-----------------------------------------------------------------------------
