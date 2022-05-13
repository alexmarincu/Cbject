#ifndef OBJECT_H
#define OBJECT_H
#include "Class.h"

/**
 * @brief ObjectClass
 */
typedef struct {
    extends_(Class);
} ObjectClass;

/**
 * @brief Object
 */
typedef struct {
    Type const * type;
} Object;

/**
 * @brief ObjectInterface
 */
typedef struct {
    Object * (*deinit)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
} ObjectInterface;

/**
 * @brief ObjectInterface
 * @return ObjectInterface const*
 */
ObjectInterface const * ObjectInterface_(void);

/**
 * @brief ObjectClass
 * @return ObjectClass const*
 */
ObjectClass const * ObjectClass_(void);

/**
 * @brief Initialize an object
 * @param me Object reference
 * @param type Type reference
 * @return Object* Initialized object
 */
Object * Object_init(Object * const me, Type const * const type);

/**
 * @brief Initialize an object
 * @param me Object reference
 * @param className Class name
 */
#define initObject_(me, className) Object_init(toObject_(me), toType_(className##Class_()))

/**
 * @brief Override an object
 * @param me
 * @param className
 */
#define overrideObject_(me, className) initObject_(me, className)

/**
 * @brief Override nested object
 * @param me
 * @param className
 * @param typeContainerClassName
 * @param typeName
 */
#define overrideNestedObject_(me, className, typeContainerClassName, typeName)               \
    Object_init(                                                                             \
        toObject_(nestedObjectOf_(me, typeContainerClassName, typeName)),                    \
        toType_(&to_(typeContainerClassName##Class, className##Class_())->n##typeName##Type) \
    )

/**
 * @brief Initialize nested object
 * @param me
 * @param className
 * @param typeName
 */
#define initNestedObject_(me, className, typeName)                              \
    Object_init(                                                                \
        toObject_(nestedObjectOf_(me, className, typeName)),                    \
        toType_(&to_(className##Class, className##Class_())->n##typeName##Type) \
    )

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
 * @brief Get offset from objecy
 */
#define offsetOf_(me) typeOf_(me)->offset

/**
 * @brief Get parent object from nested object
 */
#define parentObjectOf_(me) toObject_(toAny_(me) - offsetOf_(me))

/**
 * @brief Get nested object from parent object
 */
#define nestedObjectOf_(me, className, typeName) \
    to_(typeName, toAny_(me) + toType_(&to_(className##Class, classOf_(me))->n##typeName##Type)->offset)

/**
 * @brief Get class of an object
 */
#define classOf_(me) toClass_(typeOf_(me))

/**
 * @brief Get interface of an object
 */
#define interfaceOf_(me) typeOf_(me)->interface

/**
 * @brief Get the class name of an object
 */
#define classNameOf_(me) classOf_(me)->name

/**
 * @brief Get the superClass of an object
 */
#define superClassOf_(me) classOf_(me)->superClass

/**
 * @brief Get the size in memory of an object
 */
#define objectSizeOf_(me) classOf_(me)->objectSize

/**
 * @brief Call an object operation
 * @param typeName Type name of object
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define call_(typeName, operationName, ...) \
    to_(typeName##Interface, interfaceOf_(VaArgs_first_(__VA_ARGS__)))->operationName(__VA_ARGS__)

/**
 * @brief Call a parent object operation
 * @param superClassName Class name of parent object
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define superCall_(superClassName, operationName, ...) \
    to_(superClassName##Interface, toType_(superClassName##Class_())->interface)->operationName(__VA_ARGS__)

/**
 * @brief Call a nested object of parent object operation
 * @param superClassName Class name of parent object
 * @param typeName Type name of nested object
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define superNestedCall_(superClassName, typeName, operationName, ...) \
    to_(superClassName##Interface, toType_(superClassName##Class_())->interface)->n##typeName##Interface.operationName(__VA_ARGS__)

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
#define isOfClass_(me, className) Object_isOfClass(toObject_(me), toClass_(className##Class_()))

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

#define inheritInterface_(me, superClassName) \
    *to_(superClassName##Interface, me) = *superClassName##Interface_()

#define overrideNestedOperation_(me, className, typeName, operationName) \
    to_(className##Interface, me)->n##typeName##Interface.operationName = operationName

#define overrideOperation_(me, superClassName, operationName) \
    to_(superClassName##Interface, me)->operationName = operationName

#endif // OBJECT_H
