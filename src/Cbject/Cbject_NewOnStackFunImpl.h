#ifndef CBJECT_NEWONSTACKFUNIMPL_H
#define CBJECT_NEWONSTACKFUNIMPL_H
#include "Cbject_NewOnStackFunPrototype.h"

/*
Cbject_NewOnStackFunImpl
*/
#define Cbject_NewOnStackFunImpl(className)  \
    Cbject_NewOnStackFunPrototype(className) \
    {                                        \
        memset(me, 0, sizeof(className));    \
        className##_init(me, params);        \
        return me;                           \
    }

#endif // CBJECT_NEWONSTACKFUNIMPL_H
