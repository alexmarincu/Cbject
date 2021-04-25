#ifndef CBJECTPREPROCESSOR_H
#define CBJECTPREPROCESSOR_H
#include "CbjectFunction.h"
#include "CbjectSettings.h"
#include "CbjectUtilities.h"
#include "Primitives.h"
#include "CbjectPropertiesTypeDefinition.h"
#include "CbjectInitParamsTypeDefinition.h"
#include "CbjectShellTypeDefinition.h"
#include "CbjectVirtualFunctionsTypeDefinition.h"
#include "CbjectKlassTypeDefinition.h"






#define CbjectPreprocessor_virtualFunctionPointer0(klassName, returnType, functionName, ...) \
    returnType (*functionName)(klassName * const me)
#define CbjectPreprocessor_virtualFunctionPointer_(klassName, returnType, functionName, ...) \
    returnType (*functionName)(klassName * const me, __VA_ARGS__)
#define CbjectPreprocessor_virtualFunctionPointer(klassName, returnType, functionName, case, ...) \
    CbjectPreprocessor_virtualFunctionPointer##case (klassName, returnType, functionName, __VA_ARGS__)
#define CbjectVirtualFunctionPointer(klassName, type, functionName, ...) \
    CbjectPreprocessor_virtualFunctionPointer(klassName, type, functionName, __VA_ARGS__)

#define CbjectPreprocessor_VirtualFunctionPointer(returnType, functionName, arguments) \
    CbjectVirtualFunctionPointer(klass, returnType, functionName, CbjectUtilities_stripParentheses(arguments))

#define CbjectPreprocessor_stripParenthesesAndApplyVirtualFunctionPointer(functionPrototype) \
    CbjectPreprocessor_VirtualFunctionPointer functionPrototype;





#define CbjectPreprocessor_getCbjectDecl(klassName) klassName * get_##klassName(klassName##InitParams const * const params)
#define CbjectPreprocessor_newCbjectDecl(klassName) klassName * new_##klassName(klassName##InitParams const * const params)
#define CbjectPreprocessor_deleteCbjectDecl(klassName) klassName * delete_##klassName(klassName * me)

#if CbjectSettings_useStaticPool == true
    #if CbjectSettings_useHeap == true
        #define CbjectPreprocessor_expandKlass_(klassName, superKlassName, initParams, properties, virtualFunctions)                 \
            CbjectInitParamsTypeDefinition(klassName, CbjectUtilities_stripParentheses(initParams)); \
            CbjectPropertiesTypeDefinition(klassName, CbjectUtilities_stripParentheses(properties));                       \
            typedef struct klassName klassName;                                                                                   \
            CbjectShellTypeDefinition(klassName, superKlassName);                                                    \
            void klassName##_init(klassName * const me, klassName##InitParams const * const params);                              \
            void klassName##_terminate(klassName * const me);                                                                     \
            CbjectVirtualFunctionsTypeDefinition(klassName, CbjectUtilities_stripParentheses(virtualFunctions));     \
            CbjectKlassTypeDefinition(klassName, superKlassName);                                                    \
            klassName##Klass const * const klassName##Klass_instance();                                                           \
            SuperFunctions(CbjectUtilities_stripParentheses(virtualFunctions));                                                   \
            Functions(CbjectUtilities_stripParentheses(virtualFunctions));                                                        \
            uint8 klassName##Klass_size();                                                                                        \
            CbjectPreprocessor_getCbjectDecl(klassName);                                                                          \
            CbjectPreprocessor_newCbjectDecl(klassName);                                                                          \
            CbjectPreprocessor_deleteCbjectDecl(klassName)
    #else
        #define CbjectPreprocessor_expandKlass_(klassName, superKlassName, initParams, properties)                                   \
            CbjectInitParamsTypeDefinition(klassName, CbjectUtilities_stripParentheses(initParams)); \
            CbjectPropertiesTypeDefinition(klassName, CbjectUtilities_stripParentheses(properties));                       \
            typedef struct klassName klassName;                                                                                   \
            CbjectShellTypeDefinition(klassName, superKlassName);                                                    \
            void klassName##_init(klassName * const me, klassName##InitParams const * const params);                              \
            void klassName##_terminate(klassName * const me);                                                                     \
            uint8 klassName##Klass_size();                                                                                        \
            CbjectPreprocessor_getCbjectDecl(klassName)
    #endif
