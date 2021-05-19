#ifndef ___CBJ_PROPSTYPEDEF_H
#define ___CBJ_PROPSTYPEDEF_H
#include "___Cbj_Utils.h"

#define ___Cbj_PropsTypeDef_0(cbjType, ...) \
    typedef char cbjType##Props

#define ___Cbj_PropsTypeDef__(cbjType, ...)                          \
    typedef struct cbjType##Props                                    \
    {                                                                \
        ___Cbj_Utils_forEach(___Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType##Props

#define ___Cbj_PropsTypeDef_case(cbjType, case, ...) \
    ___Cbj_PropsTypeDef_##case (cbjType, __VA_ARGS__)

#define ___Cbj_PropsTypeDef(cbjType, ...) \
    ___Cbj_PropsTypeDef_case(cbjType, __VA_ARGS__)

#endif // ___CBJ_PROPSTYPEDEF_H
