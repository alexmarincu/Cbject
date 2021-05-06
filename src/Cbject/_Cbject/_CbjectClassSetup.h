#ifndef _CBJECTKLASSSETUP_H
#define _CBJECTKLASSSETUP_H
#include "../CbjectSettings.h"
#include "_CbjectDeleteImpl.h"
#include "_CbjectGetImpl.h"
#include "_CbjectNewImpl.h"

#if CbjectSettings_useHeap == true
    #include <stdlib.h>
    #if CbjectSettings_useStaticPool == true
        #define _CbjectClassSetup(cbjectTypeName, parentName, virtualFunCalls, bindFuns) \
            AbstractClassSetup(virtualFunCalls, bindFuns);                              \
            _CbjectGetImpl(cbjectTypeName);                                                     \
            _CbjectNewImpl(cbjectTypeName);                                                     \
            _CbjectDeleteImpl(cbjectTypeName)
    #else
        #define _CbjectClassSetup(cbjectTypeName, parentName, virtualFunCalls, bindFuns) \
            AbstractClassSetup(virtualFunCalls, bindFuns);                              \
            _CbjectNewImpl(cbjectTypeName);                                                     \
            _CbjectDeleteImpl(cbjectTypeName)
    #endif
#else
    #if CbjectSettings_useStaticPool == true
        #define _CbjectClassSetup(cbjectTypeName, parentName, virtualFunCalls, bindFuns) \
            AbstractClassSetup(virtualFunCalls, bindFuns);                              \
            _CbjectGetImpl(cbjectTypeName)
    #else
        #define _CbjectClassSetup(cbjectTypeName, parentName, virtualFunCalls, bindFuns) \
            AbstractClassSetup(virtualFunCalls, bindFuns);
    #endif
#endif

#endif // _CBJECTKLASSSETUP_H
