
#include <vector>

#define ASSERT_INT_EQ(a,b) \
    ::ktesting::CompareIntEQ((a), (b))


namespace ktesting {


/**
 * AssertionResult
 */
class AssertionResult {
    bool assertion;

public:
    AssertionResult(bool b) : assertion{b} {};
};

/**
 * TestResult
 * Has all the information returned from a test
 */
struct TestResult {
    bool assertions;
};


/**
 * Test
 */
class Test {};


/**
 * TestCase
 */
class TestCase {

    std::vector<Test> tests;

public:
    void run();
};


/**
 * UnitTest
 * A collection of TestCases.
 * Your ClassnameTest.cpp should inherit from this class.
 */
class UnitTest {

    std::vector<TestCase> testCases;

public:
    /**
     * run()
     * Run all tests included in the Unit
     */
    void run();
};


} // namespace ktesting
