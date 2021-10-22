#ifndef CBJECT_DATATYPEDEF_H
#define CBJECT_DATATYPEDEF_H
#include "Cbject_Utils.h"

#define Cbject_DataTypeDef(cbjType, ...)                             \
    typedef struct cbjType                                           \
    {                                                                \
        Cbject_Utils_forEach(Cbject_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType

#endif // CBJECT_DATATYPEDEF_H
