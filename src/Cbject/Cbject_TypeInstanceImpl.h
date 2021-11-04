#ifndef CBJECT_TYPEINSTANCEIMPL_H
#define CBJECT_TYPEINSTANCEIMPL_H
#include "Cbject_BindFuns.h"
#include "Cbject_TypeInstanceFunPrototype.h"

#define Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindFun(funPrototype) \
    Cbject_BindFun funPrototype;

#define Cbject_TypeInstanceImpl_case_(typeName, superTypeName, ...)                                                       \
    Cbject_TypeInstanceFunPrototype(typeName)                                                                             \
    {                                                                                                                     \
        static typeName##Type type;                                                                                       \
                                                                                                                          \
        typedef struct ObjectTypeT                                                                                        \
        {                                                                                                                 \
            Cbject_Settings_maxAlign align;                                                                               \
            char const * name;                                                                                            \
            ObjectType * superType;                                                                                       \
            ObjectVirtFuns virtFuns;                                                                                      \
        } ObjectTypeT;                                                                                                    \
                                                                                                                          \
        if (((ObjectTypeT *)&type)->name == NULL)                                                                         \
        {                                                                                                                 \
            /*static char const * const name = #typeName;  */                                                             \
            *((superTypeName##TypeContainer *)&type) = *((superTypeName##TypeContainer *)superTypeName##Type_instance()); \
            ((ObjectTypeT *)&type)->name = NULL;                                                                          \
            ((ObjectTypeT *)&type)->virtFuns.size = (uint8(*)(Object const * const me))super_##typeName##_size;           \
            ((ObjectTypeT *)&type)->name = #typeName;                                                                     \
            ((ObjectTypeT *)&type)->superType = (ObjectType *)superTypeName##Type_instance();                             \
        }                                                                                                                 \
                                                                                                                          \
        return &type;                                                                                                     \
    }

#define Cbject_TypeInstanceImpl_case_bindFuns(typeName, superTypeName, ...)                                               \
    Cbject_TypeInstanceFunPrototype(typeName)                                                                             \
    {                                                                                                                     \
        static typeName##Type type;                                                                                       \
                                                                                                                          \
        typedef struct ObjectTypeT                                                                                        \
        {                                                                                                                 \
            Cbject_Settings_maxAlign align;                                                                               \
            char const * name;                                                                                            \
            ObjectType * superType;                                                                                       \
            ObjectVirtFuns virtFuns;                                                                                      \
        } ObjectTypeT;                                                                                                    \
                                                                                                                          \
        if (((ObjectTypeT *)&type)->name == NULL)                                                                         \
        {                                                                                                                 \
            /*static char const * const name = #typeName;  */                                                             \
            *((superTypeName##TypeContainer *)&type) = *((superTypeName##TypeContainer *)superTypeName##Type_instance()); \
            ((ObjectTypeT *)&type)->name = NULL;                                                                          \
            ((ObjectTypeT *)&type)->virtFuns.size = (uint8(*)(Object const * const me))super_##typeName##_size;           \
            Cbject_Utils_forEach(Cbject_TypeInstanceImpl_stripParenthesesAndApplyBindFun, __VA_ARGS__);                   \
            ((ObjectTypeT *)&type)->name = #typeName;                                                                     \
            ((ObjectTypeT *)&type)->superType = (ObjectType *)superTypeName##Type_instance();                             \
        }                                                                                                                 \
                                                                                                                          \
        return &type;                                                                                                     \
    }

#define Cbject_TypeInstanceImpl_switch(typeName, superTypeName, case, ...) \
    Cbject_TypeInstanceImpl_case_##case (typeName, superTypeName, __VA_ARGS__)

#define Cbject_TypeInstanceImpl_x1(typeName, superTypeName, ...) \
    Cbject_TypeInstanceImpl_switch(typeName, superTypeName, __VA_ARGS__)

#define Cbject_TypeInstanceImpl(typeName, superTypeName, bindFuns) \
    Cbject_TypeInstanceImpl_x1(typeName, superTypeName, Cbject_Utils_stripParentheses(bindFuns))

#endif // CBJECT_TYPEINSTANCEIMPL_H
