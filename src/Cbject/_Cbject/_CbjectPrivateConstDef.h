#ifndef _CBJECTPRIVATECONSTDEF_H
#define _CBJECTPRIVATECONSTDEF_H
#include "_CbjectConstDef.h"

#define _CbjectPrivateConstDef(cbjectTypeName, type, constNameAndValue) \
    static _CbjectConstDef(cbjectTypeName, type, constNameAndValue)

#endif // _CBJECTPRIVATECONSTDEF_H
