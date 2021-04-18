#ifndef CBJECTPREPROCESSOR_H
#define CBJECTPREPROCESSOR_H
#include "CbjectSettings.h"
#include "CbjectUtilities.h"
#include "Primitives.h"

#define CbjectPreprocessor_initParamsStructDefinition(className, superClassName, ...) \
    struct className##InitParams                                                      \
    {                                                                                 \
        superClassName##InitParams super;                                             \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, ##__VA_ARGS__)          \
    }

#define CbjectPreprocessor_initParamsTypeDefinition(className, superClassName, ...) \
    typedef CbjectPreprocessor_initParamsStructDefinition(className, superClassName, ##__VA_ARGS__) className##InitParams

#define CbjectPreprocessor_membersStructDefinition(className, superClassName, ...) \
    struct className##Members                                                      \
    {                                                                              \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, ##__VA_ARGS__)       \
    }

#define CbjectPreprocessor_membersTypeDefinition(className, superClassName, ...) \
    typedef CbjectPreprocessor_membersStructDefinition(className, superClassName, ##__VA_ARGS__) className##Members

#define CbjectPreprocessor_shellStructDefinition(className, superClassName) \
    union className##Shell                                                  \
    {                                                                       \
        char d[sizeof(struct { superClassName##Shell super; className##Members m; })];                                         \
        maxAlign a;                                                         \
    }

#define CbjectPreprocessor_shellTypeDefinition(className, superClassName) \
    typedef CbjectPreprocessor_shellStructDefinition(className, superClassName) className##Shell

#define CbjectPreprocessor_virtualFunctionsStructDefinition(className, superClassName, ...)                       \
    struct className##ClassVirtualFunctions                                                                       \
    {                                                                                                             \
        CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyVirtualFunctionPointer, ##__VA_ARGS__) \
    }

#define CbjectPreprocessor_virtualFunctionsTypeDefinition(className, superClassName, ...) \
    typedef CbjectPreprocessor_virtualFunctionsStructDefinition(className, superClassName, ##__VA_ARGS__) className##ClassVirtualFunctions

#define CbjectPreprocessor_classTypeDefinition(className, superClassName) \
    typedef struct className##Class                                       \
    {                                                                     \
        superClassName##Class super;                                      \
        className##ClassVirtualFunctions vf;                              \
    } className##Class

#define CbjectPreprocessor_stripParenthesesAndApplyFunction(functionPrototype) Function functionPrototype;
#define CbjectPreprocessor_expandFunctions(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyFunction, ##__VA_ARGS__)

#define CbjectPreprocessor_stripParenthesesAndApplySuperFunction(functionPrototype) SuperFunction functionPrototype;
#define CbjectPreprocessor_expandSuperFunctions(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplySuperFunction, ##__VA_ARGS__)

#define CbjectPreprocessor_getCbjectDecl(className) className * get_##className(className##InitParams const * const params)
#define CbjectPreprocessor_newCbjectDecl(className) className * new_##className(className##InitParams const * const params)
#define CbjectPreprocessor_deleteCbjectDecl(className) className * delete_##className(className * me)

#if Cbject_useStaticPool == true
    #if Cbject_useHeap == true
        #define CbjectPreprocessor_expandClass_(className, superClassName, initParams, members, virtualFunctions)                                                    \
            CbjectPreprocessor_initParamsTypeDefinition(className, superClassName CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(initParams)));             \
            CbjectPreprocessor_membersTypeDefinition(className, superClassName CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(members)));                   \
            typedef struct className className;                                                                                                                      \
            CbjectPreprocessor_shellTypeDefinition(className, superClassName);                                                                                       \
            void className##_init(className * const me, className##InitParams const * const params);                                                                 \
            void className##_terminate(className * const me);                                                                                                        \
            CbjectPreprocessor_virtualFunctionsTypeDefinition(className, superClassName CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(virtualFunctions))); \
            CbjectPreprocessor_classTypeDefinition(className, superClassName);                                                                                       \
            className##Class const * const className##Class_instance();                                                                                              \
            SuperFunctions(CbjectUtilities_stripParentheses(virtualFunctions));                                                                                      \
            Functions(CbjectUtilities_stripParentheses(virtualFunctions));                                                                                           \
            uint8 className##Class_size();                                                                                                                           \
            CbjectPreprocessor_getCbjectDecl(className);                                                                                                             \
            CbjectPreprocessor_newCbjectDecl(className);                                                                                                             \
            CbjectPreprocessor_deleteCbjectDecl(className)
    #else
        #define CbjectPreprocessor_expandClass_(className, superClassName, initParams, members)                                   \
            CbjectPreprocessor_initParamsTypeDefinition(className, superClassName, CbjectUtilities_stripParentheses(initParams)); \
            CbjectPreprocessor_membersTypeDefinition(className, CbjectUtilities_stripParentheses(members));                       \
            typedef struct className className;                                                                                   \
            CbjectPreprocessor_shellTypeDefinition(className, superClassName);                                                    \
            void className##_init(className * const me, className##InitParams const * const params);                              \
            void className##_terminate(className * const me);                                                                     \
            uint8 className##Class_size();                                                                                        \
            CbjectPreprocessor_getCbjectDecl(className)
    #endif
#else
    #if Cbject_useHeap == true
        #define CbjectPreprocessor_expandClass_(className, superClassName, initParams, members)                                   \
            CbjectPreprocessor_initParamsTypeDefinition(className, superClassName, CbjectUtilities_stripParentheses(initParams)); \
            CbjectPreprocessor_membersTypeDefinition(className, CbjectUtilities_stripParentheses(members));                       \
            typedef struct className className;                                                                                   \
            CbjectPreprocessor_shellTypeDefinition(className, superClassName);                                                    \
            void className##_init(className * const me, className##InitParams const * const params);                              \
            void className##_terminate(className * const me);                                                                     \
            uint8 className##Class_size();                                                                                        \
            CbjectPreprocessor_newCbjectDecl(className);                                                                          \
            CbjectPreprocessor_deleteCbjectDecl(className)
    #else
        #define CbjectPreprocessor_expandClass_(className, superClassName, initParams, members)                                   \
            CbjectPreprocessor_initParamsTypeDefinition(className, superClassName, CbjectUtilities_stripParentheses(initParams)); \
            CbjectPreprocessor_membersTypeDefinition(className, CbjectUtilities_stripParentheses(members));                       \
            typedef struct className className;                                                                                   \
            CbjectPreprocessor_shellTypeDefinition(className, superClassName);                                                    \
            void className##_init(className * const me, className##InitParams const * const params);                              \
            void className##_terminate(className * const me);                                                                     \
            uint8 className##Class_size()
    #endif
#endif
#define CbjectPreprocessor_expandClass(className, superClassName, initParams, members, virtualFunctions) \
    CbjectPreprocessor_expandClass_(className, superClassName, initParams, members, virtualFunctions)

#define CbjectPreprocessor_expandClassNew(className, superClassName, initParams, members, virtualFunctions, functions) \
    CbjectPreprocessor_expandClassNew_(className, superClassName, initParams, members, virtualFunctions, functions)

#define CbjectPreprocessor_expandAbstractClass_(className, superClassName, initParams, members, virtualFunctions)                                            \
    CbjectPreprocessor_membersTypeDefinition(className, superClassName CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(members)));                   \
    CbjectPreprocessor_initParamsTypeDefinition(className, superClassName CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(initParams)));             \
    typedef struct className className;                                                                                                                      \
    CbjectPreprocessor_shellTypeDefinition(className, superClassName);                                                                                       \
    void className##_init(className * const me, className##InitParams const * const params);                                                                 \
    void className##_terminate(className * const me);                                                                                                        \
    CbjectPreprocessor_virtualFunctionsTypeDefinition(className, superClassName CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(virtualFunctions))); \
    CbjectPreprocessor_classTypeDefinition(className, superClassName);                                                                                       \
    className##Class const * const className##Class_instance();                                                                                              \
    SuperFunctions(CbjectUtilities_stripParentheses(virtualFunctions));                                                                                      \
    Functions(CbjectUtilities_stripParentheses(virtualFunctions))
