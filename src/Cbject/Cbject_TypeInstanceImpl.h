#ifndef CBJECT_TYPEINSTANCEIMPL_H
#define CBJECT_TYPEINSTANCEIMPL_H
#include "Cbject_BindSuperFun.h"
#include "Cbject_TypeInstanceFunPrototype.h"

#define Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun(funPrototype) \
    Cbject_BindSuperFun funPrototype;

#define Cbject_TypeInstanceImpl_void(typeName, parent, ...)                                            \
    Cbject_TypeInstanceFunPrototype(typeName)                                                          \
    {                                                                                                  \
        static typeName##Type t;                                                                       \
                                                                                                       \
        typedef struct CbjectTypeT                                                                     \
        {                                                                                              \
            Cbject_Settings_maxAlign a;                                                                \
            char const * name;                                                                         \
            CbjectType * st;                                                                           \
            CbjectVirtFuns vf;                                                                         \
        } CbjectTypeT;                                                                                 \
                                                                                                       \
        if (((CbjectTypeT *)&t)->name == NULL)                                                         \
        {                                                                                              \
            /*static char const * const name = #typeName;  */                                          \
            *((parent##TypeContainer *)&t) = *((parent##TypeContainer *)parent##Type_instance());      \
            ((CbjectTypeT *)&t)->name = NULL;                                                          \
            ((CbjectTypeT *)&t)->vf.size = (uint8(*)(Cbject const * const me))super_##typeName##_size; \
            ((CbjectTypeT *)&t)->name = #typeName;                                                     \
            ((CbjectTypeT *)&t)->st = (CbjectType *)parent##Type_instance();                           \
        }                                                                                              \
                                                                                                       \
        return &t;                                                                                     \
    }

#define Cbject_TypeInstanceImpl_(typeName, parent, ...)                                                      \
    Cbject_TypeInstanceFunPrototype(typeName)                                                                \
    {                                                                                                        \
        static typeName##Type t;                                                                             \
                                                                                                             \
        typedef struct CbjectTypeT                                                                           \
        {                                                                                                    \
            Cbject_Settings_maxAlign a;                                                                      \
            char const * name;                                                                               \
            CbjectType * st;                                                                                 \
            CbjectVirtFuns vf;                                                                               \
        } CbjectTypeT;                                                                                       \
                                                                                                             \
        if (((CbjectTypeT *)&t)->name == NULL)                                                               \
        {                                                                                                    \
            /*static char const * const name = #typeName;  */                                                \
            *((parent##TypeContainer *)&t) = *((parent##TypeContainer *)parent##Type_instance());            \
            ((CbjectTypeT *)&t)->name = NULL;                                                                \
            ((CbjectTypeT *)&t)->vf.size = (uint8(*)(Cbject const * const me))super_##typeName##_size;       \
            Cbject_Utils_forEach(Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindSuperFun, __VA_ARGS__); \
            ((CbjectTypeT *)&t)->name = #typeName;                                                           \
            ((CbjectTypeT *)&t)->st = (CbjectType *)parent##Type_instance();                                 \
        }                                                                                                    \
                                                                                                             \
        return &t;                                                                                           \
    }

#define Cbject_TypeInstanceImpl_case(typeName, parent, case, ...) \
    Cbject_TypeInstanceImpl_##case (typeName, parent, __VA_ARGS__)

#define Cbject_TypeInstanceImpl(typeName, parent, ...) \
    Cbject_TypeInstanceImpl_case(typeName, parent, __VA_ARGS__)

#endif // CBJECT_TYPEINSTANCEIMPL_H
