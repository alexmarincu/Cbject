#ifndef COBJECTUTILITIES_H
#define COBJECTUTILITIES_H
#include "CObjectSettings.h"
#include "Primitives.h"

#define va_args_(...) , ##__VA_ARGS__
#define va_args(...) va_args_(__VA_ARGS__)

#define strip_parentheses__(...) __VA_ARGS__
#define strip_parentheses_(x) x
#define strip_parentheses(arguments) strip_parentheses_(strip_parentheses__ arguments)

#define fe_1(macro, x) macro(x)
#define fe_2(macro, x, ...) macro(x) fe_1(macro, __VA_ARGS__)
#define fe_3(macro, x, ...) macro(x) fe_2(macro, __VA_ARGS__)
#define fe_4(macro, x, ...) macro(x) fe_3(macro, __VA_ARGS__)
#define fe_5(macro, x, ...) macro(x) fe_4(macro, __VA_ARGS__)
#define fe_6(macro, x, ...) macro(x) fe_5(macro, __VA_ARGS__)
#define fe_7(macro, x, ...) macro(x) fe_6(macro, __VA_ARGS__)
#define fe_8(macro, x, ...) macro(x) fe_7(macro, __VA_ARGS__)
#define fe_9(macro, x, ...) macro(x) fe_8(macro, __VA_ARGS__)
#define fe_10(macro, x, ...) macro(x) fe_9(macro, __VA_ARGS__)
#define fe_11(macro, x, ...) macro(x) fe_10(macro, __VA_ARGS__)
#define fe_12(macro, x, ...) macro(x) fe_11(macro, __VA_ARGS__)
#define fe_13(macro, x, ...) macro(x) fe_12(macro, __VA_ARGS__)
#define fe_14(macro, x, ...) macro(x) fe_13(macro, __VA_ARGS__)
#define fe_15(macro, x, ...) macro(x) fe_14(macro, __VA_ARGS__)
#define fe_16(macro, x, ...) macro(x) fe_15(macro, __VA_ARGS__)
#define fe_17(macro, x, ...) macro(x) fe_16(macro, __VA_ARGS__)
#define fe_18(macro, x, ...) macro(x) fe_17(macro, __VA_ARGS__)
#define fe_19(macro, x, ...) macro(x) fe_18(macro, __VA_ARGS__)
#define fe_20(macro, x, ...) macro(x) fe_19(macro, __VA_ARGS__)
#define fe_21(macro, x, ...) macro(x) fe_20(macro, __VA_ARGS__)
#define fe_22(macro, x, ...) macro(x) fe_21(macro, __VA_ARGS__)
#define fe_23(macro, x, ...) macro(x) fe_22(macro, __VA_ARGS__)
#define fe_24(macro, x, ...) macro(x) fe_23(macro, __VA_ARGS__)
#define fe_25(macro, x, ...) macro(x) fe_24(macro, __VA_ARGS__)
#define fe_26(macro, x, ...) macro(x) fe_25(macro, __VA_ARGS__)
#define fe_27(macro, x, ...) macro(x) fe_26(macro, __VA_ARGS__)
#define fe_28(macro, x, ...) macro(x) fe_27(macro, __VA_ARGS__)
#define fe_29(macro, x, ...) macro(x) fe_28(macro, __VA_ARGS__)
#define fe_30(macro, x, ...) macro(x) fe_29(macro, __VA_ARGS__)
#define get_argN(                                                         \
    arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10,          \
    arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, \
    arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, \
    argN, ...) argN
#define for_each(macro, ...)                                                  \
    get_argN(                                                                 \
        __VA_ARGS__,                                                          \
        fe_30, fe_29, fe_28, fe_27, fe_26, fe_25, fe_24, fe_23, fe_22, fe_21, \
        fe_20, fe_19, fe_18, fe_17, fe_16, fe_15, fe_14, fe_13, fe_12, fe_11, \
        fe_10, fe_9, fe_8, fe_7, fe_6, fe_5, fe_4, fe_3, fe_2, fe_1)(macro, __VA_ARGS__)

