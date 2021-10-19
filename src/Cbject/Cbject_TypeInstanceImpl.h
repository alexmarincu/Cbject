#ifndef CBJECT_TYPEINSTANCEIMPL_H
#define CBJECT_TYPEINSTANCEIMPL_H
#include "Cbject_BindSuperFun.h"
#include "Cbject_TypeInstanceFunPrototype.h"

#define Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun(funPrototype) \
    Cbject_BindSuperFun funPrototype;

#define Cbject_TypeInstanceImpl_0(cbjType, parent, ...)                                                            \
    Cbject_TypeInstanceFunPrototype(cbjType)                                                                       \
    {                                                                                                              \
        static cbjType##Type type;                                                                                 \
                                                                                                                   \
        typedef struct ___CbjectType                                                                               \
        {                                                                                                          \
            Cbject_Settings_maxAlign ___align;                                                                        \
            char const * name;                                                                                     \
            CbjectVirtFuns virtFuns;                                                                               \
        } ___CbjectType;                                                                                           \
                                                                                                                   \
        if (((___CbjectType *) &type)->name == NULL)                                                               \
        {                                                                                                          \
            /*static char const * const name = #cbjType;  */                                                       \
            *((___##parent##Type *) &type) = *((___##parent##Type *) parent##Type_());                             \
            ((___CbjectType *) &type)->name = NULL;                                                                \
            ((___CbjectType *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) super_##cbjType##_size; \
            ((___CbjectType *) &type)->name = #cbjType;                                                            \
        }                                                                                                          \
                                                                                                                   \
        return &type;                                                                                              \
    }

#define Cbject_TypeInstanceImpl_(cbjType, parent, ...)                                                            \
    Cbject_TypeInstanceFunPrototype(cbjType)                                                                       \
    {                                                                                                              \
        static cbjType##Type type;                                                                                 \
                                                                                                                   \
        typedef struct ___CbjectType                                                                               \
        {                                                                                                          \
            Cbject_Settings_maxAlign ___align;                                                                        \
            char const * name;                                                                                     \
            CbjectVirtFuns virtFuns;                                                                               \
        } ___CbjectType;                                                                                           \
                                                                                                                   \
        if (((___CbjectType *) &type)->name == NULL)                                                               \
        {                                                                                                          \
            /*static char const * const name = #cbjType;  */                                                       \
            *((___##parent##Type *) &type) = *((___##parent##Type *) parent##Type_());                             \
            ((___CbjectType *) &type)->name = NULL;                                                                \
            ((___CbjectType *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) super_##cbjType##_size; \
            Cbject_Utils_forEach(Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun, __VA_ARGS__);       \
            ((___CbjectType *) &type)->name = #cbjType;                                                            \
        }                                                                                                          \
                                                                                                                   \
        return &type;                                                                                              \
    }

#define Cbject_TypeInstanceImpl_case(cbjType, parent, case, ...) \
    Cbject_TypeInstanceImpl_##case (cbjType, parent, __VA_ARGS__)

#define Cbject_TypeInstanceImpl(cbjType, parent, ...) \
    Cbject_TypeInstanceImpl_case(cbjType, parent, __VA_ARGS__)

#endif // CBJECT_TYPEINSTANCEIMPL_H
