/*!
 *  File Name: Date.hpp
 *  Function: Definition of Date used in SerialNumber
 *  Developer: Alfred Dai   7/1/2022
 *  Updating: N/A
 */

#ifndef Date_hpp
#define Date_hpp
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "../../..//Debug/Debug.hpp"

/*!
 *  Name: Date
 *  Function: define date which is a part of Serial Number
 *  API: constructor and overloading function
 *  Developer: Alfred Dai   7/8/2022
 *  Updating: N/A
 */
class Date {
public:
    /*!
     *  Name: Constructor
     *  Function: Initilize object of Date with year, month, day
     *  Parameters: All input, year, month, day
     *  Return Value: N/A
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    Date (unsigned int year = 1900, unsigned int month = 1, unsigned int day = 1);
    Date (const Date & source) = default;

    /*!
     *  Name: operator =
     *  Function: assignment
     *  Parameters: const reference of Date
     *  Return Value: reference of Date
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    Date& operator = (const Date& Source) = default;
    
    /*!
     *  Name: operator ==
     *  Function: Judge whether two dates are equal
     *  Parameters: two objects of Date we want to judge
     *  Return Value: if two dates are equal, return true
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    friend bool operator == (const Date& d1, const Date& d2);
    
    /*!
     *  Name: operator <<
     *  Function: standerd output
     *  Parameters: const reference of Date
     *  Return Value, ostream&, in order to make the output can continue
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    friend std:: ostream& operator << (std:: ostream& cout, const Date& date);
protected:
    /*
     *  limit the max year and the min year
     */
    static unsigned int MAX_YEAR;
    static unsigned int MIN_YEAR;
private:
    unsigned int m_Year;
    unsigned int m_Month;
    unsigned int m_Day;
    
    /*!
     *  storage the days of each month,
     *  '0' refers to common year and '1' refers to leap year
     */
    static const unsigned int DayOfMonth[2][12];
    
    /*!
     *  Name: SetYear
     *  Function: Set m_Year with input parameter 'year', and if illegal, throw an error
     *  Parameters: All inputs
     *  Return value: bool, if input is legal, set it and return true; otherwise, throw an error
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    bool SetYear(unsigned int year);
    
    /*!
     *  Name: SetMonth
     *  Function: Set m_Month with input parameter 'month', and if illegal, throw an error
     *  Parameters: All inputs
     *  Return value: bool, if input is legal, set it and return true; otherwise, throw an error
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    bool SetMonth(unsigned int month);
    
    /*!
     *  Name: SetDay
     *  Function: Set m_Day with input parameter 'day', and if illegal, throw an error
     *  Parameters: All inputs
     *  Return value: bool, if input is legal, set it and return true; otherwise, throw an error
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    bool SetDay(unsigned int day);
};


#endif /* Date_hpp */
