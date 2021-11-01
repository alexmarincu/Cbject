#ifndef CBJECT_DELETEOBJECTFUN_H
#define CBJECT_DELETEOBJECTFUN_H
#include <stdlib.h>

#define Cbject_DeleteObjectFun_Prototype(typeName) \
    void typeName##_delete(typeName * const me)

#define Cbject_DeleteObjectFun_Impl(typeName)  \
    Cbject_DeleteObjectFun_Prototype(typeName) \
    {                                          \
        typeName##_terminate(me);              \
        free(me);                              \
    }

#endif // CBJECT_DELETEOBJECTFUN_H
