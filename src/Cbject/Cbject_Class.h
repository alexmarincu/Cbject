#ifndef CBJECT_CLASS_H
#define CBJECT_CLASS_H
#include "Cbject_DeleteObjectFunPrototype.h"
#include "Cbject_GetObjectFunPrototype.h"
#include "Cbject_NewObjectFunPrototype.h"
#include "Cbject_NewOnStackFunPrototype.h"
#include "Cbject_Settings.h"

#if Cbject_Settings_useHeap == true
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class(typeName, parent, params, data, virtFuns) \
            AbstractClass(params, data, virtFuns);                     \
            Cbject_NewOnStackFunPrototype(typeName);                   \
            Cbject_GetObjectFunPrototype(typeName);                    \
            Cbject_NewObjectFunPrototype(typeName);                    \
            Cbject_DeleteObjectFunPrototype(typeName)
    #else
        #define Cbject_Class(typeName, parent, params, data, virtFuns) \
            AbstractClass(params, data, virtFuns);                     \
            Cbject_NewOnStackFunPrototype(typeName);                   \
            Cbject_NewObjectFunPrototype(typeName);                    \
            Cbject_DeleteObjectFunPrototype(typeName)
    #endif
#else
    #if Cbject_Settings_useStaticPool == true
        #define Cbject_Class(typeName, parent, params, data, virtFuns) \
            AbstractClass(params, data, virtFuns);                     \
            Cbject_NewOnStackFunPrototype(typeName);                   \
            Cbject_GetObjectFunPrototype(typeName)
    #else
        #define Cbject_Class(typeName, parent, params, data, virtFuns) \
            AbstractClass(params, data, virtFuns);                     \
            Cbject_NewOnStackFunPrototype(typeName)
    #endif
#endif

#endif // CBJECT_CLASS_H
