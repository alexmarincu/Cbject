#ifndef _CBJECTKLASSDECLARATION_H
#define _CBJECTKLASSDECLARATION_H
#include "../CbjectSettings.h"
#include "_CbjectDeleteFunctionPrototype.h"
#include "_CbjectGetFunctionPrototype.h"
#include "_CbjectNewFunctionPrototype.h"

#if CbjectSettings_useStaticPool == true
    #if CbjectSettings_useHeap == true
        #define _CbjectKlassDeclaration(klassName, superKlassName, params, properties, virtualFunctions) \
            AbstractKlass(params, properties, virtualFunctions);                                         \
            _CbjectGetFunctionPrototype(klassName);                                                     \
            _CbjectNewFunctionPrototype(klassName);                                                     \
            _CbjectDeleteFunctionPrototype(klassName)
    #else
        #define _CbjectKlassDeclaration(klassName, superKlassName, params, properties, virtualFunctions) \
            AbstractKlass(params, properties, virtualFunctions);                                         \
            _CbjectGetFunctionPrototype(klassName)
    #endif
#else
    #if CbjectSettings_useHeap == true
        #define _CbjectKlassDeclaration(klassName, superKlassName, params, properties, virtualFunctions) \
            AbstractKlass(params, properties, virtualFunctions);                                         \
            _CbjectNewFunctionPrototype(klassName);                                                     \
            _CbjectDeleteFunctionPrototype(klassName)
    #else
        #define _CbjectKlassDeclaration(klassName, superKlassName, params, properties, virtualFunctions) \
            AbstractKlass(params, properties, virtualFunctions)
    #endif
#endif

#endif // _CBJECTKLASSDECLARATION_H
