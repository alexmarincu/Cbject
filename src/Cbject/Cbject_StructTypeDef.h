#ifndef CBJECT_STRUCTTYPEDEF_H
#define CBJECT_STRUCTTYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_StructTypeDef(typeName, ...)                          \
    typedef struct typeName                                          \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } typeName

#endif // CBJECT_STRUCTTYPEDEF_H
