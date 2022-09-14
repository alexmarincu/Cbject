#include "Interface.h"
Interface * Interface_init(
    Interface * const me,
    size_t offset,
    Operations const * operations
) {
    Type_init((Type *)me, offset, operations);
    return me;
}
