#include "Client.hpp"
//-----------------------------------------------------------------------------
//                          Client Input
//-----------------------------------------------------------------------------
ClientCommand ClientInput::GetCommand() {
    string CommandLine;
    cin >> CommandLine;
    if (CommandLine == "register") {
        return ClientCommand:: Register;
    } else if (CommandLine == "login") {
        return ClientCommand:: Login;
    } else if (CommandLine == "logout") {
        return ClientCommand:: Logout;
    } else if (CommandLine == "set_admin") {
        return ClientCommand:: SetAdmin;
    } else if (CommandLine == "set_collector") {
        return ClientCommand:: SetCollector;
    } else if (CommandLine == "set_entry") {
        return ClientCommand:: SetEntry;
    } else if (CommandLine == "new_tube") {
        return ClientCommand:: NewTube;
    } else if (CommandLine == "fill_tube") {
        return ClientCommand:: FillTube;
    } else if (CommandLine == "set_result") {
        return ClientCommand:: SetResult;
    } else if (CommandLine == "quit") {
        return ClientCommand:: Quit;
    } else {
        return ClientCommand:: CommandNotFound;
    }
}
//-----------------------------------------------------------------------------
char ClientInput::GetChar() {
    char Temp = cin.get();
    return Temp;
}
//-----------------------------------------------------------------------------
string ClientInput::GetString() {
    string Message;
    cin >> Message;
    return Message;
}
//-----------------------------------------------------------------------------
unsigned int ClientInput::GetUnsignedNumber() {
    unsigned int uNum = 0;
    cin >> uNum;
    return uNum;
}
//-----------------------------------------------------------------------------
void ClientInput::DeleteChar() {
    cin.get();
}
//-----------------------------------------------------------------------------
void ClientInput::ClearBuffer() {
    while (cin.get() != '\n') {
        // empty
    }
}
//-----------------------------------------------------------------------------
//                        Client Output
//-----------------------------------------------------------------------------
//                      Deal with Register error
//-----------------------------------------------------------------------------
void ClientOutput::IDIllegal() {
    cout << "ID is illegal" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::IDRepeat() {
    cout << "There are two same ID" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::PasswordTooShort() {
    cout << "Password too short" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
//                      Deal with login error
//-----------------------------------------------------------------------------
void ClientOutput::Login(bool IsSuccessful, const DateTime& SamplingTime,
                          const DateTime& EntryTime, TestResult inResult) {
    if (IsSuccessful) {
        // test result has been set
        if (inResult != TestResult::UNKNOWN) {
            cout << "Sampling Time : " << SamplingTime << " , " << "Entry Time : "
            << EntryTime << endl;
            cout << "Your recent test result is: " << inResult << endl;
        } else {
            cout << "Your recent test result is: unknown" << endl;
        }
    } else {
        cout << "Login failed" << endl;
    }
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::NoUserLogin() {
    cout << "No user login" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::LoginRepeat() {
    cout << "Repeat login" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
//                      Deal with set users type
//-----------------------------------------------------------------------------
void ClientOutput::NoPermission() {
    cout << "No permission" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::IndentityRepeatSetting() {
    cout << "Repeat setting user's type" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
//                    Deal with initilize a new tube
//-----------------------------------------------------------------------------
void ClientOutput::SerialNumberIllegal() {
    cout << "Serial number's format illegal" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::SerialNumberRepeat() {
    cout << "Serial number repeat" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
//                      Deal with fill tube error
//-----------------------------------------------------------------------------
void ClientOutput::SamplingTimeIllegal() {
    cout << "Sampling time illegal" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::NoTubeToModify() {
    cout << "No tube to modify, creat a tube first" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::TubeFull() {
    cout << "This tube has been full, creat another tube to continue" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
//                    Deal with set tube's result error
//-----------------------------------------------------------------------------
void ClientOutput::InvalidResult() {
    cout << "Invalid result setting" << endl;
    NextCommand();
}

void ClientOutput::EntryTimeIllegal() {
    cout << "Entry time's format is illegal" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
//                      Confirm quit command
//-----------------------------------------------------------------------------
void ClientOutput::ConfirmQuit() {
    cout << "Are you sure you want to exit?" << endl;
    cout << "[Y/n] : ";
}

void ClientOutput::IllegalConfimationInput() {
    cout << "Enter y/n" << endl;
}
//-----------------------------------------------------------------------------
//                      Deal with general error
//-----------------------------------------------------------------------------
void ClientOutput::NoUser() {
    cout << "No user with this ID" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::NoTube() {
    cout << "No tube with this serial number" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::CommandNotFound() {
    cout << "Command not found" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ClientOutput::NextCommand() {
    cout << "(client) >> ";
}

