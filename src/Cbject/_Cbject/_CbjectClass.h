#ifndef _CBJECTKLASS_H
#define _CBJECTKLASS_H
#include "../CbjectSettings.h"
#include "_CbjectDeleteFunPrototype.h"
#include "_CbjectGetObjectFunPrototype.h"
#include "_CbjectNewFunPrototype.h"

#if CbjectSettings_useHeap == true
    #if CbjectSettings_useStaticPool == true
        #define _CbjectClass(cbjectTypeName, parentName, params, props, virtualFuns) \
            AbstractClass(params, props, virtualFuns);                              \
            _CbjectGetObjectFunPrototype(cbjectTypeName);                                           \
            _CbjectNewFunPrototype(cbjectTypeName);                                           \
            _CbjectDeleteFunPrototype(cbjectTypeName)
    #else
        #define _CbjectClass(cbjectTypeName, parentName, params, props, virtualFuns) \
            AbstractClass(params, props, virtualFuns);                              \
            _CbjectNewFunPrototype(cbjectTypeName);                                           \
            _CbjectDeleteFunPrototype(cbjectTypeName)
    #endif
#else
    #if CbjectSettings_useStaticPool == true
        #define _CbjectClass(cbjectTypeName, parentName, params, props, virtualFuns) \
            AbstractClass(params, props, virtualFuns);                              \
            _CbjectGetObjectFunPrototype(cbjectTypeName)
    #else
        #define _CbjectClass(cbjectTypeName, parentName, params, props, virtualFuns) \
            AbstractClass(params, props, virtualFuns)
    #endif
#endif

#endif // _CBJECTKLASS_H
