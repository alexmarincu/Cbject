#ifndef ___CBJ_PRIVATECONSTDEF_H
#define ___CBJ_PRIVATECONSTDEF_H
#include "___Cbj_ConstDef.h"

#define ___Cbj_PrivateConstDef(cbjType, constType, constNameAndValue) \
    static ___Cbj_ConstDef(cbjType, constType, constNameAndValue)

#endif // ___CBJ_PRIVATECONSTDEF_H
