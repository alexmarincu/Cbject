#ifndef CBJECT_CLASSPARAMSSTRUCT_H
#define CBJECT_CLASSPARAMSSTRUCT_H
#include "Cbject_Utils.h"

/*
Cbject_ClassParamsStruct
*/
#define Cbject_ClassParamsStruct_caseNA(class, ...) \
    typedef void class##Params

#define Cbject_ClassParamsStruct_caseParams(class, ...)              \
    typedef struct class##Params                                     \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } class##Params

#define Cbject_ClassParamsStruct_x1(class, case, ...) \
    Cbject_ClassParamsStruct_case##case (class, __VA_ARGS__)

#define Cbject_ClassParamsStruct_x0(class, ...) \
    Cbject_ClassParamsStruct_x1(class, __VA_ARGS__)

#define Cbject_ClassParamsStruct(class, paramsPack) \
    Cbject_ClassParamsStruct_x0(class, Cbject_Utils_unpack(paramsPack))

#endif // CBJECT_CLASSPARAMSSTRUCT_H
