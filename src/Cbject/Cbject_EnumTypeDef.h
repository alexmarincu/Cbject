#ifndef CBJECT_ENUMTYPEDEF_H
#define CBJECT_ENUMTYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_EnumTypeDef_prependTypeNameAndAddComma__(typeName, valueName) \
    typeName##_##valueName,

#define Cbject_EnumTypeDef_prependTypeNameAndAddComma_(typeName, valueName) \
    Cbject_EnumTypeDef_prependTypeNameAndAddComma__(typeName, valueName)

#define Cbject_EnumTypeDef_prependTypeNameAndAddComma(valueName) \
    Cbject_EnumTypeDef_prependTypeNameAndAddComma_(Type, valueName)

#define Cbject_EnumTypeDef(typeName, ...)                                                \
    typedef enum typeName                                                                \
    {                                                                                    \
        Cbject_Utils_forEach(Cbject_EnumTypeDef_prependTypeNameAndAddComma, __VA_ARGS__) \
    } typeName

#endif // CBJECT_ENUMTYPEDEF_H
