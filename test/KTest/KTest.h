#ifndef KTEST_H_
#define KTEST_H_


#include "../debug.h"

#include <iostream>

#define ASSERT_TRUE( cond ) std::cout << ((cond) ? true : false) << std::endl

#define ASSERT_FALSE( cond ) std::cout << ((cond) ? false : true) << std::endl

#define ASSERT_EQ( expectation, reality )\
    std::cout << (((expectation) == (reality)) ? true : false) << std::endl

#define CREATE_ASSERT_EQ( expectation, reality, file, line)\



namespace ktest {

const static bool print_assert_success = true;

class Test;


/**
 * AssertResult
 */
struct AssertResult {
    const char *msg_;
    const bool result_;
    AssertResult( const char*,  const bool);
};

std::ostream& operator<< (std::ostream &, AssertResult);


void PrintAssert( AssertResult);
void PrintTestHeader( Test &);

/**
 * TestList
 * A linked list of Tests. Lives inside every Test.
 */
class TestList {
    Test *listFront;
    Test *listBack;
public:
    void add( Test *test);
    Test* front() { return listFront; }
public:
    TestList() : listFront{nullptr}, listBack{nullptr} {};
};


/**
 * AddTest
 * Allow us to "call a function" outside of main
 */
class AddTest {
public:
    AddTest( TestList &, Test *);
};




/**
 * Test
 */
class Test {
    Test( Test const &);
    Test& operator= ( Test const &);
public:
    virtual void run() {};
    static TestList& getList();
    Test *next;
    const char *testName;
public:
    Test( const char *testname) : next{nullptr}, testName{testname} {}
    virtual ~Test() {}
};


/**
 * TestCase
 */
class TestCase {
protected:
    virtual void SetUp(){};
    virtual void TearDown(){};
    TestCase(){};
    ~TestCase(){};
public:
    virtual void run(){};
};


inline void TestList::add( Test *test) {
    if( listBack == nullptr) {
        listFront = test;
        listBack = test;
    } else {
        listBack->next = test;
        listBack = test;
    }
}

// TODO: Check if templates are necessary

void execute( TestCase &);


void RunAllTests();


} // namespace ktest


//TODO: Move SetUp() out of the constructor
#define KTEST( test_case, test)\
class test_case##test##Helper : public test_case {\
    test_case##test##Helper( test_case##test##Helper const & );\
    test_case##test##Helper& operator=( test_case##test##Helper const &);\
public:\
    test_case##test##Helper() : test_case() {\
        SetUp();\
    }\
    void run();\
};\
class test_case##test##Test : public ktest::Test {\
    virtual void run();\
public:\
    test_case##test##Test() : ktest::Test( #test ) {}\
} test_case##test##TestInstance;\
ktest::AddTest add##test_case##test( ktest::Test::getList(), &test_case##test##TestInstance );\
void test_case##test##Test::run() {\
    test_case##test##Helper helper;\
    ktest::execute( helper);\
}\
void test_case##test##Helper::run()


#endif // KTEST_H_
