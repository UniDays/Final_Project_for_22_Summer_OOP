/*!
 *  File Name: Client.hpp
 *  Function: implement both input and output in the client
 *  Developer: Alfred Dai   7/12/2022
 *  Updating: N/A
 */

#ifndef Client_hpp
#define Client_hpp

#include <iostream>
#include <string>
#include "../Message/Command.hpp"
#include "../Message/StdMessage.hpp"

using namespace std;

/*!
 *  Class Name: ClientInput
 *  Function: implement the input in the client
 *  API:1.GetCommand: get the command from client's input
        2.GetString: get the string from client's input
        3.GetUnsignedNumber: get the unsigned number from client's input
        4.DeleteChar: get a character from the buffer but not return to controller
        5.Clearbuffer: clear the buffer
 *  Developer: Alfred Dai   7/12/2022
 *  Updating: N/A
 */
class ClientInput {
public:
    /*!
     *  Name: GetCommand
     *  Function: get the client command from buffer and trans to ClientCommand
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static ClientCommand GetCommand();
    
    /*!
     *  Name: GetChar
     *  Function: get the designative type message from buffer
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static char GetChar();
    
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
     *  Name: GetUnsignedNumber
     *  Function: get the designative type message from buffer
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static unsigned int GetUnsignedNumber();
    
    /*!
     *  Name: DeleteChar
     *  Function: delete one character from the buffer
     *  Parameters: none
     *  Return Value: void
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void DeleteChar();
    
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
 *  Class Name: ClientOutput
 *  Function: implement the output in the client
 *  API:1.LoginRepeat: feedback repeated login error
        2.Login: if successfully log in, feedback the recent test result, otherwise feedback login failed error.
        3.NoUserLogin: if user try to implement operation when there is no user login, feed it back
        4.NoPermission: if user try to implement operation which he/she has no permission, feed it back
        5.IndentityRepeatSetting: if user tru to set one's indentity repeatedly, feed it back
        6.SerialNumberIllegal: if the format of serial number is not legal, feed it back
        7.SerialNumberRepeat: if collector try to set new tube with the same serial number, feed it back
        8.SamplingTimeIllegal: if the format or value of sampling time is not legal, feed it back
        9.NoTubeToModify: if collector doesn't creat a new tube before, feed it back
        10.TubeFull: if tube is full, feed it back to remind the collector to creat a new tube to continue
        11.InvalidResult: if entry staff sets tube test result with invalid input, feed it back
        12.EntryTimeIllegal: if the format or value of entry time is not legal, feed it back
        13.ConfirmQuit: When user try to quit the system, call it and enable the user to confirm the operation
        14.IllegalConfimationInput: if user input illegal characters when confirming quit command, feed it back
        15.Notube: the serial number does not exist
        16.NoUser: the ID number does not exist
        17.CommandNotFound: the command input is illegal
 *  Developer: Alfred Dai   7/12/2022
 *  Updating: N/A
 */
class ClientOutput {
public:
    
    
    /*
     *  Deal with register error
     */
    
    /*!
     *  Name: IDIllegal
     *  Function: output the "id illegal" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void IDIllegal();
    
    /*!
     *  Name: IDRepeat
     *  Function: output the "id repeat" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void IDRepeat();
    
    /*!
     *  Name: PasswordTooShort
     *  Function: output the "password too short" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void PasswordTooShort();
    
    
    /*
     *  Deal with login error
     */
    
    /*!
     *  Name: LoginRepeat
     *  Function: output the "login repeat" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void LoginRepeat();
    
    /*!
     *  Name: Login
     *  Function: output the "login" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void Login(bool IsSuccessful, const DateTime& SamplingTime = DateTime(1900,1,1,0,0,0),
    const DateTime& EntryTime = DateTime(1900,1,1,0,0,0), TestResult inResult = TestResult:: UNKNOWN);
    
    /*!
     *  Name: NoUserLogin
     *  Function: output the "no user login" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void NoUserLogin();
    
    
    /*
     *  Deal with set users type
     */
    
    /*!
     *  Name: NoPermission
     *  Function: output the "no permission" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void NoPermission();
    
    /*!
     *  Name: IndentityRepeatSetting
     *  Function: output the "Indentity Repeat Setting" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void IndentityRepeatSetting();
    
    
    /*
     *  Deal with initilize a new tube
     */
    
    /*!
     *  Name: SerialNumberIllegal
     *  Function: output the "Serial Number Illegal" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void SerialNumberIllegal();
    
    /*!
     *  Name: SerialNumberRepeat
     *  Function: output the "Serial Number Repeat" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void SerialNumberRepeat();
    
    
    /*
     *  Deal with fill tube error
     */
    
    /*!
     *  Name: SamplingTimeIllegal
     *  Function: output the "Sampling Time Illegal" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void SamplingTimeIllegal();
    
    /*!
     *  Name: NoTubeToModify
     *  Function: output the "No Tube To Modify" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void NoTubeToModify();
    
    /*!
     *  Name: TubeFull
     *  Function: output the "tube has been full" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void TubeFull();
    
    
    /*
     *  Deal with set tube's result error
     */
    
    /*!
     *  Name: InvalidResult
     *  Function: output the "invalid result" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void InvalidResult();
    
    /*!
     *  Name: EntryTimeIllegal
     *  Function: output the "entry time illegal" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void EntryTimeIllegal();
    
    /*
     *  Confirm quit command
     */
    
    /*!
     *  Name: ConfirmQuit
     *  Function: output the "confirm quit command" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void ConfirmQuit();
    
    /*!
     *  Name: IllegalConfimationInput
     *  Function: output the "illegal input" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void IllegalConfimationInput();
    
    /*
     *  Deal with general error
     */
    
    /*!
     *  Name: NoTube
     *  Function: output the "no tube with this serial number" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void NoTube();
    
    /*!
     *  Name: NoUser
     *  Function: output the "no user with this id" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void NoUser();
    
    /*!
     *  Name: CommandNotFound
     *  Function: output the "CommandNotFound" message on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void CommandNotFound();
    
    /*!
     *  Name: NextCommand
     *  Function: output the next command symbol on the client
     *  Parameter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/12/2022
     *  Updating: N/A
     */
    static void NextCommand();
};

#endif /* Client_hpp */
