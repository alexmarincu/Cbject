#ifndef _CBJECTINIT_H
#define _CBJECTINIT_H
#include "_CbjectInitImpl.h"

#define _CbjectInit(cbjectTypeName, parentName) \
    _CbjectInitImpl(cbjectTypeName, parentName)

#endif // _CBJECTINIT_H
