#include "Time.hpp"

//-----------------------------------------------------------------------------
//                       const member
const unsigned int Time::DAY_PER_SECONDS = 86400u;
const unsigned int Time::HOUR_PER_SECONDS = 3600u;
const unsigned int Time::MINUTE_PER_SECONDS = 60u;
//-----------------------------------------------------------------------------
// Error: TimeIllegal
Time::Time(unsigned int hour, unsigned int minute, unsigned int second) {
    try {
        // set
        SetHour(hour);
        SetMinute(minute);
        SetSecond(second);
        m_TotalSeconds = HOUR_PER_SECONDS * m_Hour + MINUTE_PER_SECONDS * m_Minute + m_Second;
    } catch (std::exception& e) {
        // if Date is illegal, throw an error
        throw (MyException:: TimeIllegal);
    }
}
//-----------------------------------------------------------------------------
bool Time::operator == (const Time & AnotherTime) const {
    return m_TotalSeconds == AnotherTime.m_TotalSeconds;
}
//-----------------------------------------------------------------------------
std:: ostream & operator << (std:: ostream & cout, const Time& time){
    cout << std:: setw(2) << std::setfill('0') << time.m_Hour << ":" <<
    std:: setw(2) << std::setfill('0') << time.m_Minute << ":" <<
    std:: setw(2) << std::setfill('0') << time.m_Second;
    return cout;
}
//-----------------------------------------------------------------------------
// Error: invalid_argument
bool Time::SetHour(unsigned int hour) {
    // if hour is illegal
    if (hour > 24) {
        m_Hour = 0;
        m_Minute = 0;
        m_Second = 0;
        m_TotalSeconds = HOUR_PER_SECONDS * m_Hour + MINUTE_PER_SECONDS * m_Minute + m_Second;
        throw std:: invalid_argument("Hour is out of range!");
    } else {
        m_Hour = hour;
        return true;
    }
}
//-----------------------------------------------------------------------------
// Error: invalid_argument
bool Time::SetMinute(unsigned int minute) {
    // if minute is illegal
    if (minute > 60) {
        m_Minute = 0;
        m_Second = 0;
        m_TotalSeconds = HOUR_PER_SECONDS * m_Hour + MINUTE_PER_SECONDS * m_Minute + m_Second;
        throw std:: invalid_argument("Minute is out of range!");
    } else {
        m_Minute = minute;
        return true;
    }
}
//-----------------------------------------------------------------------------
// Error: invalid_argument
bool Time::SetSecond(unsigned int second) {
    // if second is illegal
    if (second > 60) {
        m_Second = 0;
        m_TotalSeconds = HOUR_PER_SECONDS * m_Hour + MINUTE_PER_SECONDS * m_Minute + m_Second;
        throw std:: invalid_argument("Second is out of range!");
    } else {
        m_Second = second;
        return true;
    }
}
//-----------------------------------------------------------------------------
