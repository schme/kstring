#ifndef KTEST_H_
#define KTEST_H_

#include <vector>
#include <iostream>
#include <string>

// TODO: Check needed permission

namespace ktest {

class Test;
class TestCase;
class UnitTest;


/**
 * AssertionResult
 */
struct AssertionResult {
    bool assert;
    AssertionResult(bool b) : assert{b} {};
};

/**
 * TestResult
 * Has all the information returned from a test
 */
struct TestResult {
    std::vector<AssertionResult> asserts;
};


#define KTEST( test_case_name, test_name )\
    class test_name : Test {\
        test_name() : Test( #test_case_name, #test_name)\
        friend test_case_name;\
    };\
    test_case_name::registerAndCreate();\
    test_name::testCode()

/**
 * Test
 */
class Test {
    const char * parentName;
    const char * testName;
    Test( const char *, const char * );
    virtual void testCode();
};

/**
 * TestCase
 */
class TestCase {
    std::vector<Test> tests;
    void registerAndCreate();
protected:
    void SetUp();
    void TearDown();
    std::string name;
public:
    TestCase();
    ~TestCase();
    friend Test;
};

/**
 * UnitTest
 * singleton
 */
class UnitTest {
    
    std::vector<TestCase> testCases;
    static UnitTest* instance;
    static bool initialised;
    UnitTest();
public:
    static UnitTest* Get();
    void Run();
};


} // namespace ktest

inline void RunAllTests() {
    ::ktest::UnitTest::Get()->Run();
}


#endif // KTEST_H_
