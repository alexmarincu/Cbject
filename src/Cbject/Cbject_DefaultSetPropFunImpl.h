#ifndef CBJECT_DEFAULTSETPROPFUNIMPL_H
#define CBJECT_DEFAULTSETPROPFUNIMPL_H
#include "Cbject_SetPropFunPrototype.h"

#define Cbject_DefaultSetPropFunImpl(cbjType, propType, propName) \
    Cbject_SetPropFunPrototype(cbjType, propType, propName) { me->props.propName = propName; }

#endif // CBJECT_DEFAULTSETPROPFUNIMPL_H
