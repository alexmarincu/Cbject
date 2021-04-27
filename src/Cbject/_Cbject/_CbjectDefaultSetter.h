#ifndef _CBJECTDEFAULTSETTER_H
#define _CBJECTDEFAULTSETTER_H
#include "_CbjectDefaultSetterImpl.h"

#define _CbjectDefaultSetter(klassName, type, memberName) \
    _CbjectDefaultSetterImpl(klassName, type, memberName)

#endif // _CBJECTDEFAULTSETTER_H
