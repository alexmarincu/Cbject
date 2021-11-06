#ifndef CBJECT_CLASSTYPEINFOSTRUCT_H
#define CBJECT_CLASSTYPEINFOSTRUCT_H

#define Cbject_ClassTypeInfoStruct_Decl(typeName) \
    typedef struct typeName##Type typeName##Type

#define Cbject_ClassTypeInfoStruct_Def_withoutVirtFuns(typeName, superTypeName) \
    struct typeName##Type                                                       \
    {                                                                           \
        superTypeName##TypeContainer super;                                     \
    }

#define Cbject_ClassTypeInfoStruct_Def_withVirtFuns(typeName, superTypeName) \
    struct typeName##Type                                                    \
    {                                                                        \
        superTypeName##TypeContainer super;                                  \
        typeName##VirtFuns virtFuns;                                         \
    }

#define Cbject_ClassTypeInfoStruct_Def(typeName, superTypeName, case) \
    Cbject_ClassTypeInfoStruct_Def_##case (typeName, superTypeName)

#endif // CBJECT_CLASSTYPEINFOSTRUCT_H
