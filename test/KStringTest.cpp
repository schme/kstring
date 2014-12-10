#include "../src/KString.h"
#include "KTest/KTest.h"


struct KStringTest : ktest::TestCase {
    
    void SetUp() {
        kms::string str3("This goes in str3");
    }
    void TearDown() {
    }

protected:
    // variables here
    kms::string str1;
    kms::string str2 = "Hello my ragtime gal!";
    kms::string str3;
};


KTEST( KStringTest, StrlenFunctions ) {

    ASSERT_EQ( 0, kms::strlen(""));
    ASSERT_EQ( 0, str1.size());  // Why is copy constructor called here?
    ASSERT_EQ( 12, str2.size());
}


KTEST( KStringTest, BasicConstructors ) {

    //ASSERT_TRUE(!(0 != kms::strlen( str1)));
}


int main(int argc, char *argv[])
{

    ktest::RunAllTests();
    return 0;
}
