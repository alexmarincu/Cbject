#ifndef CBJECT_INITFUN_H
#define CBJECT_INITFUN_H

/*
Cbject_InitFun_OnInitFunPrototype
*/
#define Cbject_InitFun_OnInitFunPrototype_x0(className) \
    static void className##_onInit(className * const me, className##Params const params, void * const super_params)

#define Cbject_InitFun_OnInitFunPrototype(className) \
    Cbject_InitFun_OnInitFunPrototype_x0(className)

/*
Cbject_InitFun_Prototype
*/
#define Cbject_InitFun_Prototype(className) \
    void className##_init(className * const me, className##Params const params)

/*
Cbject_InitFun_Impl
*/
#define Cbject_InitFun_Impl_x0(className, superClassName)                 \
    Cbject_InitFun_OnInitFunPrototype(className);                         \
    Cbject_InitFun_Prototype(className)                                   \
    {                                                                     \
        typedef struct ObjectT                                            \
        {                                                                 \
            Cbject_Settings_maxAlign align;                               \
            ObjectType * type;                                            \
        } ObjectT;                                                        \
                                                                          \
        superClassName##Params super_params;                              \
        className##_onInit(me, params, &super_params);                    \
        superClassName##_init((superClassName *)me, super_params);        \
        ((ObjectT *)me)->type = (ObjectType *)className##Type_instance(); \
    }

#define Cbject_InitFun_Impl(className, superClassName) \
    Cbject_InitFun_Impl_x0(className, superClassName)
#endif // CBJECT_INITFUN_H
