#ifndef _CBJ_TYPEINSTANCEIMPL_H
#define _CBJ_TYPEINSTANCEIMPL_H
#include "_Cbj_BindSuperFun.h"
#include "_Cbj_TypeInstanceFunPrototype.h"

#define _Cbj_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun(mFunPrototype) \
    _Cbj_BindSuperFun mFunPrototype;

#define _Cbj_TypeInstanceImpl_0(m_cbjType, mParent, ...)                                               \
    _Cbj_TypeInstanceFunPrototype(m_cbjType)                                                          \
    {                                                                                               \
        static m_cbjType##Type type;                                                                     \
                                                                                                    \
        typedef struct _CbjectType                                                                  \
        {                                                                                           \
            Cbj_Settings_maxAlign x_align;                                                                \
            char const * name;                                                                      \
            CbjectVirtFuns virtFuns;                                                                      \
        } _CbjectType;                                                                              \
                                                                                                    \
        if (((_CbjectType *) &type)->name == NULL)                                                     \
        {                                                                                           \
            /*static char const * const name = #m_cbjType;  */                                        \
            *((_##mParent##Type *) &type) = *((_##mParent##Type *) mParent##Type_instance());             \
            ((_CbjectType *) &type)->name = NULL;                                                      \
            ((_CbjectType *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) s_##m_cbjType##_size; \
            ((_CbjectType *) &type)->name = #m_cbjType;                                                  \
        }                                                                                           \
                                                                                                    \
        return &type;                                                                                  \
    }

#define _Cbj_TypeInstanceImpl__(m_cbjType, mParent, ...)                                                    \
    _Cbj_TypeInstanceFunPrototype(m_cbjType)                                                               \
    {                                                                                                    \
        static m_cbjType##Type type;                                                                          \
                                                                                                         \
        typedef struct _CbjectType                                                                       \
        {                                                                                                \
            Cbj_Settings_maxAlign x_align;                                                                     \
            char const * name;                                                                           \
            CbjectVirtFuns virtFuns;                                                                           \
        } _CbjectType;                                                                                   \
                                                                                                         \
        if (((_CbjectType *) &type)->name == NULL)                                                          \
        {                                                                                                \
            /*static char const * const name = #m_cbjType;  */                                             \
            *((_##mParent##Type *) &type) = *((_##mParent##Type *) mParent##Type_instance());                  \
            ((_CbjectType *) &type)->name = NULL;                                                           \
            ((_CbjectType *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) s_##m_cbjType##_size;      \
            _Cbj_Utils_forEach(_Cbj_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun, __VA_ARGS__); \
            ((_CbjectType *) &type)->name = #m_cbjType;                                                       \
        }                                                                                                \
                                                                                                         \
        return &type;                                                                                       \
    }

#define _Cbj_TypeInstanceImpl_case(m_cbjType, mParent, mCase, ...) \
    _Cbj_TypeInstanceImpl_##mCase (m_cbjType, mParent, __VA_ARGS__)

#define _Cbj_TypeInstanceImpl(m_cbjType, mParent, ...) \
    _Cbj_TypeInstanceImpl_case(m_cbjType, mParent, __VA_ARGS__)

#endif // _CBJ_TYPEINSTANCEIMPL_H
