#ifndef KSTRING_H_
#define KSTRING_H_

#ifndef NDEBUG
    #include "../test/debug.h"
#endif

#include <cinttypes>

typedef uint32_t uint32;


namespace kms {


class string {

    /**
     * buffer_size
     * Size of buffer in bytes
     */
    uint32 buffer_size;

    /**
     * length
     * Length of the actual string
     */
    uint32 length;
    char *strBuf;
    /**
     * realloc( uint32)
     * Leaves garbage to the string
     */
    void realloc( uint32);

public:
    //void push_back( const char *);
    //pop_back();
    //insert();
    //erase();
    //swap();
    
    //char operator[]
    //operator=
    //input output operations(?)
    
    /**
     * needs access to length
     */
    friend uint32 strlen( string);

public:
    string();
    string(const char *);
    string( string const&);
    ~string();

};


uint32 strlen( string str);
/**
 * parameter should be null terminated
 */
uint32 strlen( const char *);
void strcpy( char *, const char *);

} // namespace kms

#endif // KTEST_H_
