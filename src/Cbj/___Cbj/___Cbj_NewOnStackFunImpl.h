#ifndef _CBJ_NEWONSTACKFUNIMPL_H
#define _CBJ_NEWONSTACKFUNIMPL_H
#include "___Cbj_NewOnStackFunPrototype.h"

#define ___Cbj_NewOnStackFunImpl(cbjType)  \
    ___Cbj_NewOnStackFunPrototype(cbjType) \
    {                                      \
        memset(me, 0, sizeof(cbjType));    \
        ___##cbjType##_init(me, params);   \
        return me;                         \
    }

#endif // _CBJ_NEWONSTACKFUNIMPL_H
