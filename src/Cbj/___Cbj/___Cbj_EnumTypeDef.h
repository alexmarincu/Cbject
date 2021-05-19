#ifndef ___CBJ_ENUMTYPEDEF_H
#define ___CBJ_ENUMTYPEDEF_H
#include "___Cbj_Utils.h"

#define ___Cbj_EnumTypeDef_prependTypeNameAndAddComma__(cbjType, valueName) \
    cbjType##_##valueName,

#define ___Cbj_EnumTypeDef_prependTypeNameAndAddComma_(cbjType, valueName) \
    ___Cbj_EnumTypeDef_prependTypeNameAndAddComma__(cbjType, valueName)

#define ___Cbj_EnumTypeDef_prependTypeNameAndAddComma(valueName) \
    ___Cbj_EnumTypeDef_prependTypeNameAndAddComma_(Type, valueName)

#define ___Cbj_EnumTypeDef(cbjType, ...)                                                 \
    typedef enum cbjType                                                                 \
    {                                                                                    \
        ___Cbj_Utils_forEach(___Cbj_EnumTypeDef_prependTypeNameAndAddComma, __VA_ARGS__) \
    } cbjType

#endif // ___CBJ_ENUMTYPEDEF_H
