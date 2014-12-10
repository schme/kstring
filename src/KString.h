#ifndef KSTRING_H_
#define KSTRING_H_

#ifndef NDEBUG
    #include "../test/debug.h"
#endif

#include <cinttypes>

typedef uint32_t uint32;


namespace kms {


class string {

    char *strBuf;
    /**
     * buffer_size
     * Size of buffer in bytes
     */
    uint32 buffer_size;

    /**
     * length
     * Length of the actual string
     */
    int length;

    /**
     * realloc( uint32)
     * Leaves garbage to the string
     */
    void realloc( uint32);
    void allocate();

public:
    //push_back();
    int size() const { return length; }
    //void push_back( const char *);
    //pop_back();
    //insert();
    //erase();
    //swap();
    
    //char operator[]
    //operator=
    //input output operations(?)
    
public:
    /* Default constructor */
    string();

    /* Char array constructor */
    string(const char *);

    /* Copy constructor */
    string( string const&);

    /* Move constructor */
    // string( string &&rhs);

    /* Destructor */
    ~string();

public:
    /* Move assignment */
};


int strlen( string str);
/**
 * parameter should be null terminated
 */
int strlen( const char *);
void strcpy( char *, const char *);

} // namespace kms

#endif // KTEST_H_
