#ifndef _CBJECTTERMINATEFUNIMPL_H
#define _CBJECTTERMINATEFUNIMPL_H
#include "_CbjectTerminateFunPrototype.h"
#include "_CbjectOnTerminateFunPrototype.h"

#define _CbjectTerminateFunImpl(cbjectTypeName, parentName) \
    _CbjectOnTerminateFunPrototype(cbjectTypeName);          \
    _CbjectTerminateFunPrototype(cbjectTypeName)                \
    {                                                 \
        _##cbjectTypeName##_onTerminate(me);                 \
        parentName##_terminate((parentName *) me); \
    }                                                 \
                                                      \
    _CbjectOnTerminateFunPrototype(cbjectTypeName)

#endif // _CBJECTTERMINATEFUNIMPL_H
