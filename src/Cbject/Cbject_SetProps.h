#ifndef CBJECT_SETPROPS_H
#define CBJECT_SETPROPS_H
#include "Cbject_Utils.h"

#define Cbject_SetProps_stripParenthesesAndApplySetProp(propPrototype) \
    SetProp propPrototype;

#define Cbject_SetProps_0(...)

#define Cbject_SetProps_(...) \
    Cbject_Utils_forEach(Cbject_SetProps_stripParenthesesAndApplySetProp, __VA_ARGS__)

#define Cbject_SetProps(case, ...) \
    Cbject_SetProps_##case (__VA_ARGS__)

#endif // CBJECT_SETPROPS_H
