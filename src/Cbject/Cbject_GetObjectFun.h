#ifndef CBJECT_GETOBJECTFUN_H
#define CBJECT_GETOBJECTFUN_H

/*
Cbject_GetObjectFun_Prototype
*/
#define Cbject_GetObjectFun_Prototype(class) \
    class * class##_get(class##Params const params)

/*
Cbject_GetObjectFun_Impl
*/
#define Cbject_GetObjectFun_Impl(class)      \
    Cbject_GetObjectFun_Prototype(class)     \
    {                                        \
        static class pool[class##_poolSize]; \
        static uint64 count = 0;             \
        class * me = NULL;                   \
                                             \
        if (count < class##_poolSize)        \
        {                                    \
            me = &pool[count];               \
            *me = (class){0};                \
            class##_init(me, params);        \
            count++;                         \
        }                                    \
                                             \
        return me;                           \
    }

#endif // CBJECT_GETOBJECTFUN_H
