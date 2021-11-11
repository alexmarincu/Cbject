#ifndef CBJECT_STRUCT_H
#define CBJECT_STRUCT_H
#include "Cbject_Utils.h"

/*
Cbject_Struct
*/
#define Cbject_Struct(class, ...)                                    \
    typedef struct class                                             \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } class

#endif // CBJECT_STRUCT_H
