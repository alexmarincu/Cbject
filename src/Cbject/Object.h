#ifndef OBJECT_H
#define OBJECT_H
#include "Class.h"

class_(Object);

/**
 * @brief ObjectOperations
 */
typedef struct ObjectOperations {
    Object * (*deinit)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
} ObjectOperations;

/**
 * @brief ObjectClass
 */
struct ObjectClass {
    extend_(Class);
};

/**
 * @brief Object
 */
struct Object {
    Type const * type;
};

/**
 * @brief ObjectOperations
 * @return ObjectOperations const*
 */
ObjectOperations const * ObjectOperations_(void);

/**
 * @brief ObjectClass
 * @return ObjectClass const*
 */
ObjectClass const * ObjectClass_(void);

/**
 * @brief Initialize an object
 * @param me The object
 * @param cls The class
 * @return Object* The initialized object
 */
Object * Object_init(Object * const me, Type const * const type);

/**
 * @brief Initialize the root object
 * @param me
 * @param className
 */
#define initObject_(me, type) Object_init(toObject_(me), toType_(type))

/**
 * @brief Initialize a derived object
 * @param className The object class
 * @param ... (me The object to initialize, ... The init arguments)
 */
#define init_(className, ...) \
    className##_init(to_(className, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))

/**
 * @brief Get type of an object
 */
#define typeOf_(me) toObject_(me)->type

/**
 * @brief Get object offset from object or interface
 */
#define objectOffsetOf_(me) typeOf_(me)->offset

/**
 * @brief Get object from object or interface
 */
#define objectOf_(me) toObject_(toAny_(me) - objectOffsetOf_(me))

/**
 * @brief Get class of an object
 */
#define classOf_(me) toClass_(typeOf_(me))

/**
 * @brief Get interface of an object
 */
#define interfaceOf_(me) toInterface_(typeOf_(me))

/**
 * @brief Get the class name of an object
 */
#define classNameOf_(me) classOf_(me)->name

/**
 * @brief Get the size in memory of an object
 */
#define objectSizeOf_(me) classOf_(me)->objectSize

/**
 * @brief Call an object operation
 */
#define call_(typeName, operationName, ...) \
    to_(typeName##Operations, interfaceOf_(VaArgs_first_(__VA_ARGS__))->operations)->operationName(__VA_ARGS__)

/**
 * @brief
 * @param me
 * @param cls
 * @return true
 * @return false
 */
bool Object_isOfClass(Object const * const me, Class const * const cls);

/**
 * @brief
 */
#define isOfClass_(className, me) Object_isOfClass(toObject_(me), toClass_(className##Class_()))

/**
 * @brief
 * @param cls
 * @return Object*
 */
Object * Object_alloc(Class const * const cls);

/**
 * @brief
 */
#define alloc_(className) to_(className, Object_alloc(toClass_(className##Class_())))

/**
 * @brief
 * @param me
 */
Object * Object_dealloc(Object * const me);

/**
 * @brief
 */
#define dealloc_(me) Object_dealloc(toObject_(me))

/**
 * @brief
 * @param me
 */
Object * Object_deinit(Object * me);

/**
 * @brief
 */
#define deinit_(me) toAny_(Object_deinit(toObject_(me)))

/**
 * @brief
 * @param me
 * @return Object*
 */
Object * Object_copy(Object const * const me);

/**
 * @brief
 */
#define copy_(className, me) to_(className, Object_copy(toObject_(me)))

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
#define equals_(me, other) Object_equals(toObject_(me), toObject_(other))

/**
 * @brief
 * @param me
 * @return uint64_t
 */
uint64_t Object_hashCode(Object const * const me);

/**
 * @brief
 */
#define hashCode_(me) Object_hashCode(toObject_(me))

/**
 * @brief Cast to (Object *)
 */
#define toObject_(me) to_(Object, (me))

#endif // OBJECT_H
