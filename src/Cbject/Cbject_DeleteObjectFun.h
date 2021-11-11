#ifndef CBJECT_DELETEOBJECTFUN_H
#define CBJECT_DELETEOBJECTFUN_H
#include <stdlib.h>

/*
Cbject_DeleteObjectFun_Prototype
*/
#define Cbject_DeleteObjectFun_Prototype(class) \
    void class##_delete(class * const me)

/*
Cbject_DeleteObjectFun_Impl
*/
#define Cbject_DeleteObjectFun_Impl(class)  \
    Cbject_DeleteObjectFun_Prototype(class) \
    {                                       \
        class##_terminate(me);              \
        free(me);                           \
    }

#endif // CBJECT_DELETEOBJECTFUN_H
