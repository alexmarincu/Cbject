#ifndef COBJECTUTILITIES_H
#define COBJECTUTILITIES_H
#include "CObjectSettings.h"
#include "Primitives.h"

#define super_class CObject

#define abstract_class_init_params__(className, ...)       \
    typedef struct className _ptr __##className;           \
    typedef struct className ptr _##className;             \
    typedef struct className const ptr className;          \
    _UInt8 className##_classSize();                        \
    Void className##_init(_##className me, ##__VA_ARGS__); \
    Void className##_reset(_##className me)
#define abstract_class_init_params_(className, ...) abstract_class_init_params__(className, ##__VA_ARGS__)
#define abstract_class_init_params(...) abstract_class_init_params_(class, ##__VA_ARGS__)

#define class_init_params__(className, ...)                \
    typedef struct className _ptr __##className;           \
    typedef struct className ptr _##className;             \
    typedef struct className const ptr className;          \
    __##className className##_get(__VA_ARGS__);            \
    Void drop_##className(__##className me);               \
    _UInt8 className##_classSize();                        \
    Void className##_init(_##className me, ##__VA_ARGS__); \
    Void className##_reset(_##className me)
#define class_init_params_(className, ...) class_init_params__(className, ##__VA_ARGS__)
#define class_init_params(...) class_init_params_(class, ##__VA_ARGS__)

#define class_members__(className, superClassName, classMembers) \
    struct className                                             \
    {                                                            \
        struct superClassName super;                             \
        classMembers;                                            \
    }
#define class_members_(className, superClassName, classMembers) class_members__(className, superClassName, classMembers)
#define class_members(classMembers) class_members_(class, super_class, classMembers)

#define end }

#define data_class_members__(className, classMembers) \
    typedef struct className _##className;            \
    typedef struct className const className;         \
    struct className                                  \
    {                                                 \
        classMembers;                                 \
    }
#define data_class_members_(className, classMembers) data_class_members__(className, classMembers)
#define data_class_members(classMembers) data_class_members_(class, classMembers)

#define class_virtual_functions__(className, superClassName, classVirtualFunctions) \
    typedef struct className##VT _##className##VT;                                  \
    typedef struct className##VT const className##VT;                               \
    struct className##VT                                                            \
    {                                                                               \
        superClassName##VT super;                                                   \
        classVirtualFunctions;                                                      \
    }
#define class_virtual_functions_(className, superClassName, classVirtualFunctions) class_virtual_functions__(className, superClassName, classVirtualFunctions)
#define class_virtual_functions(classVirtualFunctions) class_virtual_functions_(class, super_class, classVirtualFunctions)

#define $(className, varName, ...)                  \
    UInt8 varName##Size = className##_classSize();  \
    UInt8 varName##Stack[varName##Size];            \
    className varName = (className) varName##Stack; \
    className##_init((_##className) varName, ##__VA_ARGS__)

#define _$(className, varName, ...)                       \
    UInt8 varName##Size = className##_classSize();        \
    UInt8 varName##Stack[varName##Size];                  \
    _##className varName = (_##className) varName##Stack; \
    className##_init(varName, ##__VA_ARGS__)

#define set_get__(className, type, memberName)                                \
    Void className##_##memberName##Set(_##className me, type ptr memberName); \
    Void className##_##memberName##Get(className me, _##type ptr memberName)
#define set_get_(className, type, memberName) set_get__(className, type, memberName)
#define set_get(type, memberName) set_get_(class, type, memberName)

#define default_set__(className, type, memberName) \
    Void className##_##memberName##Set(_##className me, type ptr memberName) { me->memberName = *memberName; }
#define default_set_(className, type, memberName) default_set__(className, type, memberName)
#define default_set(type, memberName) default_set_(class, type, memberName)

#define default_get__(className, type, memberName) \
    Void className##_##memberName##Get(className me, _##type ptr memberName) { *memberName = me->memberName; }
#define default_get_(className, type, memberName) default_get__(className, type, memberName)
#define default_get(type, memberName) default_get_(class, type, memberName)

#define fun__(className, type, functionName, ...) \
    type className##_##functionName(className me, ##__VA_ARGS__)
