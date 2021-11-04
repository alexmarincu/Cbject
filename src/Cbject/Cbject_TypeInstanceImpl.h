#ifndef CBJECT_TYPEINSTANCEIMPL_H
#define CBJECT_TYPEINSTANCEIMPL_H
#include "Cbject_BindFuns.h"
#include "Cbject_TypeInstanceFunPrototype.h"

#define Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindFun(funPrototype) \
    Cbject_BindFun funPrototype;

#define Cbject_TypeInstanceImpl_case_(typeName, parent, ...)                                      \
    Cbject_TypeInstanceFunPrototype(typeName)                                                     \
    {                                                                                             \
        static typeName##Type t;                                                                  \
                                                                                                  \
        typedef struct ObjectTypeT                                                                \
        {                                                                                         \
            Cbject_Settings_maxAlign a;                                                           \
            char const * name;                                                                    \
            ObjectType * st;                                                                      \
            ObjectVirtFuns vf;                                                                    \
        } ObjectTypeT;                                                                            \
                                                                                                  \
        if (((ObjectTypeT *)&t)->name == NULL)                                                    \
        {                                                                                         \
            /*static char const * const name = #typeName;  */                                     \
            *((parent##TypeContainer *)&t) = *((parent##TypeContainer *)parent##Type_instance()); \
            ((ObjectTypeT *)&t)->name = NULL;                                                     \
            ((ObjectTypeT *)&t)->vf.size = (uint8(*)(Object const * const me))typeName##_s_size;  \
            ((ObjectTypeT *)&t)->name = #typeName;                                                \
            ((ObjectTypeT *)&t)->st = (ObjectType *)parent##Type_instance();                      \
        }                                                                                         \
                                                                                                  \
        return &t;                                                                                \
    }

#define Cbject_TypeInstanceImpl_case_bindFuns(typeName, parent, ...)                                    \
    Cbject_TypeInstanceFunPrototype(typeName)                                                           \
    {                                                                                                   \
        static typeName##Type t;                                                                        \
                                                                                                        \
        typedef struct ObjectTypeT                                                                      \
        {                                                                                               \
            Cbject_Settings_maxAlign a;                                                                 \
            char const * name;                                                                          \
            ObjectType * st;                                                                            \
            ObjectVirtFuns vf;                                                                          \
        } ObjectTypeT;                                                                                  \
                                                                                                        \
        if (((ObjectTypeT *)&t)->name == NULL)                                                          \
        {                                                                                               \
            /*static char const * const name = #typeName;  */                                           \
            *((parent##TypeContainer *)&t) = *((parent##TypeContainer *)parent##Type_instance());       \
            ((ObjectTypeT *)&t)->name = NULL;                                                           \
            ((ObjectTypeT *)&t)->vf.size = (uint8(*)(Object const * const me))typeName##_s_size;        \
            Cbject_Utils_forEach(Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindFun, __VA_ARGS__); \
            ((ObjectTypeT *)&t)->name = #typeName;                                                      \
            ((ObjectTypeT *)&t)->st = (ObjectType *)parent##Type_instance();                            \
        }                                                                                               \
                                                                                                        \
        return &t;                                                                                      \
    }

#define Cbject_TypeInstanceImpl_switch(typeName, parent, case, ...) \
    Cbject_TypeInstanceImpl_case_##case (typeName, parent, __VA_ARGS__)

#define Cbject_TypeInstanceImpl_x1(typeName, parent, ...) \
    Cbject_TypeInstanceImpl_switch(typeName, parent, __VA_ARGS__)

#define Cbject_TypeInstanceImpl(typeName, parent, bindFuns) \
    Cbject_TypeInstanceImpl_x1(typeName, parent, Cbject_Utils_stripParentheses(bindFuns))

#endif // CBJECT_TYPEINSTANCEIMPL_H
