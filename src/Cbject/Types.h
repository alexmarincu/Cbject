#ifndef TYPES_H
#define TYPES_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Helper macro for getting length of an array
 */
#define lengthOf_(array) (sizeof(array) / sizeof(array[0]))

/**
 * @brief Typedef to use for pointer to any kind of type
 */
typedef void Any;

/**
 * @brief Helper macro for casting to (Any *)
 */
#define anyOf_(me) ((Any *)(me))

/**
 * @brief Helper macro for allocating memory on stack
 * @param typeName The type to allocate memory for
 */
#define salloc_(typeName) (&(typeName){ 0 })

/**
 * @brief Helper macro to perform a block of code only once
 * @remark Not thread safe
 */
#define doOnce_(...)                  \
    do {                              \
        static bool once = false;     \
        if (once == false) {          \
            do __VA_ARGS__ while (0); \
            once = true;              \
        }                             \
    } while (0);

/**
 * @brief Get first argument from __VA_ARGS__
 */
#define VaArgs_first_(...) VaArgs_first__(__VA_ARGS__, discard)
#define VaArgs_first__(first, ...) first

/**
 * @brief Get list of arguments from __VA_ARGS__ except the first
 * @remark Comma is added before the list
 * @remark Supports max 10 arguments
 */
#define VaArgs_rest_(...) VaArgs_rest__(VaArgs_number_(__VA_ARGS__), __VA_ARGS__)
#define VaArgs_rest__(case, ...) VaArgs_rest___(case, __VA_ARGS__)
#define VaArgs_rest___(case, ...) VaArgs_rest_case_##case (__VA_ARGS__)
#define VaArgs_rest_case_one(first)
#define VaArgs_rest_case_more(first, ...) , __VA_ARGS__
#define VaArgs_number_(...) \
    VaArgs_get10th_(__VA_ARGS__, more, more, more, more, more, more, more, more, one, discard)
#define VaArgs_get10th_(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ...) a10

#endif // TYPES_H
