#ifndef COBJECTUTILITIES_H
#define COBJECTUTILITIES_H

#define ABSTRACT_CLASS_INIT_PARAMS__(className)                            \
    typedef struct className _Ref __##className;                           \
    typedef struct className Ref _##className;                             \
    typedef struct className const Ref className;                          \
    typedef struct className##InitParams _##className##InitParams;         \
    typedef struct className##InitParams const className##InitParams;      \
    Void className##_init(className me, className##InitParams Ref params); \
    Void className##_reset(className me);                                  \
    struct className##InitParams                                           \
    {
#define ABSTRACT_CLASS_INIT_PARAMS_(className) ABSTRACT_CLASS_INIT_PARAMS__(className)
#define ABSTRACT_CLASS_INIT_PARAMS ABSTRACT_CLASS_INIT_PARAMS_(CLASS_NAME)

#define CLASS_INIT_PARAMS__(className)                                     \
    typedef struct className _Ref __##className;                           \
    typedef struct className Ref _##className;                             \
    typedef struct className const Ref className;                          \
    typedef struct className##InitParams _##className##InitParams;         \
    typedef struct className##InitParams const className##InitParams;      \
    __##className get_##className(className##InitParams Ref params);       \
    Void drop_##className(__##className me);                               \
    _UInt8 className##_classSize();                                        \
    Void className##_init(className me, className##InitParams Ref params); \
    Void className##_reset(className me);                                  \
    struct className##InitParams                                           \
    {
#define CLASS_INIT_PARAMS_(className) CLASS_INIT_PARAMS__(className)
#define CLASS_INIT_PARAMS CLASS_INIT_PARAMS_(CLASS_NAME)

#define CLASS_EXTENSION_INIT_PARAMS__(className, superClassName)           \
    typedef struct className _Ref __##className;                           \
    typedef struct className Ref _##className;                             \
    typedef struct className const Ref className;                          \
    typedef struct className##InitParams _##className##InitParams;         \
    typedef struct className##InitParams const className##InitParams;      \
    __##className get_##className(className##InitParams Ref params);       \
    Void drop_##className(__##className me);                               \
    _UInt8 className##_classSize();                                        \
    Void className##_init(className me, className##InitParams Ref params); \
    Void className##_reset(className me);                                  \
    struct className##InitParams                                           \
    {                                                                      \
        superClassName##InitParams super;
#define CLASS_EXTENSION_INIT_PARAMS_(className, superClassName) CLASS_EXTENSION_INIT_PARAMS__(className, superClassName)
#define CLASS_EXTENSION_INIT_PARAMS CLASS_EXTENSION_INIT_PARAMS_(CLASS_NAME, SUPER_CLASS_NAME)

#define class_members__(className) \
    struct className               \
    {                              \
        struct CObject super;
#define class_members_(className) class_members__(className)
#define class_members class_members_(CLASS_NAME)

#define class_extension_members__(className, superClassName) \
    struct className                                         \
    {                                                        \
        struct superClassName super;
#define class_extension_members_(className, superClassName) class_extension_members__(className, superClassName)
#define class_extension_members class_extension_members_(CLASS_NAME, SUPER_CLASS_NAME)

#define end }

#define DATA_CLASS(dataClassName)                     \
    typedef struct dataClassName _##dataClassName;    \
    typedef struct dataClassName const dataClassName; \
    struct dataClassName                              \
    {

#define class_virtual_functions__(className)            \
    typedef struct className##VT _##className##VT;    \
    typedef struct className##VT const className##VT; \
    struct className##VT                              \
    {                                                 \
        CObjectVT super;
#define class_virtual_functions_(className) class_virtual_functions__(className)
#define class_virtual_functions class_virtual_functions_(CLASS_NAME)

#define class_extension_virtual_functions__(className, superClassName) \
    typedef struct className##VT _##className##VT;                   \
    typedef struct className##VT const className##VT;                \
    struct className##VT                                             \
    {                                                                \
        superClassName##VT super;
#define class_extension_virtual_functions_(className, superClassName) class_extension_virtual_functions__(className, superClassName)
#define class_extension_virtual_functions class_extension_virtual_functions_(CLASS_NAME, SUPER_CLASS_NAME)

#define $(className, varName, initParams)           \
    UInt8 varName##Size = className##_classSize();  \
    UInt8 varName##Stack[varName##Size];            \
    className varName = (className) varName##Stack; \
    className##_init((_##className) varName, initParams)

#define _$(className, varName, initParams)                \
    UInt8 varName##Size = className##_classSize();        \
    UInt8 varName##Stack[varName##Size];                  \
    _##className varName = (_##className) varName##Stack; \
    className##_init(varName, initParams)

#define set_get__(className, type, memberName)                          \
    Void className##_##memberName##Set(_##className me, type Ref memberName); \
    Void className##_##memberName##Get(className me, _##type Ref memberName)
#define set_get_(className, type, memberName) set_get__(className, type, memberName)
#define set_get(type, memberName) set_get_(CLASS_NAME, type, memberName)

#define default_set__(className, type, memberName) \
    Void className##_##memberName##Set(_##className me, type Ref memberName) { me->memberName = *memberName; }
#define default_set_(className, type, memberName) default_set__(className, type, memberName)
#define default_set(type, memberName) default_set_(CLASS_NAME, type, memberName)

#define default_get__(className, type, memberName) \
    Void className##_##memberName##Get(className me, _##type Ref memberName) { *memberName = me->memberName; }
#define default_get_(className, type, memberName) default_get__(className, type, memberName)
#define default_get(type, memberName) default_get_(CLASS_NAME, type, memberName)

#define fun__(className, type, functionName, ...) \
    type className##_##functionName(className me, ##__VA_ARGS__)
#define fun_(className, type, functionName, ...) fun__(className, type, functionName, ##__VA_ARGS__)
#define fun(type, functionName, ...) fun_(CLASS_NAME, type, functionName, ##__VA_ARGS__)

#define virtual_fun__(className, type, functionName, ...) \
    type(Ref functionName)(className me, ##__VA_ARGS__);
#define virtual_fun_(className, type, functionName, ...) virtual_fun__(className, type, functionName, ##__VA_ARGS__)
#define virtual_fun(type, functionName, ...) virtual_fun_(CLASS_NAME, type, functionName, ##__VA_ARGS__)

#define default_fun__(className, type, functionName, ...)                                                                         \
    type className##_##functionName(className me, ##__VA_ARGS__) { return ((className##VT Ref)((CObject) me)->vT)->functionName(me); } \
    static type default_##className##_##functionName(className me, ##__VA_ARGS__)
#define default_fun_(className, type, functionName, ...) default_fun__(className, type, functionName, ##__VA_ARGS__)
#define default_fun(type, functionName, ...) default_fun_(CLASS_NAME, type, functionName, ##__VA_ARGS__)

#define _default_fun__(className, type, functionName, ...) \
    static type default_##className##_##functionName(className me, ##__VA_ARGS__)
#define _default_fun_(className, type, functionName, ...) _default_fun__(className, type, functionName, ##__VA_ARGS__)
#define _default_fun(type, functionName, ...) _default_fun_(CLASS_NAME, type, functionName, ##__VA_ARGS__)

#define override_fun__(className, superClassName, type, functionName, ...) \
    static type override_##superClassName##_##functionName(className me, ##__VA_ARGS__)
#define override_fun_(className, superClassName, type, functionName, ...) override_fun__(className, superClassName, type, functionName, ##__VA_ARGS__)
#define override_fun(superClassName, type, functionName, ...) override_fun_(CLASS_NAME, superClassName, type, functionName, ##__VA_ARGS__)

#endif // COBJECTUTILITIES_H