#else
    #if CbjectSettings_useHeap == true
        #define CbjectPreprocessor_expandKlass_(klassName, superKlassName, initParams, properties)                                   \
            CbjectInitParamsTypeDefinition(klassName, CbjectUtilities_stripParentheses(initParams)); \
            CbjectPropertiesTypeDefinition(klassName, CbjectUtilities_stripParentheses(properties));                       \
            typedef struct klassName klassName;                                                                                   \
            CbjectShellTypeDefinition(klassName, superKlassName);                                                    \
            void klassName##_init(klassName * const me, klassName##InitParams const * const params);                              \
            void klassName##_terminate(klassName * const me);                                                                     \
            uint8 klassName##Klass_size();                                                                                        \
            CbjectPreprocessor_newCbjectDecl(klassName);                                                                          \
            CbjectPreprocessor_deleteCbjectDecl(klassName)
    #else
        #define CbjectPreprocessor_expandKlass_(klassName, superKlassName, initParams, properties)                                   \
            CbjectInitParamsTypeDefinition(klassName, CbjectUtilities_stripParentheses(initParams)); \
            CbjectPropertiesTypeDefinition(klassName, CbjectUtilities_stripParentheses(properties));                       \
            typedef struct klassName klassName;                                                                                   \
            CbjectShellTypeDefinition(klassName, superKlassName);                                                    \
            void klassName##_init(klassName * const me, klassName##InitParams const * const params);                              \
            void klassName##_terminate(klassName * const me);                                                                     \
            uint8 klassName##Klass_size()
    #endif
#endif
#define CbjectPreprocessor_expandKlass(klassName, superKlassName, initParams, properties, virtualFunctions) \
    CbjectPreprocessor_expandKlass_(klassName, superKlassName, initParams, properties, virtualFunctions)

#define CbjectPreprocessor_expandKlassNew(klassName, superKlassName, initParams, properties, virtualFunctions, functions) \
    CbjectPreprocessor_expandKlassNew_(klassName, superKlassName, initParams, properties, virtualFunctions, functions)


#define CbjectPreprocessor_expandSingleton_(klassName, superKlassName, initParams, properties)                               \
    CbjectInitParamsTypeDefinition(klassName, CbjectUtilities_stripParentheses(initParams)); \
    CbjectPropertiesTypeDefinition(klassName, CbjectUtilities_stripParentheses(properties));                       \
    typedef struct klassName klassName;                                                                                   \
    CbjectShellTypeDefinition(klassName, superKlassName);                                                    \
    void klassName##_init(klassName * const me, klassName##InitParams const * const params);                              \
    void klassName##_terminate(klassName * const me);                                                                     \
    klassName * klassName##_instance()
#define CbjectPreprocessor_expandSingleton(klassName, superKlassName, initParams, properties) \
    CbjectPreprocessor_expandSingleton_(klassName, superKlassName, initParams, properties)

#define CbjectPreprocessor_klass(klassName, superKlassName) \
    typedef struct klassName##Klass                         \
    {                                                       \
        superKlassName##Klass super;                        \
    } klassName##Klass;                                     \
                                                            \
    klassName##Klass const * const klassName##Klass_instance()

#define CbjectPreprocessor_properties(klassName, superKlassName) \
    struct klassName                                          \
    {                                                         \
        superKlassName##Shell super;                          \
        klassName##Properties m;                                 \
    }

#define CbjectPreprocessor_cm_(klassName, superKlassName)  \
    CbjectPreprocessor_properties(klassName, superKlassName); \
    // CbjectPreprocessor_klass(klassName, superKlassName)
#define CbjectPreprocessor_cm(klassName, superKlassName) CbjectPreprocessor_cm_(klassName, superKlassName)

#define CbjectPreprocessor_c_(klassName, type, ...) type const klassName##_##__VA_ARGS__
#define CbjectPreprocessor_c(klassName, type, ...) CbjectPreprocessor_c_(klassName, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyConstant(constPrototype) Constant constPrototype;

#define CbjectPreprocessor_pbc_(klassName, type, constName) extern type const klassName##_##constName
#define CbjectPreprocessor_pbc(klassName, type, constName) CbjectPreprocessor_pbc_(klassName, type, constName)
#define CbjectPreprocessor_stripParenthesesAndApplyPublicConstant(constPrototype) PublicConstant constPrototype;

#define CbjectPreprocessor_pc_(klassName, type, ...) static type const klassName##_##__VA_ARGS__
#define CbjectPreprocessor_pc(klassName, type, ...) CbjectPreprocessor_pc_(klassName, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant(constPrototype) PrivateConstant constPrototype;

#define CbjectAbstractKlassProperties_(klassName, superKlassName) \
    CbjectPreprocessor_properties(klassName, superKlassName)
#define CbjectAbstractKlassProperties(klassName, superKlassName) CbjectAbstractKlassProperties_(klassName, superKlassName)

#define CbjectPreprocessor_expandDataKlass_(klassName, ...)         \
    typedef struct klassName                                               \
    {                                                                      \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } klassName
#define CbjectPreprocessor_expandDataKlass(klassName, ...) \
    CbjectPreprocessor_expandDataKlass_(klassName, __VA_ARGS__)

