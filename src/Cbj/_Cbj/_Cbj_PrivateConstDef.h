#ifndef _CBJ_PRIVATECONSTDEF_H
#define _CBJ_PRIVATECONSTDEF_H
#include "_Cbj_ConstDef.h"

#define _Cbj_PrivateConstDef(typeName, type, constNameAndValue) \
    static _Cbj_ConstDef(typeName, type, constNameAndValue)

#endif // _CBJ_PRIVATECONSTDEF_H
