#ifndef _CBJECTDEFAULTGETTER_H
#define _CBJECTDEFAULTGETTER_H
#include "_CbjectDefaultGetterImpl.h"

#define _CbjectDefaultGetter(klassName, type, memberName) \
    _CbjectDefaultGetterImpl(klassName, type, memberName)

#endif // _CBJECTDEFAULTGETTER_H