#define CbjectPreprocessor_pcnaac__(klassName, valueName) klassName##_##valueName,
#define CbjectPreprocessor_pcnaac_(klassName, valueName) CbjectPreprocessor_pcnaac__(klassName, valueName)
#define CbjectPreprocessor_prependKlassNameAndAddComma(valueName) CbjectPreprocessor_pcnaac_(klass, valueName)

#define CbjectPreprocessor_expandEnumKlass_(klassName, ...)                           \
    typedef enum klassName                                                                   \
    {                                                                                        \
        CbjectUtilities_forEach(CbjectPreprocessor_prependKlassNameAndAddComma, __VA_ARGS__) \
    } klassName
#define CbjectPreprocessor_expandEnumKlass(klassName, ...) CbjectPreprocessor_expandEnumKlass_(klassName, __VA_ARGS__)

#define CbjectPreprocessor_privateFunctionPrototype(klassName, returnType, functionName, arguments) \
    static CbjectFunctionPrototype(klassName, returnType, functionName, arguments)
#define CbjectPreprocessor_expandPrivateFunction(klassName, returnType, functionName, arguments) CbjectPreprocessor_privateFunctionPrototype(klassName, returnType, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyPrivateFunction(functionPrototype) PrivateFunction functionPrototype;
#define CbjectPreprocessor_expandPrivateFunctions(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateFunction, __VA_ARGS__)

#define CbjectPreprocessor_superFunctionPrototypeOld(klassName, type, functionName, arguments) \
    type super##klassName##_##functionName(klassName * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))

#define CbjectPreprocessor_superFunctions_(klassName, type, functionName, arguments) \
    CbjectPreprocessor_superFunctionPrototypeOld(klassName, type, functionName, arguments)

#define CbjectPreprocessor_superFunctions(type, functionName, arguments) \
    CbjectPreprocessor_superFunctions_(klass, type, functionName, arguments)

