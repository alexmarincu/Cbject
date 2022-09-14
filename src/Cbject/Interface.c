#include "Interface.h"
Interface * Interface_init(
    Interface * const me,
    size_t const offset,
    Operations const * const operations
) {
    me->offset = offset;
    me->operations = operations;
    return me;
}
