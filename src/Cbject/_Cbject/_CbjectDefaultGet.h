#ifndef _CBJECTDEFAULTGETTER_H
#define _CBJECTDEFAULTGETTER_H
#include "_CbjectDefaultGetImpl.h"

#define _CbjectDefaultGet(cbjectTypeName, type, memberName) \
    _CbjectDefaultGetImpl(cbjectTypeName, type, memberName)

#endif // _CBJECTDEFAULTGETTER_H
