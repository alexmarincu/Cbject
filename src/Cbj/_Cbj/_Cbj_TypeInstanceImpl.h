#ifndef _CBJ_TYPEINSTANCEIMPL_H
#define _CBJ_TYPEINSTANCEIMPL_H
#include "_Cbj_BindSuperFun.h"
#include "_Cbj_TypeInstanceFunPrototype.h"

#define _Cbj_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun(funPrototype) \
    _Cbj_BindSuperFun funPrototype;

#define _Cbj_TypeInstanceImpl_0(cbjType, parent, ...)                                               \
    _Cbj_TypeInstanceFunPrototype(cbjType)                                                          \
    {                                                                                               \
        static cbjType##Type type;                                                                     \
                                                                                                    \
        typedef struct _CbjectType                                                                  \
        {                                                                                           \
            Cbj_Settings_maxAlign xalign;                                                                \
            char const * name;                                                                      \
            CbjectVirtFuns virtFuns;                                                                      \
        } _CbjectType;                                                                              \
                                                                                                    \
        if (((_CbjectType *) &type)->name == NULL)                                                     \
        {                                                                                           \
            /*static char const * const name = #cbjType;  */                                        \
            *((_##parent##Type *) &type) = *((_##parent##Type *) parent##Type_instance());             \
            ((_CbjectType *) &type)->name = NULL;                                                      \
            ((_CbjectType *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) s_##cbjType##_size; \
            ((_CbjectType *) &type)->name = #cbjType;                                                  \
        }                                                                                           \
                                                                                                    \
        return &type;                                                                                  \
    }

#define _Cbj_TypeInstanceImpl__(cbjType, parent, ...)                                                    \
    _Cbj_TypeInstanceFunPrototype(cbjType)                                                               \
    {                                                                                                    \
        static cbjType##Type type;                                                                          \
                                                                                                         \
        typedef struct _CbjectType                                                                       \
        {                                                                                                \
            Cbj_Settings_maxAlign xalign;                                                                     \
            char const * name;                                                                           \
            CbjectVirtFuns virtFuns;                                                                           \
        } _CbjectType;                                                                                   \
                                                                                                         \
        if (((_CbjectType *) &type)->name == NULL)                                                          \
        {                                                                                                \
            /*static char const * const name = #cbjType;  */                                             \
            *((_##parent##Type *) &type) = *((_##parent##Type *) parent##Type_instance());                  \
            ((_CbjectType *) &type)->name = NULL;                                                           \
            ((_CbjectType *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) s_##cbjType##_size;      \
            _Cbj_Utils_forEach(_Cbj_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun, __VA_ARGS__); \
            ((_CbjectType *) &type)->name = #cbjType;                                                       \
        }                                                                                                \
                                                                                                         \
        return &type;                                                                                       \
    }

#define _Cbj_TypeInstanceImpl_case(cbjType, parent, case, ...) \
    _Cbj_TypeInstanceImpl_##case (cbjType, parent, __VA_ARGS__)

#define _Cbj_TypeInstanceImpl(cbjType, parent, ...) \
    _Cbj_TypeInstanceImpl_case(cbjType, parent, __VA_ARGS__)

#endif // _CBJ_TYPEINSTANCEIMPL_H
