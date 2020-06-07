#ifndef CObjectBJECTUTILITIES_H
#define CObjectBJECTUTILITIES_H

#define CLASS(className)                         \
    typedef struct className _Ref __##className; \
    typedef struct className Ref _##className;   \
    typedef struct className const Ref className

#define ABSTRACT_CLASS_INIT_PARAMS(className)                         \
    typedef struct className _Ref __##className;                      \
    typedef struct className Ref _##className;                        \
    typedef struct className const Ref className;                     \
    typedef struct className##InitParams _##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
    struct className##InitParams                                      \
    {

#define CLASS_INIT_PARAMS(className)                                  \
    typedef struct className _Ref __##className;                      \
    typedef struct className Ref _##className;                        \
    typedef struct className const Ref className;                     \
    typedef struct className##InitParams _##className##InitParams;    \
    typedef struct className##InitParams const className##InitParams; \
    __##className get_##className(className##InitParams Ref params);  \
    Void drop_##className(__##className me);                          \
    struct className##InitParams                                      \
    {

#define CLASS_EXTENSION(className, superClassName) \
    typedef struct className _Ref __##className;   \
    typedef struct className Ref _##className;     \
    typedef struct className const Ref className

#define CLASS_EXTENSION_INIT_PARAMS(className, superClassName)        \
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

#define CLASS_MEMBERS(className)                                              \
    Void className##_init(_##className me, className##InitParams Ref params); \
    Void className##_reset(_##className me);                                  \
    struct className                                                          \
    {                                                                         \
        struct CObject super;

#define CLASS_EXTENSION_MEMBERS(className, superClassName)                    \
    Void className##_init(_##className me, className##InitParams Ref params); \
    Void className##_reset(_##className me);                                  \
    struct className                                                          \
    {                                                                         \
        struct superClassName super;

#define END }

#define DATA_CLASS(dataClassName)                     \
    typedef struct dataClassName _##dataClassName;    \
    typedef struct dataClassName const dataClassName; \
    struct dataClassName                              \
    {

#define CLASS_VIRTUAL_METHODS(className)              \
    typedef struct className##VT _##className##VT;    \
    typedef struct className##VT const className##VT; \
    struct className##VT                              \
    {                                                 \
        CObjectVT super;

#define CLASS_EXTENSION_VIRTUAL_METHODS(className, superClassName) \
    typedef struct className##VT _##className##VT;                 \
    typedef struct className##VT const className##VT;              \
    struct className##VT                                           \
    {                                                              \
        superClassName##VT super;

#endif // CObjectBJECTUTILITIES_H
