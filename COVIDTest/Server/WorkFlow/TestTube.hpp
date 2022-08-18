/*!
 *  File Name: TestTube.hpp
 *  Function and Purpose:
 *                    1.Creat object of TestTube and note test reult for each tube
 *                    2.Allowing Entry Staff record the result of test
 *                    3.Providng test result for User to update storage
 *  Developer: Alfred Dai   7/2/2022
 *  Updaing: N/A
 */

#ifndef TestTube_hpp
#define TestTube_hpp


#include <vector>
#include "../../Debug/Debug.hpp"
#include "../../Message/StdMessage.hpp"

class User;
class SerialNumber;
class DateTime;


class TestTube {
public:
    /*!
     *  All functions following:
     *  Name: Constructors and Duplicate Function
     *  Function: Disable complier to gernerate default constructors and duplicate functions
     *          to make sure that all objects of TestTube are singleton pattern
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
    TestTube() = delete;
    TestTube(const TestTube& Source) = delete;
    TestTube& operator = (const TestTube& Source) = delete;
    
    /*!
     *  Name: SetMaxCapacity
     *  Function: Set the max samples one tube including;Default is 10;
     *  Pararmeter: All inputs
     *  Return value: if inMax == 0, return false, otherwise true
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
    static bool SetMaxCapacity (unsigned int inuMax);
    
    /*!
     *  Name: GetInstance
     *  Function: Initialize the object of tube and make sure that it is singleton pattern.
     *          TestResult is Unknown by default;
     *  Parameters : All inputs
     *  Return value: bool, "true" means it is successful to creat a object with input parameters, otherwise throw an error
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    static TestTube* GetInstance(const SerialNumber& inSerialNumber);

    /*!
     *  Name: SetTestedInfo
     *  Function: Collector related users with test tube and record related user's pointer in m_RelatedUsers
     *  Parameters: All input
     *  Return Value: bool, if ID number is correct, it will return true and record user's pointer in m_RelatedUsers
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    bool SetTestedInfo(const MessageSamplingInfo& inUserIDAndSampingTime);
 
    /*!
     *  Name:IsExist
     *  Function: Judge the Serial Number entered by Entry Staff whether has been registered or not
     *  Parameters: All input
     *  Return Value: bool, if Serial Number is correct, it will return true and record test tube's  pointer in m_AllTubs
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    static TestTube* IsExist(const SerialNumber& inSerialNumber);
    
    /*!
     *  Name: SetUserTestResult
     *  Function and Purpose: Set users' test result by pointer in m_RelatedUsers pointing to users
     *  Parameters: N/A
     *  Return Value: void
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    void SetTubeTestResult(const DateTime& inEntryTime, const TestResult inTestResult);
    
    /*!
     *  Name: PackageTubeInfo
     *  Function: Package all tubes' test reult and users' infomation and send to FileOut to print
     *  Parametes: N/A
     *  Return value:vector<TestTubeIO::IOFileOut>, include all test result and user's related information
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    static vector<MessageTubeOutput> PackageTubeInfo();
    
    /*!
     *  Name: MessageTubeOutput, constructor
     *  Function: Package tube's test result and sent to FileOut to save
     *  Parameters: All inputs
     *  Developer: Alfred Dai   7/5/2022
     *  Updating: N/A
     */
    friend MessageTubeOutput:: MessageTubeOutput(const TestTube* inTestTube);
protected:
    
    /*!
     *  Name: SetTestedInfo
     *  Function: Collector related users with test tube and record related user's pointer in m_RelatedUsers
     *  Parameters: All input
     *  Return Value: bool, if ID number is correct, it will return true and record user's pointer in m_RelatedUsers
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    bool SetTestedInfo(const string& inIDNumber, const DateTime& inSamplingTime);
    
private:
    /*!
     *  Name: Constructor
     *  Function: Only called by GetInstance and initialize object of TestTube
     *  Parameters: All inputs
     *  Return Value: N/A
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    TestTube(const SerialNumber& inSerialNumber);
    
    /*!
     *  Features of one test tube
     *  Use nCounter to count how many Test Sample have been added into this tube
     */
    SerialNumber m_SerialNumber;
    TestResult m_TestResult;
    DateTime m_EntryTime;
    unsigned int m_uCounter;
    
    /*!
     *  TestTube related to Users and each user's sampling time
     */
    vector<pair<User*, DateTime> > m_RelatedUsers;
    
    /*!
     *  Set maximum tested person for each test tube
     */
    static unsigned int MAXCAPACITY;
    
    /*!
     *  As a static member of Testtube, s_AllTube records pointers which point to each TestTube
     */
    static vector<shared_ptr<TestTube> > s_AllTubes;
};

#endif /* TestTube_hpp */

