#include "KTest.h"

namespace ktest {


Test::Test( const char *test_case_name, 
            const char *test_name) : parentName{ test_case_name},
                                     testName{ test_name } {
    
}

void Test::testCode() { 
    std::cerr << "Running default testCode of " << testName << std::endl;
}


void TestCase::registerAndCreate() {
}


UnitTest *UnitTest::instance = nullptr;
bool UnitTest::initialised = false;
UnitTest::UnitTest(){}

UnitTest* UnitTest::Get() {
    if( !instance) {
        instance = new UnitTest;
    }
    return instance;
}


void UnitTest::Run() {
    if( !initialised) {
    }
}



} // namespace ktest
