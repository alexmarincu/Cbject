#ifndef _CBJ_PROPSTYPEDEF_H
#define _CBJ_PROPSTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_PropsTypeDef_0(typeName, ...) \
    typedef char typeName##Props

#define _Cbj_PropsTypeDef__(typeName, ...)                       \
    typedef struct typeName##Props                               \
    {                                                            \
        _Cbj_Utils_forEach(_Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } typeName##Props

#define _Cbj_PropsTypeDef_case(typeName, case, ...) \
    _Cbj_PropsTypeDef_##case (typeName, __VA_ARGS__)

#define _Cbj_PropsTypeDef(typeName, ...) \
    _Cbj_PropsTypeDef_case(typeName, __VA_ARGS__)

#endif // _CBJ_PROPSTYPEDEF_H
