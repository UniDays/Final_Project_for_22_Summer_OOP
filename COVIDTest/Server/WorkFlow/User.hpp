/*!
 *  File Name: User.hpp
 *  Function and Purpose:
 *                  1. Creat object of User, which includes Tested person, Entry Person, Collector and Administrator
 *                  2. Store all users' infomation and test results
 *                  3. Communicate with Server to provide login verificationa and test result inquiry
 *  Developer: Alfred Dai   7/1/2022
 *  Updating: N/A
 */
#ifndef User_hpp
#define User_hpp

#include <string>
#include <vector>
#include <stdexcept>
#include "../../Message/StdMessage.hpp"
#include "../../Debug/Debug.hpp"


using namespace std;

class DateTime;

/*!
 *  Class Name: UserType
 *  Function:class of UserType contain all kinds of users
 *  API: Only Constructors
 *  Developer: Alfred Dai   7/1/2022
 *  Updating: N/A
 */
class UserType {
public:
    /*!
     *  Name: Default Paremeters Constructor and Copy Constructor
     *  Function: Creat object of UserType with default parameters
     *  Parameters: All inputs
     *  Developer: Alfred Dai   7/1/2022
     *  Upating: N/A
     */
    UserType (const bool inputIsAdmin = false,const bool inIsCollector = false,
              const bool inIsEntry = false);
    UserType (const UserType & Source);

    /*!
     *  Function: show users type
     */
    bool m_IsCollector;
    bool m_IsEntry;
    bool m_IsAdmin;
};




/*!
 *  Class Name: User
 *  Function: User's fucntion, include creat, set type, set reesult and output
 *  API: 1.GetInstantce: FileIn packages all users infomation and send to this function for initializing, Creat objects of User and make sure that it is singleton pattern
 *       2.SetCollector: Set user with this ID to be Collector
 *       3.SetEntry: Set user with this ID to be Entry Staff
 *       4.SetAdmin: Set user with this ID to be Admin
 *       5.IsAllowedToLog: Judge the password whether is correct
 *       6.IsExist: Judge the IDnumber entered by Collector whether has been registered or not
 *       7.SetTestResult: TestTube calls this function by pointer stored in itself and change user's test result
 *       8.PackageUserInfo: Package all users' identity infomation and send to FileOut to print
 *  Developer: Alfred Dai   7/1/2022
 *  Updating: N/A
 */
class User {
public:
    /*!
     *  All functions following:
     *  Name: Constructors and Duplicate Function
     *  Function: Disable complier to gernerate default constructors and duplicate functions
     *          to make sure that all objects of Users are singleton pattern
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
    User () = delete;
    User (const User& Source) = delete;
    User& operator = (const User& Source) = delete;

    /*!
     *  Name: SetTestResult
     *  Function: 1. Has the same function of bool GetInstance (const string& InputName, const string& InputIDNumber,
     *           const string& InputPassword, const bool& InputIsAdmin);
     *          2. FileIn packages all users infomation and send to this function for initializing
     *  Parameters: All inputs;
     *  Return value:  bool, "true" means it is successful to creat a object with input parameters, otherwise throw an error
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    static bool GetInstance (const vector<MessageUserInput>& inAllUserInfo);
    
    /*!
     *  Name: GetInstance
     *  Function: Initialize the object of users and make sure that it is singleton pattern.
     *          TestResult is Unknown by default;
     *  Parameters : All inputs
     *  Return value: User*, if sucessful, return pointer point to new object
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
     static User* GetInstance (const string& inName, const string& inIDNumber,
                              const string& inPassword, const bool& inIsAdmin);
    
    /*!
     *  Name: SetCollector
     *  Function: 1. Only Admin can call this function, if not, it would throw an error "No Athotrized"
     *         2. Judge whether IDNumber is registered, if not, throwing an error "No User"
     *         3. Set user with this ID to be Collector
     *  Parameters: All input
     *  Return Value: bool, if successful, return true;
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    bool SetCollector (const string& inIDNumber);
    
    /*!
     *  Name: SetEntry
     *  Function: 1. Only Admin can call this function, if not, it would throw an error "No Athotrized"
     *         2. Judge whether IDNumber is registered, if not, throwing an error "No User"
     *         3. Set user with this ID to be Entry Staff
     *  Parameters: All input
     *  Return Value: bool, if successful, return true;
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    bool SetEntry (const string& inIDNumber);
    
    /*!
     *  Name: SetAdmin
     *  Function: 1. Only Admin can call this function, if not, it would throw an error "No Athotrized"
     *         2. Judge whether IDNumber is registered, if not, throwing an error "No User"
     *         3. Set user with this ID to be Admin
     *  Parameters: All input
     *  Return Value: bool, if successful, return true;
     *  Developer: Alfred Dai   7/3/2022
     *  Updating: N/A
     */
    bool SetAdmin (const string& inIDNumber);
    
