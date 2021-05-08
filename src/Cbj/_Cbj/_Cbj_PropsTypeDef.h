#ifndef _CBJ_PROPSTYPEDEF_H
#define _CBJ_PROPSTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_PropsTypeDef_0(cbjType, ...) \
    typedef char cbjType##Props

#define _Cbj_PropsTypeDef__(cbjType, ...)                        \
    typedef struct cbjType##Props                                \
    {                                                            \
        _Cbj_Utils_forEach(_Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType##Props

#define _Cbj_PropsTypeDef_case(cbjType, case, ...) \
    _Cbj_PropsTypeDef_##case (cbjType, __VA_ARGS__)

#define _Cbj_PropsTypeDef(cbjType, ...) \
    _Cbj_PropsTypeDef_case(cbjType, __VA_ARGS__)

#endif // _CBJ_PROPSTYPEDEF_H
