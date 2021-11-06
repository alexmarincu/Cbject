#ifndef CBJECT_INITFUN_H
#define CBJECT_INITFUN_H

#define Cbject_InitFun_OnInitFunPrototype(className, superClassName) \
    static void className##_onInit(className * const me, className##Params const params, superClassName##Params * const superParams)

#define Cbject_InitFun_Prototype(className) \
    void className##_init(className * const me, className##Params const params)

#define Cbject_InitFun_Impl_x(className, superClassName)                  \
    Cbject_InitFun_OnInitFunPrototype(className, superClassName);         \
    Cbject_InitFun_Prototype(className)                                   \
    {                                                                     \
        typedef struct ObjectT                                            \
        {                                                                 \
            Cbject_Settings_maxAlign align;                               \
            ObjectType * type;                                            \
        } ObjectT;                                                        \
                                                                          \
        superClassName##Params superParams;                               \
        className##_onInit(me, params, &superParams);                     \
        superClassName##_init((superClassName *)me, superParams);         \
        ((ObjectT *)me)->type = (ObjectType *)className##Type_instance(); \
    }                                                                     \
    Cbject_InitFun_OnInitFunPrototype(className, superClassName)

#define Cbject_InitFun_Impl(className, superClassName) \
    Cbject_InitFun_Impl_x(className, superClassName)
#endif // CBJECT_INITFUN_H
