#include "TubeLabel.hpp"

//-----------------------------------------------------------------------------
// Error: DateIllegal, TimeIllegal
DateTime::DateTime(unsigned int inYear, unsigned int inMonth, unsigned int inDay,
                    unsigned int inHour, unsigned int inMinute, unsigned int inSecond):
                    Date(inYear, inMonth, inDay), Time(inHour, inMinute, inSecond)
{
    // Empty
}
//-----------------------------------------------------------------------------
bool operator == (const DateTime& inDateTime_1, const DateTime& inDateTime_2) {
    // Get the base part of DateTime
    const Date& d1 = inDateTime_1;
    const Date& d2 = inDateTime_2;
    const Time& t1 = inDateTime_1;
    const Time& t2 = inDateTime_2;
    
    return (d1 == d2) && (t1 == t2);
}
//-----------------------------------------------------------------------------
ostream& operator << (ostream& cout, const DateTime& inDateTime) {
    const Date& d = inDateTime;
    const Time& t = inDateTime;
    cout << d << ' ' << t;
    return cout;
 }
//-----------------------------------------------------------------------------
// Error: SerialNumberIllegal
SerialNumber::SerialNumber(const DateTime& inDateTime, const string& inIndentificationCode) {
    m_DateTime = inDateTime;
    if (inIndentificationCode.size() != 6) {
        m_IndentificationCode = "000000";
        throw MyException:: SerialNumberIllegal;
    }
    for (const auto& n: inIndentificationCode) {
        if (n < '0' || n > '9') {
            m_IndentificationCode = "000000";
            throw MyException:: SerialNumberIllegal;
        }
    }
    m_IndentificationCode = inIndentificationCode;
}
//-----------------------------------------------------------------------------
// Error: SerialNumberIllegal
SerialNumber::SerialNumber(unsigned int inYear, unsigned int inMonth, unsigned int inDay,
             unsigned int inHour, unsigned int inMinute, unsigned int inSecond,
                            const string& inIndentificationCode) {
    // initialize the datetime part of serial number
    try {
        m_DateTime = DateTime(inYear, inMonth, inDay, inHour, inMinute, inSecond);
    } catch (MyException& e) {
        m_IndentificationCode = "000000";
        throw MyException::SerialNumberIllegal;
    }
    // whether the indentification code in serial number is illegal
    if (m_IndentificationCode.size() != 6) {
        m_IndentificationCode = "000000";
        throw MyException::SerialNumberIllegal;
    }
    for (const auto& n: inIndentificationCode) {
        if (n < '0' || n > '9') {
            m_IndentificationCode = "000000";
            throw MyException::SerialNumberIllegal;
        }
    }
    // set indentification code
    m_IndentificationCode = inIndentificationCode;
}
//-----------------------------------------------------------------------------
bool operator == (const SerialNumber& Number_1, const SerialNumber& Number_2) {
    return (Number_1.m_DateTime == Number_2.m_DateTime) &&
        (Number_1.m_IndentificationCode == Number_2.m_IndentificationCode);
}
//-----------------------------------------------------------------------------
ostream& operator << (ostream& cout, const SerialNumber& inSerialNumber) {
    cout << inSerialNumber.m_DateTime << ' ' << inSerialNumber.m_IndentificationCode;
    return cout;
}
