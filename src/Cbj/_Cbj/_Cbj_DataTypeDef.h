#ifndef _CBJ_DATATYPEDEF_H
#define _CBJ_DATATYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_DataTypeDef(cbjType, ...)                           \
    typedef struct cbjType                                       \
    {                                                            \
        _Cbj_Utils_forEach(_Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } cbjType

#endif // _CBJ_DATATYPEDEF_H
