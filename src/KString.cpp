#include "KString.h"

string::string() : size{ INIT_LENGTH }
{
    str = new char[INIT_LENGTH];
}

/*
string::string(char *) {
}

void string::check() {
}
*/

string::~string() {
    delete[] str;
}


/*
int main(int argc, char *argv[])
{
    string as;    
    return 0;
}
*/
