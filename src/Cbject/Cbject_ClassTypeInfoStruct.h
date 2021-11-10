#ifndef CBJECT_CLASSTYPEINFOSTRUCT_H
#define CBJECT_CLASSTYPEINFOSTRUCT_H

/*
Cbject_ClassTypeInfoStruct_Decl
*/
#define Cbject_ClassTypeInfoStruct_Decl(class) \
    typedef struct class##Type class##Type

/*
Cbject_ClassTypeInfoStruct_Def
*/
#define Cbject_ClassTypeInfoStruct_Def_caseNA(class, superClass) \
    struct class##Type                                           \
    {                                                            \
        superClass##TypeContainer super;                         \
    }

#define Cbject_ClassTypeInfoStruct_Def_caseVirtFunSetup(class, superClass) \
    struct class##Type                                                     \
    {                                                                      \
        superClass##TypeContainer super;                                   \
        class##VirtFuns virtFuns;                                          \
    }

#define Cbject_ClassTypeInfoStruct_Def_x1(class, superClass, virtFunSetupCase, ...) \
    Cbject_ClassTypeInfoStruct_Def_case##virtFunSetupCase(class, superClass)

#define Cbject_ClassTypeInfoStruct_Def_x0(class, superClass, ...) \
    Cbject_ClassTypeInfoStruct_Def_x1(class, superClass, __VA_ARGS__)

#define Cbject_ClassTypeInfoStruct_Def(class, superClass, virtFunSetupPack) \
    Cbject_ClassTypeInfoStruct_Def_x0(class, superClass, Cbject_Utils_unpack(virtFunSetupPack))

#endif // CBJECT_CLASSTYPEINFOSTRUCT_H
