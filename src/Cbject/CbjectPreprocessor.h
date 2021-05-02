#ifndef CBJECTPREPROCESSOR_H
#define CBJECTPREPROCESSOR_H
#include "CbjectSettings.h"
#include "Primitives.h"
#include "_Cbject/_CbjectContainerTypeDefinition.h"
#include "_Cbject/_CbjectFunction.h"
#include "_Cbject/_CbjectKlassTypeDefinition.h"
#include "_Cbject/_CbjectParamsTypeDefinition.h"
#include "_Cbject/_CbjectPropertiesTypeDefinition.h"
#include "_Cbject/_CbjectUtilities.h"
#include "_Cbject/_CbjectVirtualFunctionsTypeDefinition.h"
#include "_Cbject/_CbjectTypeDefinition.h"


#define CbjectPreprocessor_virtualFunctionPointer0(klassName, returnType, functionName, ...) \
    returnType (*functionName)(klassName * const me)
#define CbjectPreprocessor_virtualFunctionPointer_(klassName, returnType, functionName, ...) \
    returnType (*functionName)(klassName * const me, __VA_ARGS__)
#define CbjectPreprocessor_virtualFunctionPointer(klassName, returnType, functionName, case, ...) \
    CbjectPreprocessor_virtualFunctionPointer##case (klassName, returnType, functionName, __VA_ARGS__)
#define CbjectVirtualFunctionPointer(klassName, type, functionName, ...) \
    CbjectPreprocessor_virtualFunctionPointer(klassName, type, functionName, __VA_ARGS__)

#define CbjectPreprocessor_VirtualFunctionPointer(returnType, functionName, arguments) \
    CbjectVirtualFunctionPointer(klass, returnType, functionName, _CbjectUtilities_stripParentheses(arguments))

#define CbjectPreprocessor_stripParenthesesAndApplyVirtualFunctionPointer(functionPrototype) \
    CbjectPreprocessor_VirtualFunctionPointer functionPrototype;

#define CbjectPreprocessor_expandKlassNew(klassName, superKlassName, params, properties, virtualFunctions, functions) \
    CbjectPreprocessor_expandKlassNew_(klassName, superKlassName, params, properties, virtualFunctions, functions)

#define CbjectPreprocessor_klass(klassName, superKlassName) \
    typedef struct klassName##Klass                         \
    {                                                       \
        superKlassName##Klass s;                        \
    } klassName##Klass;                                     \
                                                            \
    klassName##Klass const * const klassName##Klass_instance()

#define CbjectPreprocessor_cm_(klassName, superKlassName)     \
    _CbjectTypeDefinition(klassName, superKlassName); \
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
    _CbjectTypeDefinition(klassName, superKlassName)
#define CbjectAbstractKlassProperties(klassName, superKlassName) CbjectAbstractKlassProperties_(klassName, superKlassName)

