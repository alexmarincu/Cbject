#ifndef CBJECT_DATATYPEDEF_H
#define CBJECT_DATATYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_DataTypeDef_case_(typeName, ...) \
    typedef char typeName##Data

#define Cbject_DataTypeDef_case_data(typeName, ...)                  \
    typedef struct typeName##Data                                    \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } typeName##Data

#define Cbject_DataTypeDef_switch(typeName, case, ...) \
    Cbject_DataTypeDef_case_##case (typeName, __VA_ARGS__)

#define Cbject_DataTypeDef_x(typeName, ...) \
    Cbject_DataTypeDef_switch(typeName, __VA_ARGS__)

#define Cbject_DataTypeDef(typeName, data) \
    Cbject_DataTypeDef_x(typeName, Cbject_Utils_stripParentheses(data))

#endif // CBJECT_DATATYPEDEF_H
