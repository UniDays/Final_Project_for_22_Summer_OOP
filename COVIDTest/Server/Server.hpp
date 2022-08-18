/*!
 *  File Name: Server
 *  Function: Receive the command from Controllor and inplement corresponding operations
 *  Developer: Alfred Dai    7/5/2022
 *  Upading: N/A
 */

#ifndef Server_hpp
#define Server_hpp

#include <iostream>
#include "WorkFlow/User.hpp"
#include "WorkFlow/TestTube.hpp"
#include "WorkFlow/FileIO.hpp"
#include "../Message/StdMessage.hpp"
using namespace std;
enum class ServerCommand;



/*!
 *  Class Name: Server
 *  Function: Receive the command from Controllor and inplement corresponding operations
 *  API:1.CreatAllUers: Read the input file and initialize all users
 *      2.Login: Receive the info from keyboard and determine whether user can log in or not,
            if the password is correct, set the m_LoginUSer.
 *      3.ShowTestResult: Get the Test Result of login users and return back
 *      4.SetAdmin: if login user is Admin, he/she can call this function to set Admin
 *      5.SetCollector: if login user is Admin, he/she can call this function to set Collector
 *      6.SetEntryStaff: if login user is Admin, he/she can call this function to set Entry Staff
 *      7.CreatTube: if login user is Collector, he/she can call this function to creat tube with unique serial number
 *      8.FillTube: if login user is Collector, he/she can call this function to relat tube with tested person (up to MAX) with ID nubmer
 *      9.SetTestResult: if login user is Entry Staff, he/she can call this function to set test result with unique serial number for tube
 *      10.SaveUserInfo: save all users identity and test result in designative file
 *      11.SaveTubeInfo: save all tubes test result in designative file
 *      12.Logout: log out
 *      13.IsLogin: return whether there is user loging now, equals to m_LoginUsers is not nullptr
 *      14.HasTubeToModify: return whether there is tube to be modified, equals to m_Modifying is not nullptr
 *  Developer: Alfred Dai    7/5/2022
 *  Upading: N/A
 */
class Server {
public:
    
    /*!
     *  Name: CreatAllUser
     *  Function: Read the input file and initialize all users
     *  Parameters: FilePath appoint which file to be read
     *  Return: if file path or the target file's format is wrong, it will throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: FailedToOpen, NoAdmin, IDIllegal, IDRepeat, PasswordTooShort
     */
    static bool CreatAllUsers(const char* FilePath = UserDataFilePath.c_str());
    
    /*!
     *  Name: Register
     *  Function: user register a new count
     *  Parameters: user's infomation
     *  Return: if register successfully, return true, otherwise, return false
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: IDIllegal, IDRepeat, PasswordTooShort
     */
    static void Register(const MessageUserInput& inMessage);
    
    /*!
     *  Name: Login
     *  Function: Receive the info from keyboard and determine whether user can log in or not,
                if the password is correct, set the m_LoginUSer.
     *  Parameters: ID number and Password input from keyboard
     *  Return: if it can not log in, throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  No Error
     */
    static bool Login (const MessageLogin& inIDNumAndPassword);
    
    /*!
     *  Name: ShowTestResult
     *  Function: Get the Test Result of login users and return back
     *  Parameters: N/A;
     *  Return: N/A
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: NoUserLogin
     */
    static TestResult ShowTestResult();
    
    /*!
     *  Name: ShowTestResult
     *  Function: Get the sampling time of login users and return back
     *  Parameters: N/A;
     *  Return: N/A
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: NoUserLogin
     */
    static const DateTime& ShowSamplingTime();
    
    /*!
     *  Name: ShowTestResult
     *  Function: Get the entry time of login users and return back
     *  Parameters: N/A;
     *  Return: N/A
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: NoUserLogin
     */
    static const DateTime& ShowEntryTime();
    
    /*!
     *  Name: SetAdmin
     *  Function: if login user is Admin, he/she can call this function to set Admin
     *  Parameters: use's ID number who you want to set to be admin
     *  Return: if no autority or no user, it would throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
     */
    static bool SetAdmin(const string& IDNumber);
    
