#ifndef _CBJ_ENUMTYPEDEF_H
#define _CBJ_ENUMTYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_EnumTypeDef_prependClassNameAndAddComma__(typeName, valueName) \
    typeName##_##valueName,

#define _Cbj_EnumTypeDef_prependClassNameAndAddComma_(typeName, valueName) \
    _Cbj_EnumTypeDef_prependClassNameAndAddComma__(typeName, valueName)

#define _Cbj_EnumTypeDef_prependClassNameAndAddComma(valueName) \
    _Cbj_EnumTypeDef_prependClassNameAndAddComma_(Cbj_Type, valueName)

#define _Cbj_EnumTypeDef(typeName, ...)                                               \
    typedef enum typeName                                                             \
    {                                                                                 \
        _Cbj_Utils_forEach(_Cbj_EnumTypeDef_prependClassNameAndAddComma, __VA_ARGS__) \
    } typeName

#endif // _CBJ_ENUMTYPEDEF_H