#define CbjectPreprocessor_expandAbstractClass(className, superClassName, initParams, members, virtualFunctions) \
    CbjectPreprocessor_expandAbstractClass_(className, superClassName, initParams, members, virtualFunctions)

#define CbjectPreprocessor_expandSingleton_(className, superClassName, initParams, members)                                                      \
    CbjectPreprocessor_initParamsTypeDefinition(className, superClassName CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(initParams))); \
    CbjectPreprocessor_membersTypeDefinition(className, superClassName CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(members)));       \
    typedef struct className className;                                                                                                          \
    CbjectPreprocessor_shellTypeDefinition(className, superClassName);                                                                           \
    void className##_init(className * const me, className##InitParams const * const params);                                                     \
    void className##_terminate(className * const me);                                                                                            \
    className * className##_instance()
#define CbjectPreprocessor_expandSingleton(className, superClassName, initParams, members) \
    CbjectPreprocessor_expandSingleton_(className, superClassName, initParams, members)

#define CbjectPreprocessor_expandInitParams_(className, superClassName, ...) \
    CbjectPreprocessor_initParamsTypeDefinition(className, superClassName, __VA_ARGS__)
#define CbjectPreprocessor_expandInitParams(className, superClassName, ...) CbjectPreprocessor_expandInitParams_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_expandPoolSize_(className, poolSize) \
    enum                                                        \
    {                                                           \
        className##_poolSize = poolSize                         \
    }
