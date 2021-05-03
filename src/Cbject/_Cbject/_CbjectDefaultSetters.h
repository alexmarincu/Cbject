#ifndef _CBJECTDEFAULTSETTERS_H
#define _CBJECTDEFAULTSETTERS_H

#define _CbjectDefaultSetters_stripParenthesesAndApplyDefaultSetter(memberPrototype) \
    DefaultSetter memberPrototype;

#define _CbjectDefaultSetters_0(...)

#define _CbjectDefaultSetters__(...) \
    _CbjectUtilities_forEach(_CbjectDefaultSetters_stripParenthesesAndApplyDefaultSetter, __VA_ARGS__)

#define _CbjectDefaultSetters(case, ...) \
    _CbjectDefaultSetters_##case (__VA_ARGS__)

#endif // _CBJECTDEFAULTSETTERS_H
