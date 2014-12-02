#include "../src/KString.h"
#include "KTest/KTest.h"


const char *hello = "Hello string!\n";


class KStringTest : ktest::TestCase 
{ 
    KStringTest() {
        name = "KStringTest";
    }

    void SetUp() {
        //str1("Hello there friend!");
        kms::string *s = new kms::string("Hello friend ^^\n");
    }

    void TearDown() {
    }

    ~KStringTest() {
    }

    kms::string str1;
    kms::string str2;
    kms::string str3;
};


int main(int argc, char *argv[])
{
    RunAllTests();
    return 0;
}
