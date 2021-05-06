#ifndef _CBJECTDEFAULTSETTER_H
#define _CBJECTDEFAULTSETTER_H
#include "_CbjectDefaultSetImpl.h"

#define _CbjectDefaultSet(cbjectTypeName, type, memberName) \
    _CbjectDefaultSetImpl(cbjectTypeName, type, memberName)

#endif // _CBJECTDEFAULTSETTER_H
