#ifndef _CBJ_PARAMSTYPEDEF_H
#define _CBJ_PARAMSTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_ParamsTypeDef_0(cbjType, ...) \
    typedef char cbjType##Params

#define _Cbj_ParamsTypeDef__(cbjType, ...)                       \
    typedef struct cbjType##Params                               \
    {                                                            \
        _Cbj_Utils_forEach(_Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType##Params

#define _Cbj_ParamsTypeDef_case(cbjType, case, ...) \
    _Cbj_ParamsTypeDef_##case (cbjType, __VA_ARGS__)

#define _Cbj_ParamsTypeDef(cbjType, ...) \
    _Cbj_ParamsTypeDef_case(cbjType, __VA_ARGS__)

#endif // _CBJ_PARAMSTYPEDEF_H
