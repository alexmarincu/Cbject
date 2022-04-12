#ifndef INTERFACE_H
#define INTERFACE_H
#include "Object.h"
#include "Types.h"

/**
 * @brief Interface members
 */
typedef struct Interface {
    Object * object;
    Any const * ops;
} Interface;

/**
 * @brief
 * @param me
 * @param object
 * @param ops
 * @return Interface*
 */
Interface * Interface_init(
    Interface * const me,
    Object * const object,
    Any const * const ops
);

/**
 * @brief
 */
#define initInterface_(me, object, ops) \
    Interface_init(toInterface_(me), toObject_(object), toAny_(ops))

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
#define interfaceCall_(interfaceName, operationName, ...)                 \
    ((interfaceName##Ops *)toInterface_(VaArgs_first_(__VA_ARGS__))->ops) \
        ->operationName(__VA_ARGS__)

#endif // INTERFACE_H
