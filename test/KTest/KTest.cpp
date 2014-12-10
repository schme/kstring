#include "KTest.h"

namespace ktest {


AddTest::AddTest( TestList &list, Test *test) {
    list.add( test);
}


TestList& Test::getList() {
    static TestList list;
    return list;
}

AssertResult AssertTrue(const char *msg) {
    return AssertResult( msg, true);
}
AssertResult AssertFalse(const char *msg) {
    return AssertResult( msg, false);
}

void RunAllTests() {
    TestList list = Test::getList();
    Test *test = list.front();

    while( test != nullptr) {
        test->run();
        test = test->next;
    }
}


std::ostream& operator<< (std::ostream &out, AssertResult ar) {
    out << ((ar.result_) ? "SUCCESS" : "FAIL") << ": " << ar.msg_;
    return out;
}

AssertResult& operator<< (AssertResult &ar, const char *msg) {
    std::string s( ar.msg_);
    s += msg;
    ar.msg_ = s.substr();
    return ar;
}


AssertResult::AssertResult( const char *msg, const bool result) :
                                msg_{msg}, result_{result}
{ }


void PrintAssert(AssertResult ar) {
    if( print_assert_success && ar.result_) {
        std::cout << ar << std::endl;
    }
    else if(! ar.result_ ) {
        std::cout << ar << std::endl;
    }
}


void PrintTestHeader( Test &test) {
    std::cout << std::endl;
}

 
void execute( TestCase &tc) {
    tc.run();
}


} // namespace ktest
