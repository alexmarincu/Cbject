#ifndef CBJECT_DEFAULTGETPROPFUNIMPL_H
#define CBJECT_DEFAULTGETPROPFUNIMPL_H
#include "Cbject_GetPropFunPrototype.h"

#define Cbject_DefaultGetPropFunImpl(cbjType, propType, propName) \
    Cbject_GetPropFunPrototype(cbjType, propType, propName) { return me->props.propName; }

#endif // CBJECT_DEFAULTGETPROPFUNIMPL_H
