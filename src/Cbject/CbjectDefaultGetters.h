#ifndef CBJECTDEFAULTGETTERS_H
#define CBJECTDEFAULTGETTERS_H

#define CbjectPreprocessor_stripParenthesesAndApplyDefaultGetter(memberPrototype) \
    DefaultGetter memberPrototype

#define CbjectDefaultGetters0(...)

#define CbjectDefaultGetters_(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyDefaultGetter, __VA_ARGS__)

#define CbjectDefaultGetters(case, ...) \
    CbjectDefaultGetters##case (__VA_ARGS__)

#endif // CBJECTDEFAULTGETTERS_H
