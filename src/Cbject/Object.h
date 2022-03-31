#ifndef OBJECT_H
#define OBJECT_H
#include "Class.h"
#include "Types.h"

/**
 * @brief Object members
 *
 */
typedef struct Object {
    Class const * class_;
} Object;

/**
 * @brief Helper macro for extending an object
 *
 * @param type The type of the parent object
 */
#define extends_(type) type _x##type

/**
 * @brief Helper macro for inheriting an interface
 *
 */
#define inherits_(type) type _i##type

/**
 * @brief Initializes an object
 *
 * @param this_ The object
 * @param class_ The class
 * @return Object* The initialized object
 */
Object * Object_init(Object * const this_, Class const * const class_);

/**
 * @brief Helper macro for initializing an object
 *
 */
#define initObject_(this_, class_) Object_init(objectOf_(this_), class_)

/**
 * @brief Helper macro for casting to (Object *)
 *
 */
#define objectOf_(this_) ((Object *)(this_))

/**
 * @brief Helper macro to get class of an object
 *
 */
#define classOf_(this_) objectOf_(this_)->class_

/**
 * @brief
 *
 */
#define superClassOf_(this_) classOf_(this_)->superClass

/**
 * @brief
 *
 */
#define classNameOf_(this_) classOf_(this_)->name

/**
 * @brief
 *
 */
#define objectSizeOf_(this_) classOf_(this_)->objectSize

/**
 * @brief
 *
 */
#define operationsOf_(className, this_) ((className##Operations *)classOf_(this_)->operations)

/**
 * @brief
 *
 */
#define superOperationsOf_(className, this_) \
    ((className##Operations *)superClassOf_(this_)->operations)

/**
 * @brief
 *
 */
#define call_(className, operationName, this_) \
    operationsOf_(className, this_)->operationName(cast_(className, this_))

/**
 * @brief
 *
 */
#define callWithArgs_(className, operationName, this_, ...) \
    operationsOf_(className, this_)->operationName(cast_(className, this_), __VA_ARGS__)

/**
 * @brief
 *
 */
#define superCall_(className, operationName, this_) \
    superOperationsOf_(className, this_)->operationName(cast_(className, this_))

/**
 * @brief
 *
 */
#define supercallWithArgs_(className, operationName, this_, ...) \
    superOperationsOf_(className, this_)->operationName(cast_(className, this_), __VA_ARGS__)

/**
 * @brief
 *
 * @param this_
 * @param class_
 * @return true
 * @return false
 */
bool Object_isOfClass(Object const * const this_, Class const * const class_);

/**
 * @brief
 *
 */
#define isOfClass_(this_, class_) Object_isOfClass(objectOf_(this_), class_)

/**
 * @brief
 *
 * @param this_
 * @param class_
 * @return Object*
 */
Object * Object_cast(Object * const this_, Class const * const class_);

/**
 * @brief
 *
 */
#define cast_(className, this_) ((className *)Object_cast(objectOf_(this_), className##Class_()))

/**
 * @brief
 *
 * @param class_
 * @return Object*
 */
Object * Object_new(Class const * const class_);

/**
 * @brief
 *
 */
#define new_(className) ((className *)Object_new(className##Class_()))

/**
 * @brief
 *
 */
#define obj_(className) (&(className){ 0 })

/**
 * @brief
 *
 * @param this_
 */
void Object_delete(Object * const this_);

/**
 * @brief
 *
 */
#define delete_(this_) Object_delete(objectOf_(this_))

/**
 * @brief
 *
 * @param this_
 */
void Object_finalize(Object * this_);
typedef void (*ObjectOperation_finalize)(Object * this_);

/**
 * @brief
 *
 */
#define finalize_(this_) Object_finalize(objectOf_(this_))

/**
 * @brief
 *
 * @param this_
 * @return Object*
 */
Object * Object_copy(Object const * const this_);
typedef Object * (*ObjectOperation_copy)(Object const * const this_);

/**
 * @brief
 *
 */
#define copy_(className, this_) ((className *)Object_copy(objectOf_(this_)))

/**
 * @brief
 *
 * @param this_
 * @param other
 * @return true
 * @return false
 */
bool Object_equals(Object const * const this_, Object const * const other);
typedef bool (*ObjectOperation_equals)(Object const * const this_, Object const * const other);

/**
 * @brief
 *
 */
#define equals_(this_, other) Object_equals(objectOf_(this_), objectOf_(other))

/**
 * @brief
 *
 * @param this_
 * @return uint64_t
 */
uint64_t Object_hashCode(Object const * const this_);
typedef uint64_t (*ObjectOperation_hashCode)(Object const * const this_);

/**
 * @brief
 *
 */
#define hashCode_(this_) Object_hashCode(objectOf_(this_))

/**
 * @brief
 *
 */
typedef struct ObjectOperations {
    ObjectOperation_finalize finalize;
    ObjectOperation_hashCode hashCode;
    ObjectOperation_copy copy;
    ObjectOperation_equals equals;
} ObjectOperations;

/**
 * @brief
 *
 * @return ObjectOperations const*
 */
ObjectOperations const * ObjectOperations_(void);

/**
 * @brief
 *
 * @return Class const*
 */
Class const * ObjectClass_(void);

#endif // OBJECT_H
