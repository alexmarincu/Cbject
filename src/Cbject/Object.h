#ifndef OBJECT_H
#define OBJECT_H
#include "Class.h"
#include "Types.h"

/**
 * @brief class Object
 */
typedef struct Object {
    Class const * class_;
} Object;

/**
 * @brief Helper macro for extending an object
 * @param type The type of the parent object
 */
#define extends_(type) type _x##type

/**
 * @brief Helper macro for inheriting an interface
 * @param type The type of the interface
 */
#define inherits_(type) type _i##type

Object * Object_init(Object * const me, Class const * const class_);

/**
 * @brief Helper macro for initializing the root object
 * @param me
 * @param className
 */
#define initObject_(me, className) Object_init(objectOf_(me), className##Class_())

/**
 * @brief Helper macro for initializing a derived object
 * @param className The object class
 * @param ... (me The object to initialize, ... The init arguments)
 */
#define init_(className, ...) \
    className##_init((className *)VaArgs_first_(__VA_ARGS__) VaArgs_rest_(__VA_ARGS__))

/**
 * @brief Helper macro for casting to (Object *)
 */
#define objectOf_(me) ((Object *)(me))

/**
 * @brief Helper macro to get class of an object
 */
#define classOf_(me) objectOf_(me)->class_

/**
 * @brief
 */
#define superClassOf_(me) classOf_(me)->superClass

/**
 * @brief
 */
#define classNameOf_(me) classOf_(me)->name

/**
 * @brief
 */
#define objectSizeOf_(me) classOf_(me)->objectSize

/**
 * @brief
 */
#define operationsOf_(className, me) ((className##Operations *)classOf_(me)->operations)

/**
 * @brief
 */
#define superOperationsOf_(className, me) \
    ((className##Operations *)superClassOf_(me)->operations)

/**
 * @brief Helper macro for calling an object operation
 */
#define call_(className, operationName, ...) \
    operationsOf_(className, VaArgs_first_(__VA_ARGS__))->operationName(cast_(className, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))

/**
 * @brief Helper macro for calling a super object operation
 */
#define superCall_(className, operationName, ...) \
    className##Operations_()->operationName(&VaArgs_first_(__VA_ARGS__)->_x##className VaArgs_rest_(__VA_ARGS__))

/**
 * @brief Helper macro for calling a super object interface operation
 */
#define superInterfaceCall_(className, interfaceName, operationName, ...) \
    (void)VaArgs_first_(__VA_ARGS__)->_x##className._i##interfaceName;    \
    className##Operations_()->_i##interfaceName##Operations.operationName((interfaceName *)VaArgs_first_(__VA_ARGS__) VaArgs_rest_(__VA_ARGS__))

/**
 * @brief
 * @param me
 * @param class_
 * @return true
 * @return false
 */
bool Object_isOfClass(Object const * const me, Class const * const class_);

/**
 * @brief
 */
#define isOfClass_(className, me) Object_isOfClass(objectOf_(me), className##Class_())

/**
 * @brief
 * @param me
 * @param class_
 * @return Object*
 */
Object * Object_cast(Object * const me, Class const * const class_);

/**
 * @brief
 */
#define cast_(className, me) ((className *)Object_cast(objectOf_(me), className##Class_()))

/**
 * @brief
 * @param class_
 * @return Object*
 */
Object * Object_new(Class const * const class_);

/**
 * @brief
 */
#define new_(className) ((className *)Object_new(className##Class_()))

/**
 * @brief
 * @param me
 */
void Object_delete(Object * const me);

/**
 * @brief
 */
#define delete_(me) Object_delete(objectOf_(me))

/**
 * @brief
 * @param me
 */
void Object_finalize(Object * me);

/**
 * @brief
 */
#define finalize_(me) Object_finalize(objectOf_(me))

/**
 * @brief
 * @param me
 * @return Object*
 */
Object * Object_copy(Object const * const me);

/**
 * @brief
 */
#define copy_(className, me) cast_(className, Object_copy(objectOf_(me)))

/**
 * @brief
 * @param me
 * @param other
 * @return true
 * @return false
 */
bool Object_equals(Object const * const me, Object const * const other);

/**
 * @brief
 */
#define equals_(me, other) Object_equals(objectOf_(me), objectOf_(other))

/**
 * @brief
 * @param me
 * @return uint64_t
 */
uint64_t Object_hashCode(Object const * const me);

/**
 * @brief
 */
#define hashCode_(me) Object_hashCode(objectOf_(me))

/**
 * @brief Contains Object's operations (aka virtual functions)
 */
typedef struct ObjectOperations {
    void (*finalize)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
} ObjectOperations;

/**
 * @brief
 * @return ObjectOperations const*
 */
ObjectOperations const * ObjectOperations_(void);

/**
 * @brief
 * @return Class const*
 */
Class const * ObjectClass_(void);

#endif // OBJECT_H
