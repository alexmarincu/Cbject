#ifndef CBJECTSUPERFUNCTIONS_H
#define CBJECTSUPERFUNCTIONS_H
#include "CbjectUtilities.h"

#define CbjectPreprocessor_stripParenthesesAndApplySuperFunction(functionPrototype) \
    SuperFunction functionPrototype;

#define CbjectSuperFunctions0(...)

#define CbjectSuperFunctions_(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplySuperFunction, __VA_ARGS__)

#define CbjectSuperFunctions(case, ...) \
    CbjectSuperFunctions##case (__VA_ARGS__)

#endif // CBJECTSUPERFUNCTIONS_H