#define add_semicolon__(className, memberTypeAndName) memberTypeAndName;
#define add_semicolon_(className, memberTypeAndName) add_semicolon__(className, memberTypeAndName)
#define add_semicolon(memberTypeAndName) add_semicolon_(class, memberTypeAndName)

#define abstract_class_init_params__(className, ...)                  \
    typedef struct className m##className;                            \
    typedef struct className const className;                         \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        for_each(add_semicolon, __VA_ARGS__)                          \
    };                                                                \
                                                                      \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className Pt me, className##InitParams Pt params)
#define abstract_class_init_params_(className, ...) abstract_class_init_params__(className, __VA_ARGS__)
#define abstract_class_init_params(...) abstract_class_init_params_(class, __VA_ARGS__)

#define singleton_class_init_params__(className, ...)                 \
    typedef struct className m##className;                            \
    typedef struct className const className;                         \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        for_each(add_semicolon, __VA_ARGS__)                          \
    };                                                                \
                                                                      \
    m##className mPt className##_getInstance();                       \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className Pt me, className##InitParams Pt params)
#define singleton_class_init_params_(className, ...) singleton_class_init_params__(className, __VA_ARGS__)
#define singleton_class_init_params(...) singleton_class_init_params_(class, __VA_ARGS__)

#if CObject_useStaticPool == true
    #if CObject_useHeap == true
        #define class_init_params__(className, ...)                            \
            typedef struct className m##className;                             \
            typedef struct className const className;                          \
            typedef struct className##InitParams m##className##InitParams;     \
            typedef struct className##InitParams const className##InitParams;  \
                                                                               \
            struct className##InitParams                                       \
            {                                                                  \
                for_each(add_semicolon, __VA_ARGS__)                           \
            };                                                                 \
                                                                               \
            m##className mPt get_##className(className##InitParams Pt params); \
            m##className mPt new_##className(className##InitParams Pt params); \
            mUInt8 className##_classSize();                                    \
            Void className##_init(m##className Pt me, className##InitParams Pt params)
    #else
        #define class_init_params__(className, ...)                            \
            typedef struct className m##className;                             \
            typedef struct className const className;                          \
            typedef struct className##InitParams m##className##InitParams;     \
            typedef struct className##InitParams const className##InitParams;  \
                                                                               \
            struct className##InitParams                                       \
            {                                                                  \
                for_each(add_semicolon, __VA_ARGS__)                           \
            };                                                                 \
                                                                               \
            m##className mPt get_##className(className##InitParams Pt params); \
            mUInt8 className##_classSize();                                    \
            Void className##_init(m##className Pt me, className##InitParams Pt params)
    #endif
#else
    #if CObject_useHeap == true
        #define class_init_params__(className, ...)                            \
            typedef struct className m##className;                             \
            typedef struct className const className;                          \
            typedef struct className##InitParams m##className##InitParams;     \
            typedef struct className##InitParams const className##InitParams;  \
                                                                               \
            struct className##InitParams                                       \
            {                                                                  \
                for_each(add_semicolon, __VA_ARGS__)                           \
            };                                                                 \
                                                                               \
            m##className mPt new_##className(className##InitParams Pt params); \
            mUInt8 className##_classSize();                                    \
            Void className##_init(m##className Pt me, className##InitParams Pt params)
    #else
        #define class_init_params__(className, ...)                           \
            typedef struct className m##className;                            \
            typedef struct className const className;                         \
            typedef struct className##InitParams m##className##InitParams;    \
            typedef struct className##InitParams const className##InitParams; \
                                                                              \
            struct className##InitParams                                      \
            {                                                                 \
                for_each(add_semicolon, __VA_ARGS__)                          \
            };                                                                \
                                                                              \
            mUInt8 className##_classSize();                                   \
            Void className##_init(m##className Pt me, className##InitParams Pt params)
    #endif
