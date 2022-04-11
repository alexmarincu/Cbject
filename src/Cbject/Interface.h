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
 * @param me
 * @param object
 * @param operations
 * @return Interface*
 */
Interface * Interface_init(
    Interface * const me,
    Object * const object,
    Any const * const operations
);

/**
 * @brief
 */
#define initInterface_(me, object, operations) \
    Interface_init(toInterface_(me), toObject_(object), toAny_(operations))

/**
 * @brief
 */
#define toInterface_(me) ((Interface *)(me))

/**
 * @brief
 */
#define objectOf_(me) toInterface_(me)->object

/**
 * @brief
 */
#define interfaceCall_(interfaceName, operationName, ...)                               \
    ((interfaceName##Operations *)toInterface_(VaArgs_first_(__VA_ARGS__))->operations) \
        ->operationName(__VA_ARGS__)

#endif // INTERFACE_H
