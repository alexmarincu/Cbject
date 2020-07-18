#ifndef SUPER_CO_H
#define SUPER_CO_H
#include "CO.h"

typedef struct COClass
{
    char const * type;

    struct
    {
        UInt8 (*objectSize)(CO const * const _this);
    } virtuals;
} COClass;

struct CO
{
    COClass const * _class;
};

COClass const * const COClass_getInstance();
UInt8 super_CO_objectSize(CO const * const _this);

#endif // SUPER_CO_H
