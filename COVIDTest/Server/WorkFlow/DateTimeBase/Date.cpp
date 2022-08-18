#include "Date.hpp"

//-----------------------------------------------------------------------------
unsigned int Date::MAX_YEAR = 9999u;
unsigned int Date::MIN_YEAR = 1900u;
const unsigned int Date:: DayOfMonth[2][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};
//-----------------------------------------------------------------------------
// Error: DateIllegal
Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    try {
        SetYear(year);
        SetMonth(month);
        SetDay(day);
    } catch (std::exception& e) {
        throw (MyException:: DateIllegal);
    } 
}
//-----------------------------------------------------------------------------
bool operator == (const Date &d1, const Date& d2) {
    // compare each digits
    return (d1.m_Year == d2.m_Year) && (d1.m_Month == d2.m_Month) && (d1.m_Day == d2.m_Day);
}
//-----------------------------------------------------------------------------
std:: ostream& operator << (std:: ostream & cout, const Date & date) {
    cout << std:: setw(4) << std:: setfill('0') << date.m_Year << "." <<
    std:: setw(2) << std:: setfill('0') << date.m_Month << "." <<
    std:: setw(2) << std:: setfill('0') << date.m_Day;
    return cout;
}
//-----------------------------------------------------------------------------
// Error: invalid_argument
bool Date::SetYear(unsigned int year) {
    if (year > MAX_YEAR || year < MIN_YEAR) {
        m_Year = MIN_YEAR;
        m_Month = 1;
        m_Day = 1;
        throw (std::invalid_argument("YearIllegal"));
    } else {
        m_Year = year;
        return true;
    }
}
//-----------------------------------------------------------------------------
// Error: invalid_argument
bool Date::SetMonth(unsigned int month) {
    if (month > 12 || !month) {
        m_Month = 1;
        m_Day = 1;
        throw (std::invalid_argument("MonthIllegal"));
    } else {
        m_Month = month;
        return false;
    }
}
//-----------------------------------------------------------------------------
// Error: invalid_argument
bool Date::SetDay(unsigned int day) {
// This function should be called after SetYear and SetMonth;
    if (day > DayOfMonth[(int)!(m_Year % 4) && (m_Year % 100 || !(m_Year % 400))][m_Month - 1]) {
        m_Day = 1;
        throw (std::invalid_argument("MonthIllegal"));
    } else {
        m_Day = day;
        return false;
    }
}
//-----------------------------------------------------------------------------
