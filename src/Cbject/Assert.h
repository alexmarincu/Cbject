#ifndef ASSERT_H
#define ASSERT_H
#if TEST
    #include "CException.h"
#else
    #include <assert.h>
#endif

/**
 * @brief Run time assert
 */
#if TEST
    #define assert_(condition) \
        if (!(condition)) Throw(0)
#else
    #define assert_(condition) assert(condition)
#endif

/**
 * @brief Compile time assert
 */
#define assertStatic_(condition, identifier) typedef char identifier[(!!(condition)) * 2 - 1]

#endif // ASSERT_H
