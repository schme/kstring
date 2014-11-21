CXX = g++
CXXFLAGS = -Wall -Werror -Wno-unused-variable -std=c++11
SOURCES = kstring.cpp

kstring:
	$(CXX) $(CXXFLAGS) $(SOURCES)
