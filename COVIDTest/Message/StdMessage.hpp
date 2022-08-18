/*!
 *  File Name: StdMessage.hpp
 *  Function and Purpose: 1. Standerlize the message tranfering between the class and modular
 *                    2. Provding functions to package information in specific format to use and transfer
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */

#ifndef StdMessage_hpp
#define StdMessage_hpp

#include<vector>
#include <string>
#include <iostream>
#include "../Server/WorkFlow/TestResult.hpp"
#include "../Server/WorkFlow/TubeLabel.hpp"
using namespace std;


class TestTube;

/*!
 *  Class Name: MessageUserInput
 *  Function: Package parameters for User:: GetInctance to creat an object of User Class
 *  API: Only Constructor
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */
class MessageUserInput {
public:
    MessageUserInput(const string& inName, const string& inPassword,
                     const string& inIDNumber, const bool& inIsAdmin);
    
    const string m_Name;
    const string m_Password;
    const string m_IDNumber;
    const bool m_IsAdmin;
};



/*!
 *  Class Name: MessageUserOutput
 *  Function: Package parameters for FileOut to save users' test result
 *  API: Only Constructor
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */
class MessageUserOutput {
public:
    MessageUserOutput(const string& inName, const string& inIDNumber,
                      const TestResult& inTestResult);
    const string m_Name;
    const string m_IDNumber;
    const TestResult m_TestResult;
};



/*!
 *  Class Name: MessageLogin
 *  Function: Package parameters for User:: IsAllowedToLog
 *  API: Only Constructor
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */
class MessageLogin {
public:
    MessageLogin(const string& inIDNumber, const string& inPassword);
    
    const string m_IDNumber;
    const string m_Password;
};



/*!
 *  Class Name: MessageSamplingInfo
 *  Function: Package sampling infomation for TestTube to set tube related persons
 *  API: Only Constructor
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */
class MessageSamplingInfo {
public:
    MessageSamplingInfo(const string& inIDNumber, const DateTime& inSamplingTime);
    
    const string m_IDNumber;
    const DateTime m_SamplingTime;
};



/*!
 *  Class Name: MessageTubeTestResult
 *  Function: Package test result infomation for TestTube to set tubes's related persons
 *  API: Only Constructor
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */
class MessageTubeTestResult {
public:
    MessageTubeTestResult(const SerialNumber& inTubeNum,
                          const DateTime& inEntryTime, const TestResult inResult);
    
    const SerialNumber m_TubeSerialNum;
    const DateTime m_EntryTime;
    const TestResult m_TestResult;
};



/*!
 *  Class Name: MessageTubeOutput
 *  Function: Package tube's test result and sent to FileOut to save
 *  API: Only Constructor
 *  Developer: Alfred Dai   7/5/2022
 *  Updating: N/A
 */
class MessageTubeOutput {
public:
    MessageTubeOutput(const TestTube* inTestTube);
    
    const SerialNumber m_SerialNumber;
    const DateTime m_EntryTime;
    const TestResult m_TestResult;
    /*!
     *  string includes tested person's ID number, Datetime means sampling time
     */
    vector<pair<string, DateTime> > m_RelatedTestedUser;
};


#endif /* StdMessage_hpp */
