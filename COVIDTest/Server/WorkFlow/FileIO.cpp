#include "FileIO.hpp"
//-----------------------------------------------------------------------------
//                          FileInput Class
//-----------------------------------------------------------------------------
// Error: FailedToOpen
vector<MessageUserInput> FileInput::operator()(const char *p_FilePath) {
    fstream fin;
    fin.open(p_FilePath);
    // if failed to open designative, throw an error
    if (!fin.is_open()) {
        throw MyException::FailedToOpen;
    }
    
    vector<MessageUserInput> Package;
    
    string Name;
    string Password;
    string IDNumber;
    bool IsAdmin;
    // there shoundn't be whitespace between the name
    fin >> Name >> Password >> IDNumber >> IsAdmin;
    while (!fin.eof()) {
        // package the infomation into the Package
        Package.push_back(MessageUserInput(Name, Password, IDNumber, IsAdmin));
        fin >> Name >> Password >> IDNumber >> IsAdmin;
    }
    return Package;
}
//-----------------------------------------------------------------------------
//                          FileOutput Class
//-----------------------------------------------------------------------------
// Error: FailedToOpen
void FileOutput::operator ()(const char* p_FilePath, const vector<MessageUserOutput>& Message) {
    fstream fout;
    // it can creat a file following the designative path
    // Cover mode
    fout.open(p_FilePath);
    // if failed to open designative file, throw an error
    if (!fout.is_open()) {
        throw MyException::FailedToOpen;
    }
    
    // save the users infomation in designative file
    for (const auto& n: Message) {
        fout << setw(15) << n.m_Name << '\t' << setw(18) << n.m_IDNumber <<
        '\t' << setw(12) << n.m_TestResult << endl;
    }
}
//-----------------------------------------------------------------------------
// Error: FailedToOpen
void FileOutput::operator()(const char *p_FilePath, const vector<MessageUserInput> &Message) {
    fstream fout;
    // it can creat a file following the designative path
    // Cover mode
    fout.open(p_FilePath);
    // if failed to open designative file, throw an error
    if (!fout.is_open()) {
        throw MyException::FailedToOpen;
    }
    
    // save the users infomation in designative file
    for (const auto& n: Message) {
        fout << n.m_Name << endl;
        fout << n.m_Password << endl;
        fout << n.m_IDNumber << endl;
        fout << n.m_IsAdmin << endl;
    }
}

//-----------------------------------------------------------------------------
// Error: FailedToOpen
void FileOutput::operator ()(const char* p_FilePath, const vector<MessageTubeOutput>& Message) {
    fstream fout;
    // it can creat a file following the designative path
    // Cover mode
    fout.open(p_FilePath);
    // if failed to open designative file, throw an error
    if (!fout.is_open()) {
        throw MyException::FailedToOpen;
    }
    
    // save the users infomation in designative file
    for (const auto& n: Message) {
        fout << n.m_SerialNumber << '\t' << n.m_EntryTime << '\t' << n.m_TestResult << endl;
        // output the related users' ID number and sampling time
        for (const auto& m: n.m_RelatedTestedUser) {
            fout << m.first << '\t' << m.second << endl;
        }
        fout << "----------------------------------------------------------------------------" << endl;
    }
}