    /*!
     *  Name: SetCollector
     *  Function: if login user is Admin, he/she can call this function to set Collector
     *  Parameters: use's ID number who you want to set to be Collector
     *  Return: if no autority or no user, it would throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
     */
    static bool SetCollector(const string& IDNumber);
    
    /*!
     *  Name: SetEntryStaff
     *  Function: if login user is Admin, he/she can call this function to set Entry Staff
     *  Parameters: use's ID number who you want to set to be Entry Staff
     *  Return: if no autority or no user, it would throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
     */
    static bool SetEntryStaff(const string& IDNumber);
    
    /*!
     *  Name: CreatTube
     *  Function: if login user is Collector, he/she can call this function to creat tube with unique serial number
     *  Parameters: test's Serial Number
     *  Return: if serial number has existed, it will throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: SerialNumberRepeat, NoPermission
     */
    static void CreatTube(const SerialNumber& inSerialNumber);
    
    /*!
     *  Name: FillTube
     *  Function:  if login user is Collector, he/she can call this function to relat tube with tested person (up to MAX) with ID nubmer
     *  Parameters: tested person's ID Number
     *  Return: if ID number is wrong or tube is up to MAX, throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: NoTubeToModify, TubeFull, IDNotExist, NoPermission
     */
    static bool FillTube (const MessageSamplingInfo& inIDNumAndSamplingTime);
    
    /*!
     *  Name: SetTestResult
     *  Function:  if login user is Entry Staff, he/she can call this function to set test result with unique serial number for tube
     *  Parameters: serial number and tube's test result
     *  Return: if no serial number, throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: SerialNumberNotExist, InvalidResultSetting, NoPermission
     */
    static bool SetTestResult(const MessageTubeTestResult& inSerialandTubeResult);
    
    /*!
     *  Name: SaveUserInfo
     *  Function:  save all users' identity info and test result in designative file
     *  Parameters: file path
     *  Return: if FilePath is not illegal, throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: FailedToOpen
     */
    static void SaveUserInfo(const char* p_FilePath = UserResultFilePath.c_str());
    
    /*!
     *  Name: SaveTubeInfo
     *  Function:  save all tubes' serial number and test result in designative file
     *  Parameters: file path
     *  Return: if FilePath is not illegal, throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: FailedToOpen
     */
    static void SaveTubeInfo(const char* p_FilePath = TubeResultFilePath.c_str());
    
    /*!
     *  Name: UpdateUserInfo
     *  Function:  save all users' identity info
     *  Parameters: file path
     *  Return: if FilePath is not illegal, throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: FailedToOpen
     */
    static void UpdateUserInfo(const char* p_FilePath = UserDataFilePath.c_str());
    
    /*!
     *  Name: Logout
     *  Function:  log out
     *  Parameters: N/A
     *  Return: if no user is logging, throw an error
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     */
    static void Logout();
    
    /*!
     *  Name: IsLogin
     *  Function:  return whether user is login or not
     *  Parameters: N/A
     *  Return: if no user log in, return false
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  No Error
     */
    static bool IsLogin();
    
    /*!
     *  Name:IsAdmin
     *  Function:  return whether user is admin
     *  Parameters: N/A
     *  Return: if not, return false
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  Error: NoUserLogin
     */
    static bool IsAdmin();
    
    /*!
     *  Name: HasTubeToModify
     *  Function:  return whether there is tube to be modified or not
     *  Parameters: N/A
     *  Return: if no tube, return false
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  No Error
     */
    static bool HasTubeToModify();
    
    /*!
     *  Name: HasTubeToModify
     *  Function:  return whether server has loaded data from designative file
     *  Parameters: N/A
     *  Return: if  never loading data,  return false
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  No Error
     */
    static bool HasLoadData();
    
    /*!
     *  Name: IsFilePathValid
     *  Function:  return whether file path is valid
     *  Parameters: N/A
     *  Return: if file path is valid, return true
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  No Error
     */
    static bool IsFilePathValid(const string& inFilePath);
    
    
    /*!
     *  Name: SetFilePath
     *  Function:  return whether file path is valid
     *  Parameters: unsigned int: 1 -> UserDataFilePath
     *                            2 -> UserResultFilePath
     *                            3 -> TubeResultFilePath
     *              string: file path
     *  Return: if file path is valid, return true
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  No Error
     */
    static bool SetFilePath(unsigned int inWhichOne, const string& inFilePath);
    
