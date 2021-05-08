#ifndef _CBJ_CLASSINSTANCEIMPL_H
#define _CBJ_CLASSINSTANCEIMPL_H
#include "_Cbj_ClassInstanceFunPrototype.h"

#define _Cbj_ClassInstanceImpl_stripParenthesesAndApplyBindFun(funPrototype) \
    BindFun funPrototype;

#define _Cbj_ClassInstanceImpl_0(cbjType, parent, ...)                                              \
    _Cbj_ClassInstanceFunPrototype(cbjType)                                                         \
    {                                                                                               \
        static cbjType##Class c;                                                                    \
                                                                                                    \
        if (((CbjectClass *) &c)->type == NULL)                                                     \
        {                                                                                           \
            static char const * const type = #cbjType;                                              \
            *((parent##Class *) &c) = *parent##Class_instance();                                    \
            ((CbjectClass *) &c)->vf.size = (uint8(*)(Cbject const * const me)) s_##cbjType##_size; \
            ((CbjectClass *) &c)->type = type;                                                      \
        }                                                                                           \
                                                                                                    \
        return &c;                                                                                  \
    }

#define _Cbj_ClassInstanceImpl__(cbjType, parent, ...)                                               \
    _Cbj_ClassInstanceFunPrototype(cbjType)                                                          \
    {                                                                                                \
        static cbjType##Class c;                                                                     \
                                                                                                     \
        if (((CbjectClass *) &c)->type == NULL)                                                      \
        {                                                                                            \
            static char const * const type = #cbjType;                                               \
            *((parent##Class *) &c) = *parent##Class_instance();                                     \
            ((CbjectClass *) &c)->vf.size = (uint8(*)(Cbject const * const me)) s_##cbjType##_size;  \
            _Cbj_Utils_forEach(_Cbj_ClassInstanceImpl_stripParenthesesAndApplyBindFun, __VA_ARGS__); \
            ((CbjectClass *) &c)->type = type;                                                       \
        }                                                                                            \
                                                                                                     \
        return &c;                                                                                   \
    }

#define _Cbj_ClassInstanceImpl_case(cbjType, parent, case, ...) \
    _Cbj_ClassInstanceImpl_##case (cbjType, parent, __VA_ARGS__)

#define _Cbj_ClassInstanceImpl(cbjType, parent, ...) \
    _Cbj_ClassInstanceImpl_case(cbjType, parent, __VA_ARGS__)

#endif // _CBJ_CLASSINSTANCEIMPL_H
