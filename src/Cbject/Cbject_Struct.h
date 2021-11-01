#ifndef CBJECT_STRUCT_H
#define CBJECT_STRUCT_H
#include "Cbject_Utils.h"

#define Cbject_Struct(typeName, ...)                                 \
    typedef struct typeName                                          \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } typeName

#endif // CBJECT_STRUCT_H
