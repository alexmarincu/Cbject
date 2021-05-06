#ifndef _CBJECTKLASSINSTANCEIMPLNEW_H
#define _CBJECTKLASSINSTANCEIMPLNEW_H
#include "_CbjectClassInstanceFunPrototype.h"

#define _CbjectClassInstanceImpl_stripParenthesesAndApplyBindFun(funPrototype) \
    BindFun funPrototype;

#define _CbjectClassInstanceImpl_0(cbjectTypeName, parentName, ...)                                 \
    _CbjectClassInstanceFunPrototype(cbjectTypeName)                                                  \
    {                                                                                                 \
        static cbjectTypeName##Class k;                                                                    \
                                                                                                      \
        if (((CbjectClass *) &k)->type == NULL)                                                       \
        {                                                                                             \
            static char const * const type = #cbjectTypeName;                                              \
            *((parentName##Class *) &k) = *parentName##Class_instance();                      \
            ((CbjectClass *) &k)->vf.size = (uint8(*)(Cbject const * const me)) s_##cbjectTypeName##_size; \
            ((CbjectClass *) &k)->type = type;                                                        \
        }                                                                                             \
                                                                                                      \
        return &k;                                                                                    \
    }

#define _CbjectClassInstanceImpl__(cbjectTypeName, parentName, ...)                                                \
    _CbjectClassInstanceFunPrototype(cbjectTypeName)                                                                 \
    {                                                                                                                \
        static cbjectTypeName##Class k;                                                                                   \
                                                                                                                     \
        if (((CbjectClass *) &k)->type == NULL)                                                                      \
        {                                                                                                            \
            static char const * const type = #cbjectTypeName;                                                             \
            *((parentName##Class *) &k) = *parentName##Class_instance();                                     \
            ((CbjectClass *) &k)->vf.size = (uint8(*)(Cbject const * const me)) s_##cbjectTypeName##_size;                \
                                                                                                                     \
            _CbjectUtilities_forEach(_CbjectClassInstanceImpl_stripParenthesesAndApplyBindFun, __VA_ARGS__); \
                                                                                                                     \
            ((CbjectClass *) &k)->type = type;                                                                       \
        }                                                                                                            \
                                                                                                                     \
        return &k;                                                                                                   \
    }

#define _CbjectClassInstanceImpl_case(cbjectTypeName, parentName, case, ...) \
    _CbjectClassInstanceImpl_##case (cbjectTypeName, parentName, __VA_ARGS__)

#define _CbjectClassInstanceImpl(cbjectTypeName, parentName, ...) \
    _CbjectClassInstanceImpl_case(cbjectTypeName, parentName, __VA_ARGS__)

#endif // _CBJECTKLASSINSTANCEIMPLNEW_H
