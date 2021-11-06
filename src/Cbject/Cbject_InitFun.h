#ifndef CBJECT_INITFUN_H
#define CBJECT_INITFUN_H

#define Cbject_InitFun_OnInitFunPrototype(typeName, superTypeName) \
    static void typeName##_onInit(typeName * const me, typeName##Params const params, superTypeName##Params * const superParams)

#define Cbject_InitFun_Prototype(typeName) \
    void typeName##_init(typeName * const me, typeName##Params const params)

#define Cbject_InitFun_Impl_x(typeName, superTypeName)                   \
    Cbject_InitFun_OnInitFunPrototype(typeName, superTypeName);          \
    Cbject_InitFun_Prototype(typeName)                                   \
    {                                                                    \
        typedef struct ObjectT                                           \
        {                                                                \
            Cbject_Settings_maxAlign align;                              \
            ObjectType * type;                                           \
        } ObjectT;                                                       \
                                                                         \
        superTypeName##Params superParams;                               \
        typeName##_onInit(me, params, &superParams);                     \
        superTypeName##_init((superTypeName *)me, superParams);          \
        ((ObjectT *)me)->type = (ObjectType *)typeName##Type_instance(); \
    }                                                                    \
    Cbject_InitFun_OnInitFunPrototype(typeName, superTypeName)

#define Cbject_InitFun_Impl(typeName, superTypeName) \
    Cbject_InitFun_Impl_x(typeName, superTypeName)
#endif // CBJECT_INITFUN_H
