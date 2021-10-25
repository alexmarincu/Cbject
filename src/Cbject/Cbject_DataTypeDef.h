#ifndef CBJECT_DATATYPEDEF_H
#define CBJECT_DATATYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_DataTypeDef_0(typeName, ...) \
    typedef char typeName##Data

#define Cbject_DataTypeDef_(typeName, ...)                           \
    typedef struct typeName##Data                                    \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } typeName##Data

#define Cbject_DataTypeDef_case(typeName, case, ...) \
    Cbject_DataTypeDef_##case (typeName, __VA_ARGS__)

#define Cbject_DataTypeDef(typeName, ...) \
    Cbject_DataTypeDef_case(typeName, __VA_ARGS__)

#endif // CBJECT_DATATYPEDEF_H
