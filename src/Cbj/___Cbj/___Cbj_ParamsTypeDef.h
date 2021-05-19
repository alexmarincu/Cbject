#ifndef ___CBJ_PARAMSTYPEDEF_H
#define ___CBJ_PARAMSTYPEDEF_H
#include "___Cbj_Utils.h"

#define ___Cbj_ParamsTypeDef_0(cbjType, ...) \
    typedef char cbjType##Params

#define ___Cbj_ParamsTypeDef__(cbjType, ...)                         \
    typedef struct cbjType##Params                                   \
    {                                                                \
        ___Cbj_Utils_forEach(___Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType##Params

#define ___Cbj_ParamsTypeDef_case(cbjType, case, ...) \
    ___Cbj_ParamsTypeDef_##case (cbjType, __VA_ARGS__)

#define ___Cbj_ParamsTypeDef(cbjType, ...) \
    ___Cbj_ParamsTypeDef_case(cbjType, __VA_ARGS__)

#endif // ___CBJ_PARAMSTYPEDEF_H
