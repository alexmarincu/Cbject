#ifndef COBJECTUTILITIES_H
#define COBJECTUTILITIES_H
#include "CObjectSettings.h"
#include "Primitives.h"
#include <assert.h>

#define ct_assert(condition, message) typedef char ct_assert_##message[(!!(condition)) * 2 - 1]

#define cou_vaArgs_(...) , ##__VA_ARGS__
#define cou_vaArgs(...) cou_vaArgs_(__VA_ARGS__)

#define cou_sp_(...) __VA_ARGS__
#define cou_sp(x) x
#define cou_stripParentheses(arguments) cou_sp(cou_sp_ arguments)

#define cou_fe1(macro, x) macro(x)
#define cou_fe2(macro, x, ...) macro(x) cou_fe1(macro, __VA_ARGS__)
#define cou_fe3(macro, x, ...) macro(x) cou_fe2(macro, __VA_ARGS__)
#define cou_fe4(macro, x, ...) macro(x) cou_fe3(macro, __VA_ARGS__)
#define cou_fe5(macro, x, ...) macro(x) cou_fe4(macro, __VA_ARGS__)
#define cou_fe6(macro, x, ...) macro(x) cou_fe5(macro, __VA_ARGS__)
#define cou_fe7(macro, x, ...) macro(x) cou_fe6(macro, __VA_ARGS__)
#define cou_fe8(macro, x, ...) macro(x) cou_fe7(macro, __VA_ARGS__)
#define cou_fe9(macro, x, ...) macro(x) cou_fe8(macro, __VA_ARGS__)
#define cou_fe10(macro, x, ...) macro(x) cou_fe9(macro, __VA_ARGS__)
#define cou_fe11(macro, x, ...) macro(x) cou_fe10(macro, __VA_ARGS__)
#define cou_fe12(macro, x, ...) macro(x) cou_fe11(macro, __VA_ARGS__)
#define cou_fe13(macro, x, ...) macro(x) cou_fe12(macro, __VA_ARGS__)
#define cou_fe14(macro, x, ...) macro(x) cou_fe13(macro, __VA_ARGS__)
#define cou_fe15(macro, x, ...) macro(x) cou_fe14(macro, __VA_ARGS__)
#define cou_fe16(macro, x, ...) macro(x) cou_fe15(macro, __VA_ARGS__)
#define cou_fe17(macro, x, ...) macro(x) cou_fe16(macro, __VA_ARGS__)
#define cou_fe18(macro, x, ...) macro(x) cou_fe17(macro, __VA_ARGS__)
#define cou_fe19(macro, x, ...) macro(x) cou_fe18(macro, __VA_ARGS__)
#define cou_fe20(macro, x, ...) macro(x) cou_fe19(macro, __VA_ARGS__)
#define cou_fe21(macro, x, ...) macro(x) cou_fe20(macro, __VA_ARGS__)
#define cou_fe22(macro, x, ...) macro(x) cou_fe21(macro, __VA_ARGS__)
#define cou_fe23(macro, x, ...) macro(x) cou_fe22(macro, __VA_ARGS__)
#define cou_fe24(macro, x, ...) macro(x) cou_fe23(macro, __VA_ARGS__)
#define cou_fe25(macro, x, ...) macro(x) cou_fe24(macro, __VA_ARGS__)
#define cou_fe26(macro, x, ...) macro(x) cou_fe25(macro, __VA_ARGS__)
#define cou_fe27(macro, x, ...) macro(x) cou_fe26(macro, __VA_ARGS__)
#define cou_fe28(macro, x, ...) macro(x) cou_fe27(macro, __VA_ARGS__)
#define cou_fe29(macro, x, ...) macro(x) cou_fe28(macro, __VA_ARGS__)
#define cou_fe30(macro, x, ...) macro(x) cou_fe29(macro, __VA_ARGS__)
#define cou_getArgN(                                                      \
    arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,          \
    arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, \
    arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, \
    argN, ...) argN
