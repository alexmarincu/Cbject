#ifndef CBJECT_GETPROPS_H
#define CBJECT_GETPROPS_H
#include "Cbject_Utils.h"

#define Cbject_GetProps_stripParenthesesAndApplyGetProp(propPrototype) \
    GetProp propPrototype;

#define Cbject_GetProps_0(...)

#define Cbject_GetProps_(...) \
    Cbject_Utils_forEach(Cbject_GetProps_stripParenthesesAndApplyGetProp, __VA_ARGS__)

#define Cbject_GetProps(case, ...) \
    Cbject_GetProps_##case (__VA_ARGS__)

#endif // CBJECT_GETPROPS_H
