/*!
 *  File Name: Controller.hpp
 *  Function: contoller, connect the server and client
 *  Developer: Alfred Dai   7/8/2022
 *  Update: N/A
 */

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include "../Message/Command.hpp"
#include "../Server/Server.hpp"
#include "../Client/Client.hpp"

/*!
 *  Class Name: Control
 *  Function: control all program running
 *  API: CovidTest: call it to run the CovidTest
 *  Developer: Alfred Dai   7/8/2022
 *  Update: N/A
 */
class Control {
public:
    
    /*!
     *  Name: CovidTest
     *  Function: application entry point
     *  Paremeter: none
     *  Return Value: none
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void CovidTest();
    
private:
    
    /*!
     *  Name: ServerControl
     *  Function: server setting
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void ServerControl();
    
    /*!
     *  Name: ClientControl
     *  Function: get the command from client and implement the operation
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void ClientControl();
    
    
    /*
     *  Server operation
     */
    
    /*!
     *  Name: SetFilePath
     *  Function: set file path on the server
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void SetFilePath();
    
    /*!
     *  Name: LoadData
     *  Function: load data from designative file
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static bool LoadData();
    
    /*!
     *  Name: ServerCommandInvalid
     *  Function: call it when the input command is invalid
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void ServerCommandInvalid();
    
    
    /*
     *  Client operation
     */
    
    /*!
     *  Name: Register
     *  Function: register
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void Register();
    
    /*!
     *  Name: Login
     *  Function: log in
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void Login();
    
    /*!
     *  Name: Logout
     *  Function: log out
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void Logout();
    
    /*!
     *  Name: SetAdmin
     *  Function: set admin
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void SetAdmin();
    
    /*!
     *  Name: SetCollector
     *  Function: set collector
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void SetCollector();
    
    /*!
     *  Name: SetEntry
     *  Function: set entry
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void SetEntry();
    
    /*!
     *  Name: NewTube
     *  Function: creat a new tube
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void NewTube();
    
    /*!
     *  Name: FillTube
     *  Function: related tube with tested person
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void FillTube();
    
    /*!
     *  Name: SetResult
     *  Function: set test result for each tube
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void SetResult();
    
    /*!
     *  Name: Quit
     *  Function: quit
     *  Parameter: bool, if user confirms exiting the application, it returns true
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static bool Quit();
    
    /*!
     *  Name: ClientCommandInvalid
     *  Function: command invalid
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static void ClientCommandInvalid();
    
    
    /*
     *  trans function
     */
    
    /*!
     *  Name: StringToDateTime
     *  Function: StringToDateTime
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static DateTime StringToDateTime();
    
    /*!
     *  Name: StringToSerialNumber
     *  Function: StringToSerialNumber
     *  Parameter: none
     *  Return value: void
     *  Developer: Alfred Dai   7/8/2022
     *  Update: N/A
     */
    static SerialNumber StringToSerialNumber();
};

#endif /* Controller_hpp */
