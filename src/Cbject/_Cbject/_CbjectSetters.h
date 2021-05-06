#ifndef _CBJECTSETTERS_H
#define _CBJECTSETTERS_H
#include "_CbjectUtilities.h"

#define _CbjectSetters_stripParenthesesAndApplySet(memberPrototype) \
    Set memberPrototype;

#define _CbjectSetters_0(...)

#define _CbjectSetters__(...) \
    _CbjectUtilities_forEach(_CbjectSetters_stripParenthesesAndApplySet, __VA_ARGS__)

#define _CbjectSetters(case, ...) \
    _CbjectSetters_##case (__VA_ARGS__)

#endif // _CBJECTSETTERS_H
