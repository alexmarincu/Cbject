#ifndef CBJECT_ENUM_H
#define CBJECT_ENUM_H
#include "Cbject_Utils.h"

#define Cbject_EnumTypeDef_prependTypeNameAndAddComma__(typeName, valueName) \
    typeName##_##valueName,

#define Cbject_EnumTypeDef_prependTypeNameAndAddComma_(typeName, valueName) \
    Cbject_EnumTypeDef_prependTypeNameAndAddComma__(typeName, valueName)

#define Cbject_Enum_prependTypeNameAndAddComma(valueName) \
    Cbject_EnumTypeDef_prependTypeNameAndAddComma_(Type, valueName)

#define Cbject_Enum(typeName, ...)                                                \
    typedef enum typeName                                                         \
    {                                                                             \
        Cbject_Utils_forEach(Cbject_Enum_prependTypeNameAndAddComma, __VA_ARGS__) \
    } typeName

#endif // CBJECT_ENUM_H
