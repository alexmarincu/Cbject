#ifndef CBJECTPREPROCESSORFUNCTION_H
#define CBJECTPREPROCESSORFUNCTION_H

#define CbjectPreprocessor_functionPrototype0(klassName, returnType, functionName, ...) \
    returnType klassName##_##functionName(klassName * const me)

#define CbjectPreprocessor_functionPrototype_(klassName, returnType, functionName, ...) \
    returnType klassName##_##functionName(klassName * const me, __VA_ARGS__)

#define CbjectPreprocessor_functionPrototype(klassName, returnType, functionName, case, ...) \
    CbjectPreprocessor_functionPrototype##case (klassName, returnType, functionName, __VA_ARGS__)

#define CbjectKeywordFunction_expand(klassName, returnType, functionName, ...) \
    CbjectPreprocessor_functionPrototype(klassName, returnType, functionName, __VA_ARGS__)

#endif // CBJECTPREPROCESSORFUNCTION_H
