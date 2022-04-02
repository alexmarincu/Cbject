#ifndef TYPES_H
#define TYPES_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Helper macro for getting length of an array
 *
 */
#define lengthOf_(array) (sizeof(array) / sizeof(array[0]))

/**
 * @brief
 *
 */
typedef void Any;

/**
 * @brief Helper macro for casting to (Any *)
 *
 */
#define anyOf_(this_) ((Any *)(this_))

/**
 * @brief Helper macro for allocating memory on stack
 *
 * @param typeName The type to allocate memory for
 */
#define salloc_(typeName) (&(typeName){ 0 })

#define doOnce_(block)            \
    do {                          \
        static bool once = false; \
        if (once == false) {      \
            do block while (0);   \
            once = true;          \
        }                         \
    } while (0);

#endif // TYPES_H
