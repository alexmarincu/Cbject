#ifndef TYPE_H
#define TYPE_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Type
 */
typedef struct {
    size_t offset;
} Type;

/**
 * @brief Initialize a type
 * @param me The type reference
 * @param offset The offset of the object in the parent structure
 * @return Type* The initialized type
 */
Type * Type_init(Type * const me, size_t const offset);

/**
 * @brief Any
 * @remark To be used with pointers to anything
 */
typedef void Any;

/**
 * @brief Cast to a type
 * @param typeName
 * @param me
 */
#define to_(typeName, me) ((typeName *)(me))

/**
 * @brief Cast to (Any *)
 */
#define toAny_(me) to_(Any, (me))

/**
 * @brief Cast to (Type *)
 */
#define toType_(me) to_(Type, (me))

/**
 * @brief Initialize a type
 * @param me
 * @param offset
 */
#define initType_(me, offset) \
    Type_init(toType_(me), offset)

/**
 * @brief Extend a class
 * @param className The class to extend
 */
#define super_(className) className super

/**
 * @brief Implement a mixin
 * @param mixinName The type to inherit
 */
#define mixin_(mixinName) mixinName m##mixinName

/**
 * @brief Get length of an array
 */
#define lengthOf_(array) (sizeof(array) / sizeof(array[0]))

/**
 * @brief Allocate memory on stack
 * @param typeName The type to allocate memory for
 */
#define salloc_(typeName) (&(typeName){ 0 })

/**
 * @brief Run a block of code only once
 * @remark Not thread safe
 */
#define doOnce_               \
    static bool once = false; \
    for (; once == false; once = true)

/**
 * @brief Get first argument from __VA_ARGS__
 */
#define VaArgs_first_(...) VaArgs_first__(__VA_ARGS__, discard)
#define VaArgs_first__(first, ...) (first)

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

#endif // TYPE_H
