#include <iostream>

#include "KTest.h"

namespace ktesting {

/**
 * UnitTest
 */
void UnitTest::run() {
    std::cout << "UnitTest Running:" << std::endl;
    for (unsigned i = 0; i < testCases.size(); ++i) {
        std::cout << "TestCase " << i << ": ";
        // run test
        std::cout << std::endl;
    }
}


/**
 * TestCase
 */
void TestCase::run() {
    //std::cout << "   TestCase:"  << std::endl;
    for (unsigned i = 0; i < tests.size(); ++i) {
        std::cout << "    Test: ";
        // run test
        std::cout << std::endl;
    }
}


AssertionResult CompareIntEQ( int a, int b ) {
    return (a == b) ? AssertionResult(true) : AssertionResult(false);
}


} // namespace ktesting
