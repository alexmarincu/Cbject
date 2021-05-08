#ifndef _CBJ_CLASS_H
#define _CBJ_CLASS_H
#include "../Cbj_Settings.h"
#include "_Cbj_DeleteObjectFunPrototype.h"
#include "_Cbj_GetObjectFunPrototype.h"
#include "_Cbj_NewObjectFunPrototype.h"

#if Cbj_Settings_useHeap == true
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_Class(typeName, Cbj_ParentName, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                              \
            _Cbj_GetObjectFunPrototype(typeName);                                           \
            _Cbj_NewObjectFunPrototype(typeName);                                           \
            _Cbj_DeleteObjectFunPrototype(typeName)
    #else
        #define _Cbj_Class(typeName, Cbj_ParentName, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                              \
            _Cbj_NewObjectFunPrototype(typeName);                                           \
            _Cbj_DeleteObjectFunPrototype(typeName)
    #endif
#else
    #if Cbj_Settings_useStaticPool == true
        #define _Cbj_Class(typeName, Cbj_ParentName, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns);                              \
            _Cbj_GetObjectFunPrototype(typeName)
    #else
        #define _Cbj_Class(typeName, Cbj_ParentName, params, props, virtFuns) \
            AbstractClass(params, props, virtFuns)
    #endif
#endif

#endif // _CBJ_CLASS_H
