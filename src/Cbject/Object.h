#ifndef OBJECT_H
#define OBJECT_H
#include "Class.h"
/**
 * @brief Object_Class
 */
typedef struct {
    extends_(Class);
} Object_Class;
/**
 * @brief Object
 */
typedef struct {
    Interface const * interface;
} Object;
/**
 * @brief Object_Operations
 */
typedef struct {
    Object * (*deinit)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
} Object_Operations;
/**
 * @brief Object_Operations
 * @return Object_Operations const*
 */
Object_Operations const * Object_Operations_(void);
/**
 * @brief Object_Class
 * @return Object_Class const*
 */
Object_Class const * Object_Class_(void);
/**
 * @brief Initialize an object
 * @param me Object reference
 * @param type Interface reference
 * @return Object* Initialized object
 */
Object * Object_init(Object * const me, Interface const * const interface);
/**
 * @brief Set interface of object
 * @param me Object reference
 * @param type Interface reference
 */
void Object_setInterface(Object * const me, Interface const * const interface);
/**
 * @brief Initialize an object
 * @param me Object reference
 * @param className Class name
 */
#define initObject_(me, className) Object_init(toObject_(me), toInterface_(className##_Class_()))
/**
 * @brief Set class of object
 * @param me Object reference
 * @param className Class name
 */
#define setClassOf_(me, className) Object_setInterface(toObject_(me), toInterface_(className##_Class_()))
/**
 * @brief Override an object
 * @param me
 * @param className
 */
#define overrideObject_(me, className) initObject_(me, className)
/**
 * @brief Override included object
 * @param me
 * @param className
 * @param typeContainerClassName
 * @param typeName
 */
#define overrideInterfaceObject_(me, className, typeContainerClassName, typeName)                         \
    Object_init(                                                                                          \
        toObject_(interfaceObjectOf_(me, typeContainerClassName, typeName)),                              \
        toInterface_(&to_(typeContainerClassName##_Class, className##_Class_())->n##typeName##_Interface) \
    )
/**
 * @brief Initialize included object
 * @param me
 * @param className
 * @param typeName
 */
#define initInterfaceObject_(me, className, typeName)                                        \
    Object_init(                                                                             \
        toObject_(interfaceObjectOf_(me, className, typeName)),                              \
        toInterface_(&to_(className##_Class, className##_Class_())->n##typeName##_Interface) \
    )
/**
 * @brief Cast to (Object *)
 */
#define toObject_(me) to_(Object, (me))
/**
 * @brief Get type of an object
 */
#define typeOf_(me) toObject_(me)->interface
/**
 * @brief Get offset from object
 */
#define offsetOf_(me) typeOf_(me)->offset
/**
 * @brief Get base object
 */
#define objectOf_(me) toObject_(toAny_(me) - offsetOf_(me))
/**
 * @brief Get included object
 */
#define interfaceObjectOf_(me, className, typeName) \
    to_(typeName, toAny_(me) + toInterface_(&to_(className##_Class, classOf_(me))->n##typeName##_Interface)->offset)
/**
 * @brief Get class of an object
 */
#define classOf_(me) toClass_(typeOf_(me))
/**
 * @brief Get operations of an object
 */
#define operationsOf_(me) typeOf_(me)->operations
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
    to_(typeName##_Operations, operationsOf_(VaArgs_first_(__VA_ARGS__)))->operationName(__VA_ARGS__)
/**
 * @brief Call a parent object operation
 * @param superClassName Class name of parent object
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define superCall_(superClassName, operationName, ...) \
    to_(superClassName##_Operations, toInterface_(superClassName##_Class_())->operations)->operationName(__VA_ARGS__)
/**
 * @brief Call a included object of parent object operation
 * @param superClassName Class name of parent object
 * @param typeName Interface name of included object
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define superIncludedCall_(superClassName, typeName, operationName, ...) \
    to_(superClassName##_Operations, toInterface_(superClassName##_Class_())->operations)->n##typeName##_Operations.operationName(__VA_ARGS__)
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
#define isOfClass_(me, className) Object_isOfClass(toObject_(me), toClass_(className##_Class_()))
/**
 * @brief
 * @param cls
 * @return Object*
 */
Object * Object_alloc(Class const * const cls);
/**
 * @brief
 */
#define alloc_(className) to_(className, Object_alloc(toClass_(className##_Class_())))
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
#define inheritOperations_(me, superClassName) \
    *to_(superClassName##_Operations, me) = *superClassName##_Operations_()
#define overrideIncludedOperation_(me, className, typeName, operationName) \
    to_(className##_Operations, me)->n##typeName##_Operations.operationName = operationName
#define overrideOperation_(me, superClassName, operationName) \
    to_(superClassName##_Operations, me)->operationName = operationName
#endif // OBJECT_H
