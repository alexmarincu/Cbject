#ifndef _CBJECTDEFAULTSETTERS_H
#define _CBJECTDEFAULTSETTERS_H

#define _CbjectDefaultSetters_stripParenthesesAndApplyDefaultSetter(memberPrototype) \
    DefaultSetter memberPrototype;

#define _CbjectDefaultSetters0(...)

#define _CbjectDefaultSetters_(...) \
    _CbjectUtilities_forEach(_CbjectDefaultSetters_stripParenthesesAndApplyDefaultSetter, __VA_ARGS__)

#define _CbjectDefaultSetters(case, ...) \
    _CbjectDefaultSetters##case (__VA_ARGS__)

#endif // _CBJECTDEFAULTSETTERS_H
