#include "Type.h"

Type * Type_init(
    Type * const me,
    size_t const offset
) {
    me->offset = offset;
    return me;
}
