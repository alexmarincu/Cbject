#ifndef TYPE_H
#define TYPE_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Type info
 */
typedef struct Type {
    size_t offset;
} Type;

/**
 *
 */
Type * Type_init(
    Type * const me,
    size_t const offset
);

/**
 * @brief Declare an interface
 * @param name The interface name
 */
#define interface_(name)                            \
    typedef struct name##Ops name##Ops;             \
    typedef struct name##Interface name##Interface; \
    typedef struct name name

/**
 * @brief Declare a class
 * @param name The class name
 */
#define class_(name)                        \
    typedef struct name##Ops name##Ops;     \
    typedef struct name##Class name##Class; \
    typedef struct name name

/**
 * @brief Typedef to use for pointer to any kind of type
 */
typedef void Any;

/**
 * @brief Cast to (Any *)
 */
#define toAny_(me) ((Any *)(me))

/**
 * @brief Cast to a type
 * @param typeName
 * @param me
 */
#define to_(typeName, me) ((typeName *)(me))

/**
 * @brief Cast to (Type *)
 */
#define toType_(me) ((Type *)(me))

/**
 * @brief Cast to (Object *)
 */
#define toObject_(me) ((Object *)(me))

/**
 * @brief Cast to (Class *)
 */
#define toClass_(me) ((Class *)(me))

/**
 * @brief Cast to (Interface *)
 * @param me
 */
#define toInterface_(me) ((Interface *)(me))

/**
 * @brief Initialize an interface
 * @param me
 * @param offset
 */
#define initType_(me, offset) \
    Type_init(toType_(me), offset)

/**
 * @brief Extend an object
 * @param type The type of the parent object
 */
#define extend_(type) type x##type

/**
 * @brief Inherit an interface
 * @param type The type of the interface
 */
#define inherit_(type) type i##type

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
