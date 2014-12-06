
#include "KString.h"


namespace kms {

/**
 * string::string()
 * Default constructor
 */
string::string() : buffer_size{8}
{
    length = 0;
    strBuf = new char[buffer_size];
    *strBuf = '\0';
}


/**
 * string::string(const char *)
 */
string::string(const char *array) {

    unsigned length = 0;
    // Get length of char array
    const char *ptr = array;
    while( *ptr++) { ++length; }

    buffer_size = length + 1;
    strBuf = new char[buffer_size];

    // Copy content of *a
    strcpy( strBuf, array);
}


/*
string::string(const char *&array) {
    strlen(
    if( buffer_size <= 
}
*/


/*
void string::check() {
}
*/

string::~string() {
    delete strBuf;
}


unsigned strlen( string str) {
    return str.length;
}

unsigned strlen( const char *array) {
    unsigned i = 0;
    while( *array++) { ++i; }
    return i;
}

void strcpy( char *to, const char *from) {
    while( *to++ = *from++) {}
}


} // namespace kms
