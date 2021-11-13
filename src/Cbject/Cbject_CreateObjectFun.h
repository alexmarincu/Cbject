#ifndef CBJECT_CREATEOBJECTFUN_H
#define CBJECT_CREATEOBJECTFUN_H
#include <stdlib.h>

/*
Cbject_CreateObjectFun_Prototype
*/
#define Cbject_CreateObjectFun_Prototype(class) \
    class * class##_create(class##Params const * const params)

/*
Cbject_CreateObjectFun_Impl
*/
#define Cbject_CreateObjectFun_Impl(class)                       \
    Cbject_CreateObjectFun_Prototype(class)                      \
    {                                                            \
        class * me = (class *)malloc(sizeof(class));             \
        Assert((me != NULL) && "Heap memory allocation failed"); \
        *me = (class){0};                                        \
        class##_setup(me, params);                               \
        return me;                                               \
    }

#endif // CBJECT_CREATEOBJECTFUN_H
