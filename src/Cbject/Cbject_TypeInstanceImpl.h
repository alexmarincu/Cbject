#ifndef CBJECT_TYPEINSTANCEIMPL_H
#define CBJECT_TYPEINSTANCEIMPL_H
#include "Cbject_BindSuperFun.h"
#include "Cbject_TypeInstanceFunPrototype.h"

#define Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun(funPrototype) \
    Cbject_BindSuperFun funPrototype;

#define Cbject_TypeInstanceImpl_0(cbjType, parent, ...)                                                                  \
    Cbject_TypeInstanceFunPrototype(cbjType)                                                                             \
    {                                                                                                                    \
        static cbjType##Type type;                                                                                       \
                                                                                                                         \
        typedef struct CbjectTypeContainer                                                                               \
        {                                                                                                                \
            Cbject_Settings_maxAlign a;                                                                                  \
            char const * name;                                                                                           \
            CbjectVirtFuns virtFuns;                                                                                     \
        } CbjectTypeContainer;                                                                                           \
                                                                                                                         \
        if (((CbjectTypeContainer *) &type)->name == NULL)                                                               \
        {                                                                                                                \
            /*static char const * const name = #cbjType;  */                                                             \
            *((parent##TypeContainer *) &type) = *((parent##TypeContainer *) parent##Type_());                           \
            ((CbjectTypeContainer *) &type)->name = NULL;                                                                \
            ((CbjectTypeContainer *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) super_##cbjType##_size; \
            ((CbjectTypeContainer *) &type)->name = #cbjType;                                                            \
        }                                                                                                                \
                                                                                                                         \
        return &type;                                                                                                    \
    }

#define Cbject_TypeInstanceImpl_(cbjType, parent, ...)                                                                   \
    Cbject_TypeInstanceFunPrototype(cbjType)                                                                             \
    {                                                                                                                    \
        static cbjType##Type type;                                                                                       \
                                                                                                                         \
        typedef struct CbjectTypeContainer                                                                               \
        {                                                                                                                \
            Cbject_Settings_maxAlign a;                                                                                  \
            char const * name;                                                                                           \
            CbjectVirtFuns virtFuns;                                                                                     \
        } CbjectTypeContainer;                                                                                           \
                                                                                                                         \
        if (((CbjectTypeContainer *) &type)->name == NULL)                                                               \
        {                                                                                                                \
            /*static char const * const name = #cbjType;  */                                                             \
            *((parent##TypeContainer *) &type) = *((parent##TypeContainer *) parent##Type_());                           \
            ((CbjectTypeContainer *) &type)->name = NULL;                                                                \
            ((CbjectTypeContainer *) &type)->virtFuns.size = (uint8(*)(Cbject const * const me)) super_##cbjType##_size; \
            Cbject_Utils_forEach(Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun, __VA_ARGS__);             \
            ((CbjectTypeContainer *) &type)->name = #cbjType;                                                            \
        }                                                                                                                \
                                                                                                                         \
        return &type;                                                                                                    \
    }

#define Cbject_TypeInstanceImpl_case(cbjType, parent, case, ...) \
    Cbject_TypeInstanceImpl_##case (cbjType, parent, __VA_ARGS__)

#define Cbject_TypeInstanceImpl(cbjType, parent, ...) \
    Cbject_TypeInstanceImpl_case(cbjType, parent, __VA_ARGS__)

#endif // CBJECT_TYPEINSTANCEIMPL_H
