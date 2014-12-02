/*
 *
 * NOTE:
 * Cannot use standard containers.
 *
 */
#ifndef KSTRING_H_
#define KSTRING_H_

#ifndef NDEBUG
    #include <stdlib.h>
    // TODO: asserts should use exceptions
    #define ASSERT(a) (if(!(a)) (abort();))
#else
    #define ASSERT(a)
#endif

namespace kms {

class string {
    /**
     * buffer_size
     * Size of the internal buffer
     */
    unsigned buffer_size;
    /**
     * length
     */
    unsigned length;
    /**
     * *strBuf
     * pointer to the stored char array
     */
    char *strBuf;
 
    //check();
    //
public:
    string();
    string(const char *);
    ~string();
    //push_back();
    //pop_back();
    //insert();
    //erase();
    //swap();
    
    //char operator[]
    //operator=
    //input output operations(?)
    friend unsigned strlen( string );
};


unsigned strlen( const char *);
void strcpy( char *, const char *);

} // namespace kms

#endif // KTEST_H_
