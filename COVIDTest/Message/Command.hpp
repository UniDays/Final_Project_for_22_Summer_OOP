#ifndef Command_hpp
#define Command_hpp

enum class ClientCommand {
    
    // Register: register Name ID Password
    Register,
    // Request to log in: login "ID number" "Password"
    Login,
    // Request to log out: logout
    Logout,
    // Set Admin: set_admin "ID number"
    SetAdmin,
    // Set collector: set_collector "ID number"
    SetCollector,
    // Set Entry Staff: set_entry "ID number"
    SetEntry,
    //Creat new tube: new_tube YYYY/MM/DD HH:MM:SS 123456
    NewTube,
    //set tested person's ID and sampling time: fill_tube "ID number" YYYY/MM/DD HH:MM:SS
    FillTube,
    //set test result for designative tube: set_result SerialNumber YYYY/MM/DD HH:MM:SS nagetive
    SetResult,
    
    //user want to close the program: quit
    Quit,
    
    //Command not found
    CommandNotFound
};

enum class ServerCommand {
    // Load all users' data from designative file: load
    LoadData,
    // Set path file: set_fp
    SetFilePath,
    // Command not found
    CommandNotFound
};

#endif /* Command_hpp */
