#ifndef INTERFACE_H
#define INTERFACE_H
#include "Object.h"
#include "Types.h"

/**
 * @brief Interface members
 *
 */
typedef struct Interface {
    Object * object;
    Any const * operations;
} Interface;

/**
 * @brief
 *
 * @param this_
 * @param object
 * @param operations
 * @return Interface*
 */
Interface * Interface_init(
    Interface * const this_,
    Object * const object,
    Any const * const operations);

/**
 * @brief
 *
 */
#define initInterface_(this_, object, operations) \
    Interface_init(interfaceOf_(this_), objectOf_(object), anyOf_(operations))

/**
 * @brief
 *
 */
#define interfaceOf_(this_) ((Interface *)(this_))

/**
 * @brief
 *
 */
#define interfaceOperationsOf_(interfaceName, this_) \
    ((interfaceName##Operations *)interfaceOf_(this_)->operations)

/**
 * @brief
 *
 */
#define interfaceObjectOf_(this_) interfaceOf_(this_)->object

/**
 * @brief
 *
 */
#define interfaceCall_(interfaceName, operationName, this_) \
    interfaceOperationsOf_(interfaceName, this_)            \
        ->operationName((interfaceName *)interfaceObjectOf_(this_))

/**
 * @brief
 *
 */
#define interfaceCallWithArgs_(interfaceName, operationName, this_, ...) \
    interfaceOperationsOf_(interfaceName, this_)                         \
        ->operationName((interfaceName *)interfaceObjectOf_(this_), __VA_ARGS__)

#endif // INTERFACE_H
