#ifndef _CBJ_PARAMSTYPEDEF_H
#define _CBJ_PARAMSTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_ParamsTypeDef_0(typeName, ...) \
    typedef char typeName##Params

#define _Cbj_ParamsTypeDef__(typeName, ...)                      \
    typedef struct typeName##Params                              \
    {                                                            \
        _Cbj_Utils_forEach(_Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } typeName##Params

#define _Cbj_ParamsTypeDef_case(typeName, case, ...) \
    _Cbj_ParamsTypeDef_##case (typeName, __VA_ARGS__)

#define _Cbj_ParamsTypeDef(typeName, ...) \
    _Cbj_ParamsTypeDef_case(typeName, __VA_ARGS__)

#endif // _CBJ_PARAMSTYPEDEF_H
