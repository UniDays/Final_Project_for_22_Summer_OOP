/*!
 *  File Name: TubeLabel.hpp
 *  Function and Purpose:
 *                  1. Define a Derived Class DateTime from Date and Time
 *                  2. Label the TestTube with date, time and numbers
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */

#ifndef TubeLabel_hpp
#define TubeLabel_hpp

#include "DateTimeBase/Date.hpp"
#include "DateTimeBase/Time.hpp"
#include "../../Debug/Debug.hpp"
#include <string>

using namespace std;

class DateTime: public Date, public Time {
public:
    /*!
     *  @Name Constructor
     *  @Brief Initialize the datetime with year.month.day hour:min:sec
     *  @Parameter  All inputs
     *  @Author Alfred Dai   7/8/2022
     *  Updating  N/A
     */
    DateTime (unsigned int inYear = 1900, unsigned int inMonth = 1,
              unsigned int inDay = 1, unsigned int inHour = 0,
              unsigned int inMinute = 0, unsigned int inSecond = 0);
    
    /*!
     *  Name: operator =
     *  Function: compare two datetime
     *  Parameters: All inputs, const reference of DateTime
     *  Return Value: bool, if d1 and d2 is same, return true
     *  Developer: Alfred Dai   7/8/2022
     *  Upating: N/A
     */
    friend bool operator == (const DateTime& inDateTime_1, const DateTime& inDateTime_2);
    
    /*!
     *  Name: operator <<
     *  Function: standerd output of DateTime
     *  Parameters: All inputs, const reference of DateTime
     *  Return Value: ostream&
     *  Developer: Alfred Dai   7/8/2022
     *  Upating: N/A
     */
    friend ostream& operator << (ostream& cout, const DateTime& inDateTime);
};

/*!
 *  Name: SerialNumber
 *  Function: Creat the Serial Number for each test tube
 *  API: Only constructors
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */
class SerialNumber {
public:
    
    /*!
     *  Name: Constructor
     *  Function: Initialize the object of SerialNumber Class
     *  Parameters: All input
     *  Developer: Alfred Dai  7/2/2022
     *  Updating: N/A
     */
    SerialNumber(const DateTime& inDateTime = DateTime(1900,1,1,0,0,0),
                 const string& inIndentificationCode = "000000");
    
    /*!
     *  Name: Constructor
     *  Function: Initialize the object of SerialNumber Class
     *  Parameters: All input
     *  Developer: Alfred Dai  7/12/2022
     *  Updating: N/A
     */
    SerialNumber(unsigned int inYear, unsigned int inMonth, unsigned int inDay,
                 unsigned int inHour, unsigned int inMinute, unsigned int inSecond,
                 const string& inIndentificationCode);
    
    /*!
     *  Name: overloading of "=="
     *  Function: Judge whether serial numbers are equal
     *  Parameters: All input
     *  Developer: Alfred Dai   7/6/2022
     *  Updating: N/A
     */
    friend bool operator == (const SerialNumber& Number_1, const SerialNumber& Number_2);
    
    friend ostream& operator << (ostream& cout, const SerialNumber& inSerialNumber);
private:
    
    /*
     * The time tag of tube
     */
    DateTime m_DateTime;
    /*!
     *   The last six digits of Test Tube's Serial Number
     */
    string m_IndentificationCode;
};

#endif /* TubeLabel_hpp */
