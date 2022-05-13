#include "Type.h"

Type * Type_init(
    Type * const me,
    size_t const offset,
    Interface const * const interface
) {
    me->offset = offset;
    me->interface = interface;
    return me;
}