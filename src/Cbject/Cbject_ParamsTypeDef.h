#ifndef CBJECT_PARAMSTYPEDEF_H
#define CBJECT_PARAMSTYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_ParamsTypeDef_0(cbjType, ...) \
    typedef char cbjType##Params

#define Cbject_ParamsTypeDef_(cbjType, ...)                         \
    typedef struct cbjType##Params                                   \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType##Params

#define Cbject_ParamsTypeDef_case(cbjType, case, ...) \
    Cbject_ParamsTypeDef_##case (cbjType, __VA_ARGS__)

#define Cbject_ParamsTypeDef(cbjType, ...) \
    Cbject_ParamsTypeDef_case(cbjType, __VA_ARGS__)

#endif // CBJECT_PARAMSTYPEDEF_H
