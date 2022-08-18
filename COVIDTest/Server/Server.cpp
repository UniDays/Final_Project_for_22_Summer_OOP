#include "Server.hpp"
#include "../Message/Command.hpp"

//-----------------------------------------------------------------------------
//                              static member
//-----------------------------------------------------------------------------
User* Server::m_LoginUser = nullptr;
TestTube* Server::m_ModifyingTube = nullptr;
bool Server::m_HasLoadData = false;
//default constructor of string
string Server::UserDataFilePath;
string Server::UserResultFilePath;
string Server::TubeResultFilePath;
bool Server::m_HasSetAllFile[3] = {false, false, false};
//-----------------------------------------------------------------------------
// Error: FailedToOpen, NoAdmin, IDIllegal, IDRepeat, PasswordTooShort
bool Server::CreatAllUsers(const char* FilePath) {
    User:: GetInstance(FileInput()(FilePath));
    m_HasLoadData = true;
    return true;
}
//-----------------------------------------------------------------------------
// Error: IDIllegal, IDRepeat, PasswordTooShort
void Server::Register(const MessageUserInput &inMessage) {
    User:: GetInstance(inMessage.m_Name, inMessage.m_IDNumber, inMessage.m_Password, false);
}
//-----------------------------------------------------------------------------
//  No Error
bool Server::Login (const MessageLogin& inIDNumAndPassword) {
    User* pTemp = User:: IsAllowedToLog(inIDNumAndPassword);
    
    // if user can not log in
    if (pTemp == nullptr) {
        return false;
    } else {
        m_LoginUser = pTemp;
        return true;
    }
}
//-----------------------------------------------------------------------------
// Error: NoUserLogin
TestResult Server::ShowTestResult() {
    if (m_LoginUser == nullptr) {
        throw MyException:: NoUserLogin;
    }
    // controller just call it when there is a user loging
    return m_LoginUser->TestResult();
}
//-----------------------------------------------------------------------------
// Error: NoUserLogin
const DateTime& Server::ShowSamplingTime() {
    if (m_LoginUser == nullptr) {
        throw MyException:: NoUserLogin;
    }
    // controller just call it when there is a user loging
    return m_LoginUser->SamplingTime();
}
//-----------------------------------------------------------------------------
// Error: NoUserLogin
const DateTime& Server::ShowEntryTime() {
    if (m_LoginUser == nullptr) {
        throw MyException:: NoUserLogin;
    }
    // controller just call it when there is a user loging
    return m_LoginUser->EntryTime();
}
//-----------------------------------------------------------------------------
// Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
bool Server::SetAdmin(const string& IDNumber) {
    if (m_LoginUser == nullptr) {
        throw MyException:: NoUserLogin;
    }
    // set
    m_LoginUser->SetAdmin(IDNumber);
    return true;
}
//-----------------------------------------------------------------------------
// Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
bool Server::SetCollector(const string& IDNumber) {
    if (m_LoginUser == nullptr) {
        throw MyException:: NoUserLogin;
    }
    // set
    m_LoginUser->SetCollector(IDNumber);
    return true;
}
//-----------------------------------------------------------------------------
// Error: NoUserLogin, NoPermission, IDNotExist, IdentityRepeatSetting
bool Server::SetEntryStaff(const string& IDNumber) {
    if (m_LoginUser == nullptr) {
        throw MyException:: NoUserLogin;
    }
    // set
    m_LoginUser->SetEntry(IDNumber);
    return true;
}
//-----------------------------------------------------------------------------
// Error: SerialNumberRepeat, NoPermission
void Server::CreatTube(const SerialNumber& inSerialNumber) {
    // only collector can creat tube
    if (!m_LoginUser->IsCollector) {
        throw MyException::NoPermission;
    }
    // if serial number is repeat, throw error "SerialNumberRepeat"
    // set m_ModifyingTube point to this tube
    m_ModifyingTube = TestTube::GetInstance(inSerialNumber);
}
//-----------------------------------------------------------------------------
// Error: NoTubeToModify, TubeFull, IDNotExist, NoPermission
bool Server::FillTube (const MessageSamplingInfo& inIDNumAndSamplingTime) {
    // only collector can creat tube
    if (!m_LoginUser->IsCollector) {
        throw MyException::NoPermission;
    }
    // collector should creat a tube first
    if (m_ModifyingTube == nullptr) {
        throw MyException::NoTubeToModify;
    }
    //if the tube is full or ID number is wrong, throw error
    m_ModifyingTube->SetTestedInfo(inIDNumAndSamplingTime);
    return true;
}
//-----------------------------------------------------------------------------
// Error: SerialNumberNotExist, InvalidResultSetting, NoPermission
bool Server::SetTestResult(const MessageTubeTestResult& inSerialandTubeResult) {
    // Only Entry staff can set test result
    if (!m_LoginUser->IsEntryStaff) {
        throw MyException:: NoPermission;
    }
    m_ModifyingTube = TestTube:: IsExist(inSerialandTubeResult.m_TubeSerialNum);
    // if serial number doesn't exist
    if (m_ModifyingTube == nullptr) {
        throw MyException::SerialNumberNotExist;
    }
    // set test result of tube
    m_ModifyingTube->SetTubeTestResult(inSerialandTubeResult.m_EntryTime,
                                       inSerialandTubeResult.m_TestResult);
    return true;
}
//-----------------------------------------------------------------------------
// Error: FailedToOpen
void Server::SaveUserInfo(const char* p_FilePath) {
    FileOutput()(p_FilePath, User:: PackageUserInfo());
}
//-----------------------------------------------------------------------------
// Error: FailedToOpen
void Server::SaveTubeInfo(const char* p_FilePath) {
    FileOutput()(p_FilePath, TestTube:: PackageTubeInfo());
}
//-----------------------------------------------------------------------------
// Error: FailedToOpen
void Server::UpdateUserInfo(const char* p_FilePath) {
    FileOutput()(p_FilePath, User:: PackageUserIdentiyInfo());
}
//-----------------------------------------------------------------------------
// No Error
void Server::Logout() {
    // set pointer to be nullptr
    m_LoginUser = nullptr;
    m_ModifyingTube = nullptr;
}
//-----------------------------------------------------------------------------
// No Error
bool Server::IsLogin() {
    if (m_LoginUser == nullptr) {
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------
// Error: NoUserLogin
bool Server::IsAdmin() {
    if (!IsLogin()) {
        throw MyException:: NoUserLogin;
    }
    return m_LoginUser->IsAdmin;
}
//-----------------------------------------------------------------------------
// No Error
bool Server::HasTubeToModify() {
    if (m_ModifyingTube == nullptr) {
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------
// No Error
bool Server::HasLoadData() {
    return m_HasLoadData;
}
//-----------------------------------------------------------------------------
// No Error
bool Server::IsFilePathValid(const string &inFilePath) {
    fstream file;
    file.open(inFilePath.c_str());
    if (file.is_open()) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}
//-----------------------------------------------------------------------------
// No Error
bool Server::SetFilePath(unsigned int inWhichOne, const string& inFilePath) {
    // whether the file path is correct
    if (!IsFilePathValid(inFilePath)) {
        return false;
    }
    switch (inWhichOne) {
        case 1: {
            UserDataFilePath = inFilePath;
            m_HasSetAllFile[0] = true;
            return true;
        }
        case 2: {
            UserResultFilePath = inFilePath;
            m_HasSetAllFile[1] = true;
            return true;
        }
        case 3: {
            TubeResultFilePath = inFilePath;
            m_HasSetAllFile[2] = true;
            return true;
        }
        default: {
            return false;
        }
    }
}
//-----------------------------------------------------------------------------
// No Error
bool Server:: HasSetAllFile() {
    return m_HasSetAllFile[0] && m_HasSetAllFile[1] && m_HasSetAllFile[2];
}
//-----------------------------------------------------------------------------
//                          ServerInput
//-----------------------------------------------------------------------------
ServerCommand ServerInput::GetCommand() {
    string inCommand = GetString();
    if (inCommand == "load") {
        return ServerCommand::LoadData;
    } else if (inCommand == "set_fp") {
        return ServerCommand::SetFilePath;
    } else {
        return ServerCommand::CommandNotFound;
    }
}
//-----------------------------------------------------------------------------
unsigned int ServerInput::GetUnsignedNumber() {
    char Temp = cin.get();
    while (Temp == ' ' || Temp == '\n' || Temp == '\t') {
        Temp = cin.get();
    }
    return (unsigned int)(Temp - '0');
};
//-----------------------------------------------------------------------------
string ServerInput::GetString() {
    string inStr;
    cin >> inStr;
    return inStr;
}
//-----------------------------------------------------------------------------
void ServerInput::ClearBuffer() {
    while (cin.get() != '\n') {
        // empty
    }
}
//-----------------------------------------------------------------------------
//                          ServerOutput
//-----------------------------------------------------------------------------
void ServerOutput::SetFilePathError(unsigned int inWhichOne) {
    switch (inWhichOne) {
        case 1: {
            cout << "User data file path invalid" << endl;
            break;
        }
        case 2: {
            cout << "User test result file path invalid" << endl;
            break;
        }
        case 3: {
            cout << "Tube test result file path invalid" << endl;
            break;
        }
        default: {
            cout << "Error type code (1 ~ 3)" << endl;
            break;
        }
    }
    NextCommand();
}
//-----------------------------------------------------------------------------
void ServerOutput::FilePathInvalid() {
    cout << "Server file path invalid" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ServerOutput::IDIllegal() {
    cout << "There is at least one user's ID illegal in the initialization file" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ServerOutput::IDRepeat() {
    cout << "There are two same ID in the initialization file " << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ServerOutput:: NoAdmin() {
    cout << "There is no Admin in in the initialization file" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ServerOutput::PasswordTooShort() {
    cout << "Password too short" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ServerOutput::CommandNotFound() {
    cout << "Command not found" << endl;
    NextCommand();
}
//-----------------------------------------------------------------------------
void ServerOutput::NextCommand() {
    cout << "(Server) >> ";
}
//-----------------------------------------------------------------------------
