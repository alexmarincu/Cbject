#ifndef CBJECT_ENUMTYPEDEF_H
#define CBJECT_ENUMTYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_EnumTypeDef_prependTypeNameAndAddComma__(cbjType, valueName) \
    cbjType##_##valueName,

#define Cbject_EnumTypeDef_prependTypeNameAndAddComma_(cbjType, valueName) \
    Cbject_EnumTypeDef_prependTypeNameAndAddComma__(cbjType, valueName)

#define Cbject_EnumTypeDef_prependTypeNameAndAddComma(valueName) \
    Cbject_EnumTypeDef_prependTypeNameAndAddComma_(Type, valueName)

#define Cbject_EnumTypeDef(cbjType, ...)                                                 \
    typedef enum cbjType                                                                 \
    {                                                                                    \
        Cbject_Utils_forEach(Cbject_EnumTypeDef_prependTypeNameAndAddComma, __VA_ARGS__) \
    } cbjType

#endif // CBJECT_ENUMTYPEDEF_H
