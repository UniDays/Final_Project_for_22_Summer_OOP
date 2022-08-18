#include "Controller.hpp"
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
//                           public member funciton
//-----------------------------------------------------------------------------
void Control::CovidTest() {
    ServerControl();
    ClientControl();
}
//-----------------------------------------------------------------------------
//                         private member function
//-----------------------------------------------------------------------------
void Control::ServerControl() {
    ServerOutput::NextCommand();
    ServerCommand inServerCommand = ServerInput::GetCommand();
    // server settings
    while (true) {
        // implement command line
        if (inServerCommand == ServerCommand::SetFilePath) {
            SetFilePath();
        } else if (inServerCommand == ServerCommand::LoadData) {
            if (LoadData()) {
                // enter the client;
                ServerInput::ClearBuffer();
                break;
            }
        } else if (inServerCommand == ServerCommand::CommandNotFound) {
            ServerOutput::CommandNotFound();
        }
        // clear the buffer
        ServerInput::ClearBuffer();
        // get the next command from server
        inServerCommand = ServerInput::GetCommand();
    }
}
//-----------------------------------------------------------------------------
void Control::ClientControl() {
    ClientOutput::NextCommand();
    ClientCommand inCommand = ClientInput::GetCommand();
    // client function
    while (true) {
        // implement command line
        if (inCommand == ClientCommand:: Register) {
            Register();
        } else if (inCommand == ClientCommand::Login) {
            Login();
        } else if (inCommand == ClientCommand::Logout) {
            Logout();
        } else if (inCommand == ClientCommand::SetAdmin) {
            SetAdmin();
        } else if (inCommand == ClientCommand::SetCollector) {
            SetCollector();
        } else if (inCommand == ClientCommand::SetEntry) {
            SetEntry();
        } else if (inCommand == ClientCommand::NewTube) {
            NewTube();
        } else if (inCommand == ClientCommand::FillTube) {
            FillTube();
        } else if (inCommand == ClientCommand::SetResult) {
            SetResult();
        } else if (inCommand == ClientCommand::Quit) {
            if (Quit()) {
                // stop the program
                break;
            }
        } else if (inCommand == ClientCommand::CommandNotFound) {
            ClientCommandInvalid();
        }
        
        //cout << "Check1" << endl;
        
        // clear the buffer
        ClientInput::ClearBuffer();
        //cout << "Check2" << endl;
        
        // get the next command from client
        inCommand = ClientInput:: GetCommand();
    }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Control:: SetFilePath() {
    unsigned int inWhichOne = ServerInput::GetUnsignedNumber();
    string inFilePath = ServerInput::GetString();
    if (Server::SetFilePath(inWhichOne, inFilePath)) {
        ServerOutput::NextCommand();
    } else {
        ServerOutput::SetFilePathError(inWhichOne);
    }
}
//-----------------------------------------------------------------------------
bool Control::LoadData() {
    try {
        if (!Server:: HasSetAllFile()) {
            throw MyException:: FailedToOpen;
        }
        // Error: FailedToOpen, NoAdmin, IDIllegal, IDRepeat, PasswordTooShort
        Server:: CreatAllUsers();
        return true;
    } catch (MyException& e) {
        if (e == MyException::FailedToOpen) {
            ServerOutput:: FilePathInvalid();
        } else if (e == MyException::NoAdmin) {
            ServerOutput::NoAdmin();
        } else if (e == MyException::IDIllegal) {
            ServerOutput::IDIllegal();
        } else if (e == MyException::IDRepeat) {
            ServerOutput::IDRepeat();
        } else if (e == MyException::PasswordTooShort) {
            ServerOutput::PasswordTooShort();
        }
        return false;
    }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Control::Register() {
    string inName = ClientInput::GetString();
    string inID = ClientInput::GetString();
    string inPassword = ClientInput::GetString();
    try {
        Server:: Register(MessageUserInput(inName, inPassword, inID, false));
        ClientOutput:: NextCommand();
    } catch (MyException& e) {
        if (e == MyException::IDIllegal) {
            ClientOutput::IDIllegal();
        } else if (e == MyException::IDRepeat) {
            ClientOutput::IDRepeat();
        } else if (e == MyException::PasswordTooShort) {
            ClientOutput::PasswordTooShort();
        }
    }
}
//-----------------------------------------------------------------------------
void Control::Login() {
    // check whether there is user login now
    if (Server::IsLogin()) {
        ClientOutput::LoginRepeat();
        return;
    }
    // input the id and password
    string inIDNumber = ClientInput::GetString();
    string inPassword = ClientInput::GetString();
    MessageLogin inMessage(inIDNumber, inPassword);
    // output whether it can log in
    if (Server:: Login(inMessage)) {
        ClientOutput::Login(true, Server::ShowSamplingTime(), Server::ShowEntryTime() ,Server::ShowTestResult());
    } else {
        ClientOutput::Login(false);
    }
}
//-----------------------------------------------------------------------------
void Control::Logout() {
    if (!Server:: IsLogin()) {
        ClientOutput::NoUserLogin();
    } else {
        Server:: Logout();
        ClientOutput::NextCommand();
    }
}
//-----------------------------------------------------------------------------
void Control::SetAdmin() {
    string inIDNumber = ClientInput::GetString();
    try {
        // Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
        Server:: SetAdmin(inIDNumber);
        ClientOutput::NextCommand();
    } catch (MyException& e) {
        if (e == MyException::NoUserLogin) {
            ClientOutput:: NoUserLogin();
        } else if (e == MyException::NoPermission) {
            ClientOutput::NoPermission();
        } else if (e == MyException::IDNotExist) {
            ClientOutput::NoUser();
        } else if (e == MyException::IdentityRepeatSetting) {
            ClientOutput::IndentityRepeatSetting();
        }
    }
}
//-----------------------------------------------------------------------------
void Control::SetCollector() {
    string inIDNumber = ClientInput::GetString();
    try {
        // Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
        Server:: SetCollector(inIDNumber);
        ClientOutput:: NextCommand();
    } catch (MyException& e) {
        if (e == MyException::NoUserLogin) {
            ClientOutput::NoUserLogin();
        } else if (e == MyException::NoPermission) {
            ClientOutput:: NoPermission();
        } else if (e == MyException::IDNotExist) {
            ClientOutput:: NoUser();
        } else if (e == MyException::IdentityRepeatSetting) {
            ClientOutput:: IndentityRepeatSetting();
        }
    }
}
//-----------------------------------------------------------------------------
void Control::SetEntry() {
    string inIDNumber = ClientInput:: GetString();
    try {
        // Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
        Server:: SetEntryStaff(inIDNumber);
        ClientOutput:: NextCommand();
    } catch (MyException& e) {
        if (e == MyException::NoUserLogin) {
            ClientOutput::NoUserLogin();
        } else if (e == MyException::NoPermission) {
            ClientOutput:: NoPermission();
        } else if (e == MyException::IDNotExist) {
            ClientOutput:: NoUser();
        } else if (e == MyException::IdentityRepeatSetting) {
            ClientOutput::IndentityRepeatSetting();
        }
    }
}
//-----------------------------------------------------------------------------
void Control::NewTube() {
    try {
        // Error: SerialNumberIllegal
        SerialNumber inSerialNumber = StringToSerialNumber();
        // Error: SerialNumberRepeat
        Server:: CreatTube(inSerialNumber);
        ClientOutput:: NextCommand();
    // deal with error
    } catch (MyException& e) {
        if (e == MyException::SerialNumberIllegal) {
            ClientOutput::SerialNumberIllegal();
        } else if (e == MyException::SerialNumberRepeat) {
            ClientOutput::SerialNumberRepeat();
        } else if (e == MyException::NoPermission) {
            ClientOutput::NoPermission();
        }
    }
}
//-----------------------------------------------------------------------------
void Control::FillTube() {
    try {
        string inIDNumber = ClientInput::GetString();
        // Error: DateTimeIllegal
        DateTime inSamplingTime = StringToDateTime();
        //Error: NoTubeToModify, TubeFull, IDNotExist
        Server::FillTube(MessageSamplingInfo(inIDNumber, inSamplingTime));
        ClientOutput::NextCommand();
    // Deal with error
    } catch (MyException& e) {
        if (e == MyException::DateTimeIllegal) {
            ClientOutput::SamplingTimeIllegal();
        } else if (e == MyException::NoTubeToModify) {
            ClientOutput::NoTubeToModify();
        } else if (e == MyException::TubeFull) {
            ClientOutput::TubeFull();
        } else if (e == MyException::IDNotExist) {
            ClientOutput::NoUser();
        } else if (e == MyException::NoPermission) {
            ClientOutput::NoPermission();
        }
    }
}
//-----------------------------------------------------------------------------
void Control::SetResult() {
    // set tube's test result
    try {
        // Error: SerialNumberIllegal
        SerialNumber inSerialNumber = StringToSerialNumber();
        // Error: DateIllegal
        DateTime inEntryTime = StringToDateTime();
        TestResult inResult = TestResult::UNKNOWN;
        
        // transform string to TestResult, and Unknown is invalid
        string inStringResult = ClientInput::GetString();
        if (inStringResult == "negative") {
            inResult = TestResult::NEGATIVE;
        } else if (inStringResult == "positive") {
            inResult = TestResult::POSITIVE;
        } else {
            ClientOutput::InvalidResult();
            return;
        }
        // set test result for tube
        // Error: SerialNumberNotExist
        Server::SetTestResult(MessageTubeTestResult(inSerialNumber, inEntryTime,
                                                     inResult));
        ClientOutput::NextCommand();
        
    } catch (MyException& e) {
        if (e == MyException::SerialNumberIllegal) {
            ClientOutput::SerialNumberIllegal();
        } else if (e == MyException::DateTimeIllegal) {
            ClientOutput::EntryTimeIllegal();
        } else if (e == MyException::SerialNumberNotExist) {
            ClientOutput::NoTube();
        } else if (e == MyException::NoPermission) {
            ClientOutput::NoPermission();
        }
    }
}
//-----------------------------------------------------------------------------
bool Control::Quit() {
    // only admin can exit the program
    if (!Server::IsAdmin()) {
        ClientOutput::NoPermission();
        return false;
    }
    ClientOutput::ConfirmQuit();
    while (true) {
        char Confirm = ClientInput::GetChar();
        while (Confirm == ' ' || Confirm == '\n' || Confirm == '\t') {
            Confirm = ClientInput::GetChar();
        }
        if(Confirm == 'Y' || Confirm == 'y') {
            Server::SaveUserInfo();
            Server::SaveTubeInfo();
            Server::UpdateUserInfo();
            return true;
        } else if (Confirm == 'N' || Confirm == 'n') {
            ClientOutput::NextCommand();
            return false;
        } else {
            ClientOutput::IllegalConfimationInput();
            ClientOutput::NextCommand();
            return false;
        }
    }
}
//-----------------------------------------------------------------------------
void Control::ClientCommandInvalid() {
    ClientOutput::CommandNotFound();
}
//-----------------------------------------------------------------------------
//                          transform function
//-----------------------------------------------------------------------------
// Error: DateTimeIllegal
DateTime Control::StringToDateTime() {
    unsigned int DateTimeNumber[6] = {0};
    // get in sampling time
    for (int i = 0;i < 6;i++) {
        DateTimeNumber[i] = ClientInput::GetUnsignedNumber();
        // keep the separator character (as '\n', ' ','.' etc.) at the end of input
        if (i < 5) {
            ClientInput::DeleteChar();
        }
    }
    try {
        // Error: TimeIllegal, DateIllegal
        DateTime ReValue (DateTimeNumber[0], DateTimeNumber[1], DateTimeNumber[2],
                          DateTimeNumber[3], DateTimeNumber[4], DateTimeNumber[5]);
        return ReValue;
    } catch (MyException& e) {
        throw MyException::DateTimeIllegal;
    }
}
//-----------------------------------------------------------------------------
// Error: SerialNumberIllegal
SerialNumber Control::StringToSerialNumber() {
    try {
        // Error: DateTimeIllegal
        DateTime inDateTime = StringToDateTime();
        string inIndentifictionCode = ClientInput::GetString();
        // Error: SerialNumberIllegal
        SerialNumber ReValue(inDateTime, inIndentifictionCode);
        return ReValue;
    } catch (MyException& e) {
        throw MyException::SerialNumberIllegal;
    }
}