#endif
#define class_init_params_(className, ...) class_init_params__(className, __VA_ARGS__)
#define class_init_params(...) class_init_params_(class, __VA_ARGS__)

#if CObject_useStaticPool == true
    #define class_pool_size__(className, poolSize) \
        enum                                       \
        {                                          \
            className##_poolSize = poolSize        \
        }
    #define class_pool_size_(className, poolSize) class_pool_size__(className, poolSize)
    #define class_pool_size(poolSize) class_pool_size_(class, poolSize)
#endif

#define class_members__(className, superClassName, ...) \
    struct className                                    \
    {                                                   \
        struct superClassName super;                    \
        for_each(add_semicolon, __VA_ARGS__)            \
    };                                                  \
                                                        \
    typedef struct className##VT m##className##VT;      \
    typedef struct className##VT const className##VT;   \
                                                        \
    struct className##VT                                \
    {                                                   \
        m##superClassName##VT super;                    \
    }
#define class_members_(className, superClassName, ...) class_members__(className, superClassName, __VA_ARGS__)
#define class_members(...) class_members_(class, super_class, __VA_ARGS__)

#define abstract_class_members__(className, superClassName, ...) \
    struct className                                             \
    {                                                            \
        m##superClassName super;                                 \
        for_each(add_semicolon, __VA_ARGS__)                     \
    }
#define abstract_class_members_(className, superClassName, ...) abstract_class_members__(className, superClassName, __VA_ARGS__)
#define abstract_class_members(...) abstract_class_members_(class, super_class, __VA_ARGS__)

#define singleton_class_members__(className, superClassName, ...) \
    struct className                                              \
    {                                                             \
        m##superClassName super;                                  \
        for_each(add_semicolon, __VA_ARGS__)                      \
    };                                                            \
                                                                  \
    typedef struct className##VT m##className##VT;                \
    typedef struct className##VT const className##VT;             \
                                                                  \
    struct className##VT                                          \
    {                                                             \
        m##superClassName##VT super;                              \
    }
#define singleton_class_members_(className, superClassName, ...) singleton_class_members__(className, superClassName, __VA_ARGS__)
#define singleton_class_members(...) singleton_class_members_(class, super_class, __VA_ARGS__)

#define data_class_members__(className, ...)  \
    typedef struct className m##className;    \
    typedef struct className const className; \
                                              \
    struct className                          \
    {                                         \
        for_each(add_semicolon, __VA_ARGS__)  \
    }
#define data_class_members_(className, ...) data_class_members__(className, __VA_ARGS__)
#define data_class_members(...) data_class_members_(class, __VA_ARGS__)

#define prepend_class_name_and_add_comma__(className, valueName) className##_##valueName,
#define prepend_class_name_and_add_comma_(className, valueName) prepend_class_name_and_add_comma__(className, valueName)
#define prepend_class_name_and_add_comma(valueName) prepend_class_name_and_add_comma_(class, valueName)

#define enum_class_values__(className, ...)                     \
    typedef enum className m##className;                        \
    typedef enum className const className;                     \
                                                                \
    enum className                                              \
    {                                                           \
        for_each(prepend_class_name_and_add_comma, __VA_ARGS__) \
    }
#define enum_class_values_(className, ...) enum_class_values__(className, __VA_ARGS__)
#define enum_class_values(...) enum_class_values_(class, __VA_ARGS__)

#define virtual_fun_Pt_(className, type, functionName, arguments) \
    type(mPt functionName)(className Pt me va_args(strip_parentheses(arguments)))
//#define virtual_fun_(className, type, functionName, arguments) virtual_fun__(className, type, functionName, arguments)
#define virtual_fun_Pt(type, functionName, arguments) virtual_fun_Pt_(class, type, functionName, arguments)
#define strip_parentheses_and_apply_virtual_fun_Pt(funSignature) virtual_fun_Pt funSignature;

#define virtual_fun__(className, type, functionName, arguments) \
    type super_##className##_##functionName(className Pt me va_args(strip_parentheses(arguments)))
