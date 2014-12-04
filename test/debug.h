#ifndef DEBUG_H_
#define DEBUG_H_

#include <cstdio>
#include <exception>

#define assert(cond)\
    do { if(!(cond)) {\
        char msg[256];\
        snprintf( msg, 256, #cond " at " __FILE__ ", line: %d", __LINE__);\
        ::debug::throwAssert( msg );\
    } } while(0)

namespace debug {

struct AssertException {
    const char *message;
    AssertException( const char *msg ) : message{msg}
    {};
};

void inline printAssert( AssertException e ) {
    printf("%s\n", e.message);
}

void inline throwAssert( const char *msg) {
    AssertException e( msg);
    printAssert( e);
    throw e;
}

} // namespace debug

#endif // DEBUG_H_
