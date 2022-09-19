#ifndef OBJECT_H
#define OBJECT_H
#include "Any.h"
#include "Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/**
 * @brief Operations
 * @remark To be used with pointers to Operations types
 */
typedef Any Operations;
/**
 * @brief Object_Interface
 */
typedef struct {
    size_t offset;
    Operations const * operations;
} Object_Interface;
/**
 * @brief Initialize a Interface
 * @param me Interface reference
 * @param offset Offset of included object inside parent object
 * @param operations Interface operations
 * @return Interface* Initialized type
 */
Object_Interface * Object_Interface_init(
    Object_Interface * const me,
    size_t offset,
    Operations const * operations
);
/**
 * @brief Object_Class
 */
typedef struct Object_Class_t Object_Class;
struct Object_Class_t {
    extends_(Object_Interface);
    char const * name;
    size_t objectSize;
    Object_Class const * superClass;
};
/**
 * @brief Initialize a class
 * @param me Class reference
 * @param name String containing the class name
 * @param objectSize Object instance size
 * @param operations Class operations
 * @param superClass Parent class
 * @return Class* Initialized class
 */
Object_Class * Object_Class_init(
    Object_Class * const me,
    Operations const * const operations,
    char const * const name,
    size_t const objectSize,
    Object_Class const * const superClass
);
/**
 * @brief Object_Class
 * @return Object_Class const*
 */
Object_Class const * Object_Class_(void);
/**
 * @brief Object
 */
typedef struct {
    Object_Interface const * interface;
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
 * @brief
 * @param class
 * @return Object*
 */
Object * Object_alloc(Object_Class const * const class);
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
Object * Object_init(Object * const me, Object_Interface const * const interface);
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
 * @param class
 * @return true
 * @return false
 */
bool Object_isOfClass(Object const * const me, Object_Class const * const class);
/**
 * @brief Set interface of object
 * @param me Object reference
 * @param type Interface reference
 */
void Object_setClass(Object * const me, Object_Class const * const class);
/**
 * @brief Initialize a class
 * @param me Class reference
 * @param className Class name
 * @param superClassName Parent class name
 */
#define initClass_(me, className, superClassName)   \
    Object_Class_init(                              \
        to_(Object_Class, me),                      \
        to_(Operations, className##_Operations_()), \
        #className,                                 \
        sizeof(className),                          \
        to_(Object_Class, class_(superClassName))   \
    )
/**
 * @brief Override a type contained in a class
 * @param me
 * @param className
 * @param interfaceClassName
 * @param interfaceName
 */
#define initInterfaceOf_(me, className, interfaceClassName, interfaceName)                                               \
    Object_Interface_init(                                                                                               \
        to_(Object_Interface, &to_(interfaceClassName##_Class, me)->i##interfaceName##_Interface),                       \
        offsetof(interfaceClassName, i##interfaceName),                                                                  \
        to_(Operations, &to_(interfaceClassName##_Operations, className##_Operations_())->i##interfaceName##_Operations) \
    )
/**
 * @brief Initialize an object
 * @param me Object reference
 * @param className Class name
 */
#define initObject_(me, className) \
    Object_init(to_(Object, me), to_(Object_Interface, class_(className)))
/**
 * @brief Override included object
 * @param me
 * @param className
 * @param interfaceClassName
 * @param typeName
 */
#define initIObjectOf_(me, className, interfaceClassName, interfaceName)                                         \
    Object_init(                                                                                                 \
        to_(Object, iObjectOf_(me, interfaceClassName, interfaceName)),                                          \
        to_(Object_Interface, &to_(interfaceClassName##_Class, class_(className))->i##interfaceName##_Interface) \
    )
/**
 * @brief Set class of object
 * @param me Object reference
 * @param className Class name
 */
#define setClassOf_(me, className) \
    Object_setClass(to_(Object, me), to_(Object_Class, class_(className)))
/**
 * @brief Get type of an object
 */
#define interfaceOf_(me) \
    to_(Object, me)->interface
/**
 * @brief Get offset from object
 */
#define offsetOf_(me) \
    interfaceOf_(me)->offset
/**
 * @brief Get base object
 */
#define rObjectOf_(me) \
    to_(Object, to_(Any, me) - offsetOf_(me))
/**
 * @brief Get included object
 */
#define iObjectOf_(me, className, interfaceName) \
    to_(interfaceName, (to_(Any, me) + to_(Object_Interface, &to_(className##_Class, classOf_(me))->i##interfaceName##_Interface)->offset))
/**
 * @brief Get class of an object
 */
#define classOf_(me) \
    to_(Object_Class, interfaceOf_(rObjectOf_(me)))
/**
 * @brief Get operations of an object
 */
#define operationsOf_(me) \
    interfaceOf_(me)->operations
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
    to_(typeName##_Operations, operationsOf_(VaArgs_first_(__VA_ARGS__)))->operationName(__VA_ARGS__)
/**
 * @brief Call a super object operation
 * @param superClassName Super class name
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define superCall_(superClassName, operationName, ...) \
    to_(superClassName##_Operations, to_(Object_Interface, class_(superClassName))->operations)->operationName(__VA_ARGS__)
/**
 * @brief Call a super interface object operation
 * @param superClassName Super class name
 * @param interfaceName Interface name
 * @param operationName Operation name
 * @param ... (me Object reference, ... Operation arguments)
 */
#define superICall_(superClassName, interfaceName, operationName, ...) \
    to_(superClassName##_Operations, to_(Object_Interface, class_(superClassName))->operations)->i##interfaceName##_Operations.operationName(__VA_ARGS__)
/**
 * @brief Syntactic sugar for Object_isOfClass method
 */
#define isOfClass_(me, className) \
    Object_isOfClass(to_(Object, me), to_(Object_Class, class_(className)))
/**
 * @brief Syntactic sugar for Object_alloc method
 */
#define alloc_(className) \
    to_(className, Object_alloc(to_(Object_Class, class_(className))))
/**
 * @brief Syntactic sugar for Object_dealloc method
 */
#define dealloc_(me) \
    Object_dealloc(to_(Object, me))
/**
 * @brief Syntactic sugar for Object_deinit method
 */
#define deinit_(me) \
    to_(Any, (Object_deinit(to_(Object, me))))
/**
 * @brief Syntactic sugar for Object_copy method
 */
#define copy_(className, me) \
    to_(className, Object_copy(to_(Object, me)))
/**
 * @brief Syntactic sugar for Object_equals method
 */
#define equals_(me, other) \
    Object_equals(to_(Object, me), to_(Object, other))
/**
 * @brief Syntactic sugar for Object_hashCode method
 */
#define hashCode_(me) \
    Object_hashCode(to_(Object, me))
#endif // OBJECT_H
