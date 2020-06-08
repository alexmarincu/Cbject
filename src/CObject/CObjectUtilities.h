#ifndef CObjectBJECTUTILITIES_H
#define CObjectBJECTUTILITIES_H

#define ABSTRACT_CLASS_INIT_PARAMS__(className)                       \
    typedef struct className _Ref __##className;                      \
    typedef struct className Ref _##className;                        \
    typedef struct className const Ref className;                     \
    typedef struct className##InitParams _##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
    struct className##InitParams                                      \
    {
#define ABSTRACT_CLASS_INIT_PARAMS_(className) ABSTRACT_CLASS_INIT_PARAMS__(className)
#define ABSTRACT_CLASS_INIT_PARAMS ABSTRACT_CLASS_INIT_PARAMS_(CLASS_NAME)

#define CLASS_INIT_PARAMS__(className)                                \
    typedef struct className _Ref __##className;                      \
    typedef struct className Ref _##className;                        \
    typedef struct className const Ref className;                     \
    typedef struct className##InitParams _##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
    __##className get_##className(className##InitParams Ref params);  \
    Void drop_##className(__##className me);                          \
    struct className##InitParams                                      \
    {
#define CLASS_INIT_PARAMS_(className) CLASS_INIT_PARAMS__(className)
#define CLASS_INIT_PARAMS CLASS_INIT_PARAMS_(CLASS_NAME)

#define CLASS_EXTENSION_INIT_PARAMS__(className, superClassName)      \
    typedef struct className _Ref __##className;                      \
    typedef struct className Ref _##className;                        \
    typedef struct className const Ref className;                     \
    typedef struct className##InitParams _##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
    __##className get_##className(className##InitParams Ref params);  \
    Void drop_##className(__##className me);                          \
    struct className##InitParams                                      \
    {                                                                 \
        superClassName##InitParams super;
#define CLASS_EXTENSION_INIT_PARAMS_(className, superClassName) CLASS_EXTENSION_INIT_PARAMS__(className, superClassName)
#define CLASS_EXTENSION_INIT_PARAMS CLASS_EXTENSION_INIT_PARAMS_(CLASS_NAME, SUPER_CLASS_NAME)

#define CLASS_MEMBERS__(className)                                            \
    Void className##_init(_##className me, className##InitParams Ref params); \
    Void className##_reset(_##className me);                                  \
    struct className                                                          \
    {                                                                         \
        struct CObject super;
#define CLASS_MEMBERS_(className) CLASS_MEMBERS__(className)
#define CLASS_MEMBERS CLASS_MEMBERS_(CLASS_NAME)

#define CLASS_EXTENSION_MEMBERS__(className, superClassName)                  \
    Void className##_init(_##className me, className##InitParams Ref params); \
    Void className##_reset(_##className me);                                  \
    struct className                                                          \
    {                                                                         \
        struct superClassName super;
#define CLASS_EXTENSION_MEMBERS_(className, superClassName) CLASS_EXTENSION_MEMBERS__(className, superClassName)
#define CLASS_EXTENSION_MEMBERS CLASS_EXTENSION_MEMBERS_(CLASS_NAME, SUPER_CLASS_NAME)

#define END }

#define DATA_CLASS(dataClassName)                     \
    typedef struct dataClassName _##dataClassName;    \
    typedef struct dataClassName const dataClassName; \
    struct dataClassName                              \
    {

#define CLASS_VIRTUAL_METHODS__(className)            \
    typedef struct className##VT _##className##VT;    \
    typedef struct className##VT const className##VT; \
    struct className##VT                              \
    {                                                 \
        CObjectVT super;
#define CLASS_VIRTUAL_METHODS_(className) CLASS_VIRTUAL_METHODS__(className)
#define CLASS_VIRTUAL_METHODS CLASS_VIRTUAL_METHODS_(CLASS_NAME)

#define CLASS_EXTENSION_VIRTUAL_METHODS__(className, superClassName) \
    typedef struct className##VT _##className##VT;                   \
    typedef struct className##VT const className##VT;                \
    struct className##VT                                             \
    {                                                                \
        superClassName##VT super;
#define CLASS_EXTENSION_VIRTUAL_METHODS_(className, superClassName) CLASS_EXTENSION_VIRTUAL_METHODS__(className, superClassName)
#define CLASS_EXTENSION_VIRTUAL_METHODS CLASS_EXTENSION_VIRTUAL_METHODS_(CLASS_NAME, SUPER_CLASS_NAME)

#endif // CObjectBJECTUTILITIES_H
