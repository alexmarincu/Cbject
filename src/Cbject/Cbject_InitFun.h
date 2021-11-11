#ifndef CBJECT_INITFUN_H
#define CBJECT_INITFUN_H

/*
Cbject_InitFun_OnInitFunPrototype
*/
#define Cbject_InitFun_OnInitFunPrototype_x0(class) \
    static void class##_onInit(class * const me, class##Params const params, void * const super_params)

#define Cbject_InitFun_OnInitFunPrototype(class) \
    Cbject_InitFun_OnInitFunPrototype_x0(class)

/*
Cbject_InitFun_Prototype
*/
#define Cbject_InitFun_Prototype(class) \
    void class##_init(class * const me, class##Params const params)

/*
Cbject_InitFun_Impl
*/
#define Cbject_InitFun_Impl_x0(class, superClass)                     \
    Cbject_InitFun_OnInitFunPrototype(class);                         \
    Cbject_InitFun_Prototype(class)                                   \
    {                                                                 \
        typedef struct ObjectT                                        \
        {                                                             \
            Cbject_Settings_maxAlign align;                           \
            ObjectType * type;                                        \
        } ObjectT;                                                    \
                                                                      \
        superClass##Params super_params;                              \
        class##_onInit(me, params, &super_params);                    \
        superClass##_init((superClass *)me, super_params);            \
        ((ObjectT *)me)->type = (ObjectType *)class##Type_instance(); \
    }

#define Cbject_InitFun_Impl(class, superClass) \
    Cbject_InitFun_Impl_x0(class, superClass)
#endif // CBJECT_INITFUN_H