#define CbjectPreprocessor_expandPoolSize(className, poolSize) CbjectPreprocessor_expandPoolSize_(className, poolSize)

#define CbjectPreprocessor_class(className, superClassName) \
    typedef struct className##Class                         \
    {                                                       \
        superClassName##Class super;                        \
    } className##Class;                                     \
                                                            \
    className##Class const * const className##Class_instance()

#define CbjectPreprocessor_members(className, superClassName) \
    struct className                                          \
    {                                                         \
        superClassName##Shell super;                          \
        className##Members m;                                 \
    }

#define CbjectPreprocessor_cm_(className, superClassName)  \
    CbjectPreprocessor_members(className, superClassName); \
    // CbjectPreprocessor_class(className, superClassName)
#define CbjectPreprocessor_cm(className, superClassName) CbjectPreprocessor_cm_(className, superClassName)

#define CbjectPreprocessor_c_(className, type, ...) type const className##_##__VA_ARGS__
#define CbjectPreprocessor_c(className, type, ...) CbjectPreprocessor_c_(className, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyConstant(constPrototype) Constant constPrototype;

#define CbjectPreprocessor_pbc_(className, type, constName) extern type const className##_##constName
#define CbjectPreprocessor_pbc(className, type, constName) CbjectPreprocessor_pbc_(className, type, constName)
#define CbjectPreprocessor_stripParenthesesAndApplyPublicConstant(constPrototype) PublicConstant constPrototype;

#define CbjectPreprocessor_pc_(className, type, ...) static type const className##_##__VA_ARGS__
#define CbjectPreprocessor_pc(className, type, ...) CbjectPreprocessor_pc_(className, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant(constPrototype) PrivateConstant constPrototype;

#define CbjectPreprocessor_expandAbstractClassMembers_(className, superClassName) \
    CbjectPreprocessor_members(className, superClassName)
#define CbjectPreprocessor_expandAbstractClassMembers(className, superClassName) CbjectPreprocessor_expandAbstractClassMembers_(className, superClassName)

#define CbjectPreprocessor_expandDataClassMembers_(className, ...)         \
    typedef struct className                                               \
    {                                                                      \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } className
#define CbjectPreprocessor_expandDataClassMembers(className, ...) \
    CbjectPreprocessor_expandDataClassMembers_(className, __VA_ARGS__)