#define CbjectPreprocessor_expandDataKlass_(klassName, ...)                  \
    typedef struct klassName                                                 \
    {                                                                        \
        _CbjectUtilities_forEach(_CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } klassName
#define CbjectPreprocessor_expandDataKlass(klassName, ...) \
    CbjectPreprocessor_expandDataKlass_(klassName, __VA_ARGS__)

#define CbjectPreprocessor_pcnaac__(klassName, valueName) klassName##_##valueName,
#define CbjectPreprocessor_pcnaac_(klassName, valueName) CbjectPreprocessor_pcnaac__(klassName, valueName)
#define CbjectPreprocessor_prependKlassNameAndAddComma(valueName) CbjectPreprocessor_pcnaac_(klass, valueName)

#define CbjectPreprocessor_expandEnumKlass_(klassName, ...)                                   \
    typedef enum klassName                                                                    \
    {                                                                                         \
        _CbjectUtilities_forEach(CbjectPreprocessor_prependKlassNameAndAddComma, __VA_ARGS__) \
    } klassName
#define CbjectPreprocessor_expandEnumKlass(klassName, ...) CbjectPreprocessor_expandEnumKlass_(klassName, __VA_ARGS__)

#define CbjectPreprocessor_privateFunctionPrototype(klassName, returnType, functionName, arguments) \
    static _CbjectFunctionPrototype(klassName, returnType, functionName, arguments)
#define CbjectPreprocessor_expandPrivateFunction(klassName, returnType, functionName, arguments) CbjectPreprocessor_privateFunctionPrototype(klassName, returnType, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyPrivateFunction(functionPrototype) PrivateFunction functionPrototype;
#define CbjectPreprocessor_expandPrivateFunctions(...) _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateFunction, __VA_ARGS__)

#define CbjectPreprocessor_superFunctionPrototypeOld(klassName, type, functionName, arguments) \
    type s##klassName##_##functionName(klassName * const me _CbjectUtilities_vaArgs(_CbjectUtilities_stripParentheses(arguments)))

#define CbjectPreprocessor_superFunctions_(klassName, type, functionName, arguments) \
    CbjectPreprocessor_superFunctionPrototypeOld(klassName, type, functionName, arguments)

#define CbjectPreprocessor_superFunctions(type, functionName, arguments) \
    CbjectPreprocessor_superFunctions_(klass, type, functionName, arguments)

#define CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, ...)                          \
    klassName##Klass const * const klassName##Klass_instance()                                        \
    {                                                                                                 \
        static klassName##Klass k;                                                                    \
                                                                                                      \
        if (((CbjectKlass *) &k)->type == null)                                                       \
        {                                                                                             \
            static char const * const type = #klassName;                                              \
            *((superKlassName##Klass *) &k) = *superKlassName##Klass_instance();                      \
            ((CbjectKlass *) &k)->vf.size = (uint8(*)(Cbject const * const me)) override_Cbject_size; \
                                                                                                      \
            do                                                                                        \
                __VA_ARGS__                                                                           \
            while (0);                                                                                \
                                                                                                      \
            ((CbjectKlass *) &k)->type = type;                                                        \
        }                                                                                             \
                                                                                                      \
        return &k;                                                                                    \
    }

#define CbjectPreprocessor_getCbjectImpl(klassName)                     \
    klassName * Get_##klassName(klassName##Params const * const params) \
    {                                                                   \
        static klassName pool[klassName##_poolSize];                    \
        static uint64 count = 0;                                        \
        klassName * me = null;                                          \
                                                                        \
        if (count < klassName##_poolSize)                               \
        {                                                               \
            me = &pool[count];                                          \
            klassName##_init(me, params);                               \
            count++;                                                    \
        }                                                               \
                                                                        \
        return me;                                                      \
    }

#define CbjectPreprocessor_newCbjectImpl(klassName)                     \
    klassName * New_##klassName(klassName##Params const * const params) \
    {                                                                   \
        klassName * me = (klassName *) malloc(sizeof(klassName));       \
        assert((me != null) && "Heap memory allocation failed");        \
        klassName##_init(me, params);                                   \
        return me;                                                      \
    }

#define CbjectPreprocessor_deleteCbjectImpl(klassName) \
    klassName * Delete_##klassName(klassName * me)     \
    {                                                  \
        klassName##_terminate(me);                     \
        free(me);                                      \
    }


#define CbjectPreprocessor_expandSingletonSetup_(klassName, superKlassName, ...)          \
    _CbjectTypeDefinition(klassName, superKlassName);                             \
    CbjectPreprocessor_klass(klassName, superKlassName);                                  \
    klassName * klassName##_instance()                                                    \
    {                                                                                     \
        static klassName me;                                                              \
        if (Cbject_klass((Cbject *) &me) == null) { klassName##_init(&me, null); }        \
        return &me;                                                                       \
    }                                                                                     \
                                                                                          \
    static uint8 override_Cbject_size(klassName const * const me) { return sizeof(*me); } \
    CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, __VA_ARGS__)
#define CbjectPreprocessor_expandSingletonSetup(klassName, superKlassName, ...) CbjectPreprocessor_expandSingletonSetup_(klassName, superKlassName, __VA_ARGS__)

#if CbjectSettings_useStaticPool == true
    #if CbjectSettings_useHeap == true
        #include <stdlib.h>
        #define CbjectPreprocessor_expandKlassSetup_(klassName, superKlassName, ...)              \
            _CbjectTypeDefinition(klassName, superKlassName);                             \
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
    k.vf.functionName = s##klassName##_##functionName;
#define CbjectPreprocessor_bvf(klassName, functionName) CbjectPreprocessor_bvf_(klassName, functionName)

#define CbjectPreprocessor_bof_(klassName, type, superKlassName, functionName, arguments) \
    ((superKlassName##Klass *) &k)->vf.functionName = (type(*)(superKlassName * const me _CbjectUtilities_vaArgs(_CbjectUtilities_stripParentheses(arguments)))) s##klassName##_##functionName
#define CbjectPreprocessor_bof(klassName, type, superKlassName, functionName, arguments) CbjectPreprocessor_bof_(klassName, type, superKlassName, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyBindFunction(functionPrototype) BindFunction functionPrototype;

#endif // CBJECTPREPROCESSOR_H
