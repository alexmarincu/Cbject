#ifndef _CBJECTCASTTOSUBIMPL_H
#define _CBJECTCASTTOSUBIMPL_H
#include "_CbjectCastToSubFunPrototype.h"

#define _CbjectCastToSubImpl(cbjectTypeName, parentName) \
    _CbjectCastToSubFunPrototype(cbjectTypeName, parentName) { return (cbjectTypeName *) me; }

#endif // _CBJECTCASTTOSUBIMPL_H