#define CbjectPreprocessor_pcnaac__(className, valueName) className##_##valueName,
#define CbjectPreprocessor_pcnaac_(className, valueName) CbjectPreprocessor_pcnaac__(className, valueName)
#define CbjectPreprocessor_prependClassNameAndAddComma(valueName) CbjectPreprocessor_pcnaac_(class, valueName)

#define CbjectPreprocessor_expandEnumClassMembers_(className, ...)                           \
    typedef enum className                                                                   \
    {                                                                                        \
        CbjectUtilities_forEach(CbjectPreprocessor_prependClassNameAndAddComma, __VA_ARGS__) \
    } className
#define CbjectPreprocessor_expandEnumClassMembers(className, ...) CbjectPreprocessor_expandEnumClassMembers_(className, __VA_ARGS__)

#define CbjectPreprocessor_functionPrototype(className, returnType, functionName, arguments) \
    returnType className##_##functionName(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))
#define CbjectPreprocessor_expandFunction(className, returnType, functionName, arguments) CbjectPreprocessor_functionPrototype(className, returnType, functionName, arguments)

#define CbjectPreprocessor_privateFunctionPrototype(className, returnType, functionName, arguments) \
    static CbjectPreprocessor_functionPrototype(className, returnType, functionName, arguments)
#define CbjectPreprocessor_expandPrivateFunction(className, returnType, functionName, arguments) CbjectPreprocessor_privateFunctionPrototype(className, returnType, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyPrivateFunction(functionPrototype) PrivateFunction functionPrototype;
#define CbjectPreprocessor_expandPrivateFunctions(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateFunction, __VA_ARGS__)

#define CbjectPreprocessor_virtualFunctionPointer(className, type, functionName, arguments) \
    type (*functionName)(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))

