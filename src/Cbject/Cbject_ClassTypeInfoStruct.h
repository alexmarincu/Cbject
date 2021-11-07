#ifndef CBJECT_CLASSTYPEINFOSTRUCT_H
#define CBJECT_CLASSTYPEINFOSTRUCT_H

/*
Cbject_ClassTypeInfoStruct_Decl
*/
#define Cbject_ClassTypeInfoStruct_Decl(className) \
    typedef struct className##Type className##Type

/*
Cbject_ClassTypeInfoStruct_Def
*/
#define Cbject_ClassTypeInfoStruct_Def_withoutVirtFuns(className, superClassName) \
    struct className##Type                                                        \
    {                                                                             \
        superClassName##TypeContainer super;                                      \
    }

#define Cbject_ClassTypeInfoStruct_Def_withVirtFuns(className, superClassName) \
    struct className##Type                                                     \
    {                                                                          \
        superClassName##TypeContainer super;                                   \
        className##VirtFuns virtFuns;                                          \
    }

#define Cbject_ClassTypeInfoStruct_Def(className, superClassName, case) \
    Cbject_ClassTypeInfoStruct_Def_##case (className, superClassName)

#endif // CBJECT_CLASSTYPEINFOSTRUCT_H