    /*!
     *  Name: HasSetAllFile
     *  Function:  return whether all file path is valid
     *  Parameters: N/A
     *  Return: if file path is valid, return true
     *  Developer: Alfred Dai    7/5/2022
     *  Upading: N/A
     *  No Error
     */
    static bool HasSetAllFile();
private:
    /*!
     *  Point to the user who has logged in, if no user logs in, it would be nullptr;
     */
    static User* m_LoginUser;
    /*!
     *  Point to the test tube which can be modified right now
     */
    static TestTube* m_ModifyingTube;
    
    /*
     *  record whether server has initial users from designative date;
     */
    static bool m_HasLoadData;
    
    /*
     *  File path
     */
    static string UserDataFilePath;
    static string UserResultFilePath;
    static string TubeResultFilePath;
    
    /*
     *  Record whether each file path has been set
     */
    static bool m_HasSetAllFile[3];
};



/*!
 *  Class Name: ServerInput
 *  Function: Get the input message from server
 *  API:1.GetCommand: get the command from buffer and trans to ServerCommand
        2.GerUnsignedNumber: get the unsigned number from buffer
        3.GetString: get the string from buffer
        4.Clear the buffer and wait for next input
 *  Developer: Alfred Dai   7/12/2022
 *  Updating: N/A
 */
class ServerInput {
public:
    
    /*!
     *  Name: GetCommand
     *  Function: get the server command from buffer and trans to ServerComand
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static ServerCommand GetCommand();
    
    /*!
     *  Name: GetChar
     *  Function: get the designative type message from buffer
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static unsigned int GetUnsignedNumber();
    
    /*!
     *  Name: GetString
     *  Function: get the designative type message from buffer
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static string GetString();
    
    /*!
     *  Name: ClearBuffer
     *  Function: clear buffer
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void ClearBuffer();
};



/*!
 *  Class Name: ServerOutput
 *  Function: Output the server feedback of user's operation
 *  API:1.SetFilePathError: feed it back, if the file path is invalid
        2.FilePathInvalid: not all file path have been set successfully
        3.NoAdmin: if there is no admin in the initialization file, feed it back
        4.IDIllegal: there is at least one user's ID format illegal
        5.IDRepeat: if there are two same ID number, feed it back
        6.PasswordTooShort: the length of password is shorter than the minimal size which is set in the server
        7.CommandNotFound: user's command does not exist in the server command set
        8.NextCommand: output the next command symbol to reminder user
 *  Developer: Alfred Dai   7/12/2022
 *  Updating: N/A
 */
class ServerOutput {
public:
    
    
    /*
     *  Deal with file loading error
     */
    
    /*!
     *  Name: SetFilePathError
     *  Function: clear feed set file path error
     *  Parameters: inWhichOne, choose the file path to set
                    '1' OriginUserData
                    '2' UserTestResultData
                    '3' TestTubeData
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void SetFilePathError(unsigned int inWhichOne);
    
    /*!
     *  Name: FilePathInvalid
     *  Function: if not all files have been set, feed it back
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void FilePathInvalid();
    
    
    /*
     *  Deal with illegal content in the initialization file
     */
    
    /*!
     *  Name: NoAdmin
     *  Function: if there is no admin in the initialization file, feed it back
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void NoAdmin();
    
    /*!
     *  Name: IDIllegal
     *  Function: there is at least one user's ID format illegal
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void IDIllegal();
    
    /*!
     *  Name: IDRepeat
     *  Function: if there are two same ID number, feed it back
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void IDRepeat();
    
    /*!
     *  Name: PasswordTooShort
     *  Function: the length of password is shorter than the minimal size which is set in the server
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void PasswordTooShort();
    
    /*!
     *  Name: CommandNotFound
     *  Function: user's command does not exist in the server command set
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void CommandNotFound();
    
    /*!
     *  Name: NextCommand
     *  Function: output the next command symbol to reminder user
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void NextCommand();
};

#endif /* Server_hpp */
