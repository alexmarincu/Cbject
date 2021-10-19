#ifndef CBJECT_PROPSTYPEDEF_H
#define CBJECT_PROPSTYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_PropsTypeDef_0(cbjType, ...) \
    typedef char cbjType##Props

#define Cbject_PropsTypeDef_(cbjType, ...)                          \
    typedef struct cbjType##Props                                    \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType##Props

#define Cbject_PropsTypeDef_case(cbjType, case, ...) \
    Cbject_PropsTypeDef_##case (cbjType, __VA_ARGS__)

#define Cbject_PropsTypeDef(cbjType, ...) \
    Cbject_PropsTypeDef_case(cbjType, __VA_ARGS__)

#endif // CBJECT_PROPSTYPEDEF_H
