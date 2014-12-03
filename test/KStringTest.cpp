#include "../src/KString.h"
#include "KTest/KTest.h"


class KStringTest {

    /*
    KStringTest() {
    }

    ~KStringTest() {
    }
    */
protected:
    kms::string str1;
};


KTEST( KStringTest, DefaultConstructor ) {
    ASSERT_TRUE( kms::strlen( str1) == 0);
    ASSERT_TRUE( kms::strlen( str1) == 1);
}


KTEST( KStringTest, CStyleStringConstructor) {
    //
}


int main(int argc, char *argv[])
{
    ktest::RunAllTests();
    return 0;
}
