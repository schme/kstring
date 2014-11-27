CC = g++
CFLAGS = -c -Wall -Werror -Wno-unused-variable -std=c++11
LDFLAGS = 
SRCF = src
SOURCES =$(SRCF)/KString.cpp $(SRCF)/KString.h
TESTF = test
TESTSOURCES = $(TESTF)/KStringTest.cpp

tests:	KStringTest.o
	$(CC) $(LDFLAGS) KStringTest.o KString.o -o tests

KStringTest.o: KTest.o KString.o $(TESTSOURCES)
	$(CC) $(CFLAGS) test/KStringTest.cpp

KTest.o: $(TESTF)/KTest/KTest.cpp  $(TESTF)/KTest/KTest.h 
	$(CC) $(CFLAGS) $(TESTF)/KTest/KTest.cpp

KString.o: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)
