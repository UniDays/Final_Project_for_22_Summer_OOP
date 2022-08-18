/*!
 *  File Name: Time.hpp
 *  Function: Definition of Time used in SerialNumber
 *  Developer: Alfred Dai   7/1/2022
 *  Updating: N/A
 */

#ifndef Time_hpp
#define Time_hpp

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "../../../Debug/Debug.hpp"

/*!
 *  Name: Time
 *  Function: define time which is a part of Serial Number
 *  API: constructor and overloading function
 *  Developer: Alfred Dai   7/8/2022
 *  Updating: N/A
 */
class Time {
public:
    /*!
     *  Name: Constructor
     *  Function: Initialize the object of time with hour, minute and second
     *  Parameters: All inputs
     *  Return Value: N/A
     *  Developer: Alfred Dai   7/8/2022
     *  Upading: N/A
     */
    Time(unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0);
    Time(const Time & source) = default;
    
    /*!
     *  Name: operator =
     *  Function: assignment
     *  Paremeters: all inputs, const reference of Time
     *  Return Value: reference of Time
     *  Developer: Alfred Dai   7/8/2022
     *  Upading: N/A
     */
    Time & operator = (const Time & source) = default;
    
    /*!
     *  Name: operator ==
     *  Function: Judge whether two times are equal
     *  Parameters: two objects of Time we want to judge
     *  Return Value: if two dates are equal, return true
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    bool operator == (const Time & AnotherTime) const;
    
    /*!
     *  Name: operator <<
     *  Function: standerd output
     *  Parameters: const reference of Time
     *  Return Value, ostream&, in order to make the output can continue
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    friend std:: ostream & operator << (std:: ostream& cout, const Time& time);
protected:
    /*
     *  constant related to conversion among hour, minute and second
     */
    static const unsigned int DAY_PER_SECONDS;
    static const unsigned int HOUR_PER_SECONDS;
    static const unsigned int MINUTE_PER_SECONDS;
private:
    unsigned int m_Hour;
    unsigned int m_Minute;
    unsigned int m_Second;
    unsigned int m_TotalSeconds;
    
    /*!
     *  Name: SetHour
     *  Function: Set m_Hour with input parameter 'hour', and if illegal, throw an error
     *  Parameters: All inputs
     *  Return value: bool, if input is legal, set it and return true; otherwise, throw an error
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    bool SetHour(unsigned int hour);
    
    /*!
     *  Name: SetMinute
     *  Function: Set m_Minute with input parameter 'minute', and if illegal, throw an error
     *  Parameters: All inputs
     *  Return value: bool, if input is legal, set it and return true; otherwise, throw an error
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    bool SetMinute(unsigned int minute);
    
    /*!
     *  Name: SetSecond
     *  Function: Set m_Second with input parameter 'second', and if illegal, throw an error
     *  Parameters: All inputs
     *  Return value: bool, if input is legal, set it and return true; otherwise, throw an error
     *  Developer: Alfred Dai   7/8/2022
     *  Updating: N/A
     */
    bool SetSecond(unsigned int second);
};

#endif /* Time_hpp */
