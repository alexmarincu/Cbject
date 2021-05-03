#ifndef _CBJECTKLASSSETUP_H
#define _CBJECTKLASSSETUP_H
#include "../CbjectSettings.h"
#include "_CbjectDeleteImpl.h"
#include "_CbjectGetImpl.h"
#include "_CbjectNewImpl.h"

#if CbjectSettings_useHeap == true
    #include <stdlib.h>
    #if CbjectSettings_useStaticPool == true
        #define _CbjectKlassSetup(klassName, superKlassName, ...) \
            AbstractKlassSetup(__VA_ARGS__);                      \
            _CbjectGetImpl(klassName);                            \
            _CbjectNewImpl(klassName);                            \
            _CbjectDeleteImpl(klassName)
    #else
        #define _CbjectKlassSetup(klassName, superKlassName, ...) \
            AbstractKlassSetup(__VA_ARGS__);                      \
            _CbjectNewImpl(klassName);                            \
            _CbjectDeleteImpl(klassName)

    #endif
#else
    #if CbjectSettings_useStaticPool == true
        #define _CbjectKlassSetup(klassName, superKlassName, ...) \
            AbstractKlassSetup(__VA_ARGS__);                      \
            _CbjectGetImpl(klassName)
    #else
        #define _CbjectKlassSetup(klassName, superKlassName, ...) \
            AbstractKlassSetup(__VA_ARGS__)
    #endif
#endif

#endif // _CBJECTKLASSSETUP_H