#define CbjectPreprocessor_expandVirtualFunctionPointer(type, functionName, arguments) \
    CbjectPreprocessor_virtualFunctionPointer(class, type, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyVirtualFunctionPointer(functionPrototype) \
    CbjectPreprocessor_expandVirtualFunctionPointer functionPrototype;

#define CbjectPreprocessor_virtualCall(className, functionName, params) \
    return ((className##Class *) Cbject_class((Cbject *) me))->vf.functionName(me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(params)))

#define CbjectPreprocessor_superFunctionPrototype(className, type, functionName, arguments) \
    type super##className##_##functionName(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))

#define CbjectPreprocessor_superFunctions_(className, type, functionName, arguments) \
    CbjectPreprocessor_superFunctionPrototype(className, type, functionName, arguments)

#define CbjectPreprocessor_superFunctions(type, functionName, arguments) \
    CbjectPreprocessor_superFunctions_(class, type, functionName, arguments)
// #define CbjectPreprocessor_stripParenthesesAndApplySuperFunction(functionPrototype) CbjectPreprocessor_superFunctions functionPrototype;

#define CbjectPreprocessor_expandSuperFunction(className, returnType, functionName, arguments) \
    CbjectPreprocessor_superFunctionPrototype(className, returnType, functionName, arguments)

#define CbjectPreprocessor_virtualFunctionPrototype(className, returnType, functionName, arguments, params)                                                   \
    CbjectPreprocessor_functionPrototype(className, returnType, functionName, arguments) { CbjectPreprocessor_virtualCall(className, functionName, params); } \
    CbjectPreprocessor_superFunctionPrototype(className, returnType, functionName, arguments)
#define CbjectPreprocessor_expandVirtualFunction(className, returnType, functionName, arguments, params) CbjectPreprocessor_virtualFunctionPrototype(className, returnType, functionName, arguments, params)

#define CbjectPreprocessor_setterFunctionPrototype(className, type, memberName) \
    void className##_##memberName##Set(className * const me, type const memberName)
#define CbjectPreprocessor_expandSetter(className, type, memberName) CbjectPreprocessor_setterFunctionPrototype(className, type, memberName)

#define CbjectPreprocessor_stripParenthesesAndApplySetter(memberPrototype) Setter memberPrototype;
#define CbjectPreprocessor_expandSetters(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplySetter, __VA_ARGS__)

#define CbjectPreprocessor_getterFunctionPrototype(className, type, memberName) \
    type className##_##memberName(className const * const me)
#define CbjectPreprocessor_expandGetter(className, type, memberName) CbjectPreprocessor_getterFunctionPrototype(className, type, memberName)

#define CbjectPreprocessor_stripParenthesesAndApplyGetter(memberPrototype) Getter memberPrototype;
#define CbjectPreprocessor_expandGetters(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyGetter, __VA_ARGS__)

#define CbjectPreprocessor_expandDefaultSetter_(className, type, memberName) \
    void className##_##memberName##Set(className * const me, type const memberName) { me->m.memberName = memberName; }
#define CbjectPreprocessor_expandDefaultSetter(className, type, memberName) CbjectPreprocessor_expandDefaultSetter_(className, type, memberName)

#define CbjectPreprocessor_expandDefaultGetter_(className, type, memberName) \
    type className##_##memberName(className const * const me) { return me->m.memberName; }
#define CbjectPreprocessor_expandDefaultGetter(className, type, memberName) CbjectPreprocessor_expandDefaultGetter_(className, type, memberName)

#define CbjectPreprocessor_stripParenthesesAndApplyDefaultSetter(memberPrototype) DefaultSetter memberPrototype
#define CbjectPreprocessor_stripParenthesesAndApplyDefaultGetter(memberPrototype) DefaultGetter memberPrototype

#define CbjectPreprocessor_of_(className, type, superClassName, functionName, arguments) \
    type super##className##_##functionName(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))
#define CbjectPreprocessor_of(className, type, superClassName, functionName, arguments) CbjectPreprocessor_of_(className, type, superClassName, functionName, arguments)

#define CbjectPreprocessor_expandOverrideFunctionNew_(className, superClassName, type, functionName, arguments) \
    type super##className##_##functionName(className * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))

#define CbjectPreprocessor_expandOverrideFunctionNew(class, superClassName, ...) \
    CbjectPreprocessor_expandOverrideFunctionNew_(class, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_stripParenthesesAndApplyOverrideFunction(functionPrototype) OverrideFunction functionPrototype;

#define CbjectPreprocessor_i_(className, superClassName, ...)                                \
    void className##_init(className * const me, className##InitParams const * const params)  \
    {                                                                                        \
        superClassName##_init((superClassName *) me, (superClassName##InitParams *) params); \
        /*if (#superClassName == "Cbject") { Cbject_init((Cbject *) me, null); }*/           \
                                                                                             \
        do                                                                                   \
            __VA_ARGS__                                                                      \
        while (0);                                                                           \
                                                                                             \
        /*((Cbject *) me)->c = (CbjectClass *) className##Class_instance(); */               \
        Cbject_classSet((Cbject *) me, (CbjectClass *) className##Class_instance());         \
    }
#define CbjectPreprocessor_i(className, superClassName, ...) CbjectPreprocessor_i_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_t_(className, superClassName, ...)    \
    void className##_terminate(className * const me)             \
    {                                                            \
        do                                                       \
            __VA_ARGS__                                          \
        while (0);                                               \
                                                                 \
        superClassName##_terminate((superClassName * const) me); \
    }
#define CbjectPreprocessor_t(className, superClassName, ...) CbjectPreprocessor_t_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_classInstanceImpl(className, superClassName, ...)                          \
    className##Class const * const className##Class_instance()                                        \
    {                                                                                                 \
        static className##Class c;                                                                    \
                                                                                                      \
        if (((CbjectClass *) &c)->type == null)                                                       \
        {                                                                                             \
            static char const * const type = #className;                                              \
            *((superClassName##Class *) &c) = *superClassName##Class_instance();                      \
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

#define CbjectPreprocessor_getCbjectImpl(className)                         \
    className * get_##className(className##InitParams const * const params) \
    {                                                                       \
        static className pool[className##_poolSize];                        \
        static uint64 count = 0;                                            \
        className * me = null;                                              \
                                                                            \
        if (count < className##_poolSize)                                   \
        {                                                                   \
            me = &pool[count];                                              \
            className##_init(me, params);                                   \
            count++;                                                        \
        }                                                                   \
                                                                            \
        return me;                                                          \
    }

#define CbjectPreprocessor_newCbjectImpl(className)                         \
    className * new_##className(className##InitParams const * const params) \
    {                                                                       \
        className * me = (className *) malloc(sizeof(className));           \
        assert((me != null) && "Heap memory allocation failed");            \
        className##_init(me, params);                                       \
        return me;                                                          \
    }

#define CbjectPreprocessor_deleteCbjectImpl(className) \
    className * delete_##className(className * me)     \
    {                                                  \
        className##_terminate(me);                     \
        free(me);                                      \
    }

#define CbjectPreprocessor_expandAbstractClassSetup_(className, superClassName, ...)      \
    CbjectPreprocessor_members(className, superClassName);                                \
    static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
    CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__)
#define CbjectPreprocessor_expandAbstractClassSetup(className, superClassName, ...) CbjectPreprocessor_expandAbstractClassSetup_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_expandSingletonSetup_(className, superClassName, ...)          \
    CbjectPreprocessor_members(className, superClassName);                                \
    CbjectPreprocessor_class(className, superClassName);                                  \
    className * className##_instance()                                                    \
    {                                                                                     \
        static className singleton;                                                       \
        return &singleton;                                                                \
    }                                                                                     \
                                                                                          \
    static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
    CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__)
#define CbjectPreprocessor_expandSingletonSetup(className, superClassName, ...) CbjectPreprocessor_expandSingletonSetup_(className, superClassName, __VA_ARGS__)

#if Cbject_useStaticPool == true
    #if Cbject_useHeap == true
        #include <stdlib.h>
        #define CbjectPreprocessor_expandClassSetup_(className, superClassName, ...)              \
            CbjectPreprocessor_members(className, superClassName);                                \
            static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__);         \
            CbjectPreprocessor_getCbjectImpl(className);                                          \
            CbjectPreprocessor_newCbjectImpl(className);                                          \
            CbjectPreprocessor_deleteCbjectImpl(className);                                       \
            uint8 className##Class_size() { return sizeof(className); }
    #else
        #define CbjectPreprocessor_expandClassSetup_(className, superClassName, ...)              \
            static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__);         \
            CbjectPreprocessor_getCbjectImpl(className);                                          \
            uint8 className##Class_size() { return sizeof(className); }
    #endif
#else
    #if Cbject_useHeap == true
        #include <stdlib.h>
        #define CbjectPreprocessor_expandClassSetup_(className, superClassName, ...)              \
            static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__);         \
            CbjectPreprocessor_newCbjectImpl(className);                                          \
            CbjectPreprocessor_deleteCbjectImpl(className);                                       \
            uint8 className##Class_size() { return sizeof(className); }
    #else
        #define CbjectPreprocessor_expandClassSetup_(className, superClassName, ...)              \
            static uint8 override_Cbject_size(className const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_classInstanceImpl(className, superClassName, __VA_ARGS__);         \
            uint8 className##Class_size() { return sizeof(className); }
    #endif
#endif
#define CbjectPreprocessor_expandClassSetup(className, superClassName, ...) CbjectPreprocessor_expandClassSetup_(className, superClassName, __VA_ARGS__)

#define CbjectPreprocessor_bvf_(className, functionName) \
    c.vf.functionName = super##className##_##functionName;
#define CbjectPreprocessor_bvf(className, functionName) CbjectPreprocessor_bvf_(className, functionName)

#define CbjectPreprocessor_bof_(className, type, superClassName, functionName, arguments) \
    ((superClassName##Class *) &c)->vf.functionName = (type(*)(superClassName * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))) super##className##_##functionName
#define CbjectPreprocessor_bof(className, type, superClassName, functionName, arguments) CbjectPreprocessor_bof_(className, type, superClassName, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyBindFunction(functionPrototype) BindFunction functionPrototype;

#endif // CBJECTPREPROCESSOR_H
