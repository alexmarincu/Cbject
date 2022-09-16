#ifndef ASSERT_H
#define ASSERT_H
#if TEST
    #include "CException.h"
#else
    #include <assert.h>
#endif
/**
 * @brief Run time assert
 * @param expression
 */
#if TEST
    #define assert_(expression) \
        if (!(expression)) Throw(0)
#else
    #define assert_(expression) assert(expression)
#endif
/**
 * @brief Compile time assert
 * @param expression
 * @param identifier
 */
#define assertStatic_(expression, identifier) typedef char identifier[(!!(expression)) * 2 - 1]
#endif // ASSERT_H
