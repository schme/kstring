#include "../src/KString.h"
#include "KTest/KTest.h"


class KStringTest {
public:
protected:
    kms::string str1;

    KStringTest() {
    }
    ~KStringTest() {
    }
};


KTEST( KStringTest, DefaultConstructor ) {
//    ASSERT_TRUE( 1 == strlen( kms::string str2("Hello my baby hello my honey hello my ragtime gal!")));
    ASSERT_TRUE( true );
}


KTEST( KStringTest, CStyleStringConstructor) {
    //
}

struct Foo {
    int x;
};

int main(int argc, char *argv[])
{
    Foo();

    ktest::RunAllTests();
    return 0;
}
