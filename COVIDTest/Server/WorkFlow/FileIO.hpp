/*!
 *  File Name: FileIO
 *  Function: read or write from the designative file
 *  Developer: Alfred Dai   7/1/2022
 *  Updating: N/A
 */

#ifndef FileIO_hpp
#define FileIO_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "../../Message/StdMessage.hpp"

using namespace std;

/*!
 * Class Name: FileInput;
 * Function: read all users' infomation from designative file
 * API: overloading function of (), read users's infomation
 * Developer: Alfred Dai    7/1/2022
 * Updating: N/A
 */
class FileInput {
public:
    
    /*!
     *  Name: operator ( )
     *  Function: input file and package users's infomation sending to User:: GetInstiance for initializing
     *  Parameters: All inputs
     *  Return Value: vector<UserIO:: IOGetInstance>, process and package information in the target file
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
    vector<MessageUserInput> operator ()(const char* p_FilePath);
};



/*!
 * Class Name: FileOutput;
 * Function: save all users' infomation from designative file
 * API: overloading function of (), save users's infomation
 * Developer: Alfred Dai    7/1/2022
 * Updating: N/A
 */
class FileOutput {
public:
    
    /*!
     *  Name: operator ( )
     *  Function: 1. write one line in the specific file each time
     *         2. record the all users' test result in .txt
     *  Parameters: All inputs
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
    void operator ()(const char* p_FilePath, const vector<MessageUserOutput>& Message);
    
    /*!
     *  Name: operator()
     *  Function: update the origin users's data file
     *  Parameters: file path and all users's
     *  Return Value: void
     *  Developer: Alfred Dai   7/1/2022
     *  Updating: N/A
     */
    void operator ()(const char* p_FilePath, const vector<MessageUserInput>& Message);
    
    /*!
     *  Name: operator ( )
     *  Function: 1. write one line in the specific file each time
     *         2. record the all testtubes's result in .txt
     *  Parameters: All inputs
     *  Developer: Alfred Dai   7/2/2022
     *  Updating: N/A
     */
    void operator ()(const char* p_FilePath, const vector<MessageTubeOutput>& Message);
};

#endif /* FileIO_hpp */
