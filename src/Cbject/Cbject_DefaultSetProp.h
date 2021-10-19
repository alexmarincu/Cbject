#ifndef CBJECT_DEFAULTSETPROP_H
#define CBJECT_DEFAULTSETPROP_H
#include "Cbject_DefaultSetPropFunImpl.h"

#define Cbject_DefaultSetProp(cbjType, propType, propName) \
    Cbject_DefaultSetPropFunImpl(cbjType, propType, propName)

#endif // CBJECT_DEFAULTSETPROP_H
