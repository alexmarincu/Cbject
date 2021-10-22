#ifndef CBJECT_DEFAULTGETPROP_H
#define CBJECT_DEFAULTGETPROP_H
#include "Cbject_DefaultGetPropFunImpl.h"

#define Cbject_DefaultGetProp(cbjType, propType, propName) \
    Cbject_DefaultGetPropFunImpl(cbjType, propType, propName)

#endif // CBJECT_DEFAULTGETPROP_H
