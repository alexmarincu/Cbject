#ifndef CBJECT_STRUCT_H
#define CBJECT_STRUCT_H
#include "Cbject_Utils.h"

/*
Cbject_Struct
*/
#define Cbject_Struct(className, ...)                                \
    typedef struct className                                         \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } className

#endif // CBJECT_STRUCT_H