#define CbjectPreprocessor_i_(klassName, superKlassName, ...)                               \
    void klassName##_init(klassName * const me, klassName##InitParams const * const params) \
    {                                                                                       \
        /*if (#superKlassName == "Cbject") { Cbject_init((Cbject *) me, null); }   */       \
        superKlassName##InitParams superInitParams;                                         \
                                                                                            \
        do                                                                                  \
            __VA_ARGS__                                                                     \
        while (0);                                                                          \
                                                                                            \
        /*((Cbject *) me)->c = (CbjectKlass *) klassName##Klass_instance(); */              \
        superKlassName##_init((superKlassName *) me, &superInitParams);                     \
        Cbject_klassSet((Cbject *) me, (CbjectKlass *) klassName##Klass_instance());        \
    }
#define CbjectPreprocessor_i(klassName, superKlassName, ...) CbjectPreprocessor_i_(klassName, superKlassName, __VA_ARGS__)

#define CbjectPreprocessor_t_(klassName, superKlassName, ...)    \
    void klassName##_terminate(klassName * const me)             \
    {                                                            \
        do                                                       \
            __VA_ARGS__                                          \
        while (0);                                               \
                                                                 \
        superKlassName##_terminate((superKlassName * const) me); \
    }
#define CbjectPreprocessor_t(klassName, superKlassName, ...) CbjectPreprocessor_t_(klassName, superKlassName, __VA_ARGS__)

#define CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, ...)                          \
    klassName##Klass const * const klassName##Klass_instance()                                        \
    {                                                                                                 \
        static klassName##Klass c;                                                                    \
                                                                                                      \
        if (((CbjectKlass *) &c)->type == null)                                                       \
        {                                                                                             \
            static char const * const type = #klassName;                                              \
            *((superKlassName##Klass *) &c) = *superKlassName##Klass_instance();                      \
            ((CbjectKlass *) &c)->vf.size = (uint8(*)(Cbject const * const me)) override_Cbject_size; \
                                                                                                      \
            do                                                                                        \
                __VA_ARGS__                                                                           \
            while (0);                                                                                \
                                                                                                      \
            ((CbjectKlass *) &c)->type = type;                                                        \
        }                                                                                             \
                                                                                                      \
        return &c;                                                                                    \
    }

#define CbjectPreprocessor_getCbjectImpl(klassName)                         \
    klassName * get_##klassName(klassName##InitParams const * const params) \
    {                                                                       \
        static klassName pool[klassName##_poolSize];                        \
        static uint64 count = 0;                                            \
        klassName * me = null;                                              \
                                                                            \
        if (count < klassName##_poolSize)                                   \
        {                                                                   \
            me = &pool[count];                                              \
            klassName##_init(me, params);                                   \
            count++;                                                        \
        }                                                                   \
                                                                            \
        return me;                                                          \
    }

#define CbjectPreprocessor_newCbjectImpl(klassName)                         \
    klassName * new_##klassName(klassName##InitParams const * const params) \
    {                                                                       \
        klassName * me = (klassName *) malloc(sizeof(klassName));           \
        assert((me != null) && "Heap memory allocation failed");            \
        klassName##_init(me, params);                                       \
        return me;                                                          \
    }

#define CbjectPreprocessor_deleteCbjectImpl(klassName) \
    klassName * delete_##klassName(klassName * me)     \
    {                                                  \
        klassName##_terminate(me);                     \
        free(me);                                      \
    }

#define CbjectAbstractKlassSetup_(klassName, superKlassName, ...)      \
    CbjectPreprocessor_properties(klassName, superKlassName);                                \
    static uint8 override_Cbject_size(klassName const * const me) { return sizeof(*me); } \
    CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, __VA_ARGS__)
#define CbjectAbstractKlassSetup(klassName, superKlassName, ...) CbjectAbstractKlassSetup_(klassName, superKlassName, __VA_ARGS__)

#define CbjectPreprocessor_expandSingletonSetup_(klassName, superKlassName, ...)          \
    CbjectPreprocessor_properties(klassName, superKlassName);                                \
    CbjectPreprocessor_klass(klassName, superKlassName);                                  \
    klassName * klassName##_instance()                                                    \
    {                                                                                     \
        static klassName singleton;                                                       \
        return &singleton;                                                                \
    }                                                                                     \
                                                                                          \
    static uint8 override_Cbject_size(klassName const * const me) { return sizeof(*me); } \
    CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, __VA_ARGS__)
#define CbjectPreprocessor_expandSingletonSetup(klassName, superKlassName, ...) CbjectPreprocessor_expandSingletonSetup_(klassName, superKlassName, __VA_ARGS__)

#if CbjectSettings_useStaticPool == true
    #if CbjectSettings_useHeap == true
        #include <stdlib.h>
        #define CbjectPreprocessor_expandKlassSetup_(klassName, superKlassName, ...)              \
            CbjectPreprocessor_properties(klassName, superKlassName);                                \
            static uint8 override_Cbject_size(klassName const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, __VA_ARGS__);         \
            CbjectPreprocessor_getCbjectImpl(klassName);                                          \
            CbjectPreprocessor_newCbjectImpl(klassName);                                          \
            CbjectPreprocessor_deleteCbjectImpl(klassName);                                       \
            uint8 klassName##Klass_size() { return sizeof(klassName); }
    #else
        #define CbjectPreprocessor_expandKlassSetup_(klassName, superKlassName, ...)              \
            static uint8 override_Cbject_size(klassName const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, __VA_ARGS__);         \
            CbjectPreprocessor_getCbjectImpl(klassName);                                          \
            uint8 klassName##Klass_size() { return sizeof(klassName); }
    #endif
#else
    #if CbjectSettings_useHeap == true
        #include <stdlib.h>
        #define CbjectPreprocessor_expandKlassSetup_(klassName, superKlassName, ...)              \
            static uint8 override_Cbject_size(klassName const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, __VA_ARGS__);         \
            CbjectPreprocessor_newCbjectImpl(klassName);                                          \
            CbjectPreprocessor_deleteCbjectImpl(klassName);                                       \
            uint8 klassName##Klass_size() { return sizeof(klassName); }
    #else
        #define CbjectPreprocessor_expandKlassSetup_(klassName, superKlassName, ...)              \
            static uint8 override_Cbject_size(klassName const * const me) { return sizeof(*me); } \
            CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, __VA_ARGS__);         \
            uint8 klassName##Klass_size() { return sizeof(klassName); }
    #endif
#endif
#define CbjectPreprocessor_expandKlassSetup(klassName, superKlassName, ...) CbjectPreprocessor_expandKlassSetup_(klassName, superKlassName, __VA_ARGS__)

#define CbjectPreprocessor_bvf_(klassName, functionName) \
    c.vf.functionName = super##klassName##_##functionName;
#define CbjectPreprocessor_bvf(klassName, functionName) CbjectPreprocessor_bvf_(klassName, functionName)

#define CbjectPreprocessor_bof_(klassName, type, superKlassName, functionName, arguments) \
    ((superKlassName##Klass *) &c)->vf.functionName = (type(*)(superKlassName * const me CbjectUtilities_vaArgs(CbjectUtilities_stripParentheses(arguments)))) super##klassName##_##functionName
#define CbjectPreprocessor_bof(klassName, type, superKlassName, functionName, arguments) CbjectPreprocessor_bof_(klassName, type, superKlassName, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyBindFunction(functionPrototype) BindFunction functionPrototype;

#endif // CBJECTPREPROCESSOR_H
