#ifndef UTILS_H
#define UTILS_H
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
 * @brief Initialize a derived object
 * @param className The object class
 * @param ... (me The object to initialize, ... The init arguments)
 */
#define init_(className, ...) \
    className##_init((className *)VaArgs_first_(__VA_ARGS__) VaArgs_rest_(__VA_ARGS__))
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
 * @brief Run a block of code only once
 * @remark Not thread safe
 */
#define doOnce_               \
    static bool once = false; \
    for (; once == false; once = true)
/**
 * @brief Get first argument from __VA_ARGS__
 */
#define VaArgs_first_(...) \
    VaArgs_first__(__VA_ARGS__, discard)
#define VaArgs_first__(first, ...) \
    (first)
/**
 * @brief Get list of arguments from __VA_ARGS__ except the first
 * @remark Comma is added before the list
 * @remark Supports max 10 arguments
 */
#define VaArgs_rest_(...) \
    VaArgs_rest__(VaArgs_number_(__VA_ARGS__), __VA_ARGS__)
#define VaArgs_rest__(case, ...) \
    VaArgs_rest___(case, __VA_ARGS__)
#define VaArgs_rest___(case, ...) \
    VaArgs_rest_case_##case (__VA_ARGS__)
#define VaArgs_rest_case_one(first)
#define VaArgs_rest_case_more(first, ...) \
    , __VA_ARGS__
#define VaArgs_number_(...) \
    VaArgs_get10th_(__VA_ARGS__, more, more, more, more, more, more, more, more, one, discard)
#define VaArgs_get10th_(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ...) \
    a10
#endif // UTILS_H
