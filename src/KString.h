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
    uint32 length;

    /**
     * realloc( uint32)
     * Leaves garbage to the string
     */
    void realloc( uint32);
    void allocate();

public:
    uint32 size() const { return length; }
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

    /* Destructor */
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
