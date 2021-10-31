#ifndef CBJECT_INITFUN_H
#define CBJECT_INITFUN_H

#define Cbject_InitFun_OnInitFunPrototype(typeName, parent) \
    static void typeName##_onInit(typeName * const me, typeName##Params const p, parent##Params * const sp)

#define Cbject_InitFun_Prototype(typeName) \
    void typeName##_init(typeName * const me, typeName##Params const p)

#define Cbject_InitFun_Impl(typeName, parent)                         \
    Cbject_InitFun_OnInitFunPrototype(typeName, parent);              \
    Cbject_InitFun_Prototype(typeName)                                \
    {                                                                 \
        typedef struct CbjectT                                        \
        {                                                             \
            Cbject_Settings_maxAlign a;                               \
            CbjectType * t;                                           \
        } CbjectT;                                                    \
                                                                      \
        parent##Params sp;                                            \
        typeName##_onInit(me, p, &sp);                                \
        parent##_init((parent *)me, sp);                              \
        ((CbjectT *)me)->t = (CbjectType *)typeName##Type_instance(); \
    }                                                                 \
    Cbject_InitFun_OnInitFunPrototype(typeName, parent)

#endif // CBJECT_INITFUN_H
