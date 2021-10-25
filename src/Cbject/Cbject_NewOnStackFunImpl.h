#ifndef CBJECT_NEWONSTACKFUNIMPL_H
#define CBJECT_NEWONSTACKFUNIMPL_H
#include "Cbject_NewOnStackFunPrototype.h"

#define Cbject_NewOnStackFunImpl(typeName)  \
    Cbject_NewOnStackFunPrototype(typeName) \
    {                                       \
        memset(me, 0, sizeof(typeName));    \
        typeName##_init(me, params);        \
        return me;                          \
    }

#endif // CBJECT_NEWONSTACKFUNIMPL_H
