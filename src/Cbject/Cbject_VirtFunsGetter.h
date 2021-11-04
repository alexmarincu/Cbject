#ifndef CBJECT_VIRTFUNSGETTER_H
#define CBJECT_VIRTFUNSGETTER_H

#define Cbject_VirtFunsGetter_Prototype(typeName) \
    typeName##VirtFuns * typeName##Type_virtFuns(typeName##Type * meType)

#define Cbject_VirtFunsGetter_Impl(typeName)       \
    Cbject_VirtFunsGetter_Prototype(typeName)      \
    {                                              \
        typeName##VirtFuns * virtFuns = NULL;      \
                                                   \
        typedef struct ObjectTypeT                 \
        {                                          \
            Cbject_Settings_maxAlign align;        \
            char const * name;                     \
            ObjectType * superType;                \
            ObjectVirtFuns virtFuns;               \
        } ObjectTypeT;                             \
                                                   \
        if (((ObjectTypeT *)meType)->name == NULL) \
        {                                          \
            virtFuns = &meType->virtFuns;          \
        }                                          \
                                                   \
        return virtFuns;                           \
    }

#endif // CBJECT_VIRTFUNSGETTER_H
