#ifndef KTEST_H_
#define KTEST_H_


namespace ktest {

class Test;

class TestList {
    Test *listFront;
    Test *listBack;
public:
    void add( Test *test);
    Test* front() { return listFront; }
public:
    TestList() : listFront{nullptr}, listBack{nullptr} {};
};


class AddTest {
public:
    AddTest( TestList &list, Test *test) {
        list.add( test);
    }
};


template <typename Type> void execute( Type &test_object) {
    test_object.run();
}


class Test {
    Test( Test const &);
    Test& operator= ( Test const &);

public:
    virtual void run() {};
    void runner() { 
        execute( *this); 
    }
    static TestList& getList() {
        static TestList list;
        return list;
    }
    Test *next;
public:
    Test() : next{nullptr} {}
    virtual ~Test() {}
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


void RunAllTests();


} // namespace ktest

#define KTEST( test_case, test)\
class test_case##test##Helper : public test_case {\
    test_case##test##Helper( test_case##test##Helper const & );\
    test_case##test##Helper& operator=( test_case##test##Helper const &);\
public:\
    test_case##test##Helper() {}\
    void run();\
};\
class test_case##test##Test : public ktest::Test {\
    virtual void run();\
public:\
    test_case##test##Test() : ktest::Test() {}\
} test_case##test##TestInstance;\
ktest::AddTest add##test_case##test( ktest::Test::getList(), &test_case##test##TestInstance );\
void test_case##test##Test::run() {\
    test_case##test##Helper helper;\
    ktest::execute( helper);\
}\
void test_case##test##Helper::run()


#endif // KTEST_H_
