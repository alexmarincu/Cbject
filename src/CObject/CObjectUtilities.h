#ifndef COBJECTUTILITIES_H
#define COBJECTUTILITIES_H
#include "CObjectSettings.h"
#include "Primitives.h"

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

#define abstract_class_init_params__(className, classInitParams)      \
    typedef struct className mPtr mm##className;                      \
    typedef struct className Ptr m##className;                        \
    typedef struct className const Ptr className;                     \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        classInitParams                                               \
    };                                                                \
                                                                      \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className me, className##InitParams Ptr params)
#define abstract_class_init_params_(className, classInitParams) abstract_class_init_params__(className, classInitParams)
#define abstract_class_init_params(classInitParams) abstract_class_init_params_(class, classInitParams)

#define singleton_class_init_params__(className, classInitParams)     \
    typedef struct className mPtr mm##className;                      \
    typedef struct className Ptr m##className;                        \
    typedef struct className const Ptr className;                     \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        classInitParams                                               \
    };                                                                \
                                                                      \
    mm##className className##_get();                                  \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className me, className##InitParams Ptr params)
#define singleton_class_init_params_(className, classInitParams) singleton_class_init_params__(className, classInitParams)
#define singleton_class_init_params(classInitParams) singleton_class_init_params_(class, classInitParams)

#if CObject_useStaticPool == true
#if CObject_useHeap == true
#define class_init_params__(className, classInitParams)               \
    typedef struct className mPtr mm##className;                      \
    typedef struct className Ptr m##className;                        \
    typedef struct className const Ptr className;                     \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        classInitParams                                               \
    };                                                                \
                                                                      \
    mm##className className##_get(className##InitParams Ptr params);  \
    mm##className className##_new(className##InitParams Ptr params);  \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className me, className##InitParams Ptr params)
#else
#define class_init_params__(className, classInitParams)               \
    typedef struct className mPtr mm##className;                      \
    typedef struct className Ptr m##className;                        \
    typedef struct className const Ptr className;                     \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        classInitParams                                               \
    };                                                                \
                                                                      \
    mm##className className##_get(className##InitParams Ptr params);  \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className me, className##InitParams Ptr params)
#endif
#else
#if CObject_useHeap == true
#define class_init_params__(className, classInitParams)               \
    typedef struct className mPtr mm##className;                      \
    typedef struct className Ptr m##className;                        \
    typedef struct className const Ptr className;                     \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        classInitParams                                               \
    };                                                                \
                                                                      \
    mm##className className##_new(className##InitParams Ptr params);  \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className me, className##InitParams Ptr params)
#else
#define class_init_params__(className, classInitParams)               \
    typedef struct className mPtr mm##className;                      \
    typedef struct className Ptr m##className;                        \
    typedef struct className const Ptr className;                     \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        classInitParams                                               \
    };                                                                \
                                                                      \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className me, className##InitParams Ptr params)
#endif
#endif
#define class_init_params_(className, classInitParams) class_init_params__(className, classInitParams)
#define class_init_params(classInitParams) class_init_params_(class, classInitParams)

#if CObject_useStaticPool == true
#define class_pool_size__(className, poolSize) \
    enum                                       \
    {                                          \
        className##_poolSize = poolSize        \
    }
#define class_pool_size_(className, poolSize) class_pool_size__(className, poolSize)
#define class_pool_size(poolSize) class_pool_size_(class, poolSize)
#endif

#define class_members__(className, superClassName, classMembers) \
    struct className                                             \
    {                                                            \
        struct superClassName super;                             \
        classMembers                                             \
    }
#define class_members_(className, superClassName, classMembers) class_members__(className, superClassName, classMembers)
#define class_members(classMembers) class_members_(class, super_class, classMembers)

#define singleton_class_members__(className, superClassName, classMembers) \
    struct className                                                       \
    {                                                                      \
        struct superClassName super;                                       \
        classMembers                                                       \
    };                                                                     \
                                                                           \
    typedef struct className##VT m##className##VT;                         \
    typedef struct className##VT const className##VT;                      \
                                                                           \
    struct className##VT                                                   \
    {                                                                      \
        m##superClassName##VT super;                                       \
    }