#define cou_forEach(macro, ...)                                                                             \
    cou_getArgN(                                                                                            \
        __VA_ARGS__,                                                                                        \
        cou_fe30, cou_fe29, cou_fe28, cou_fe27, cou_fe26, cou_fe25, cou_fe24, cou_fe23, cou_fe22, cou_fe21, \
        cou_fe20, cou_fe19, cou_fe18, cou_fe17, cou_fe16, cou_fe15, cou_fe14, cou_fe13, cou_fe12, cou_fe11, \
        cou_fe10, cou_fe9, cou_fe8, cou_fe7, cou_fe6, cou_fe5, cou_fe4, cou_fe3, cou_fe2, cou_fe1)(macro, __VA_ARGS__)

#define cou_addSemicolon(x) x;

#define cou_params(className, ...)                                                       \
    typedef struct className className;                                                  \
                                                                                         \
    typedef struct className##Params                                                     \
    {                                                                                    \
        cou_forEach(cou_addSemicolon, __VA_ARGS__)                                       \
    } className##Params;                                                                 \
                                                                                         \
    void className##_init(className * const me, className##Params const * const params); \
    void className##_terminate(className * const me)

#define cou_getObjectDecl(className) className * get_##className(className##Params const * const params)
#define cou_newObjectDecl(className) className * new_##className(className##Params const * const params)
#define cou_deleteObjectDecl(className) className * delete_##className(className * me)

#define cou_acp_(className, ...) cou_params(className, __VA_ARGS__)
#define cou_acp(className, ...) cou_acp_(className, __VA_ARGS__)
#define abstractClassParams(...) cou_acp(class, __VA_ARGS__)

#define cou_op_(className, ...)         \
    cou_params(className, __VA_ARGS__); \
    className * className##_instance()
#define cou_op(className, ...) cou_op_(className, __VA_ARGS__)
#define objectParams(...) cou_op(class, __VA_ARGS__)

#if CObject_useStaticPool == true
    #if CObject_useHeap == true
        #define cou_cp_(className, ...)         \
            cou_params(className, __VA_ARGS__); \
            uint8 className##Class_size();      \
            cou_getObjectDecl(className);       \
            cou_newObjectDecl(className);       \
            cou_deleteObjectDecl(className)
    #else
        #define cou_cp_(className, ...)         \
            cou_params(className, __VA_ARGS__); \
            uint8 className##Class_size();      \
            cou_getObjectDecl(className)
    #endif
#else
    #if CObject_useHeap == true
        #define cou_cp_(className, ...)         \
            cou_params(className, __VA_ARGS__); \
            uint8 className##Class_size();      \
            cou_newObjectDecl(className);       \
            cou_deleteObjectDecl(className)
    #else
        #define cou_cp_(className, ...)         \
            cou_params(className, __VA_ARGS__); \
            uint8 className##Class_size()
    #endif
#endif
#define cou_cp(className, ...) cou_cp_(className, __VA_ARGS__)
#define classParams(...) cou_cp(class, __VA_ARGS__)

#if CObject_useStaticPool == true
    #define cou_cps_(className, poolSize)   \
        enum                                \
        {                                   \
            className##_poolSize = poolSize \
        }
    #define cou_cps(className, poolSize) cou_cps_(className, poolSize)
    #define classPoolSize(poolSize) cou_cps(class, poolSize)
#endif

#define cou_class(className, superClassName) \
    typedef struct className##Class          \
    {                                        \
        superClassName##Class super;         \
    } className##Class;                      \
                                             \
    className##Class const * const className##Class_instance()

#define cou_members(className, superClassName, ...) \
    struct className                                \
    {                                               \
        superClassName super;                       \
        cou_forEach(cou_addSemicolon, __VA_ARGS__)  \
    }

#define cou_cm_(className, superClassName, ...)          \
    cou_members(className, superClassName, __VA_ARGS__); \
    cou_class(className, superClassName)
