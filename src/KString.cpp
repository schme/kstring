
#include "KString.h"


namespace kms {

/**
 * string::string()
 * Default constructor
 */
string::string() :  strBuf{nullptr},
                    buffer_size{0},
                    length{0}
{ }


/**
 * string::string(const char *)
 */
string::string(const char *array) : length{ strlen(array)}
{
    allocate();
    strcpy( strBuf, array);
}


string::string( string const& rhs) : length{rhs.length}
{
    allocate();
    strcpy( strBuf, rhs.strBuf);
}


string::~string() {
    if( strBuf ) {
        delete strBuf;
    }
}


void string::allocate() {
    buffer_size = length + 1;
    strBuf = new char[buffer_size];
    *strBuf = '\0';
}

void string::realloc(uint32 min) {

    buffer_size = ( buffer_size*2 >= min) ? buffer_size*2 : min;
    char *newBuf = new char[buffer_size];

    delete strBuf;
    strBuf = newBuf;
    *strBuf = '\0';
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
