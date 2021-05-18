#ifndef _CBJ_ENUMTYPEDEF_H
#define _CBJ_ENUMTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_EnumTypeDef_prependTypeNameAndAddComma__(cbjType, valueName) \
    cbjType##_##valueName,

#define _Cbj_EnumTypeDef_prependTypeNameAndAddComma_(cbjType, valueName) \
    _Cbj_EnumTypeDef_prependTypeNameAndAddComma__(cbjType, valueName)

#define _Cbj_EnumTypeDef_prependTypeNameAndAddComma(valueName) \
    _Cbj_EnumTypeDef_prependTypeNameAndAddComma_(Type, valueName)

#define _Cbj_EnumTypeDef(cbjType, ...)                                               \
    typedef enum cbjType                                                             \
    {                                                                                \
        _Cbj_Utils_forEach(_Cbj_EnumTypeDef_prependTypeNameAndAddComma, __VA_ARGS__) \
    } cbjType

#endif // _CBJ_ENUMTYPEDEF_H