#define cou_cm(className, superClassName, ...) cou_cm_(className, superClassName, __VA_ARGS__)
#define classMembers(...) cou_cm(class, superClass, __VA_ARGS__)
#define objectMembers(...) cou_cm(class, superClass, __VA_ARGS__)

#define cou_c_(className, type, ...) type const className##_##__VA_ARGS__
#define cou_c(className, type, ...) cou_c_(className, type, __VA_ARGS__)
#define constant(type, ...) cou_c(class, type, __VA_ARGS__)
#define cou_stripParenthesesAndApplyConstant(constSignature) constant constSignature;
#define constants(...) cou_forEach(cou_stripParenthesesAndApplyConstant, __VA_ARGS__)

#define cou_pbc_(className, type, constName) extern type const className##_##constName
#define cou_pbc(className, type, constName) cou_pbc_(className, type, constName)
#define publicConstant(type, constName) cou_pbc(class, type, constName)
#define cou_stripParenthesesAndApplyPublicConstant(constSignature) publicConstant constSignature;
#define publicConstants(...) cou_forEach(cou_stripParenthesesAndApplyPublicConstant, __VA_ARGS__)

#define cou_pc_(className, type, ...) static type const className##_##__VA_ARGS__
#define cou_pc(className, type, ...) cou_pc_(className, type, __VA_ARGS__)
#define privateConstant(type, ...) cou_pc(class, type, __VA_ARGS__)
#define cou_stripParenthesesAndApplyPrivateConstant(constSignature) privateConstant constSignature;
#define privateConstants(className, ...) cou_forEach(cou_stripParenthesesAndApplyPrivateConstant, __VA_ARGS__)

#define cou_acm_(className, superClassName, ...) cou_members(className, superClassName, __VA_ARGS__)
#define cou_acm(className, superClassName, ...) cou_acm_(className, superClassName, __VA_ARGS__)
#define abstractClassMembers(...) cou_acm(class, superClass, __VA_ARGS__)

#define cou_dc_(className, ...)                    \
    typedef struct className                       \
    {                                              \
        cou_forEach(cou_addSemicolon, __VA_ARGS__) \
    } className
#define cou_dc(className, ...) cou_dc_(className, __VA_ARGS__)
#define dataClass(...) cou_dc(class, __VA_ARGS__)

#define cou_pcnaac__(className, valueName) className##_##valueName,
#define cou_pcnaac_(className, valueName) cou_pcnaac__(className, valueName)
#define cou_prependClassNameAndAddComma(valueName) cou_pcnaac_(class, valueName)

#define cou_ec_(className, ...)                                   \
    typedef enum className                                        \
    {                                                             \
        cou_forEach(cou_prependClassNameAndAddComma, __VA_ARGS__) \
    } className
#define cou_ec(className, ...) cou_ec_(className, __VA_ARGS__)
#define enumClass(...) cou_ec(class, __VA_ARGS__)

#define cou_f_(className, type, functionName, arguments) \
    type className##_##functionName(className * const me cou_vaArgs(cou_stripParentheses(arguments)))
#define cou_f(className, type, functionName, arguments) cou_f_(className, type, functionName, arguments)
#define function(type, functionName, arguments) cou_f(class, type, functionName, arguments)
#define cou_stripParenthesesAndApplyFunction(funSignature) function funSignature;
#define functions(...) cou_forEach(cou_stripParenthesesAndApplyFunction, __VA_ARGS__)

#define cou_pf_(className, type, functionName, arguments) \
    static type className##_##functionName(className * const me cou_vaArgs(cou_stripParentheses(arguments)))
#define cou_pf(className, type, functionName, arguments) cou_pf_(className, type, functionName, arguments)
#define privateFunction(type, functionName, arguments) cou_pf(class, type, functionName, arguments)
#define cou_stripParenthesesAndApplyPrivateFunction(funSignature) privateFunction funSignature;
#define privateFunctions(...) cou_forEach(cou_stripParenthesesAndApplyPrivateFunction, __VA_ARGS__)

