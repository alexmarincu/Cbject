#ifndef OBJECT_H
#define OBJECT_H
#include "Any.h"
#include "Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
typedef struct Object Object;
/**
 * @brief Object_Class
 */
typedef struct Object_Class Object_Class;
struct Object_Class {
    size_t objectSize;
    Object_Class const * superClass;
    Object * (*teardown)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
};
/**
 * @brief Object_Class
 * @return Object_Class const*
 */
Object_Class const * Object_Class_(void);
/**
 * @brief Object
 */
struct Object {
    Object_Class const * class;
};
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
Object * Object_init(Object * const me);
/**
 * @brief
 * @param me
 */
Object * Object_teardown(Object * me);
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
 * @brief Initialize a class
 * @param me Class reference
 * @param className Class name
 * @param superClassName Parent class name
 */
#define initClass_(className, me) \
    *to_(className##_Class, me) = *class_(className);

/**
 * @brief Initialize a class
 * @param me Class reference
 * @param className Class name
 * @param superClassName Parent class name
 */
#define setUpClass_(className, superClassName, me)         \
    initClass_(superClassName, me);                        \
    to_(Object_Class, me)->objectSize = sizeof(className); \
    to_(Object_Class, me)->superClass = to_(Object_Class, class_(superClassName))
/**
 * @brief
 *
 */
#define overrideObjectMethod_(className, me, methodName) \
    to_(className##_Class, me)->methodName = methodName
/**
 * @brief Initialize a derived object
 * @param className The object class
 * @param ... (me The object to initialize, ... The init arguments)
 */
#define initObject_(className, ...) \
    className##_init(to_(className, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
/**
 * @brief
 *
 */
#define class_(className) \
    className##_Class_()
/**
 * @brief Initialize a class
 * @param me Class reference
 * @param className Class name
 * @param superClassName Parent class name
 */
#define initInterface_(interfaceName, me) \
    *to_(interfaceName##_Interface, me) = *interface_(interfaceName);

#define setUpInterface_(className, interfaceName, me)                   \
    initInterface_(interfaceName, &(me)->i##interfaceName##_Interface); \
    to_(Module_Interface, &(me)->i##interfaceName##_Interface)->offset = offsetof(className, i##interfaceName)
/**
 * @brief Set class of an object
 * @param me Object reference
 * @param className Class name
 */
#define setUpObject_(className, superClassName, ...) \
    initObject_(superClassName, __VA_ARGS__);        \
    classOf_(VaArgs_first_(__VA_ARGS__)) = to_(Object_Class, class_(className))
/**
 * @brief Get object from a module
 */
#define objectOf_(me) \
    to_(Object, to_(Any, me) - offsetOf_(me))
/**
 * @brief Get module of an object
 */
#define moduleOf_(me, className, interfaceName) \
    to_(interfaceName, (to_(Any, me) + to_(Module_Interface, &to_(className##_Class, classOf_(me))->i##interfaceName##_Interface)->offset))
/**
 * @brief Get the class of an object
 */
#define classOf_(me) \
    to_(Object, me)->class
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
 * @brief Call an object method
 * @param className Class name
 * @param methodName Method name
 * @param ... (me Object reference, ... Method arguments)
 */
#define objectMethodCall_(className, methodName, ...) \
    to_(className##_Class, classOf_(VaArgs_first_(__VA_ARGS__)))->methodName(__VA_ARGS__)
/**
 * @brief Call a super object method
 * @param superClassName Super class name
 * @param methodName Method name
 * @param ... (me Object reference, ... Method arguments)
 */
#define superObjectMethodCall_(superClassName, methodName, ...) \
    to_(superClassName##_Class, class_(superClassName))->methodName(__VA_ARGS__)
/**
 * @brief Call a super interface object operation
 * @param superClassName Super class name
 * @param interfaceName Interface name
 * @param methodName Method name
 * @param ... (me Object reference, ... Method arguments)
 */
#define superICall_(superClassName, interfaceName, methodName, ...) \
    to_(superClassName##_Operations, to_(Object_Interface, class_(superClassName))->operations)->i##interfaceName##_Operations.methodName(__VA_ARGS__)
/**
 * @brief Call a super object method
 * @param superClassName Super class name
 * @param methodName Method name
 * @param ... (me Object reference, ... Method arguments)
 */
#define superModuleMethodCall_(superClassName, interfaceName, methodName, ...) \
    to_(interfaceName##_Interface, &to_(superClassName##_Class, class_(superClassName))->i##interfaceName##_Interface)->methodName(__VA_ARGS__)
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
 * @brief Syntactic sugar for Object_teardown method
 */
#define teardown_(me) \
    to_(Any, (Object_teardown(to_(Object, me))))
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
