#ifndef _CBJECTCASTTOSUBIMPL_H
#define _CBJECTCASTTOSUBIMPL_H
#include "_CbjectCastToSubFunPrototype.h"

#define _CbjectCastToSubImpl(klassName, superKlassName) \
    _CbjectCastToSubFunPrototype(klassName, superKlassName) { return (klassName *) me; }

#endif // _CBJECTCASTTOSUBIMPL_H
