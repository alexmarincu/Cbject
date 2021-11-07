#ifndef CBJECT_CLASSVIRTFUNSGETTER_H
#define CBJECT_CLASSVIRTFUNSGETTER_H

/*
Cbject_ClassVirtFunsGetter_Prototype
*/
#define Cbject_ClassVirtFunsGetter_Prototype(className) \
    className##VirtFuns * className##Type_virtFuns(className##Type * meType)

/*
Cbject_ClassVirtFunsGetter_Impl
*/
#define Cbject_ClassVirtFunsGetter_Impl(className)  \
    Cbject_ClassVirtFunsGetter_Prototype(className) \
    {                                               \
        className##VirtFuns * virtFuns = NULL;      \
                                                    \
        typedef struct ObjectTypeT                  \
        {                                           \
            Cbject_Settings_maxAlign align;         \
            char const * name;                      \
            ObjectType * superType;                 \
            ObjectVirtFuns virtFuns;                \
        } ObjectTypeT;                              \
                                                    \
        if (((ObjectTypeT *)meType)->name == NULL)  \
        {                                           \
            virtFuns = &meType->virtFuns;           \
        }                                           \
                                                    \
        return virtFuns;                            \
    }
// todo: assert when accessed after init

#endif // CBJECT_CLASSVIRTFUNSGETTER_H
