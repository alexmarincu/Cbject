#ifndef _CBJ_DEFAULTSETPROPFUNIMPL_H
#define _CBJ_DEFAULTSETPROPFUNIMPL_H
#include "___Cbj_SetPropFunPrototype.h"

#define ___Cbj_DefaultSetPropFunImpl(cbjType, propType, propName) \
    ___Cbj_SetPropFunPrototype(cbjType, propType, propName) { me->props.propName = propName; }

#endif // _CBJ_DEFAULTSETPROPFUNIMPL_H
