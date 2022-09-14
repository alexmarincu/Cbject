#include "Type.h"
Type * Type_init(
    Type * const me,
    size_t offset,
    Operations const * operations
) {
    me->offset = offset;
    me->operations = operations;
    return me;
}
