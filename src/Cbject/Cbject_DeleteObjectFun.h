#ifndef CBJECT_DELETEOBJECTFUN_H
#define CBJECT_DELETEOBJECTFUN_H
#include <stdlib.h>

/*
Cbject_DeleteObjectFun_Prototype
*/
#define Cbject_DeleteObjectFun_Prototype(className) \
    void className##_delete(className * const me)

/*
Cbject_DeleteObjectFun_Impl
*/
#define Cbject_DeleteObjectFun_Impl(className)  \
    Cbject_DeleteObjectFun_Prototype(className) \
    {                                           \
        className##_terminate(me);              \
        free(me);                               \
    }

#endif // CBJECT_DELETEOBJECTFUN_H
