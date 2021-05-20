#ifndef _CBJ_DEFAULTGETPROPFUNIMPL_H
#define _CBJ_DEFAULTGETPROPFUNIMPL_H
#include "___Cbj_GetPropFunPrototype.h"

#define ___Cbj_DefaultGetPropFunImpl(cbjType, propType, propName) \
    ___Cbj_GetPropFunPrototype(cbjType, propType, propName) { return me->props.propName; }

#endif // _CBJ_DEFAULTGETPROPFUNIMPL_H
