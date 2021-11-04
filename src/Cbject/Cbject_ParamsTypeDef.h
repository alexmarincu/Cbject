#ifndef CBJECT_PARAMSTYPEDEF_H
#define CBJECT_PARAMSTYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_ParamsTypeDef_case_(typeName, ...) \
    typedef char typeName##Params

#define Cbject_ParamsTypeDef_case_params(typeName, ...)              \
    typedef struct typeName##Params                                  \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } typeName##Params

#define Cbject_ParamsTypeDef_switch(typeName, case, ...) \
    Cbject_ParamsTypeDef_case_##case (typeName, __VA_ARGS__)

#define Cbject_ParamsTypeDef_x1(typeName, ...) \
    Cbject_ParamsTypeDef_switch(typeName, __VA_ARGS__)

#define Cbject_ParamsTypeDef(typeName, params) \
    Cbject_ParamsTypeDef_x1(typeName, Cbject_Utils_stripParentheses(params))

#endif // CBJECT_PARAMSTYPEDEF_H
