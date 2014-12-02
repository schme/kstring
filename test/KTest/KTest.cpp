#include "KTest.h"

namespace ktest {

void RunAllTests() {
    TestList list = Test::getList();
    Test *test = list.front();

    while( test != nullptr) {
        test->run();
        test = test->next;
    }
}


} // namespace ktest
