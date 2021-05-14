#ifndef _CBJ_DATATYPEDEF_H
#define _CBJ_DATATYPEDEF_H
#include "_Cbj_Utils.h"

#define _Cbj_DataTypeDef(m_cbjType, ...)                           \
    typedef struct m_cbjType                                       \
    {                                                            \
        _Cbj_Utils_forEach(_Cbj_Utils_addSemicolon, __VA_ARGS__) \
    } m_cbjType

#endif // _CBJ_DATATYPEDEF_H
