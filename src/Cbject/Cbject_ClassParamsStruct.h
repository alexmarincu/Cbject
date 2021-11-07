#ifndef CBJECT_CLASSPARAMSSTRUCT_H
#define CBJECT_CLASSPARAMSSTRUCT_H
#include "Cbject_Utils.h"

#define Cbject_ClassParamsStruct_case(className, ...) \
    typedef char className##Params

#define Cbject_ClassParamsStruct_caseParams(className, ...)          \
    typedef struct className##Params                                 \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } className##Params

#define Cbject_ClassParamsStruct_x1(className, case, ...) \
    Cbject_ClassParamsStruct_case##case (className, __VA_ARGS__)

#define Cbject_ClassParamsStruct_x0(className, ...) \
    Cbject_ClassParamsStruct_x1(className, __VA_ARGS__)

#define Cbject_ClassParamsStruct(className, params) \
    Cbject_ClassParamsStruct_x0(className, Cbject_Utils_unpack(params))

#endif // CBJECT_CLASSPARAMSSTRUCT_H
