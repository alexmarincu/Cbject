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

#endif // TYPES_H
