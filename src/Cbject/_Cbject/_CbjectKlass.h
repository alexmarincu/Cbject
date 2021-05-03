#ifndef _CBJECTKLASS_H
#define _CBJECTKLASS_H
#include "../CbjectSettings.h"
#include "_CbjectDeleteFunctionPrototype.h"
#include "_CbjectGetFunctionPrototype.h"
#include "_CbjectNewFunctionPrototype.h"

#if CbjectSettings_useHeap == true
    #if CbjectSettings_useStaticPool == true
        #define _CbjectKlass(klassName, superKlassName, params, properties, virtualFunctions) \
            AbstractKlass(params, properties, virtualFunctions);                              \
            _CbjectGetFunctionPrototype(klassName);                                           \
            _CbjectNewFunctionPrototype(klassName);                                           \
            _CbjectDeleteFunctionPrototype(klassName)
    #else
        #define _CbjectKlass(klassName, superKlassName, params, properties, virtualFunctions) \
            AbstractKlass(params, properties, virtualFunctions);                              \
            _CbjectNewFunctionPrototype(klassName);                                           \
            _CbjectDeleteFunctionPrototype(klassName)
    #endif
#else
    #if CbjectSettings_useStaticPool == true
        #define _CbjectKlass(klassName, superKlassName, params, properties, virtualFunctions) \
            AbstractKlass(params, properties, virtualFunctions);                              \
            _CbjectGetFunctionPrototype(klassName)
    #else
        #define _CbjectKlass(klassName, superKlassName, params, properties, virtualFunctions) \
            AbstractKlass(params, properties, virtualFunctions)
    #endif
#endif

#endif // _CBJECTKLASS_H
