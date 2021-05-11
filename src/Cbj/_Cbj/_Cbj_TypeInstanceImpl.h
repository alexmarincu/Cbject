#ifndef _CBJ_TYPEINSTANCEIMPL_H
#define _CBJ_TYPEINSTANCEIMPL_H
#include "_Cbj_TypeInstanceFunPrototype.h"

#define _Cbj_TypeInstanceImpl_stripParenthesesAndApplyBindFun(funPrototype) \
    BindFun funPrototype;

#define _Cbj_TypeInstanceImpl_0(cbjType, parent, ...)                                              \
    _Cbj_TypeInstanceFunPrototype(cbjType)                                                         \
    {                                                                                              \
        static cbjType##Type t;                                                                    \
                                                                                                   \
        if (((CbjectType *) &t)->name == NULL)                                                     \
        {                                                                                          \
            static char const * const type = #cbjType;                                             \
            *((parent##Type *) &t) = *parent##Type_instance();                                     \
            ((CbjectType *) &t)->vf.size = (uint8(*)(Cbject const * const me)) s_##cbjType##_size; \
            ((CbjectType *) &t)->name = type;                                                      \
        }                                                                                          \
                                                                                                   \
        return &t;                                                                                 \
    }

#define _Cbj_TypeInstanceImpl__(cbjType, parent, ...)                                               \
    _Cbj_TypeInstanceFunPrototype(cbjType)                                                          \
    {                                                                                               \
        static cbjType##Type t;                                                                     \
                                                                                                    \
        if (((CbjectType *) &t)->name == NULL)                                                      \
        {                                                                                           \
            static char const * const type = #cbjType;                                              \
            *((parent##Type *) &t) = *parent##Type_instance();                                      \
            ((CbjectType *) &t)->vf.size = (uint8(*)(Cbject const * const me)) s_##cbjType##_size;  \
            _Cbj_Utils_forEach(_Cbj_TypeInstanceImpl_stripParenthesesAndApplyBindFun, __VA_ARGS__); \
            ((CbjectType *) &t)->name = type;                                                       \
        }                                                                                           \
                                                                                                    \
        return &t;                                                                                  \
    }

#define _Cbj_TypeInstanceImpl_case(cbjType, parent, case, ...) \
    _Cbj_TypeInstanceImpl_##case (cbjType, parent, __VA_ARGS__)

#define _Cbj_TypeInstanceImpl(cbjType, parent, ...) \
    _Cbj_TypeInstanceImpl_case(cbjType, parent, __VA_ARGS__)

#endif // _CBJ_TYPEINSTANCEIMPL_H
