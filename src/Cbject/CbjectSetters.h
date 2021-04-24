#ifndef CBJECTSETTERS_H
#define CBJECTSETTERS_H
#include "CbjectUtilities.h"

#define CbjectPreprocessor_stripParenthesesAndApplySetter(memberPrototype) \
    Setter memberPrototype;

#define CbjectSetters0(...)

#define CbjectSetters_(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplySetter, __VA_ARGS__)

#define CbjectSetters(case, ...) \
    CbjectSetters##case (__VA_ARGS__)

#endif // CBJECTSETTERS_H
