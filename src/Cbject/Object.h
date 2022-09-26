/* tag::overview[]
TODO

end::overview[] */
#ifndef OBJECT_H
#define OBJECT_H
#include "Any.h"
#include "Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* tag::type[]
===== Object
====
[source,c]
----
typedef struct Object Object;
----
Typedef for struct Object
====
end::type[] */
typedef struct Object Object;
/* tag::type[]
===== Object_Class
====
[source,c]
----
typedef struct Object_Class Object_Class;
----
Typedef for struct Object_Class
====
end::type[] */
typedef struct Object_Class Object_Class;
/* tag::type[]
===== struct Object
====
[source,c]
----
struct Object {
    Object_Class const * class;
};
----
Definition of struct Object

.Members
* class - Pointer to the class structure
====
end::type[] */
struct Object {
    Object_Class const * class;
};
/* tag::type[]
===== struct Object_Class
====
[source,c]
----
struct Object_Class {
    size_t objectSize;
    Object_Class const * superClass;
    Object * (*teardown)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
};
----
Definition of struct Object_Class

.Members
* objectSize - Size in memory of object
* superClass - Super class of object
* teardown - Function pointer for the teardown method
* hashCode - Function pointer for the hash code method
* copy - Function pointer for the copy method
* equals - Function pointer for the equals method
====
end::type[] */
struct Object_Class {
    size_t objectSize;
    Object_Class const * superClass;
    Object * (*teardown)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me);
    bool (*equals)(Object const * const me, Object const * const other);
};
/* tag::function[]
===== Object_Class_
====
[source,c]
----
Object_Class const * Object_Class_(void);
----
Get Object_Class instance
====
end::function[] */
Object_Class const * Object_Class_(void);
/* tag::function[]
===== Object_alloc
====
[source,c]
----
Object * Object_alloc(Object_Class const * const class);
----
Allocate an object in heap memory

.Params
* class - Class reference
====
end::function[] */
Object * Object_alloc(Object_Class const * const class);
/* tag::function[]
===== Object_dealloc
====
[source,c]
----
Object * Object_dealloc(Object * const me);
----
Free memory allocated for an object

.Params
* me - Object reference
====
end::function[] */
Object * Object_dealloc(Object * const me);
/* tag::function[]
===== Object_init
====
[source,c]
----
Object * Object_init(Object * const me);
----
Initialize an object

.Params
* me - Object reference

.Return
Initialized object
====
end::function[] */
Object * Object_init(Object * const me);
/* tag::function[]
===== Object_teardown
====
[source,c]
----
Object * Object_teardown(Object * me);
----
Teardown an object.

.Params
* me - Object reference

.Return
Always returns NULL
====
end::function[] */
Object * Object_teardown(Object * me);
/* tag::function[]
===== Object_copy
====
[source,c]
----
Object * Object_copy(Object const * const me);
----
Make a copy of an object.

.Params
* me - Object reference

.Return
Pointer to a new object (copy of the original one)
====
end::function[] */
Object * Object_copy(Object const * const me);
/* tag::function[]
===== Object_equals
====
[source,c]
----
bool Object_equals(Object const * const me, Object const * const other);
----
Make a copy of an object.

.Params
* me - Object reference
* other - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::function[] */
bool Object_equals(Object const * const me, Object const * const other);
/* tag::function[]
===== Object_hashCode
====
[source,c]
----
uint64_t Object_hashCode(Object const * const me);
----
Get hash code of object

.Params
* me - Object reference

.Return
Object hash code
====
end::function[] */
uint64_t Object_hashCode(Object const * const me);
/* tag::function[]
===== Object_isOfClass
====
[source,c]
----
bool Object_isOfClass(Object const * const me, Object_Class const * const class);
----
Get hash code of object

.Params
* me - Object reference
* class - Class reference

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::function[] */
bool Object_isOfClass(Object const * const me, Object_Class const * const class);
/* tag::define[]
===== initClass_
====
[source,c]
----
#define initClass_(className, me)
----
Initialize a class

.Params
* className - Name of the class
* me - Class reference
====
end::define[] */
#define initClass_(className, me) \
    *to_(className##_Class, me) = *class_(className);
/* tag::define[]
===== setUpClass_
====
[source,c]
----
#define setUpClass_(className, superClassName, me)
----
Class setup (initialize, set the object size and super class)

.Params
* className - Name of the class
* superClassName - Name of the super class
* me - Class reference
====
end::define[] */
#define setUpClass_(className, superClassName, me)         \
    initClass_(superClassName, me);                        \
    to_(Object_Class, me)->objectSize = sizeof(className); \
    to_(Object_Class, me)->superClass = to_(Object_Class, class_(superClassName))
/* tag::define[]
===== overrideObjectMethod_
====
[source,c]
----
#define overrideObjectMethod_(className, me, methodName)
----
Override a method of a super class

.Params
* className - Name of the class
* me - Class reference
* methodName - Name of the method
====
end::define[] */
#define overrideObjectMethod_(className, me, methodName) \
    to_(className##_Class, me)->methodName = methodName
/* tag::define[]
===== initObject_
====
[source,c]
----
#define initObject_(className, ...)
----
Syntactic sugar for object initialization

.Params
* className - Name of the class
* ...
** me - Object reference
** ... - Init params
====
end::define[] */
#define initObject_(className, ...) \
    className##_init(to_(className, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
/* tag::define[]
===== class_
====
[source,c]
----
#define class_(className)
----
Syntactic sugar to get class reference

.Params
* className - Name of the class
====
end::define[] */
#define class_(className) \
    className##_Class_()
/* tag::define[]
===== setUpObject_
====
[source,c]
----
#define setUpObject_(className, superClassName, ...)
----
Object setup (initialize, set the object class)

.Params
* className - Name of the class
* superClassName - Name of the super class
* ...
** me - Object reference
** ... - Init params
====
end::define[] */
#define setUpObject_(className, superClassName, ...) \
    initObject_(superClassName, __VA_ARGS__);        \
    classOf_(VaArgs_first_(__VA_ARGS__)) = to_(Object_Class, class_(className))
/**
 * @brief Get object from a trait
 */
#define objectOf_(me) \
    to_(Object, to_(Any, me) - offsetOf_(me))
/**
 * @brief Get trait of an object
 */
#define traitOf_(me, className, interfaceName) \
    to_(interfaceName, (to_(Any, me) + to_(Trait_Interface, &to_(className##_Class, classOf_(me))->i##interfaceName##_Interface)->offset))
/**
 * @brief Get the class of an object
 */
#define classOf_(me) \
    to_(Object, me)->class
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
 * @brief Call a super object method
 * @param superClassName Super class name
 * @param methodName Method name
 * @param ... (me Object reference, ... Method arguments)
 */
#define superTraitMethodCall_(superClassName, interfaceName, methodName, ...) \
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
