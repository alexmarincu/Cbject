#ifndef CBJECT_OBJECTSETUPFUN_H
#define CBJECT_OBJECTSETUPFUN_H

/*
Cbject_ObjectSetupFun_Prototype
*/
#define Cbject_ObjectSetupFun_Prototype_x0(class) \
    static void class##_setup(class * const me, class##Params const * const params)

#define Cbject_ObjectSetupFun_Prototype(class) \
    Cbject_ObjectSetupFun_Prototype_x0(class)

/*
Cbject_ObjectSetupFun_InitFunPrototype
*/
#define Cbject_ObjectSetupFun_InitFunPrototype_x0(class) \
    void class##_init(class * const me, class##Params const * const params)

#define Cbject_ObjectSetupFun_InitFunPrototype(class) \
    Cbject_ObjectSetupFun_InitFunPrototype_x0(class)

/*
Cbject_ObjectSetupFun_Impl
*/
#define Cbject_ObjectSetupFun_Impl_x0(class, superClass)                  \
    Cbject_ObjectSetupFun_Prototype(class)                                \
    {                                                                     \
        typedef struct ObjectT                                            \
        {                                                                 \
            Cbject_Settings_maxAlign align;                               \
            ObjectType * type;                                            \
        } ObjectT;                                                        \
                                                                          \
        if (((ObjectT *)me)->type == NULL)                                \
        {                                                                 \
            ((ObjectT *)me)->type = (ObjectType *)class##Type_instance(); \
            class##_init(me, params);                                     \
        }                                                                 \
    }

#define Cbject_ObjectSetupFun_Impl(class, superClass) \
    Cbject_ObjectSetupFun_Impl_x0(class, superClass)
#endif // CBJECT_OBJECTSETUPFUN_H
