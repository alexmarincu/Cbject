#ifndef _CBJ_DATATYPEDEF_H
#define _CBJ_DATATYPEDEF_H
#include "___Cbj_Utils.h"

#define ___Cbj_DataTypeDef(cbjType, ...)                             \
    typedef struct cbjType                                           \
    {                                                                \
        ___Cbj_Utils_forEach(___Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType

#endif // _CBJ_DATATYPEDEF_H
