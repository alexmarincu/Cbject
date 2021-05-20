#ifndef _CBJ_SETPROPS_H
#define _CBJ_SETPROPS_H
#include "___Cbj_Utils.h"

#define ___Cbj_SetProps_stripParenthesesAndApplySetProp(propPrototype) \
    SetProp propPrototype;

#define ___Cbj_SetProps_0(...)

#define ___Cbj_SetProps__(...) \
    ___Cbj_Utils_forEach(___Cbj_SetProps_stripParenthesesAndApplySetProp, __VA_ARGS__)

#define ___Cbj_SetProps(case, ...) \
    ___Cbj_SetProps_##case (__VA_ARGS__)

#endif // _CBJ_SETPROPS_H
