#ifndef _CBJ_CLASSINSTANCEIMPL_H
#define _CBJ_CLASSINSTANCEIMPL_H
#include "_Cbj_ClassInstanceFunPrototype.h"

#define _Cbj_ClassInstanceImpl_stripParenthesesAndApplyBindFun(funPrototype) \
    BindFun funPrototype;

#define _Cbj_ClassInstanceImpl_0(typeName, Cbj_ParentName, ...)                                 \
    _Cbj_ClassInstanceFunPrototype(typeName)                                                  \
    {                                                                                                 \
        static typeName##Class c;                                                                    \
                                                                                                      \
        if (((Cbj_BaseClass *) &c)->type == NULL)                                                       \
        {                                                                                             \
            static char const * const type = #typeName;                                              \
            *((Cbj_ParentName##Class *) &c) = *Cbj_ParentName##Class_instance();                      \
            ((Cbj_BaseClass *) &c)->vf.size = (uint8(*)(Cbj_Base const * const me)) s_##typeName##_size; \
            ((Cbj_BaseClass *) &c)->type = type;                                                        \
        }                                                                                             \
                                                                                                      \
        return &c;                                                                                    \
    }

#define _Cbj_ClassInstanceImpl__(typeName, Cbj_ParentName, ...)                                                \
    _Cbj_ClassInstanceFunPrototype(typeName)                                                                 \
    {                                                                                                                \
        static typeName##Class c;                                                                                   \
                                                                                                                     \
        if (((Cbj_BaseClass *) &c)->type == NULL)                                                                      \
        {                                                                                                            \
            static char const * const type = #typeName;                                                             \
            *((Cbj_ParentName##Class *) &c) = *Cbj_ParentName##Class_instance();                                     \
            ((Cbj_BaseClass *) &c)->vf.size = (uint8(*)(Cbj_Base const * const me)) s_##typeName##_size;                \
            _Cbj_Utils_forEach(_Cbj_ClassInstanceImpl_stripParenthesesAndApplyBindFun, __VA_ARGS__); \
            ((Cbj_BaseClass *) &c)->type = type;                                                                       \
        }                                                                                                            \
                                                                                                                     \
        return &c;                                                                                                   \
    }

#define _Cbj_ClassInstanceImpl_case(typeName, Cbj_ParentName, case, ...) \
    _Cbj_ClassInstanceImpl_##case (typeName, Cbj_ParentName, __VA_ARGS__)

#define _Cbj_ClassInstanceImpl(typeName, Cbj_ParentName, ...) \
    _Cbj_ClassInstanceImpl_case(typeName, Cbj_ParentName, __VA_ARGS__)

#endif // _CBJ_CLASSINSTANCEIMPL_H
