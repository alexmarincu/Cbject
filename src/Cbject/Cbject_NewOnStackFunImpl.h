#ifndef CBJECT_NEWONSTACKFUNIMPL_H
#define CBJECT_NEWONSTACKFUNIMPL_H
#include "Cbject_NewOnStackFunPrototype.h"

#define Cbject_NewOnStackFunImpl(cbjType)  \
    Cbject_NewOnStackFunPrototype(cbjType) \
    {                                      \
        memset(me, 0, sizeof(cbjType));    \
        cbjType##_init(me, params);        \
        return me;                         \
    }

#endif // CBJECT_NEWONSTACKFUNIMPL_H
