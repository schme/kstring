/*
 *
 * NOTE:
 * Cannot use standard containers.
 *
 */
#ifndef KSTRING_H
#define KSTRING_H

#define INIT_LENGTH 4

#ifndef NDEBUG
    #include <stdlib.h>
    //TODO: asserts should use exceptions
    #define ASSERT(a) (if(!(a)) (abort();))
#else
    #define ASSERT(a)
#endif


class string {

    unsigned int size;
    char *str;

    //check();
    public:
        string();
        ~string();
        //string(char *);
        //push_back();
        //pop_back();
        //insert();
        //erase();
        //swap();
        
        //char operator[]
        //operator=
        //input output operations(?)
};

#endif /* end of include guard: KSTRING_H */
