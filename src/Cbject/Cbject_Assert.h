#ifndef CBJECT_ASSERT_H
#define CBJECT_ASSERT_H

/*
Cbject_Assert_Static
*/
#define Cbject_Assert_Static(condition, identifier) typedef char identifier[(!!(condition)) * 2 - 1]

/*
Cbject_Assert_Static
*/
#if TEST
    #include "CException.h"
    #define Cbject_Assert(condition) \
        if (!(condition)) Throw(0)
#else
    #include <assert.h>
    #define Cbject_Assert(condition) \
        assert(condition)
#endif

#endif // CBJECT_ASSERT_H
