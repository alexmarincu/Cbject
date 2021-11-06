#ifndef CBJECT_DATATYPEDEF_H
#define CBJECT_DATATYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_DataTypeDef_addSemicolon(dataType, dataName) \
    Cbject_Utils_addSemicolon(dataType dataName)

#define Cbject_DataTypeDef_unpack_addSemicolon_x1(...) \
    Cbject_DataTypeDef_addSemicolon(__VA_ARGS__)

#define Cbject_DataTypeDef_unpack_addSemicolon(dataPrototype) \
    Cbject_DataTypeDef_unpack_addSemicolon_x1(Cbject_Utils_unpack(dataPrototype))

#define Cbject_DataTypeDef_discardCase_unpack_addSemicolon_switch(dataPrototype, case) \
    Cbject_DataTypeDef_unpack_addSemicolon(dataPrototype)

#define Cbject_DataTypeDef_discardCase_unpack_addSemicolon_x1(...) \
    Cbject_DataTypeDef_discardCase_unpack_addSemicolon_switch(__VA_ARGS__)

#define Cbject_DataTypeDef_discardCase_unpack_addSemicolon(dataPrototypeWithType) \
    Cbject_DataTypeDef_discardCase_unpack_addSemicolon_x1(Cbject_Utils_unpack(dataPrototypeWithType))

#define Cbject_DataTypeDef_case_(typeName, ...) \
    typedef char typeName##Data

#define Cbject_DataTypeDef_case_Data(typeName, ...)                                           \
    typedef struct typeName##Data                                                             \
    {                                                                                         \
        Cbject_Utils_forEach(Cbject_DataTypeDef_discardCase_unpack_addSemicolon, __VA_ARGS__) \
    } typeName##Data

#define Cbject_DataTypeDef_switch(typeName, case, ...) \
    Cbject_DataTypeDef_case_##case (typeName, __VA_ARGS__)

#define Cbject_DataTypeDef_x1(typeName, ...) \
    Cbject_DataTypeDef_switch(typeName, __VA_ARGS__)

#define Cbject_DataTypeDef(typeName, data) \
    Cbject_DataTypeDef_x1(typeName, Cbject_Utils_unpack(data))

#endif // CBJECT_DATATYPEDEF_H
