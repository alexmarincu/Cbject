#ifndef _CBJECTGETTERS_H
#define _CBJECTGETTERS_H
#include "_CbjectUtilities.h"

#define _CbjectGetters_stripParenthesesAndApplyGetter(memberPrototype) \
    Getter memberPrototype;

#define _CbjectGetters_0(...)

#define _CbjectGetters__(...) \
    _CbjectUtilities_forEach(_CbjectGetters_stripParenthesesAndApplyGetter, __VA_ARGS__)

#define _CbjectGetters(case, ...) \
    _CbjectGetters_##case (__VA_ARGS__)

#endif // _CBJECTGETTERS_H
