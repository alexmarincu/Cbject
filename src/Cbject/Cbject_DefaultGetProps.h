#ifndef CBJECT_DEFAULTGETPROPS_H
#define CBJECT_DEFAULTGETPROPS_H
#include "Cbject_Utils.h"

#define Cbject_DefaultGetProps_stripParenthesesAndApplyDefaultGet(propPrototype) \
    DefaultGetProp propPrototype

#define Cbject_DefaultGetProps_0(...)

#define Cbject_DefaultGetProps_(...) \
    Cbject_Utils_forEach(Cbject_DefaultGetProps_stripParenthesesAndApplyDefaultGet, __VA_ARGS__)

#define Cbject_DefaultGetProps(case, ...) \
    Cbject_DefaultGetProps_##case (__VA_ARGS__)

#endif // CBJECT_DEFAULTGETPROPS_H
