#include "StdMessage.hpp"
#include "../Server/WorkFlow/TestTube.hpp"
#include "../Server/WorkFlow/User.hpp"


//-----------------------------------------------------------------------------
MessageUserInput::MessageUserInput(const string& inName, const string& inPassword,
                                    const string& inIDNumber, const bool& inIsAdmin):
m_Name(inName), m_Password(inPassword), m_IDNumber(inIDNumber), m_IsAdmin(inIsAdmin) {
    // Empty
}
//-----------------------------------------------------------------------------
MessageUserOutput::MessageUserOutput(const string& inName, const string& inIDNumber,
                                      const TestResult& inTestResult):
m_Name(inName), m_IDNumber(inIDNumber), m_TestResult(inTestResult) {
    // Empty
}
//-----------------------------------------------------------------------------
MessageLogin::MessageLogin(const string& inIDNumber, const string& inPassword):
m_IDNumber(inIDNumber), m_Password(inPassword) {
    // Empty
}
//-----------------------------------------------------------------------------
MessageSamplingInfo::MessageSamplingInfo(const string& inIDNumber,
                                          const DateTime& inSamplingTime):
m_IDNumber(inIDNumber), m_SamplingTime(inSamplingTime) {
    // Empty
}
//-----------------------------------------------------------------------------
MessageTubeTestResult::MessageTubeTestResult(const SerialNumber& inTubeNum,
                                              const DateTime& inEntryTime,
                                              const TestResult inResult):
m_TubeSerialNum(inTubeNum), m_EntryTime(inEntryTime), m_TestResult(inResult){
    // Empty
}
//-----------------------------------------------------------------------------
MessageTubeOutput::MessageTubeOutput(const TestTube* inTestTube):
m_SerialNumber(inTestTube->m_SerialNumber), m_EntryTime(inTestTube->m_EntryTime),
m_TestResult(inTestTube->m_TestResult) {
    for (const auto& n: inTestTube-> m_RelatedUsers) {
        // make pair with related user's ID number and sampling time
        m_RelatedTestedUser.push_back(make_pair(n.first->IDNumber(), n.second));
    }
}
//-----------------------------------------------------------------------------
