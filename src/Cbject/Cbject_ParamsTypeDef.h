#ifndef CBJECT_PARAMSTYPEDEF_H
#define CBJECT_PARAMSTYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_ParamsTypeDef_void(typeName, ...) \
    typedef char typeName##Params

#define Cbject_ParamsTypeDef_(typeName, ...)                         \
    typedef struct typeName##Params                                  \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } typeName##Params

#define Cbject_ParamsTypeDef_case(typeName, case, ...) \
    Cbject_ParamsTypeDef_##case (typeName, __VA_ARGS__)

#define Cbject_ParamsTypeDef(typeName, ...) \
    Cbject_ParamsTypeDef_case(typeName, __VA_ARGS__)

#endif // CBJECT_PARAMSTYPEDEF_H
