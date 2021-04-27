#ifndef _CBJECTSETTERS_H
#define _CBJECTSETTERS_H
#include "_CbjectUtilities.h"

#define _CbjectSetters_stripParenthesesAndApplySetter(memberPrototype) \
    Setter memberPrototype;

#define _CbjectSetters0(...)

#define _CbjectSetters_(...) \
    _CbjectUtilities_forEach(_CbjectSetters_stripParenthesesAndApplySetter, __VA_ARGS__)

#define _CbjectSetters(case, ...) \
    _CbjectSetters##case (__VA_ARGS__)

#endif // _CBJECTSETTERS_H
