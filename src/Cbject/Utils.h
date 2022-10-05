#ifndef UTILS_H
#define UTILS_H
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
#define to_(typeName, var) ((typeName *)(var))
/**
 * @brief Add super member to a structure
 * @remark Needs to be the first member in the structure
 * @param typeName Type name of the super member
 */
#define extends_(typeName) \
    typeName super
/**
 * @brief Add included member to a structure
 * @remark Needs to be placed just after the super member
 * @param typeName Type name of the included member
 */
#define implements_(typeName) \
    typeName i##typeName
/**
 * @brief Get length of an array
 */
#define lengthOf_(array) \
    (sizeof(array) / sizeof(array[0]))
/**
 * @brief Allocate memory on stack
 * @param typeName The type to allocate memory for
 */
#define salloc_(typeName) \
    (&(typeName){ 0 })
/**
 * @name ignore_
 * @brief Ignore a variable
 * @param var The variable to be ignored
 */
#define ignore_(var) \
    (void)var
/**
 * @brief Get first argument from __VA_ARGS__
 */
#define VaArgs_first_(...) \
    VaArgs_first_h0(__VA_ARGS__, discard)
#define VaArgs_first_h0(first, ...) \
    first
/**
 * @brief Get list of arguments from __VA_ARGS__ except the first
 * @remark Comma is added before the list
 * @remark Supports max 10 arguments
 */
#define VaArgs_rest_(...) \
    VaArgs_rest_h0(VaArgs_case_(__VA_ARGS__), __VA_ARGS__)
#define VaArgs_rest_h0(case, ...) \
    VaArgs_rest_h1(case, __VA_ARGS__)
#define VaArgs_rest_h1(case, ...) \
    VaArgs_rest_case_##case (__VA_ARGS__)
#define VaArgs_rest_case_one(first)
#define VaArgs_rest_case_more(first, ...) \
    , __VA_ARGS__
#define VaArgs_case_(...) \
    VaArgs_get10th_(__VA_ARGS__, more, more, more, more, more, more, more, more, one, discard)
#define VaArgs_get10th_(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ...) \
    a10
#endif // UTILS_H
