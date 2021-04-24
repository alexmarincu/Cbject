#ifndef CBJECTGETTERS_H
#define CBJECTGETTERS_H
#include "CbjectUtilities.h"

#define CbjectPreprocessor_stripParenthesesAndApplyGetter(memberPrototype) \
    Getter memberPrototype;

#define CbjectGetters0(...)

#define CbjectGetters_(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyGetter, __VA_ARGS__)

#define CbjectGetters(case, ...) \
    CbjectGetters##case (__VA_ARGS__)

#endif // CBJECTGETTERS_H
