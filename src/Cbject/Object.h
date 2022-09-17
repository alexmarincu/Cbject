#ifndef OBJECT_H
#define OBJECT_H
#include "Class.h"
#include <stdbool.h>
#include <stdint.h>
/**
 * @brief Object
 */
typedef struct {
    Type const * type;
} Object;
/**
 * @brief Object_Class
 */
typedef struct {
    extends_(Class);
} Object_Class;
/**
 * @brief Object_Class
 * @return Object_Class const*
 */
Object_Class const * Object_Class_(void);
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
 * @brief
 * @param cls
 * @return Object*
 */
Object * Object_alloc(Class const * const cls);
/**
 * @brief
 * @param me
 */
Object * Object_dealloc(Object * const me);
/**
 * @brief Initialize an object
 * @param me Object reference
 * @param type Interface reference
 * @return Object* Initialized object
 */
Object * Object_init(Object * const me, Type const * const type);
/**
 * @brief
 * @param me
 */
Object * Object_deinit(Object * me);
/**
 * @brief
 * @param me
 * @return Object*
 */
Object * Object_copy(Object const * const me);
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
 * @param me
 * @return uint64_t
 */
uint64_t Object_hashCode(Object const * const me);
/**
 * @brief
 * @param me
 * @param cls
 * @return true
 * @return false
 */
bool Object_isOfClass(Object const * const me, Class const * const cls);
/**
 * @brief Set interface of object
 * @param me Object reference
 * @param type Interface reference
 */
void Object_setType(Object * const me, Type const * const type);
/**
 * @brief Initialize an object
 * @param me Object reference
 * @param className Class name
 */
#define initObject_(me, className) \
    Object_init((Object *)(me), (Type *)className##_Class_())
/**
 * @brief Set class of object
 * @param me Object reference
 * @param className Class name
 */
#define setClassOf_(me, className) \
    Object_setType((Object *)(me), (Type *)className##_Class_())
/**
 * @brief Override an object
 * @param me
 * @param className
 */
#define overrideObject_(me, className) \
    initObject_(me, className)
/**
 * @brief Override included object
 * @param me
 * @param className
 * @param typeContainerClassName
 * @param typeName
 */
#define overrideIObject_(me, className, typeContainerClassName, typeName)                          \
    Object_init(                                                                                   \
        (Object *)iObjectOf_(me, typeContainerClassName, typeName),                                \
        (Type *)&((typeContainerClassName##_Class *)className##_Class_())->i##typeName##_Interface \
    )
/**
 * @brief Initialize included object
 * @param me
 * @param className
 * @param typeName
 */
#define initIObject_(me, className, typeName)                                         \
    Object_init(                                                                      \
        (Object *)iObjectOf_(me, className, typeName),                                \
        (Type *)&((className##_Class *)className##_Class_())->i##typeName##_Interface \
    )
/**
 * @brief Get type of an object
 */
#define typeOf_(me) \
    ((Object *)(me))->type
/**
 * @brief Get offset from object
 */
#define offsetOf_(me) \
    typeOf_(me)->offset
/**
 * @brief Get base object
 */
#define objectOf_(me) \
    ((Object *)((Any *)(me)-offsetOf_(me)))
/**
 * @brief Get included object
 */
#define iObjectOf_(me, className, typeName) \
    ((typeName *)((Any *)(me) + ((Type *)&((className##_Class *)classOf_(me))->i##typeName##_Interface)->offset))
/**
 * @brief Get class of an object
 */
#define classOf_(me) \
    ((Class *)typeOf_(objectOf_(me)))
/**
 * @brief Get operations of an object
 */
#define operationsOf_(me) \
    typeOf_(me)->operations
/**
 * @brief Get the class name of an object
 */
#define classNameOf_(me) \
    classOf_(me)->name
/**
 * @brief Get the superClass of an object
 */
#define superClassOf_(me) \
    classOf_(me)->superClass
/**
 * @brief Get the size in memory of an object
 */
#define objectSizeOf_(me) \
    classOf_(me)->objectSize
/**
 * @brief Call an object operation
 * @param typeName Type name
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define call_(typeName, operationName, ...) \
    ((typeName##_Operations *)operationsOf_(VaArgs_first_(__VA_ARGS__)))->operationName(__VA_ARGS__)
/**
 * @brief Call a super object operation
 * @param superClassName Super class name
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define superCall_(superClassName, operationName, ...) \
    ((superClassName##_Operations *)((Type *)superClassName##_Class_())->operations)->operationName(__VA_ARGS__)
/**
 * @brief Call a super interface object operation
 * @param superClassName Super class name
 * @param interfaceName Interface name
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define superICall_(superClassName, interfaceName, operationName, ...) \
    ((superClassName##_Operations *)((Type *)superClassName##_Class_())->operations)->i##interfaceName##_Operations.operationName(__VA_ARGS__)
/**
 * @brief Syntactic sugar for Object_isOfClass method
 */
#define isOfClass_(me, className) \
    Object_isOfClass((Object *)(me), (Class *)className##_Class_())
/**
 * @brief Syntactic sugar for Object_alloc method
 */
#define alloc_(className) \
    ((className *)Object_alloc((Class *)className##_Class_()))
/**
 * @brief Syntactic sugar for Object_dealloc method
 */
#define dealloc_(me) \
    Object_dealloc((Object *)(me))
/**
 * @brief Syntactic sugar for Object_deinit method
 */
#define deinit_(me) \
    ((Any *)(Object_deinit((Object *)(me))))
/**
 * @brief Syntactic sugar for Object_copy method
 */
#define copy_(className, me) \
    ((className *)Object_copy((Object *)(me)))
/**
 * @brief Syntactic sugar for Object_equals method
 */
#define equals_(me, other) \
    Object_equals((Object *)(me), (Object *)(other))
/**
 * @brief Syntactic sugar for Object_hashCode method
 */
#define hashCode_(me) \
    Object_hashCode((Object *)(me))
/**
 * @brief Inherit operations from super class
 * @param me Object reference
 * @param superClassName Super class name
 */
#define inheritOperations_(me, superClassName) \
    *(superClassName##_Operations *)(me) = *superClassName##_Operations_()
/**
 * @brief Override inherited operation
 * @param me Object reference
 * @param superClassName Super class name
 * @param operationName Operation name
 */
#define overrideOperation_(me, superClassName, operationName) \
    ((superClassName##_Operations *)(me))->operationName = operationName
/**
 * @brief Override inherited operation
 * @param me Object reference
 * @param className Class name
 * @param interfaceName Interface name
 * @param operationName Operation name
 */
#define overrideIOperation_(me, className, interfaceName, operationName) \
    ((className##_Operations *)(me))->i##interfaceName##_Operations.operationName = operationName
#endif // OBJECT_H