#define singleton_class_members_(className, superClassName, classMembers) singleton_class_members__(className, superClassName, classMembers)
#define singleton_class_members(classMembers) singleton_class_members_(class, super_class, classMembers)

#define data_class_members__(className, classMembers) \
    typedef struct className m##className;            \
    typedef struct className const className;         \
                                                      \
    struct className                                  \
    {                                                 \
        classMembers                                  \
    }
#define data_class_members_(className, classMembers) data_class_members__(className, classMembers)
#define data_class_members(classMembers) data_class_members_(class, classMembers)

#define enum_val__(className, valueName) className##_##valueName,
#define enum_val_(className, valueName) enum_val__(className, valueName)
#define enum_val(valueName) enum_val_(class, valueName)

#define enum_class_values__(className, ...) \
    typedef enum className m##className;    \
    typedef enum className const className; \
                                            \
    enum className                          \
    {                                       \
        for_each(enum_val, __VA_ARGS__)     \
    }
#define enum_class_values_(className, ...) enum_class_values__(className, __VA_ARGS__)
#define enum_class_values(...) enum_class_values_(class, __VA_ARGS__)

#define class_virtual_functions__(className, superClassName, classVirtualFunctions) \
    typedef struct className##VT m##className##VT;                                  \
    typedef struct className##VT const className##VT;                               \
                                                                                    \
    struct className##VT                                                            \
    {                                                                               \
        m##superClassName##VT super;                                                \
        classVirtualFunctions                                                       \
    }
#define class_virtual_functions_(className, superClassName, classVirtualFunctions) class_virtual_functions__(className, superClassName, classVirtualFunctions)
#define class_virtual_functions(classVirtualFunctions) class_virtual_functions_(class, super_class, classVirtualFunctions)

#define Object(className, varName, ...)             \
    Byte varName##Stack[className##_classSize()];   \
    className varName = (className) varName##Stack; \
    className##_init((m##className) varName, ##__VA_ARGS__)

#define mObject(className, varName, ...)                  \
    Byte varName##Stack[className##_classSize()];         \
    m##className varName = (m##className) varName##Stack; \
    className##_init(varName, ##__VA_ARGS__)

#define set_get__(className, type, memberName)                            \
    Void className##_##memberName##Set(m##className me, type memberName); \
    m##type className##_##memberName##Get(className me)
#define set_get_(className, type, memberName) set_get__(className, type, memberName)
#define set_get(type, memberName) set_get_(class, type, memberName)

#define default_set__(className, type, memberName) \
    Void className##_##memberName##Set(m##className me, type memberName) { me->memberName = memberName; }
#define default_set_(className, type, memberName) default_set__(className, type, memberName)
#define default_set(type, memberName) default_set_(class, type, memberName)

#define default_get__(className, type, memberName) \
    m##type className##_##memberName##Get(className me) { return me->memberName; }
#define default_get_(className, type, memberName) default_get__(className, type, memberName)
#define default_get(type, memberName) default_get_(class, type, memberName)

#define default_set_get__(className, type, memberName)                                                    \
    Void className##_##memberName##Set(m##className me, type memberName) { me->memberName = memberName; } \
    m##type className##_##memberName##Get(className me) { return me->memberName; }
#define default_set_get_(className, type, memberName) default_set_get__(className, type, memberName)
#define default_set_get(type, memberName) default_set_get_(class, type, memberName)

#define fun__(className, type, functionName, ...) \
    type className##_##functionName(className me, ##__VA_ARGS__)
#define fun_(className, type, functionName, ...) fun__(className, type, functionName, ##__VA_ARGS__)
#define fun(type, functionName, ...) fun_(class, type, functionName, ##__VA_ARGS__)

