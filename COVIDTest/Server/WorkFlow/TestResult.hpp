/*!
 *  File Name: TestResult.hpp
 *  Function and Purpose:
 *                  1. Define three diffrent types of result: positive, negative and unknown
 *  Developer: Alfred Dai   7/2/2022
 *  Updating: N/A
 */

#ifndef TestResult_hpp
#define TestResult_hpp

#include <iostream>

/*!
 *  Class Name: TestResult
 *  Function: COVID-19 Test Result
 *  API: N/A
 *  Developer: Alfred Dai   7/1/2022
 *  Updating: N/A
 */
enum class TestResult {
    POSITIVE,
    NEGATIVE,
    UNKNOWN
};

std:: ostream& operator << (std:: ostream& cout, const TestResult& result);

#endif /* TestResult_hpp */
