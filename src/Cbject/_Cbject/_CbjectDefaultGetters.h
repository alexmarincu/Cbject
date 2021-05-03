#ifndef _CBJECTDEFAULTGETTERS_H
#define _CBJECTDEFAULTGETTERS_H

#define _CbjectDefaultGetters_stripParenthesesAndApplyDefaultGetter(memberPrototype) \
    DefaultGetter memberPrototype

#define _CbjectDefaultGetters_0(...)

#define _CbjectDefaultGetters__(...) \
    _CbjectUtilities_forEach(_CbjectDefaultGetters_stripParenthesesAndApplyDefaultGetter, __VA_ARGS__)

#define _CbjectDefaultGetters(case, ...) \
    _CbjectDefaultGetters_##case (__VA_ARGS__)

#endif // _CBJECTDEFAULTGETTERS_H
