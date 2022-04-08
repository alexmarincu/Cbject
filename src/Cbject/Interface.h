#ifndef INTERFACE_H
#define INTERFACE_H
#include "Object.h"
#include "Types.h"

/**
 * @brief Interface members
 */
typedef struct Interface {
    Object * object;
    Any const * operations;
} Interface;

/**
 * @brief
 *
 * @param me
 * @param object
 * @param operations
 * @return Interface*
 */
Interface * Interface_init(
    Interface * const me,
    Object * const object,
    Any const * const operations);

/**
 * @brief
 */
#define initInterface_(me, object, operations) \
    Interface_init(interfaceOf_(me), objectOf_(object), anyOf_(operations))

/**
 * @brief
 */
#define interfaceOf_(me) ((Interface *)(me))

/**
 * @brief
 */
#define interfaceOperationsOf_(interfaceName, me) \
    ((interfaceName##Operations *)interfaceOf_(me)->operations)

/**
 * @brief
 */
#define interfaceObjectOf_(me) interfaceOf_(me)->object

/**
 * @brief
 */
#define interfaceCall_(interfaceName, operationName, ...)             \
    interfaceOperationsOf_(interfaceName, VaArgs_first_(__VA_ARGS__)) \
        ->operationName((interfaceName *)interfaceObjectOf_(VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))

#endif // INTERFACE_H
