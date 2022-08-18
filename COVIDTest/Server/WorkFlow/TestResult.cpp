#include "TestResult.hpp"

std::ostream& operator << (std::ostream& cout, const TestResult& result) {
    if (result == TestResult:: POSITIVE) {
        cout << "Positive";
    } else if (result == TestResult:: NEGATIVE) {
        cout << "Negative";
    } else {
        cout << "Unknown";
    }
    return cout;
}
