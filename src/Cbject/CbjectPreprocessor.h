#ifndef CBJECTPREPROCESSOR_H
#define CBJECTPREPROCESSOR_H
#include "CbjectSettings.h"
#include "CbjectUtilities.h"
#include "Primitives.h"

#define CbjectPreprocessor_params(className, superClassName, ...)                                                      \
    typedef struct className className;                                                  \
                                                                                         \
    typedef struct className##Params                                                     \
    {                        \
        superClassName##Params super; \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, __VA_ARGS__)                                       \
    } className##Params;                                                                 \
                                                                                         \
    void className##_init(className * const me, className##Params const * const params); \
    void className##_terminate(className * const me)

#define CbjectPreprocessor_getCbjectDecl(className) className * get_##className(className##Params const * const params)
#define CbjectPreprocessor_newCbjectDecl(className) className * new_##className(className##Params const * const params)
#define CbjectPreprocessor_deleteCbjectDecl(className) className * delete_##className(className * me)

#define CbjectPreprocessor_acp_(className, superClassName, ...)  CbjectPreprocessor_params(className, superClassName, __VA_ARGS__)
#define CbjectPreprocessor_acp(className, superClassName, ...)  CbjectPreprocessor_acp_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_op_(className, superClassName, ...)         \
    CbjectPreprocessor_params(className, superClassName, __VA_ARGS__); \
    className * className##_instance()
#define CbjectPreprocessor_op(className, superClassName, ...) CbjectPreprocessor_op_(className, superClassName, __VA_ARGS__)

#if Cbject_useStaticPool == true
    #if Cbject_useHeap == true
        #define CbjectPreprocessor_cp_(className, superClassName, ...)         \
            CbjectPreprocessor_params(className, superClassName, __VA_ARGS__); \
            uint8 className##Class_size();      \
            CbjectPreprocessor_getCbjectDecl(className);       \
            CbjectPreprocessor_newCbjectDecl(className);       \
            CbjectPreprocessor_deleteCbjectDecl(className)
    #else
        #define CbjectPreprocessor_cp_(className, superClassName, ...)         \
            CbjectPreprocessor_params(className, superClassName, __VA_ARGS__); \
            uint8 className##Class_size();      \
            CbjectPreprocessor_getCbjectDecl(className)
    #endif
#else
    #if Cbject_useHeap == true
        #define CbjectPreprocessor_cp_(className, superClassName, ...)         \
            CbjectPreprocessor_params(className, superClassName, __VA_ARGS__); \
            uint8 className##Class_size();      \
            CbjectPreprocessor_newCbjectDecl(className);       \
            CbjectPreprocessor_deleteCbjectDecl(className)
    #else
        #define CbjectPreprocessor_cp_(className, superClassName, ...)         \
            CbjectPreprocessor_params(className, superClassName, __VA_ARGS__); \
            uint8 className##Class_size()
    #endif
#endif
#define CbjectPreprocessor_cp(className, superClassName, ...) CbjectPreprocessor_cp_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_cps_(className, poolSize)   \
    enum                                \
    {                                   \
        className##_poolSize = poolSize \
    }
#define CbjectPreprocessor_cps(className, poolSize) CbjectPreprocessor_cps_(className, poolSize)

#define CbjectPreprocessor_class(className, superClassName) \
    typedef struct className##Class          \
    {                                        \
        superClassName##Class super;                                                    \
    } className##Class;                      \
                                             \
    className##Class const * const className##Class_instance()

#define CbjectPreprocessor_members(className, superClassName, ...) \
    struct className                                \
    {      \
        superClassName##Shell super; \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, __VA_ARGS__)  \
    }

#define CbjectPreprocessor_cm_(className, superClassName, ...)          \
    CbjectPreprocessor_members(className, superClassName, __VA_ARGS__); \
    CbjectPreprocessor_class(className, superClassName)