#define cou_vfp__(className, type, functionName, arguments) \
    type (*functionName)(className * const me cou_vaArgs(cou_stripParentheses(arguments)))
#define cou_vfp_(className, type, functionName, arguments) cou_vfp__(className, type, functionName, arguments)
#define cou_vfp(type, functionName, arguments) cou_vfp_(class, type, functionName, arguments)
#define cou_stripParenthesesAndApplyVirtualFunctionPointer(funSignature) cou_vfp funSignature;

#define cou_virtualCall(className, functionName, params) \
    return ((className##Class *) ((Object *) me)->c)->vf.functionName(me cou_vaArgs(cou_stripParentheses(params)))

#define cou_superFunctions__(className, type, functionName, arguments) \
    type super##className##_##functionName(className * const me cou_vaArgs(cou_stripParentheses(arguments)))
#define cou_superFunctions_(className, type, functionName, arguments) cou_superFunctions__(className, type, functionName, arguments)
#define cou_superFunctions(type, functionName, arguments) cou_superFunctions_(class, type, functionName, arguments)
#define cou_stripParenthesesAndApplySuperFunction(funSignature) cou_superFunctions funSignature;

#define cou_vf_(className, type, functionName, arguments, params)                                          \
    cou_f_(className, type, functionName, arguments) { cou_virtualCall(className, functionName, params); } \
    cou_superFunctions__(className, type, functionName, arguments)
#define cou_vf(className, type, functionName, arguments, params) cou_vf_(className, type, functionName, arguments, params)
#define virtualFunction(type, functionName, arguments, params) cou_vf(class, type, functionName, arguments, params)

#define cou_vfs_(className, superClassName, ...)                                         \
    typedef struct className##Class                                                      \
    {                                                                                    \
        superClassName##Class super;                                                     \
                                                                                         \
        struct                                                                           \
        {                                                                                \
            cou_forEach(cou_stripParenthesesAndApplyVirtualFunctionPointer, __VA_ARGS__) \
        } vf;                                                                            \
    } className##Class;                                                                  \
                                                                                         \
    className##Class const * const className##Class_instance();                          \
    cou_forEach(cou_stripParenthesesAndApplySuperFunction, __VA_ARGS__)
#define cou_vfs(className, superClassName, ...) cou_vfs_(className, superClassName, __VA_ARGS__)
#define virtualFunctions(...) cou_vfs(class, superClass, __VA_ARGS__)

#define stackObject(className, varName, ...)                  \
    uint8 const varName##Stack[className##Class_size()];      \
    className * const varName = (className *) varName##Stack; \
    className##_init((className *) varName, __VA_ARGS__)

#define cou_sg_(className, type, memberName)                                         \
    void className##_##memberName##Set(className * const me, type const memberName); \
    type className##_##memberName(className const * const me)
#define cou_sg(className, type, memberName) cou_sg_(className, type, memberName)
#define setterGetter(type, memberName) cou_sg(class, type, memberName)
#define cou_stripParenthesesAndApplySetterGetter(memberSignature) setterGetter memberSignature;
#define settersGetters(...) cou_forEach(cou_stripParenthesesAndApplySetterGetter, __VA_ARGS__)

#define cou_ds_(className, type, memberName) \
    void className##_##memberName##Set(className * const me, type const memberName) { me->memberName = memberName; }
#define cou_ds(className, type, memberName) cou_ds_(className, type, memberName)
#define defaultSetter(type, memberName) cou_ds(class, type, memberName)

#define cou_dg_(className, type, memberName) \
    type className##_##memberName(className const * const me) { return me->memberName; }
#define cou_dg(className, type, memberName) cou_dg_(className, type, memberName)
#define defaultGetter(type, memberName) cou_dg(class, type, memberName)

#define cou_dsg_(className, type, memberName)                                                                        \
    void className##_##memberName##Set(className * const me, type const memberName) { me->memberName = memberName; } \
    type className##_##memberName(className const * const me) { return me->memberName; }
#define cou_dsg(className, type, memberName) cou_dsg_(className, type, memberName)
#define defaultSetterGetter(type, memberName) cou_dsg(class, type, memberName)
#define cou_stripParenthesesAndApplyDefaultSetterGetter(memberSignature) defaultSetterGetter memberSignature
#define defaultSettersGetters(...) cou_forEach(cou_stripParenthesesAndApplyDefaultSetterGetter, __VA_ARGS__)

#define cou_of_(className, type, superClassName, functionName, arguments) \
    type super##className##_##functionName(className * const me cou_vaArgs(cou_stripParentheses(arguments)))
#define cou_of(className, type, superClassName, functionName, arguments) cou_of_(className, type, superClassName, functionName, arguments)
#define overrideFunction(type, superClassName, functionName, arguments) cou_of(class, type, superClassName, functionName, arguments)
#define cou_stripParenthesesAndApplyOverrideFunction(funSignature) overrideFunction funSignature;
#define overrideFunctions(...) cou_forEach(cou_stripParenthesesAndApplyOverrideFunction, __VA_ARGS__)

#define cou_i_(className, superClassName, ...)                                           \
    void className##_init(className * const me, className##Params const * const params)  \
    {                                                                                    \
        superClassName##_init((superClassName *) me, (superClassName##Params *) params); \
                                                                                         \
        do                                                                               \
            __VA_ARGS__                                                                  \
        while (0);                                                                       \
                                                                                         \
        ((Object *) me)->c = (ObjectClass *) className##Class_instance();                \
    }
#define cou_i(className, superClassName, ...) cou_i_(className, superClassName, __VA_ARGS__)
#define init(...) cou_i(class, superClass, __VA_ARGS__)

#define cou_t_(className, superClassName, ...)                   \
    void className##_terminate(className * const me)             \
    {                                                            \
        do                                                       \
            __VA_ARGS__                                          \
        while (0);                                               \
                                                                 \
        superClassName##_terminate((superClassName * const) me); \
    }
#define cou_t(className, superClassName, ...) cou_t_(className, superClassName, __VA_ARGS__)
#define terminate(...) cou_t(class, superClass, __VA_ARGS__)

#define cou_classInstanceImpl(className, superClassName, ...)                                         \
    className##Class const * const className##Class_instance()                                        \
    {                                                                                                 \
        static className##Class c;                                                                    \
                                                                                                      \
        if (((ObjectClass *) &c)->type == null)                                                       \
        {                                                                                             \
            static char const * const type = #className;                                              \
            *((superClassName##Class *) &c) = *superClassName##Class##_instance();                    \
            ((ObjectClass *) &c)->vf.size = (uint8(*)(Object const * const me)) override_Object_size; \
                                                                                                      \
            do                                                                                        \
                __VA_ARGS__                                                                           \
            while (0);                                                                                \
                                                                                                      \
            ((ObjectClass *) &c)->type = type;                                                        \
        }                                                                                             \
                                                                                                      \
        return &c;                                                                                    \
    }

#define cou_getObjectImpl(className)                                    \
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

#define cou_newObjectImpl(className)                                    \
    className * new_##className(className##Params const * const params) \
    {                                                                   \
        className * me = (className *) malloc(sizeof(className));       \
        assert((me != null) && "Heap memory allocation failed");        \
        className##_init(me, params);                                   \
        return me;                                                      \
    }

#define cou_deleteObjectImpl(className)            \
    className * delete_##className(className * me) \
    {                                              \
        className##_terminate(me);                 \
        free(me);                                  \
    }

#define cou_acs_(className, superClassName, ...)                                          \
    static uint8 override_Object_size(className const * const me) { return sizeof(*me); } \
    cou_classInstanceImpl(className, superClassName, __VA_ARGS__)
#define cou_acs(className, superClassName, ...) cou_acs_(className, superClassName, __VA_ARGS__)
#define abstractClassSetup(...) cou_acs(class, superClass, __VA_ARGS__)

#define cou_os_(className, superClassName, ...)                                           \
    className * className##_instance()                                                    \
    {                                                                                     \
        static className singleton;                                                       \
        return &singleton;                                                                \
    }                                                                                     \
                                                                                          \
    static uint8 override_Object_size(className const * const me) { return sizeof(*me); } \
    cou_classInstanceImpl(className, superClassName, __VA_ARGS__)
#define cou_os(className, superClassName, ...) cou_os_(className, superClassName, __VA_ARGS__)
#define objectSetup(...) cou_os(class, superClass, __VA_ARGS__)

#if CObject_useStaticPool == true
    #if CObject_useHeap == true
        #include <stdlib.h>
        #define cou_cs_(className, superClassName, ...)                                           \
            static uint8 override_Object_size(className const * const me) { return sizeof(*me); } \
            cou_classInstanceImpl(className, superClassName, __VA_ARGS__);                        \
            cou_getObjectImpl(className);                                                         \
            cou_newObjectImpl(className);                                                         \
            cou_deleteObjectImpl(className);                                                      \
            uint8 className##Class_size() { return sizeof(className); }
    #else
        #define cou_cs_(className, superClassName, ...)                                           \
            static uint8 override_Object_size(className const * const me) { return sizeof(*me); } \
            cou_classInstanceImpl(className, superClassName, __VA_ARGS__);                        \
            cou_getObjectImpl(className);                                                         \
            uint8 className##Class_size() { return sizeof(className); }
    #endif
#else
    #if CObject_useHeap == true
        #include <stdlib.h>
        #define cou_cs_(className, superClassName, ...)                                           \
            static uint8 override_Object_size(className const * const me) { return sizeof(*me); } \
            cou_classInstanceImpl(className, superClassName, __VA_ARGS__);                        \
            cou_newObjectImpl(className);                                                         \
            cou_deleteObjectImpl(className);                                                      \
            uint8 className##Class_size() { return sizeof(className); }
    #else
        #define cou_cs_(className, superClassName, ...)                                           \
            static uint8 override_Object_size(className const * const me) { return sizeof(*me); } \
            cou_classInstanceImpl(className, superClassName, __VA_ARGS__);                        \
            uint8 className##Class_size() { return sizeof(className); }
    #endif
#endif
#define cou_cs(className, superClassName, ...) cou_cs_(className, superClassName, __VA_ARGS__)
#define classSetup(...) cou_cs(class, superClass, __VA_ARGS__)

#define cou_bvf_(className, functionName) \
    c.vf.functionName = super##className##_##functionName;
#define cou_bvf(className, functionName) cou_bvf_(className, functionName)
#define bindVirtualFunction(functionName) cou_bvf(class, functionName)
#define bindVirtualFunctions(...) cou_forEach(bindVirtualFunction, __VA_ARGS__)

#define cou_bof_(className, type, superClassName, functionName, arguments) \
    ((superClassName##Class *) &c)->vf.functionName = (type(*)(superClassName * const me cou_vaArgs(cou_stripParentheses(arguments)))) super##className##_##functionName
#define cou_bof(className, type, superClassName, functionName, arguments) cou_bof_(className, type, superClassName, functionName, arguments)
#define bindFunction(type, superClassName, functionName, arguments) cou_bof(class, type, superClassName, functionName, arguments)

#define cou_stripParenthesesAndApplybindFunction(funSignature) bindFunction funSignature;
#define bindFunctions(...) cou_forEach(cou_stripParenthesesAndApplybindFunction, __VA_ARGS__)

#endif // COBJECTUTILITIES_H
