#ifndef CBJECT_CLASS_H
#define CBJECT_CLASS_H
#include "Cbject_DeleteObjectFunPrototype.h"
#include "Cbject_GetObjectFunPrototype.h"
#include "Cbject_NewObjectFunPrototype.h"
#include "Cbject_NewOnStackFunPrototype.h"
#include "Cbject_Settings.h"

#if Cbject_Settings_useHeap == true
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class(cbjType, parent, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                    \
            Cbject_NewOnStackFunPrototype(cbjType);                    \
            Cbject_GetObjectFunPrototype(cbjType);                     \
            Cbject_NewObjectFunPrototype(cbjType);                     \
            Cbject_DeleteObjectFunPrototype(cbjType)
    #else
        #define Cbject_Class(cbjType, parent, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                    \
            Cbject_NewOnStackFunPrototype(cbjType);                    \
            Cbject_NewObjectFunPrototype(cbjType);                     \
            Cbject_DeleteObjectFunPrototype(cbjType)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class(cbjType, parent, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                    \
            Cbject_NewOnStackFunPrototype(cbjType);                    \
            Cbject_GetObjectFunPrototype(cbjType)
    #else
        #define Cbject_Class(cbjType, parent, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                    \
            Cbject_NewOnStackFunPrototype(cbjType)
    #endif
#endif

#endif // CBJECT_CLASS_H
