#ifndef COBJECTUTILITIES_H
#define COBJECTUTILITIES_H
#include "CObjectSettings.h"
#include "Primitives.h"

#define super_class CObject

#define abstract_class_init_params__(className, classInitParams)      \
    typedef struct className mPtr mm##className;                      \
    typedef struct className Ptr m##className;                        \
    typedef struct className const Ptr className;                     \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        classInitParams;                                              \
    };                                                                \
                                                                      \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className me, className##InitParams Ptr params)
#define abstract_class_init_params_(className, classInitParams) abstract_class_init_params__(className, classInitParams)
#define abstract_class_init_params(classInitParams) abstract_class_init_params_(class, classInitParams)

#define class_init_params__(className, classInitParams)               \
    typedef struct className mPtr mm##className;                      \
    typedef struct className Ptr m##className;                        \
    typedef struct className const Ptr className;                     \
    typedef struct className##InitParams m##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
                                                                      \
    struct className##InitParams                                      \
    {                                                                 \
        classInitParams;                                              \
    };                                                                \
                                                                      \
    mm##className className##_get(className##InitParams Ptr params);  \
    mUInt8 className##_classSize();                                   \
    Void className##_init(m##className me, className##InitParams Ptr params)
#define class_init_params_(className, classInitParams) class_init_params__(className, classInitParams)
#define class_init_params(classInitParams) class_init_params_(class, classInitParams)

#define class_members__(className, superClassName, classMembers) \
    struct className                                             \
    {                                                            \
        struct superClassName super;                             \
        classMembers;                                            \
    }
#define class_members_(className, superClassName, classMembers) class_members__(className, superClassName, classMembers)
#define class_members(classMembers) class_members_(class, super_class, classMembers)

#define data_class_members__(className, classMembers) \
    typedef struct className m##className;            \
    typedef struct className const className;         \
                                                      \
    struct className                                  \
    {                                                 \
        classMembers;                                 \
    }
#define data_class_members_(className, classMembers) data_class_members__(className, classMembers)
#define data_class_members(classMembers) data_class_members_(class, classMembers)

#define enum_class_members__(className, ...) \
    typedef enum className m##className;     \
    typedef enum className const className;  \
                                             \
    enum className                           \
    {                                        \
        __VA_ARGS__                          \
    }
#define enum_class_members_(className, ...) enum_class_members__(className, __VA_ARGS__)
#define enum_class_members(...) enum_class_members_(class, __VA_ARGS__)

#define enum_member__(className, memberName) className##_##memberName
#define enum_member_(className, memberName) enum_member__(className, memberName)
#define enum_member(memberName) enum_member_(class, memberName)

#define class_virtual_functions__(className, superClassName, classVirtualFunctions) \
    typedef struct className##VT m##className##VT;                                  \
    typedef struct className##VT const className##VT;                               \
                                                                                    \
    struct className##VT                                                            \
    {                                                                               \
        m##superClassName##VT super;                                                \
        classVirtualFunctions;                                                      \
    }
#define class_virtual_functions_(className, superClassName, classVirtualFunctions) class_virtual_functions__(className, superClassName, classVirtualFunctions)
#define class_virtual_functions(classVirtualFunctions) class_virtual_functions_(class, super_class, classVirtualFunctions)

#define Object(className, varName, ...)             \
    UInt8 varName##Stack[className##_classSize()];  \
    className varName = (className) varName##Stack; \
    className##_init((m##className) varName, ##__VA_ARGS__)

#define mObject(className, varName, ...)                  \
    UInt8 varName##Stack[className##_classSize()];        \
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
    Void className##_init(m##className me, className##InitParams Ptr params)        \
    {                                                                               \
        if (#superClassName == "CObject") { CObject_init((mCObject) me); }          \
        initBlock;                                                                  \
    }
#define abstract_class_init_(className, superClassName, initBlock) abstract_class_init__(className, superClassName, initBlock)
#define abstract_class_init(initBlock) abstract_class_init_(class, super_class, initBlock)

#if CObject_useStaticPool == true
#define class_init__(className, superClassName, initBlock)                          \
    mm##className className##_get(className##InitParams Ptr params)                 \
    {                                                                               \
        static struct className className##Pool[className##_poolSize];              \
        mm##className me = null;                                                    \
        mUInt32 i;                                                                  \
                                                                                    \
        for (i = 0; i < className##_poolSize; i++)                                  \
        {                                                                           \
            if (CObject_isInitialized((CObject) &className##Pool[i]) == false)      \
            {                                                                       \
                me = &className##Pool[i];                                           \
                className##_init(me, params);                                       \
                break;                                                              \
            }                                                                       \
        }                                                                           \
                                                                                    \
        return me;                                                                  \
    }                                                                               \
                                                                                    \
    static mUInt8 override_CObject_objectSize(className me) { return sizeof(*me); } \
    mUInt8 className##_classSize() { return sizeof(struct className); }             \
    Void className##_init(m##className me, className##InitParams Ptr params)        \
    {                                                                               \
        if (#superClassName == "CObject") { CObject_init((mCObject) me); }          \
        initBlock;                                                                  \
    }
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
            virtualFunctions;                                                                           \
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
