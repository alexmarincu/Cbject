#ifndef CBJECT_DEFAULTSETPROPS_H
#define CBJECT_DEFAULTSETPROPS_H
#include "Cbject_Utils.h"

#define Cbject_DefaultSetProps_stripParenthesesAndApplyDefaultSetProp(propPrototype) \
    DefaultSetProp propPrototype;

#define Cbject_DefaultSetProps_0(...)

#define Cbject_DefaultSetProps_(...) \
    Cbject_Utils_forEach(Cbject_DefaultSetProps_stripParenthesesAndApplyDefaultSetProp, __VA_ARGS__)

#define Cbject_DefaultSetProps(case, ...) \
    Cbject_DefaultSetProps_##case (__VA_ARGS__)

#endif // CBJECT_DEFAULTSETPROPS_H