#define virtual_function__(className, type, functionName, ...) \
    type(mPtr functionName)(className me, ##__VA_ARGS__)
#define virtual_function_(className, type, functionName, ...) virtual_function__(className, type, functionName, ##__VA_ARGS__)
#define virtual_function(type, functionName, ...) virtual_function_(class, type, functionName, ##__VA_ARGS__)

#define virtual_call__(className, functionName, ...) \
    return ((className##VT Ptr)((CObject) me)->vT)->functionName(me, ##__VA_ARGS__)
#define virtual_call_(className, functionName, ...) virtual_call__(className, functionName, ##__VA_ARGS__)
#define virtual_call(functionName, ...) virtual_call_(class, functionName, ##__VA_ARGS__)

#define virtual_fun__(className, type, functionName, ...) \
    type super_##className##_##functionName(className me, ##__VA_ARGS__)
#define virtual_fun_(className, type, functionName, ...) virtual_fun__(className, type, functionName, ##__VA_ARGS__)
#define virtual_fun(type, functionName, ...) virtual_fun_(class, type, functionName, ##__VA_ARGS__)

#define default_fun__(className, call, type, functionName, ...)            \
    type className##_##functionName(className me, ##__VA_ARGS__) { call; } \
    type super_##className##_##functionName(className me, ##__VA_ARGS__)
#define default_fun_(className, call, type, functionName, ...) default_fun__(className, call, type, functionName, ##__VA_ARGS__)
#define default_fun(call, type, functionName, ...) default_fun_(class, call, type, functionName, ##__VA_ARGS__)

#define override_fun__(className, type, superClassName, functionName, ...) \
    static type override_##superClassName##_##functionName(className me, ##__VA_ARGS__)
#define override_fun_(className, type, superClassName, functionName, ...) override_fun__(className, type, superClassName, functionName, ##__VA_ARGS__)
#define override_fun(type, superClassName, functionName, ...) override_fun_(class, type, superClassName, functionName, ##__VA_ARGS__)

#define abstract_class_init__(className, superClassName, initBlock)                 \
    static mUInt8 override_CObject_objectSize(className me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(struct className); }             \
                                                                                    \
    Void className##_init(m##className me, className##InitParams Ptr params)        \
    {                                                                               \
        if (#superClassName == "CObject") { CObject_init((mCObject) me); }          \
        initBlock                                                                   \
    }
#define abstract_class_init_(className, superClassName, initBlock) abstract_class_init__(className, superClassName, initBlock)
#define abstract_class_init(initBlock) abstract_class_init_(class, super_class, initBlock)

#define singleton_class_init__(className, superClassName, initBlock)                \
    mm##className className##_get()                                                 \
    {                                                                               \
        static struct className singleton;                                          \
        return &singleton;                                                          \
    }                                                                               \
                                                                                    \
    static mUInt8 override_CObject_objectSize(className me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(struct className); }             \
                                                                                    \
    Void className##_init(m##className me, className##InitParams Ptr params)        \
    {                                                                               \
        if (#superClassName == "CObject") { CObject_init((mCObject) me); }          \
        initBlock                                                                   \
    }
#define singleton_class_init_(className, superClassName, initBlock) singleton_class_init__(className, superClassName, initBlock)
#define singleton_class_init(initBlock) singleton_class_init_(class, super_class, initBlock)

#if CObject_useStaticPool == true
#if CObject_useHeap == true
#include <stdlib.h>
#define class_init__(className, superClassName, initBlock)                          \
    mm##className className##_get(className##InitParams Ptr params)                 \
    {                                                                               \
        static struct className pool[className##_poolSize];                         \
        static mUInt64 count = 0;                                                   \
        mm##className me = null;                                                    \
                                                                                    \
        if (count < className##_poolSize)                                           \
        {                                                                           \
            me = &pool[count];                                                      \
            className##_init(me, params);                                           \
            count++;                                                                \
        }                                                                           \
                                                                                    \
        return me;                                                                  \
    }                                                                               \
                                                                                    \
    mm##className className##_new(className##InitParams Ptr params)                 \
    {                                                                               \
        mm##className me = (mm##className) malloc(sizeof(struct className));        \
        className##_init(me, params);                                               \
        return me;                                                                  \
    }                                                                               \
                                                                                    \
    static mUInt8 override_CObject_objectSize(className me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(struct className); }             \
                                                                                    \
    Void className##_init(m##className me, className##InitParams Ptr params)        \
    {                                                                               \
        if (#superClassName == "CObject") { CObject_init((mCObject) me); }          \
        initBlock                                                                   \
    }
#else
#define class_init__(className, superClassName, initBlock)                          \
    mm##className className##_get(className##InitParams Ptr params)                 \
    {                                                                               \
        static struct className pool[className##_poolSize];                         \
        static mUInt64 count = 0;                                                   \
        mm##className me = null;                                                    \
                                                                                    \
        if (count < className##_poolSize)                                           \
        {                                                                           \
            me = &pool[count];                                                      \
            className##_init(me, params);                                           \
            count++;                                                                \
        }                                                                           \
                                                                                    \
        return me;                                                                  \
    }                                                                               \
                                                                                    \
    static mUInt8 override_CObject_objectSize(className me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(struct className); }             \
                                                                                    \
    Void className##_init(m##className me, className##InitParams Ptr params)        \
    {                                                                               \
        if (#superClassName == "CObject") { CObject_init((mCObject) me); }          \
        initBlock                                                                   \
    }
#endif
#else
#if CObject_useHeap == true
#include <stdlib.h>
#define class_init__(className, superClassName, initBlock)                          \
    mm##className className##_new(className##InitParams Ptr params)                 \
    {                                                                               \
        mm##className me = (mm##className) malloc(sizeof(struct className));        \
        className##_init(me, params);                                               \
        return me;                                                                  \
    }                                                                               \
                                                                                    \
    static mUInt8 override_CObject_objectSize(className me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(struct className); }             \
                                                                                    \
    Void className##_init(m##className me, className##InitParams Ptr params)        \
    {                                                                               \
        if (#superClassName == "CObject") { CObject_init((mCObject) me); }          \
        initBlock                                                                   \
    }
#else
#define class_init__(className, superClassName, initBlock)                          \
    static mUInt8 override_CObject_objectSize(className me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(struct className); }             \
                                                                                    \
    Void className##_init(m##className me, className##InitParams Ptr params)        \
    {                                                                               \
        if (#superClassName == "CObject") { CObject_init((mCObject) me); }          \
        initBlock                                                                   \
    }
#endif
#endif
#define class_init_(className, superClassName, initBlock) class_init__(className, superClassName, initBlock)
#define class_init(initBlock) class_init_(class, super_class, initBlock)

#define super_class_init__(superClassName, ...) \
    superClassName##_init((m##superClassName) me, ##__VA_ARGS__)
#define super_class_init_(superClassName, ...) super_class_init__(superClassName, ##__VA_ARGS__)
#define super_class_init(...) super_class_init_(super_class, ##__VA_ARGS__)

#define bind_virtual_functions__(className, superClassName, virtualFunctions)                           \
    do                                                                                                  \
    {                                                                                                   \
        static m##className##VT vT;                                                                     \
        static mBoolean isVtSetupDone = false;                                                          \
                                                                                                        \
        if (isVtSetupDone == false)                                                                     \
        {                                                                                               \
            isVtSetupDone = true;                                                                       \
            *((m##superClassName##VT Ptr) & vT) = *((superClassName##VT Ptr)(((CObject) me)->vT));      \
            ((mCObjectVT Ptr) &vT)->objectSize = (mUInt8(Ptr)(CObject me)) override_CObject_objectSize; \
            virtualFunctions                                                                            \
        }                                                                                               \
                                                                                                        \
        ((mCObject) me)->vT = (CObjectVT Ptr) &vT;                                                      \
    } while (0)
#define bind_virtual_functions_(className, superClassName, virtualFunctions) bind_virtual_functions__(className, superClassName, virtualFunctions)
#define bind_virtual_functions(virtualFunctions) bind_virtual_functions_(class, super_class, virtualFunctions)

#define bind_virtual_fun__(className, functionName) \
    vT.functionName = super_##className##_##functionName
#define bind_virtual_fun_(className, functionName) bind_virtual_fun__(className, functionName)
#define bind_virtual_fun(functionName) bind_virtual_fun_(class, functionName)

#define bind_override_fun__(className, type, superClassName, functionName, ...) \
    ((m##superClassName##VT Ptr) & vT)->functionName = (type(Ptr)(superClassName me, ##__VA_ARGS__)) override_##superClassName##_##functionName
#define bind_override_fun_(className, type, superClassName, functionName, ...) bind_override_fun__(className, type, superClassName, functionName, ##__VA_ARGS__)
#define bind_override_fun(type, superClassName, functionName, ...) bind_override_fun_(class, type, superClassName, functionName, ##__VA_ARGS__)

#endif // COBJECTUTILITIES_H
