/*!
 *  File Name: Debug.hpp
 *  Function: the definition of error in the Server and Work Flow
 *  Developer: Alfred Dai   7/2/2022
 *  Upadating: N/A
 */
#ifndef Debug_hpp
#define Debug_hpp

/*!
 *  Name: enum MyException
 *  Function: the definition of error in the Server and Work Flow
 *  API: None
 *  Developer: Alfred Dai   7/2/2022
 *  Upadating: N/A
 */
enum class MyException {
    // there is no Admin which should be appointed in the initial file
    NoAdmin,
    // the ID in the initial file is repeated
    IDRepeat,
    // the Password in the initial is shorter than the minimal limited
    PasswordTooShort,
    // the format of ID nnumber is illegal
    IDIllegal,
    // user has no permission to change other users type
    NoPermission,
    // ID number does not exist, which includes format is illegal
    IDNotExist,
    // Repeat set someone's indentity, only suggest but not prevent
    IdentityRepeatSetting,
    
    // date is illegal
    DateIllegal,
    // time is illegal
    TimeIllegal,
    // datetime is illegal
    DateTimeIllegal,
    
    // the Serial Number's format or datetime part is illeagal
    SerialNumberIllegal,
    // the Serial Number of tube is repeated when Entry Staff want to creat a tube with this one
    SerialNumberRepeat,
    // tube is full
    TubeFull,
    // Repeat set tube's test result, only suggest but not prevent
    TestResultRepeatSetting,
    // User intends to set test result with Unknown
    InvalidResultSetting,
    // serial number doesn't exist
    SerialNumberNotExist,
    
    //file path is wrong or failed to open the signative file
    FailedToOpen,
    
    // No user login
    NoUserLogin,
    // No tube can be modified
    NoTubeToModify
    
};

#endif /* Debug_hpp */
