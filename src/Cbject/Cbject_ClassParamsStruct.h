#ifndef CBJECT_CLASSPARAMSSTRUCT_H
#define CBJECT_CLASSPARAMSSTRUCT_H
#include "Cbject_Utils.h"

#define Cbject_ClassParamsStruct_case(typeName, ...) \
    typedef char typeName##Params

#define Cbject_ClassParamsStruct_caseParams(typeName, ...)           \
    typedef struct typeName##Params                                  \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } typeName##Params

#define Cbject_ClassParamsStruct_switch(typeName, case, ...) \
    Cbject_ClassParamsStruct_case##case (typeName, __VA_ARGS__)

#define Cbject_ClassParamsStruct_x(typeName, ...) \
    Cbject_ClassParamsStruct_switch(typeName, __VA_ARGS__)

#define Cbject_ClassParamsStruct(typeName, params) \
    Cbject_ClassParamsStruct_x(typeName, Cbject_Utils_unpack(params))

#endif // CBJECT_CLASSPARAMSSTRUCT_H
