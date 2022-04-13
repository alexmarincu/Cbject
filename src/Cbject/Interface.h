#ifndef INTERFACE_H
#define INTERFACE_H
#include "Object.h"
#include "Types.h"

/**
 * @brief Interface members
 */
typedef struct Interface {
    size_t offset;
    Any const * ops;
} Interface;

/**
 * @brief
 * @param me
 * @param offset
 * @param ops
 * @return Interface*
 */
Interface * Interface_init(
    Interface * const me,
    size_t const offset,
    Any const * const ops
);

/**
 * @brief Initialize an interface
 * @param me
 * @param offset
 * @param ops
 */
#define initInterface_(me, offset, ops) \
    Interface_init(toInterface_(me), offset, toAny_(ops))

/**
 * @brief Cast to (Interface *)
 * @param me
 */
#define toInterface_(me) ((Interface *)(me))

/**
 * @brief
 * @param interfaceName
 * @param operationName
 */
#define interfaceCall_(interfaceName, operationName, ...)                 \
    ((interfaceName##Ops *)toInterface_(VaArgs_first_(__VA_ARGS__))->ops) \
        ->operationName(__VA_ARGS__)

#endif // INTERFACE_H