#define CbjectPreprocessor_cm(className, superClassName, ...) CbjectPreprocessor_cm_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_cd_(className, superClassName, ...) \
typedef union className##Shell  \
{ \
    char d[sizeof(struct{ superClassName##Shell super; CbjectUtilities_forEach(CbjectUtilities_addSemicolon, __VA_ARGS__) })]; \
    maxAlign a; \
} className##Shell
#define CbjectPreprocessor_cd(className, superClassName, ...) CbjectPreprocessor_cd_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_c_(className, type, ...) type const className##_##__VA_ARGS__
#define CbjectPreprocessor_c(className, type, ...) CbjectPreprocessor_c_(className, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyConstant(constSignature) Constant constSignature;

#define CbjectPreprocessor_pbc_(className, type, constName) extern type const className##_##constName
#define CbjectPreprocessor_pbc(className, type, constName) CbjectPreprocessor_pbc_(className, type, constName)
#define CbjectPreprocessor_stripParenthesesAndApplyPublicConstant(constSignature) PublicConstant constSignature;

#define CbjectPreprocessor_pc_(className, type, ...) static type const className##_##__VA_ARGS__
#define CbjectPreprocessor_pc(className, type, ...) CbjectPreprocessor_pc_(className, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant(constSignature) PrivateConstant constSignature;

#define CbjectPreprocessor_acm_(className, superClassName, ...) CbjectPreprocessor_members(className, superClassName, __VA_ARGS__)
#define CbjectPreprocessor_acm(className, superClassName, ...) CbjectPreprocessor_acm_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_dc_(className, ...)                    \
    typedef struct className                       \
    {                                              \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } className
#define CbjectPreprocessor_dc(className, ...) CbjectPreprocessor_dc_(className, __VA_ARGS__)

#define CbjectPreprocessor_pcnaac__(className, valueName) className##_##valueName,
#define CbjectPreprocessor_pcnaac_(className, valueName) CbjectPreprocessor_pcnaac__(className, valueName)
#define CbjectPreprocessor_prependClassNameAndAddComma(valueName) CbjectPreprocessor_pcnaac_(class, valueName)

#define CbjectPreprocessor_ec_(className, ...)                                   \
    typedef enum className                                        \
    {                                                             \
        CbjectUtilities_forEach(CbjectPreprocessor_prependClassNameAndAddComma, __VA_ARGS__) \
    } className
#define CbjectPreprocessor_ec(className, ...) CbjectPreprocessor_ec_(className, __VA_ARGS__)

#define CbjectPreprocessor_f_(className, type, functionName, arguments) \
    type className##_##functionName(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))
#define CbjectPreprocessor_f(className, type, functionName, arguments) CbjectPreprocessor_f_(className, type, functionName, arguments)
#define CbjectPreprocessor_stripParenthesesAndApplyFunction(funSignature) Function funSignature;

#define CbjectPreprocessor_pf_(className, type, functionName, arguments) \
    static type className##_##functionName(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))
#define CbjectPreprocessor_pf(className, type, functionName, arguments) CbjectPreprocessor_pf_(className, type, functionName, arguments)
#define CbjectPreprocessor_stripParenthesesAndApplyPrivateFunction(funSignature) PrivateFunction funSignature;

#define CbjectPreprocessor_vfp__(className, type, functionName, arguments) \
    type (*functionName)(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))
#define CbjectPreprocessor_vfp_(className, type, functionName, arguments) CbjectPreprocessor_vfp__(className, type, functionName, arguments)
#define CbjectPreprocessor_vfp(type, functionName, arguments) CbjectPreprocessor_vfp_(class, type, functionName, arguments)
#define CbjectPreprocessor_stripParenthesesAndApplyVirtualFunctionPointer(funSignature) CbjectPreprocessor_vfp funSignature;

#define CbjectPreprocessor_virtualCall(className, functionName, params) \
    return ((className##Class *)Cbject_class((Cbject *)me))->vf.functionName(me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(params)))

#define CbjectPreprocessor_superFunctions__(className, type, functionName, arguments) \
    type super##className##_##functionName(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))
#define CbjectPreprocessor_superFunctions_(className, type, functionName, arguments) CbjectPreprocessor_superFunctions__(className, type, functionName, arguments)
#define CbjectPreprocessor_superFunctions(type, functionName, arguments) CbjectPreprocessor_superFunctions_(class, type, functionName, arguments)
#define CbjectPreprocessor_stripParenthesesAndApplySuperFunction(funSignature) CbjectPreprocessor_superFunctions funSignature;

#define CbjectPreprocessor_vf_(className, type, functionName, arguments, params)                                          \
    CbjectPreprocessor_f_(className, type, functionName, arguments) { CbjectPreprocessor_virtualCall(className, functionName, params); } \
    CbjectPreprocessor_superFunctions__(className, type, functionName, arguments)
#define CbjectPreprocessor_vf(className, type, functionName, arguments, params) CbjectPreprocessor_vf_(className, type, functionName, arguments, params)

#define CbjectPreprocessor_vfs_(className, superClassName, ...)                                         \
    typedef struct className##Class                                                      \
    {                                                                                    \
        superClassName##Class super;                                                    \
                                                                                         \
        struct                                                                           \
        {                                                                                \
            CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyVirtualFunctionPointer, __VA_ARGS__) \
        } vf;                                                                            \
    } className##Class;                                                                  \
                                                                                         \
    className##Class const * const className##Class_instance();                          \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplySuperFunction, __VA_ARGS__)
#define CbjectPreprocessor_vfs(className, superClassName, ...) CbjectPreprocessor_vfs_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_expandSetter_(className, type, memberName)                                         \
    void className##_##memberName##Set(className * const me, type const memberName)
#define CbjectPreprocessor_expandSetter(className, type, memberName) CbjectPreprocessor_expandSetter_(className, type, memberName)
#define CbjectPreprocessor_stripParenthesesAndApplySetter(memberSignature) Setter memberSignature;

#define CbjectPreprocessor_expandGetter_(className, type, memberName)                                         \
    type className##_##memberName(className const * const me)
#define CbjectPreprocessor_expandGetter(className, type, memberName) CbjectPreprocessor_expandGetter_(className, type, memberName)
#define CbjectPreprocessor_stripParenthesesAndApplyGetter(memberSignature) Getter memberSignature;

#define CbjectPreprocessor_expandDefaultSetter_(className, type, memberName) \
    void className##_##memberName##Set(className * const me, type const memberName) { me->memberName = memberName; }
#define CbjectPreprocessor_expandDefaultSetter(className, type, memberName) CbjectPreprocessor_expandDefaultSetter_(className, type, memberName)

#define CbjectPreprocessor_expandDefaultGetter_(className, type, memberName) \
    type className##_##memberName(className const * const me) { return me->memberName; }
#define CbjectPreprocessor_expandDefaultGetter(className, type, memberName) CbjectPreprocessor_expandDefaultGetter_(className, type, memberName)

#define CbjectPreprocessor_stripParenthesesAndApplyDefaultSetter(memberSignature) DefaultSetter memberSignature
#define CbjectPreprocessor_stripParenthesesAndApplyDefaultGetter(memberSignature) DefaultGetter memberSignature

#define CbjectPreprocessor_of_(className, type, superClassName, functionName, arguments) \
    type super##className##_##functionName(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))
#define CbjectPreprocessor_of(className, type, superClassName, functionName, arguments) CbjectPreprocessor_of_(className, type, superClassName, functionName, arguments)
#define CbjectPreprocessor_stripParenthesesAndApplyOverrideFunction(funSignature) OverrideFunction funSignature;

#define CbjectPreprocessor_i_(className, superClassName, ...)                                           \
    void className##_init(className * const me, className##Params const * const params)  \
    {                                                                                    \
        superClassName##_init((superClassName *) me, (superClassName##Params *) params); \
        /*if (#superClassName == "Cbject") { Cbject_init((Cbject *) me, null); }*/ \
                                                                                         \
        do                                                                               \
            __VA_ARGS__                                                                  \
        while (0);                                                                       \
                                                                                         \
        /*((Cbject *) me)->c = (CbjectClass *) className##Class_instance(); */               \
        Cbject_classSet((Cbject *) me, (CbjectClass *) className##Class_instance());  \
    }
#define CbjectPreprocessor_i(className, superClassName, ...) CbjectPreprocessor_i_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_t_(className, superClassName, ...)                   \
    void className##_terminate(className * const me)             \
    {                                                            \
        do                                                       \
            __VA_ARGS__                                          \
        while (0);                                               \
                                                                 \
        superClassName##_terminate((superClassName * const) me); \
    }
#define CbjectPreprocessor_t(className, superClassName, ...) CbjectPreprocessor_t_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_classInstanceImpl(className, superClassName, ...)                                         \
    className##Class const * const className##Class_instance()                                        \
    {                                                                                                 \
        static className##Class c;                                                                    \
                                                                                                      \
        if (((CbjectClass *) &c)->type == null)                                                       \
        {                                                                                             \
            static char const * const type = #className;                                              \
            *((superClassName##Class *) &c) = *superClassName##Class_instance();                    \
            ((CbjectClass *) &c)->vf.size = (uint8(*)(Cbject const * const me)) override_Cbject_size; \
                                                                                                      \
            do                                                                                        \
                __VA_ARGS__                                                                           \
            while (0);                                                                                \
                                                                                                      \
            ((CbjectClass *) &c)->type = type;                                                        \
        }                                                                                             \
                                                                                                      \
        return &c;                                                                                    \
    }

#define CbjectPreprocessor_getCbjectImpl(className)                                    \
    className * get_##className(className##Params const * const params) \
    {                                                                   \
        static className pool[className##_poolSize];                    \
        static uint64 count = 0;                                        \
        className * me = null;                                          \
                                                                        \
        if (count < className##_poolSize)                               \
        {                                                               \
            me = &pool[count];                                          \
            className##_init(me, params);                               \
            count++;                                                    \
        }                                                               \
                                                                        \
        return me;                                                      \
    }

#define CbjectPreprocessor_newCbjectImpl(className)                                    \
    className * new_##className(className##Params const * const params) \
    {                                                                   \
        className * me = (className *) malloc(sizeof(className));       \
        assert((me != null) && "Heap memory allocation failed");        \
        className##_init(me, params);                                   \
        return me;                                                      \
    }

#define CbjectPreprocessor_deleteCbjectImpl(className)            \
    className * delete_##className(className * me) \
    {                                              \
        className##_terminate(me);                 \
        free(me);                                  \
    }

#define CbjectPreprocessor_acs_(className, superClassName, ...)                                          \
    static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
    CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__)
#define CbjectPreprocessor_acs(className, superClassName, ...) CbjectPreprocessor_acs_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_os_(className, superClassName, ...)                                           \
    className * className##_instance()                                                    \
    {                                                                                     \
        static className singleton;                                                       \
        return &singleton;                                                                \
    }                                                                                     \
                                                                                          \
    static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
    CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__)
#define CbjectPreprocessor_os(className, superClassName, ...) CbjectPreprocessor_os_(className, superClassName, __VA_ARGS__)

#if Cbject_useStaticPool == true
    #if Cbject_useHeap == true
        #include <stdlib.h>
        #define CbjectPreprocessor_cs_(className, superClassName, ...)                                           \
            static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__);                        \
            CbjectPreprocessor_getCbjectImpl(className);                                                         \
            CbjectPreprocessor_newCbjectImpl(className);                                                         \
            CbjectPreprocessor_deleteCbjectImpl(className);                                                      \
            uint8 className##Class_size() { return sizeof(className); }
    #else
        #define CbjectPreprocessor_cs_(className, superClassName, ...)                                           \
            static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__);                        \
            CbjectPreprocessor_getCbjectImpl(className);                                                         \
            uint8 className##Class_size() { return sizeof(className); }
    #endif
#else
    #if Cbject_useHeap == true
        #include <stdlib.h>
        #define CbjectPreprocessor_cs_(className, superClassName, ...)                                           \
            static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__);                        \
            CbjectPreprocessor_newCbjectImpl(className);                                                         \
            CbjectPreprocessor_deleteCbjectImpl(className);                                                      \
            uint8 className##Class_size() { return sizeof(className); }
    #else
        #define CbjectPreprocessor_cs_(className, superClassName, ...)                                           \
            static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__);                        \
            uint8 className##Class_size() { return sizeof(className); }
    #endif
#endif
#define CbjectPreprocessor_cs(className, superClassName, ...) CbjectPreprocessor_cs_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_bvf_(className, functionName) \
    c.vf.functionName = super##className##_##functionName;
#define CbjectPreprocessor_bvf(className, functionName) CbjectPreprocessor_bvf_(className, functionName)

#define CbjectPreprocessor_bof_(className, type, superClassName, functionName, arguments) \
    ((superClassName##Class *) &c)->vf.functionName = (type(*)(superClassName * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))) super##className##_##functionName
#define CbjectPreprocessor_bof(className, type, superClassName, functionName, arguments) CbjectPreprocessor_bof_(className, type, superClassName, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyBindFunction(funSignature) BindFunction funSignature;

#endif // CBJECTPREPROCESSOR_H
