#ifndef TYPE_H
#define TYPE_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Interface
 * @remark To be used with pointers to Interface types
 */
typedef void Interface;

/**
 * @brief Type
 */
typedef struct {
    size_t offset;
    Interface const * interface;
} Type;

/**
 * @brief Initialize a Type
 * @param me Type reference
 * @param offset Offset of nested object inside parent object
 * @param interface Type interface
 * @return Type* Initialized type
 */
Type * Type_init(
    Type * const me,
    size_t const offset,
    Interface const * const interface
);

/**
 * @brief Initialize a type
 * @param me Type reference
 * @param offset Offset of nested object inside parent object
 * @param interface Type interface
 */
#define initType_(me, offset, interface) \
    Type_init(toType_(me), offset, toInterface_(interface))

/**
 * @brief Override a type contained in a class
 * @param me
 * @param className
 * @param typeContainerClassName
 * @param typeName
 */
#define overrideNestedType_(me, className, typeContainerClassName, typeName)                                   \
    Type_init(                                                                                                 \
        toType_(&to_(typeContainerClassName##Class, me)->n##typeName##Type),                                   \
        offsetof(typeContainerClassName, n##typeName),                                                         \
        toInterface_(&to_(typeContainerClassName##Interface, className##Interface_())->n##typeName##Interface) \
    )

/**
 * @brief Initialize a type contained in a class
 * @param me
 * @param className
 * @param typeName
 */
#define initNestedType_(me, className, typeName)                                                  \
    Type_init(                                                                                    \
        toType_(&to_(className##Class, me)->n##typeName##Type),                                   \
        offsetof(className, n##typeName),                                                         \
        toInterface_(&to_(className##Interface, className##Interface_())->n##typeName##Interface) \
    )

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
 * @brief Cast to (Interface *)
 */
#define toInterface_(me) to_(Interface, (me))

/**
 * @brief Add super member to a structure
 * @remark Needs to be the first member in the structure
 * @param typeName Type name of the super member
 */
#define extends_(typeName) typeName super

/**
 * @brief Add nested member to a structure
 * @remark Needs to be placed just after the super member
 * @param typeName Type name of the nested member
 */
#define contains_(typeName) typeName n##typeName

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
