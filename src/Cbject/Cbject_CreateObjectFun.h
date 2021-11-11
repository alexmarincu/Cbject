#ifndef CBJECT_NEWOBJECTIMPL_H
#define CBJECT_NEWOBJECTIMPL_H
#include <assert.h>
#include <stdlib.h>

/*
Cbject_CreateObjectFun_Prototype
*/
#define Cbject_CreateObjectFun_Prototype(class) \
    class * class##_create(class##Params const params)

/*
Cbject_CreateObjectFun_Impl
*/
#define Cbject_CreateObjectFun_Impl(class)                       \
    Cbject_CreateObjectFun_Prototype(class)                      \
    {                                                            \
        class * me = (class *)malloc(sizeof(class));             \
        assert((me != NULL) && "Heap memory allocation failed"); \
        *me = (class){0};                                        \
        class##_init(me, params);                                \
        return me;                                               \
    }

#endif // CBJECT_NEWOBJECTIMPL_H
