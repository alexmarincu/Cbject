#ifndef CBJECT_TYPEINSTANCEIMPL_H
#define CBJECT_TYPEINSTANCEIMPL_H
#include "Cbject_BindSuperFun.h"
#include "Cbject_TypeInstanceFunPrototype.h"

#define Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun(funPrototype) \
    Cbject_BindSuperFun funPrototype;

#define Cbject_TypeInstanceImpl_0(typeName, parent, ...)                                                            \
    Cbject_TypeInstanceFunPrototype(typeName)                                                                       \
    {                                                                                                               \
        static typeName##Type type;                                                                                 \
                                                                                                                    \
        typedef struct CbjectTypeContainer                                                                          \
        {                                                                                                           \
            Cbject_Settings_maxAlign a;                                                                             \
            char const * name;                                                                                      \
            CbjectVirtFuns vf;                                                                                      \
        } CbjectTypeContainer;                                                                                      \
                                                                                                                    \
        if (((CbjectTypeContainer *) &type)->name == NULL)                                                          \
        {                                                                                                           \
            /*static char const * const name = #typeName;  */                                                       \
            *((parent##TypeContainer *) &type) = *((parent##TypeContainer *) parent##Type_instance());              \
            ((CbjectTypeContainer *) &type)->name = NULL;                                                           \
            ((CbjectTypeContainer *) &type)->vf.size = (uint8(*)(Cbject const * const me)) super_##typeName##_size; \
            ((CbjectTypeContainer *) &type)->name = #typeName;                                                      \
        }                                                                                                           \
                                                                                                                    \
        return &type;                                                                                               \
    }

#define Cbject_TypeInstanceImpl_(typeName, parent, ...)                                                             \
    Cbject_TypeInstanceFunPrototype(typeName)                                                                       \
    {                                                                                                               \
        static typeName##Type type;                                                                                 \
                                                                                                                    \
        typedef struct CbjectTypeContainer                                                                          \
        {                                                                                                           \
            Cbject_Settings_maxAlign a;                                                                             \
            char const * name;                                                                                      \
            CbjectVirtFuns vf;                                                                                      \
        } CbjectTypeContainer;                                                                                      \
                                                                                                                    \
        if (((CbjectTypeContainer *) &type)->name == NULL)                                                          \
        {                                                                                                           \
            /*static char const * const name = #typeName;  */                                                       \
            *((parent##TypeContainer *) &type) = *((parent##TypeContainer *) parent##Type_instance());              \
            ((CbjectTypeContainer *) &type)->name = NULL;                                                           \
            ((CbjectTypeContainer *) &type)->vf.size = (uint8(*)(Cbject const * const me)) super_##typeName##_size; \
            Cbject_Utils_forEach(Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun, __VA_ARGS__);        \
            ((CbjectTypeContainer *) &type)->name = #typeName;                                                      \
        }                                                                                                           \
                                                                                                                    \
        return &type;                                                                                               \
    }

#define Cbject_TypeInstanceImpl_case(typeName, parent, case, ...) \
    Cbject_TypeInstanceImpl_##case (typeName, parent, __VA_ARGS__)

#define Cbject_TypeInstanceImpl(typeName, parent, ...) \
    Cbject_TypeInstanceImpl_case(typeName, parent, __VA_ARGS__)

#endif // CBJECT_TYPEINSTANCEIMPL_H