#define fun_(className, type, functionName, ...) fun__(className, type, functionName, ##__VA_ARGS__)
#define fun(type, functionName, ...) fun_(class, type, functionName, ##__VA_ARGS__)

#define virtual_fun__(className, type, functionName, ...) \
    type(ptr functionName)(className me, ##__VA_ARGS__);
#define virtual_fun_(className, type, functionName, ...) virtual_fun__(className, type, functionName, ##__VA_ARGS__)
#define virtual_fun(type, functionName, ...) virtual_fun_(class, type, functionName, ##__VA_ARGS__)

#define default_fun__(className, type, functionName, ...)                                                                              \
    type className##_##functionName(className me, ##__VA_ARGS__) { return ((className##VT ptr)((CObject) me)->vT)->functionName(me); } \
    static type default_##className##_##functionName(className me, ##__VA_ARGS__)
#define default_fun_(className, type, functionName, ...) default_fun__(className, type, functionName, ##__VA_ARGS__)
#define default_fun(type, functionName, ...) default_fun_(class, type, functionName, ##__VA_ARGS__)

#define _default_fun__(className, type, functionName, ...) \
    static type default_##className##_##functionName(className me, ##__VA_ARGS__)
#define _default_fun_(className, type, functionName, ...) _default_fun__(className, type, functionName, ##__VA_ARGS__)
#define _default_fun(type, functionName, ...) _default_fun_(class, type, functionName, ##__VA_ARGS__)

#define override_fun__(className, type, superClassName, functionName, ...) \
    static type override_##superClassName##_##functionName(className me, ##__VA_ARGS__)
#define override_fun_(className, type, superClassName, functionName, ...) override_fun__(className, type, superClassName, functionName, ##__VA_ARGS__)
#define override_fun(type, superClassName, functionName, ...) override_fun_(class, type, superClassName, functionName, ##__VA_ARGS__)

#define override_virtual_fun__(className, type, superClassName, functionName, ...) \
    (type(ptr)(superClassName me, ##__VA_ARGS__)) override_##superClassName##_##functionName
#define override_virtual_fun_(className, type, superClassName, functionName, ...) override_virtual_fun__(className, type, superClassName, functionName, ##__VA_ARGS__)
#define override_virtual_fun(type, superClassName, functionName, ...) override_virtual_fun_(class, type, superClassName, functionName, ##__VA_ARGS__)

#define class_init__(className, superClassName, ...)                                \
    static _UInt8 override_CObject_objectSize(className me) { return sizeof(*me); } \
    _UInt8 className##_classSize() { return sizeof(struct className); }             \
    Void className##_init(_##className me, ##__VA_ARGS__)
#define class_init_(className, superClassName, ...) class_init__(className, superClassName, ##__VA_ARGS__)
#define class_init(...) class_init_(class, super_class, ##__VA_ARGS__)

#define super_class_init__(superClassName, ...) \
    superClassName##_init((_##superClassName) me, ##__VA_ARGS__)
#define super_class_init_(superClassName, ...) super_class_init__(superClassName, ##__VA_ARGS__)
#define super_class_init(...) super_class_init_(super_class, ##__VA_ARGS__)

#if super_class == CObject
#define bind_virtual_functions__(className, ...)                                   \
    CObject_init((_CObject) me);                                                   \
    do                                                                             \
    {                                                                              \
        static className##VT const vT = {                                          \
            (_UInt8(ptr)(CObject me)) override_CObject_objectSize, ##__VA_ARGS__}; \
        ((_CObject) me)->vT = (CObjectVT ptr) &vT;                                 \
    } while (0)
#else
#define bind_virtual_functions__(className, ...)                                   \
    do                                                                             \
    {                                                                              \
        static className##VT const vT = {                                          \
            (_UInt8(ptr)(CObject me)) override_CObject_objectSize, ##__VA_ARGS__}; \
        ((_CObject) me)->vT = (CObjectVT ptr) &vT;                                 \
    } while (0)
#endif
#define bind_virtual_functions_(className, ...) bind_virtual_functions__(className, ##__VA_ARGS__)
#define bind_virtual_functions(...) bind_virtual_functions_(class, ##__VA_ARGS__)

#endif // COBJECTUTILITIES_H
