#ifndef CBJECT_CLASSVIRTFUNSGETTER_H
#define CBJECT_CLASSVIRTFUNSGETTER_H

/*
Cbject_ClassVirtFunsGetter_Prototype
*/
#define Cbject_ClassVirtFunsGetter_Prototype(class) \
    class##VirtFuns * class##Type_virtFuns(class##Type * meType)

/*
Cbject_ClassVirtFunsGetter_Impl
*/
#define Cbject_ClassVirtFunsGetter_Impl(class)     \
    Cbject_ClassVirtFunsGetter_Prototype(class)    \
    {                                              \
        class##VirtFuns * virtFuns = NULL;         \
                                                   \
        typedef struct ObjectTypeT                 \
        {                                          \
            Cbject_Settings_maxAlign align;        \
            uint64 size;                           \
            char const * name;                     \
            ObjectType * superType;                \
        } ObjectTypeT;                             \
                                                   \
        if (((ObjectTypeT *)meType)->name == NULL) \
        {                                          \
            virtFuns = &meType->virtFuns;          \
        }                                          \
                                                   \
        return virtFuns;                           \
    }
// todo: Assert when accessed after init

#endif // CBJECT_CLASSVIRTFUNSGETTER_H
