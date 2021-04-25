#ifndef CBJECTDEFAULTSETTERS_H
#define CBJECTDEFAULTSETTERS_H

#define CbjectPreprocessor_stripParenthesesAndApplyDefaultSetter(memberPrototype) \
    DefaultSetter memberPrototype;

#define CbjectDefaultSetters0(...)

#define CbjectDefaultSetters_(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyDefaultSetter, __VA_ARGS__)

#define CbjectDefaultSetters(case, ...) \
    CbjectDefaultSetters##case (__VA_ARGS__)

#endif // CBJECTDEFAULTSETTERS_H