#define virtual_fun_(className, type, functionName, arguments) virtual_fun__(className, type, functionName, arguments)
#define virtual_fun(type, functionName, arguments) virtual_fun_(class, type, functionName, arguments)
#define strip_parentheses_and_apply_virtual_fun(funSignature) virtual_fun funSignature;

#define virtual_functions__(className, superClassName, ...)                \
    typedef struct className##VT m##className##VT;                         \
    typedef struct className##VT const className##VT;                      \
                                                                           \
    struct className##VT                                                   \
    {                                                                      \
        m##superClassName##VT super;                                       \
        for_each(strip_parentheses_and_apply_virtual_fun_Pt, __VA_ARGS__); \
    };                                                                     \
                                                                           \
    for_each(strip_parentheses_and_apply_virtual_fun, __VA_ARGS__)
#define virtual_functions_(className, superClassName, ...) virtual_functions__(className, superClassName, __VA_ARGS__)
#define virtual_functions(...) virtual_functions_(class, super_class, __VA_ARGS__)

#define Object(className, varName, initParams)            \
    Byte varName##Stack[className##_classSize()];         \
    className Pt varName = (className Pt) varName##Stack; \
    className##_init((m##className Pt) varName, initParams)

#define mObject(className, varName, initParams)                 \
    Byte varName##Stack[className##_classSize()];               \
    m##className Pt varName = (m##className Pt) varName##Stack; \
    className##_init(varName, initParams)

#define set_get__(className, type, memberName)                               \
    Void className##_##memberName##Set(m##className Pt me, type memberName); \
    m##type className##_##memberName(className Pt me)
#define set_get_(className, type, memberName) set_get__(className, type, memberName)
#define set_get(type, memberName) set_get_(class, type, memberName)

#define default_set__(className, type, memberName) \
    Void className##_##memberName##Set(m##className Pt me, type memberName) { me->memberName = memberName; }
#define default_set_(className, type, memberName) default_set__(className, type, memberName)
#define default_set(type, memberName) default_set_(class, type, memberName)

#define default_get__(className, type, memberName) \
    m##type className##_##memberName(className Pt me) { return me->memberName; }
#define default_get_(className, type, memberName) default_get__(className, type, memberName)
#define default_get(type, memberName) default_get_(class, type, memberName)

#define default_set_get__(className, type, memberName)                                                       \
    Void className##_##memberName##Set(m##className Pt me, type memberName) { me->memberName = memberName; } \
    m##type className##_##memberName(className Pt me) { return me->memberName; }
#define default_set_get_(className, type, memberName) default_set_get__(className, type, memberName)
#define default_set_get(type, memberName) default_set_get_(class, type, memberName)

#define fun__(className, type, functionName, arguments) \
    type className##_##functionName(m##className Pt me va_args(strip_parentheses(arguments)))
#define fun_(className, type, functionName, arguments) fun__(className, type, functionName, arguments)
#define fun(type, functionName, arguments) fun_(class, type, functionName, arguments)

