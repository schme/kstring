
#include "KString.h"


namespace kms {

/**
 * string::string()
 * Default constructor
 */
string::string() : buffer_size{0},
                   length{0},
                   strBuf{nullptr}
{
}


/**
 * string::string(const char *)
 */
string::string(const char *array) : length{ strlen(array)}
{
    if( length >= buffer_size) {
        realloc( length + 1);
    }
    strcpy( strBuf, array);
}


string::string( string const& s) : length{s.length}
{
    if( length >= buffer_size) {
        realloc( length + 1);
    }
    strcpy( strBuf, s.strBuf);
}


string::~string() {
    delete strBuf;
}


void string::realloc(uint32 min) {

    if( buffer_size ) {
        delete strBuf;
    }

    buffer_size = ( buffer_size*2 >= min) ? buffer_size*2 : min;
    char *newBuf = new char[buffer_size];

    strBuf = newBuf;
    *strBuf = '\0';
}


/**
 * Outside the string
 */
uint32 strlen( string str) {
    return str.length;
}

uint32 strlen( const char *array) {
    uint32 len= 0;
    const char *ptr = array;
    while( *ptr++) {++len;}
    return len;
}

void strcpy( char *to, const char *from) {
    const char *pfrom  = from;
    char *pto = to;
    while( *pto++ = *pfrom++) {}
}


} // namespace kms
