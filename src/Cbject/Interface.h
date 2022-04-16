#ifndef INTERFACE_H
#define INTERFACE_H
#include "Type.h"

/**
 * @brief Interface
 */
typedef struct Interface {
    extend_(Type);
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

#endif // INTERFACE_H