#define virtual_call__(className, functionName, arguments) \
    return ((className##VT Pt)((CObject Pt) me)->vT)->functionName(me va_args(strip_parentheses(arguments)))
#define virtual_call_(className, functionName, arguments) virtual_call__(className, functionName, arguments)
#define virtual_call(functionName, arguments) virtual_call_(class, functionName, arguments)

#define add_comma(argument) , argument
#define ignore_first(arg1, ...) __VA_ARGS__
#define first(arg1, ...) arg1

#define virtual_functions_new__(className, type, functionName, arguments) \
    type super_##className##_##functionName(className Pt me for_each(add_comma, strip_parentheses(arguments)))
#define virtual_functions_new_(className, type, functionName, arguments) virtual_functions_new__(className, type, functionName, arguments)
#define virtual_functions_new(type, functionName, arguments) virtual_functions_new_(class, type, functionName, arguments)

#define override_fun__(className, type, superClassName, functionName, arguments) \
    static type override_##superClassName##_##functionName(className Pt me va_args(strip_parentheses(arguments)))
#define override_fun_(className, type, superClassName, functionName, arguments) override_fun__(className, type, superClassName, functionName, arguments)
#define override_fun(type, superClassName, functionName, arguments) override_fun_(class, type, superClassName, functionName, arguments)

#define abstract_class_init__(className, superClassName, initBlock)                    \
    static mUInt8 override_CObject_objectSize(className Pt me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(m##className); }                    \
                                                                                       \
    Void className##_init(m##className Pt me, className##InitParams Pt params)         \
    {                                                                                  \
        if (#superClassName == "CObject") { CObject_init((mCObject Pt) me); }          \
        initBlock                                                                      \
    }
#define abstract_class_init_(className, superClassName, initBlock) abstract_class_init__(className, superClassName, initBlock)
#define abstract_class_init(initBlock) abstract_class_init_(class, super_class, initBlock)

#define singleton_class_init__(className, superClassName, initBlock)                   \
    m##className mPt className##_getInstance()                                         \
    {                                                                                  \
        static m##className singleton;                                                 \
        return &singleton;                                                             \
    }                                                                                  \
                                                                                       \
    static mUInt8 override_CObject_objectSize(className Pt me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(m##className); }                    \
                                                                                       \
    Void className##_init(m##className Pt me, className##InitParams Pt params)         \
    {                                                                                  \
        if (#superClassName == "CObject") { CObject_init((mCObject Pt) me); }          \
        initBlock                                                                      \
    }
#define singleton_class_init_(className, superClassName, initBlock) singleton_class_init__(className, superClassName, initBlock)
#define singleton_class_init(initBlock) singleton_class_init_(class, super_class, initBlock)

#if CObject_useStaticPool == true
    #if CObject_useHeap == true
        #include <stdlib.h>
        #define class_init__(className, superClassName, initBlock)                             \
            m##className mPt get_##className(className##InitParams Pt params)                  \
            {                                                                                  \
                static m##className pool[className##_poolSize];                                \
                static mUInt64 count = 0;                                                      \
                m##className mPt me = null;                                                    \
                                                                                               \
                if (count < className##_poolSize)                                              \
                {                                                                              \
                    me = &pool[count];                                                         \
                    className##_init(me, params);                                              \
                    count++;                                                                   \
                }                                                                              \
                                                                                               \
                return me;                                                                     \
            }                                                                                  \
                                                                                               \
            m##className mPt new_##className(className##InitParams Pt params)                  \
            {                                                                                  \
                m##className mPt me = (m##className mPt) malloc(sizeof(m##className));         \
                className##_init(me, params);                                                  \
                return me;                                                                     \
            }                                                                                  \
                                                                                               \
            static mUInt8 override_CObject_objectSize(className Pt me) { return sizeof(*me); } \
            mUInt8 className##_classSize() { return sizeof(m##className); }                    \
                                                                                               \
            Void className##_init(m##className Pt me, className##InitParams Pt params)         \
            {                                                                                  \
                if (#superClassName == "CObject") { CObject_init((mCObject Pt) me); }          \
                initBlock                                                                      \
            }
    #else
        #define class_init__(className, superClassName, initBlock)                             \
            m##className mPt get_##className(className##InitParams Pt params)                  \
            {                                                                                  \
                static m##className pool[className##_poolSize];                                \
                static mUInt64 count = 0;                                                      \
                m##className mPt me = null;                                                    \
                                                                                               \
                if (count < className##_poolSize)                                              \
                {                                                                              \
                    me = &pool[count];                                                         \
                    className##_init(me, params);                                              \
                    count++;                                                                   \
                }                                                                              \
                                                                                               \
                return me;                                                                     \
            }                                                                                  \
                                                                                               \
            static mUInt8 override_CObject_objectSize(className Pt me) { return sizeof(*me); } \
            mUInt8 className##_classSize() { return sizeof(m##className); }                    \
                                                                                               \
            Void className##_init(m##className Pt me, className##InitParams Pt params)         \
            {                                                                                  \
                if (#superClassName == "CObject") { CObject_init((mCObject Pt) me); }          \
                initBlock                                                                      \
            }
    #endif
#else
    #if CObject_useHeap == true
        #include <stdlib.h>
        #define class_init__(className, superClassName, initBlock)                             \
            m##className mPt new_##className(className##InitParams Pt params)                  \
            {                                                                                  \
                m##className mPt me = (m##className Pt) malloc(sizeof(m##className));          \
                className##_init(me, params);                                                  \
                return me;                                                                     \
            }                                                                                  \
                                                                                               \
            static mUInt8 override_CObject_objectSize(className Pt me) { return sizeof(*me); } \
            mUInt8 className##_classSize() { return sizeof(m##className); }                    \
                                                                                               \
            Void className##_init(m##className Pt me, className##InitParams Pt params)         \
            {                                                                                  \
                if (#superClassName == "CObject") { CObject_init((mCObject Pt) me); }          \
                initBlock                                                                      \
            }
    #else
        #define class_init__(className, superClassName, initBlock)                             \
            static mUInt8 override_CObject_objectSize(className Pt me) { return sizeof(*me); } \
            mUInt8 className##_classSize() { return sizeof(m##className); }                    \
                                                                                               \
            Void className##_init(m##className Pt me, className##InitParams Pt params)         \
            {                                                                                  \
                if (#superClassName == "CObject") { CObject_init((mCObject Pt) me); }          \
                initBlock                                                                      \
            }
    #endif
#endif
#define class_init_(className, superClassName, initBlock) class_init__(className, superClassName, initBlock)
#define class_init(initBlock) class_init_(class, super_class, initBlock)
/*
#define super_class_init__(superClassName, ...) \
    superClassName##_init((m##superClassName Pt) me, ##__VA_ARGS__)
#define super_class_init_(superClassName, ...) super_class_init__(superClassName, ##__VA_ARGS__)
#define super_class_init(...) super_class_init_(super_class, ##__VA_ARGS__)
*/
#define bind_virtual_functions__(className, superClassName, virtualFunctions)                            \
    do                                                                                                   \
    {                                                                                                    \
        static m##className##VT vT;                                                                      \
        static mBoolean isVtSetupDone = false;                                                           \
                                                                                                         \
        if (isVtSetupDone == false)                                                                      \
        {                                                                                                \
            isVtSetupDone = true;                                                                        \
            *((m##superClassName##VT Pt) & vT) = *((superClassName##VT Pt)(((CObject Pt) me)->vT));      \
            ((mCObjectVT Pt) &vT)->objectSize = (mUInt8(Pt)(CObject Pt me)) override_CObject_objectSize; \
            virtualFunctions                                                                             \
        }                                                                                                \
                                                                                                         \
        ((mCObject Pt) me)->vT = (CObjectVT Pt) &vT;                                                     \
    } while (0)
#define bind_virtual_functions_(className, superClassName, virtualFunctions) bind_virtual_functions__(className, superClassName, virtualFunctions)
#define bind_virtual_functions(virtualFunctions) bind_virtual_functions_(class, super_class, virtualFunctions)

#define bind_virtual_fun__(className, functionName) \
    vT.functionName = super_##className##_##functionName
#define bind_virtual_fun_(className, functionName) bind_virtual_fun__(className, functionName)
#define bind_virtual_fun(functionName) bind_virtual_fun_(class, functionName)

#define bind_override_fun__(className, type, superClassName, functionName, ...) \
    ((m##superClassName##VT Pt) & vT)->functionName = (type(Pt)(superClassName Pt me, ##__VA_ARGS__)) override_##superClassName##_##functionName
#define bind_override_fun_(className, type, superClassName, functionName, ...) bind_override_fun__(className, type, superClassName, functionName, ##__VA_ARGS__)
#define bind_override_fun(type, superClassName, functionName, ...) bind_override_fun_(class, type, superClassName, functionName, ##__VA_ARGS__)

#endif // COBJECTUTILITIES_H
