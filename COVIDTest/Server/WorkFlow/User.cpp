#include "User.hpp"
#include "TubeLabel.hpp"
//-----------------------------------------------------------------------------
//                                 UseType
//-----------------------------------------------------------------------------
UserType::UserType(const bool inIsAdmin, const bool inIsCollector,
                     const bool inIsEntry) {
    m_IsAdmin = inIsAdmin;
    m_IsCollector = inIsCollector;
    m_IsEntry = inIsEntry;
}
//-----------------------------------------------------------------------------
UserType::UserType (const UserType & Source) {
    m_IsAdmin = Source.m_IsAdmin;
    m_IsCollector = Source.m_IsCollector;
    m_IsEntry = Source.m_IsEntry;
}
//-----------------------------------------------------------------------------
//                                  User
//-----------------------------------------------------------------------------
//                       static member definition
bool User:: s_HasAdmin = false;
vector<shared_ptr<User> > User:: s_AllUsers;
unsigned int User::s_PasswordMinLength = 6;
//-----------------------------------------------------------------------------
//Error: NoAdmin, IDIllegal, IDRepeat, PasswordTooShort
bool User::GetInstance (const vector<MessageUserInput>& inAllUserInfo) {
    //Creat all users and stored their pointer in s_AllUsers
    for (auto& Message: inAllUserInfo) {
        //Get the pointer
        User* pTemp = new User(Message.m_Name, Message.m_IDNumber, Message.m_Password, Message.m_IsAdmin);
        s_AllUsers.push_back(shared_ptr<User>(pTemp));
        //Judge whether there is at least on Admin or not
        s_HasAdmin = s_HasAdmin || Message.m_IsAdmin;
    }
    // If there is no Admin in all users, throw an error "NoAdmin"
    if (!s_HasAdmin) {
        throw (MyException::NoAdmin);
    }
    return true;
}
//-----------------------------------------------------------------------------
//Error: NoPermission, IDNOtExist, IdentityRepeatSetting
bool User::SetCollector(const string &inIDNumber) {
    //Judge whether the user have permission or not
    if (!IsAdmin) {
        throw (MyException:: NoPermission);
    }
    //Judge whether this ID number exists
    User* pTemp = IsExist(inIDNumber);
    if (pTemp == nullptr) {
        throw (MyException::IDNotExist);
    }
    //Judge whether repeat setting
    if (pTemp->IsCollector) {
        throw (MyException::IdentityRepeatSetting);
    }
    //set
    pTemp->m_Type.m_IsCollector = true;
    return true;
}
//-----------------------------------------------------------------------------
//Error: NoPermission, IDNOtExist, IdentityRepeatSetting
bool User::SetEntry(const string &inIDNumber) {
    //Judge whether the user have permission or not
    if (!IsAdmin) {
        throw (MyException::NoPermission);
    }
    //Judge whether this ID number exists
    User* pTemp = IsExist(inIDNumber);
    if (pTemp == nullptr) {
        throw (MyException::IDNotExist);
    }
    //Judge whether repeat setting
    if (pTemp->IsEntryStaff) {
        throw (MyException::IdentityRepeatSetting);
    }
    //set
    pTemp->m_Type.m_IsEntry = true;
    return true;
}
//-----------------------------------------------------------------------------
//Error: NoPermission, IDNOtExist, IdentityRepeatSetting
bool User::SetAdmin(const string &inIDNumber) {
    //Judge whether the user have permission or not
    if (!IsAdmin) {
        throw (MyException::NoPermission);
    }
    //Judge whether this ID number exists
    User* pTemp = IsExist(inIDNumber);
    if (pTemp == nullptr) {
        throw (MyException::IDNotExist);
    }
    //Judge whether repeat setting, and prevent admin delete hisself or herself identity
    if (pTemp->IsAdmin) {
        throw (MyException::IdentityRepeatSetting);
    }
    //set
    pTemp->m_Type.m_IsAdmin = true;
    return true;
}
//-----------------------------------------------------------------------------
//No Error
User* User::IsAllowedToLog(const MessageLogin &inIDNumAndPassword) {
    //If pTemp == nullptr which means user cannot login
    return IsAllowedToLog(inIDNumAndPassword.m_IDNumber, inIDNumAndPassword.m_Password);
}
//-----------------------------------------------------------------------------
//No Error
User* User::IsExist(const string &inIDnumber) {
    // if ID's format is not illeagal, return false
    if (!IsIDLegal(inIDnumber)) {
        return nullptr;
    }
    //Ergodic all users
    for (auto& n: s_AllUsers) {
        if(inIDnumber == n->m_IDNumber) {
            // if exist, return pointer point to user with this ID
            return n.get();
        }
    }
    // Do not exist
    return nullptr;
}
//-----------------------------------------------------------------------------
// No Error
void User::SetTestResult(const enum TestResult inTestResult) {
    // if user's test result is not negative, update
    if (m_TestResult != TestResult::NEGATIVE) {
        m_TestResult = inTestResult;
    }
}
//-----------------------------------------------------------------------------
// No Error
void User::SetSamplingTime(const DateTime &inSamplingTime) {
    m_SamplingTime = inSamplingTime;
}
//-----------------------------------------------------------------------------
// No Error
void User::SetEntryTime(const DateTime &inEntryTime) {
    m_EntryTime = inEntryTime;
}
//-----------------------------------------------------------------------------
// No Error
vector<MessageUserOutput> User::PackageUserInfo() {
    vector<MessageUserOutput> Temp;
    for (auto& n: s_AllUsers) {
        Temp.push_back(MessageUserOutput(n->m_Name, n->m_IDNumber, n->m_TestResult));
    }
    return Temp;
}
//-----------------------------------------------------------------------------
// No Error
vector<MessageUserInput> User::PackageUserIdentiyInfo() {
    vector<MessageUserInput> Temp;
    for (auto& n: s_AllUsers) {
        Temp.push_back(MessageUserInput(n->m_Name, n->m_Password, n->m_IDNumber, n->IsAdmin));
    }
    return Temp;
}
//-----------------------------------------------------------------------------
//Error: IDIllegal, IDRepeat, PasswordTooShort
User* User::GetInstance(const string& inName, const string& inIDNumber,
                         const string& inPassword, const bool& inIsAdmin){
    //Error: IDIllegal, IDRepeat, PasswordTooShort
    User* pTemp = new User(inName, inIDNumber, inPassword, inIsAdmin);
    s_AllUsers.push_back(shared_ptr<User>(pTemp));
    return pTemp;
}
//-----------------------------------------------------------------------------
// No Error
User* User::IsAllowedToLog(const string &LoginIDNumber, const string &LoginPassword) {
    // Ergodic all user
    for (auto& n: s_AllUsers) {
        if (n->m_IDNumber == LoginIDNumber && n->m_Password == LoginPassword) {
            return n.get();
        }
    }
    return nullptr;
}
//-----------------------------------------------------------------------------
// No Error
bool User::IsIDLegal(const string &inIDNumber) {
    if (inIDNumber.size() != 18u) {
        return false;
    }
    // 1st-17th digits must be all numbers
    for (unsigned int i = 0;i < 17u;i++) {
        char temp = inIDNumber[i];
        if (temp < '0' || temp > '9') {
            return false;
        }
    }
    // 18th digits must be numbers or 'X'
    char temp = inIDNumber[17];
    if (!((temp == 'X') || (temp >= '0' || temp <= '9'))) {
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------
// Error: IDIllegal, IDRepeat, PasswordTooShort
User::User (const string& inName, const string& inIDNumber,
             const string& inPassword, const bool& inIsAdmin):
IsAdmin(m_Type.m_IsAdmin), IsCollector(m_Type.m_IsCollector), IsEntryStaff(m_Type.m_IsEntry) {
    // whether format of ID number is legal or not
    if (!IsIDLegal(inIDNumber)) {
        throw (MyException:: IDIllegal);
    }
    // whether this ID number has existed
    if (IsExist(inIDNumber)) {
        throw (MyException:: IDRepeat);
    }
    // whether the password is long enough
    if (inPassword.size() < s_PasswordMinLength) {
        throw (MyException:: PasswordTooShort);
    }
    m_Name = inName;
    m_IDNumber = inIDNumber;
    m_Password = inPassword;
    m_TestResult = TestResult::UNKNOWN;
    // default parameter constructor
    m_Type = UserType(inIsAdmin);
    // call default parameteer constructor to initilize m_SamplingTime, m_EntryTime
}
//-----------------------------------------------------------------------------
