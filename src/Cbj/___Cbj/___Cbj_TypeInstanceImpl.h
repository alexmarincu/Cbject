#ifndef ___CBJ_TYPEINSTANCEIMPL_H
#define ___CBJ_TYPEINSTANCEIMPL_H
#include "___Cbj_BindSuperFun.h"
#include "___Cbj_TypeInstanceFunPrototype.h"

#define ___Cbj_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun(funPrototype) \
    ___Cbj_BindSuperFun funPrototype;

#define ___Cbj_TypeInstanceImpl_0(cbjType, parent, ...)                                                        \
    ___Cbj_TypeInstanceFunPrototype(cbjType)                                                                   \
    {                                                                                                          \
        static cbjType##Type type;                                                                             \
                                                                                                               \
        typedef struct ___CbjectType                                                                           \
        {                                                                                                      \
            Cbj_Settings_maxAlign ___align;                                                                    \
            char const * name;                                                                                 \
            CbjectVirtFuns virtFuns;                                                                           \
        } ___CbjectType;                                                                                       \
                                                                                                               \
        if (((___CbjectType *) &type)->name == NULL)                                                           \
        {                                                                                                      \
            /*static char const * const name = #cbjType;  */                                                   \
            *((___##parent##Type *) &type) = *((___##parent##Type *) parent##Type_());                         \
            ((___CbjectType *) &type)->name = NULL;                                                            \
            ((___CbjectType *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) s_##cbjType##_size; \
            ((___CbjectType *) &type)->name = #cbjType;                                                        \
        }                                                                                                      \
                                                                                                               \
        return &type;                                                                                          \
    }

#define ___Cbj_TypeInstanceImpl__(cbjType, parent, ...)                                                        \
    ___Cbj_TypeInstanceFunPrototype(cbjType)                                                                   \
    {                                                                                                          \
        static cbjType##Type type;                                                                             \
                                                                                                               \
        typedef struct ___CbjectType                                                                           \
        {                                                                                                      \
            Cbj_Settings_maxAlign ___align;                                                                    \
            char const * name;                                                                                 \
            CbjectVirtFuns virtFuns;                                                                           \
        } ___CbjectType;                                                                                       \
                                                                                                               \
        if (((___CbjectType *) &type)->name == NULL)                                                           \
        {                                                                                                      \
            /*static char const * const name = #cbjType;  */                                                   \
            *((___##parent##Type *) &type) = *((___##parent##Type *) parent##Type_());                         \
            ((___CbjectType *) &type)->name = NULL;                                                            \
            ((___CbjectType *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) s_##cbjType##_size; \
            ___Cbj_Utils_forEach(___Cbj_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun, __VA_ARGS__);   \
            ((___CbjectType *) &type)->name = #cbjType;                                                        \
        }                                                                                                      \
                                                                                                               \
        return &type;                                                                                          \
    }

#define ___Cbj_TypeInstanceImpl_case(cbjType, parent, case, ...) \
    ___Cbj_TypeInstanceImpl_##case (cbjType, parent, __VA_ARGS__)

#define ___Cbj_TypeInstanceImpl(cbjType, parent, ...) \
    ___Cbj_TypeInstanceImpl_case(cbjType, parent, __VA_ARGS__)

#endif // ___CBJ_TYPEINSTANCEIMPL_H
