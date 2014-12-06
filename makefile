CC = g++
CFLAGS = -c -g -Wall -Werror -Wno-unused-function -Wno-unused-variable -Wno-parentheses -std=c++11
LDFLAGS = 
SRCF = src
SOURCES =$(SRCF)/KString.cpp $(SRCF)/KString.h
TESTF = test
TESTSOURCES = $(TESTF)/KStringTest.cpp
TFWSOURCES = $(TESTF)/KTest/KTest.h $(TESTF)/KTest/KTest.cpp

tests:	KStringTest.o
	$(CC) $(LDFLAGS) KStringTest.o KString.o KTest.o -o run_tests

KStringTest.o: KTest.o KString.o $(TESTSOURCES)
	$(CC) $(CFLAGS) test/KStringTest.cpp

KTest.o: $(TFWSOURCES)
	$(CC) $(CFLAGS) $(TFWSOURCES)

KString.o: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -rf *.o run_tests
