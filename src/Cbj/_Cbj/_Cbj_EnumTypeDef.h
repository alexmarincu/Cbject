#ifndef _CBJ_ENUMTYPEDEF_H
#define _CBJ_ENUMTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_EnumTypeDef_prependClassNameAndAddComma__(cbjType, valueName) \
    cbjType##_##valueName,

#define _Cbj_EnumTypeDef_prependClassNameAndAddComma_(cbjType, valueName) \
    _Cbj_EnumTypeDef_prependClassNameAndAddComma__(cbjType, valueName)

#define _Cbj_EnumTypeDef_prependClassNameAndAddComma(valueName) \
    _Cbj_EnumTypeDef_prependClassNameAndAddComma_(Type, valueName)

#define _Cbj_EnumTypeDef(cbjType, ...)                                                \
    typedef enum cbjType                                                              \
    {                                                                                 \
        _Cbj_Utils_forEach(_Cbj_EnumTypeDef_prependClassNameAndAddComma, __VA_ARGS__) \
    } cbjType

#endif // _CBJ_ENUMTYPEDEF_H
