#ifndef TYPE_H
#define TYPE_H
#include "Operations.h"
#include <stddef.h>
/**
 * @brief Type
 */
typedef struct {
    size_t offset;
    Operations const * operations;
} Type;
Type * Type_init(
    Type * const me,
    size_t offset,
    Operations const * operations
);
#endif // TYPE_H
