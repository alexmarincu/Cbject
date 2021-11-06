#ifndef CBJECT_ENUMTYPEDEF_H
#define CBJECT_ENUMTYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_EnumTypeDef_member_x2(typeName, valueName) \
    typeName##_##valueName,

#define Cbject_EnumTypeDef_member_x(typeName, valueName) \
    Cbject_EnumTypeDef_member_x2(typeName, valueName)

#define Cbject_EnumTypeDef_member(valueName) \
    Cbject_EnumTypeDef_member_x(Type, valueName)

#define Cbject_EnumTypeDef(typeName, ...)                            \
    typedef enum typeName                                            \
    {                                                                \
        Cbject_Utils_forEach(Cbject_EnumTypeDef_member, __VA_ARGS__) \
    } typeName

#endif // CBJECT_ENUMTYPEDEF_H