    /*!
     *  Name: IsAllowedToLog
     *  Function: 1.Judge the password whether is correct
     *         2. the overloading function of User* const IsAllowedToLog (const string& LoginIDNumber,
     *          const string& LoginPassword)
     *  Parametes: All inputs
     *  Return value: User*,  if user is allowed to log in and pLoginUser point to this user,
     *            otherwise pLoginUser is nullptr;
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    static User* IsAllowedToLog (const MessageLogin& inIDNumAndPassword);
    
    /*!
     *  Name: IsExist
     *  Function: Judge the IDnumber entered by Collector whether has been registered or not
     *  Parametes: All inputs
     *  Return value:user*, if exist, return const user reference of this user;Otherwise, throw an eror
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    static User* IsExist (const string& inIDnumber);
    
    /*!
     *  Name: SetTestResult
     *  Function: 1. Has the same function of void SetTestResult (const string& InputIDNumber, const TestResult InputTesTResult)
     *          2. TestTube calls this function by pointer stored in itself and change user's test result
     *  Parameters: All inputs;
     *  Return value: void
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    void SetTestResult(const TestResult inTestResult);
    
    /*!
     *  Name: SetSamplingTime
     *  Function: set sampling time
     *  Parameters: All inputs;
     *  Return value: void
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    void SetSamplingTime (const DateTime& inSamplingTime);
    
    /*!
     *  Name: SetEntryTime
     *  Function: set entry time
     *  Parameters: All inputs;
     *  Return value: void
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    void SetEntryTime(const DateTime& inEntryTime);
    
    /*!
     *  Name: PackageUserInfo
     *  Function: Package all users' identity infomation and send to FileOut to print
     *  Parametes: N/A
     *  Return value:vector<UserIO:: IOFileOut>, include all identity information
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    static vector<MessageUserOutput> PackageUserInfo ();
    
    /*!
     *  Name: PackageUserInfo
     *  Function: Package all users' identity infomation and send to FileOut to update
     *  Parametes: N/A
     *  Return value:vector<UserIO:: IOFileOut>, include all identity information
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    static vector<MessageUserInput> PackageUserIdentiyInfo();
    
    /*!
     *  Make it easy to know this user's autorities
     */
    const bool& IsAdmin;
    const bool& IsCollector;
    const bool& IsEntryStaff;
    
    const string& IDNumber() {return m_IDNumber;}
    const TestResult& TestResult() {return m_TestResult;}
    const DateTime& SamplingTime() {return m_SamplingTime;}
    const DateTime& EntryTime() {return m_EntryTime;}
    
/*!
 * All functions in protected do not use any message class in order to make it easy for inheritage
 */
protected:
    
    /*!
     *  Name: IsAllowedToLog
     *  Function: Judge the password whether is correct;
     *  Parametes: All inputs
     *  Return value: User*,  if user is allowed to log in and pLoginUser point to this user,
     *            otherwise pLoginUser is nullptr;
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
     static User* IsAllowedToLog (const string& LoginIDNumber,
                                  const string& LoginPassword);
    
    /*!
     *  Name: IsIDLegal
     *  Function: check whether ID has 18 digits and all digits are numbers
     *  Parameters: ID to be checked
     *  Retrun: if legal, return true
     *  Developer: Alfred Dai   7/6/2022
     *  Updating: N/A
     */
    static bool IsIDLegal(const string& inIDNumber);
    
private:
    /*!
     *  Name: Private Constructor
     *  Function: Initialiez the object of User by private method which would only be called by GetInstance
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
    User (const string& inName, const string& inIDNumber,
         const string& inPassword, const bool& inIsAdmin);
    
    /*!
     *  Function: basic features of particular user
     */
    UserType m_Type;
    string m_Name;
    string m_IDNumber;
    string m_Password;
    enum TestResult m_TestResult;
    DateTime m_SamplingTime;
    DateTime m_EntryTime;
    
    /*!
     *  Function: record whether there is an administrator in all users
     */
    static bool s_HasAdmin;
    
    /*
     *  Set the minimal password length
     */
    static unsigned int s_PasswordMinLength;

    /*!
     *  Function: storage smart pointers which points to each uses and
     *         delete all users aotumatically
     */
    static vector<shared_ptr<User> > s_AllUsers;
};

#endif /* User_hpp */
