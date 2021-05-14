#ifndef _CBJ_ENUMTYPEDEF_H
#define _CBJ_ENUMTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_EnumTypeDef_prependTypeNameAndAddComma__(m_cbjType, valueName) \
    m_cbjType##_##valueName,

#define _Cbj_EnumTypeDef_prependTypeNameAndAddComma_(m_cbjType, valueName) \
    _Cbj_EnumTypeDef_prependTypeNameAndAddComma__(m_cbjType, valueName)

#define _Cbj_EnumTypeDef_prependTypeNameAndAddComma(valueName) \
    _Cbj_EnumTypeDef_prependTypeNameAndAddComma_(Type, valueName)

#define _Cbj_EnumTypeDef(m_cbjType, ...)                                               \
    typedef enum m_cbjType                                                             \
    {                                                                                \
        _Cbj_Utils_forEach(_Cbj_EnumTypeDef_prependTypeNameAndAddComma, __VA_ARGS__) \
    } m_cbjType

#endif // _CBJ_ENUMTYPEDEF_H
