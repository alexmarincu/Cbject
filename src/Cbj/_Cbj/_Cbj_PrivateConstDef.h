#ifndef _CBJ_PRIVATECONSTDEF_H
#define _CBJ_PRIVATECONSTDEF_H
#include "_Cbj_ConstDef.h"

#define _Cbj_PrivateConstDef(m_cbjType, constType, constNameAndValue) \
    static _Cbj_ConstDef(m_cbjType, constType, constNameAndValue)

#endif // _CBJ_PRIVATECONSTDEF_H
