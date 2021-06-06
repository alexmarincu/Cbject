#ifndef ___CBJ_CLASS_H
#define ___CBJ_CLASS_H
#include "../Cbj_Settings.h"
#include "___Cbj_GetObjectFunPrototype.h"
#include "___Cbj_NewObjectFunPrototype.h"
#include "___Cbj_NewOnStackFunPrototype.h"

#if Cbj_Settings_useHeap == true
    #if Cbj_Settings_useStaticPool == true
        #define ___Cbj_Class(cbjType, parent, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                    \
            ___Cbj_NewOnStackFunPrototype(cbjType);                    \
            ___Cbj_GetObjectFunPrototype(cbjType);                     \
            ___Cbj_NewObjectFunPrototype(cbjType)
    #else
        #define ___Cbj_Class(cbjType, parent, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                    \
            ___Cbj_NewOnStackFunPrototype(cbjType);                    \
            ___Cbj_NewObjectFunPrototype(cbjType)
    #endif
#else
    #if Cbj_Settings_useStaticPool == true
        #define ___Cbj_Class(cbjType, parent, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                    \
            ___Cbj_NewOnStackFunPrototype(cbjType);                    \
            ___Cbj_GetObjectFunPrototype(cbjType)
    #else
        #define ___Cbj_Class(cbjType, parent, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                    \
            ___Cbj_NewOnStackFunPrototype(cbjType)
    #endif
#endif

#endif // ___CBJ_CLASS_H
