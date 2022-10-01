/* tag::overview[]
The building block. All objects defined in Cbject need to extend Object.

end::overview[] */
#ifndef OBJECT_H
#define OBJECT_H
#include "Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
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
===== struct Object_Class
====
[source,c]
----
struct Object_Class {
    size_t objectSize;
    Object_Class const * superClass;
    Object * (*teardown)(Object * me);
    uint64_t (*hashCode)(Object const * const me);
    Object * (*copy)(Object const * const me, Object * const object);
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
    Object * (*copy)(Object const * const me, Object * const object);
    bool (*equals)(Object const * const me, Object const * const other);
};
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
/* tag::function[]
===== Object_Class_()
====
[source,c]
----
Object_Class const * Object_Class_(void);
----
Get Object_Class instance

.Return
Reference of the class instance
====
end::function[] */
Object_Class const * Object_Class_(void);
/* tag::function[]
===== Object_alloc()
====
[source,c]
----
Object * Object_alloc(Object_Class const * const class);
----
Allocate an object in heap memory

.Params
* class - Class reference

.Return
Reference of the allocated object
====
end::function[] */
Object * Object_alloc(Object_Class const * const class);
/* tag::function[]
===== Object_dealloc()
====
[source,c]
----
Object * Object_dealloc(Object * const me);
----
Free memory allocated for an object

.Params
* me - Object reference

.Return
Always returns NULL
====
end::function[] */
Object * Object_dealloc(Object * const me);
/* tag::function[]
===== Object_init()
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
===== Object_teardown()
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
===== Object_copy()
====
[source,c]
----
Object * Object_copy(Object const * const me, Object * const object);
----
Make a copy of an object.

.Params
* me - Object reference
* object - Reference of a new allocated object in which to copy the original one

.Return
Pointer to a new object (copy of the original one)
====
end::function[] */
Object * Object_copy(Object const * const me, Object * const object);
/* tag::function[]
===== Object_equals()
====
[source,c]
----
bool Object_equals(Object const * const me, Object const * const other);
----
Compare two objects

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
===== Object_hashCode()
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
===== Object_isOfClass()
====
[source,c]
----
bool Object_isOfClass(Object const * const me, Object_Class const * const class);
----
Check if an object is of a given class

.Params
* me - Object reference
* class - Class reference

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::function[] */
bool Object_isOfClass(Object const * const me, Object_Class const * const class);
/* tag::macro[]
===== class_()
====
[source,c]
----
#define class_(className)
----
Syntactic sugar to get class reference

.Params
* className - Name of the class

.Return
Class reference
====
end::macro[] */
#define class_(className) \
    className##_Class_()
/* tag::macro[]
===== initClass_()
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
end::macro[] */
#define initClass_(className, me) \
    *to_(className##_Class, me) = *class_(className);
/* tag::macro[]
===== setUpClass_()
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
end::macro[] */
#define setUpClass_(className, superClassName, me)         \
    initClass_(superClassName, me);                        \
    to_(Object_Class, me)->objectSize = sizeof(className); \
    to_(Object_Class, me)->superClass = to_(Object_Class, class_(superClassName))
/* tag::macro[]
===== overrideObjectMethod_()
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
end::macro[] */
#define overrideObjectMethod_(className, me, methodName) \
    to_(className##_Class, me)->methodName = methodName
/* tag::macro[]
===== initObject_()
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

.Return
Initialized object
====
end::macro[] */
#define initObject_(className, ...) \
    className##_init(to_(className, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
/* tag::macro[]
===== classOf_()
====
[source,c]
----
#define classOf_(me)
----
Get the class of an object

.Params
* me - Object reference

.Return
Class reference
====
end::macro[] */
#define classOf_(me) \
    to_(Object, me)->class
/* tag::macro[]
===== setUpObject_()
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
end::macro[] */
#define setUpObject_(className, superClassName, ...) \
    initObject_(superClassName, __VA_ARGS__);        \
    classOf_(VaArgs_first_(__VA_ARGS__)) = to_(Object_Class, class_(className))
/* tag::macro[]
===== objectSizeOf_()
====
[source,c]
----
#define objectSizeOf_(me)
----
Get the size in memory of an object

.Params
* me - Object reference

.Return
Object size
====
end::macro[] */
#define objectSizeOf_(me) \
    classOf_(me)->objectSize
/* tag::macro[]
===== traitOf_()
====
[source,c]
----
#define traitOf_(me, className, interfaceName)
----
Get trait of an object

.Params
* me - Object reference
* className - Name of the class
* interfaceName - Name of the interface

.Return
Trait reference
====
end::macro[] */
#define traitOf_(me, className, interfaceName) \
    to_(interfaceName, (to_(Any, me) + to_(Trait_Interface, &to_(className##_Class, classOf_(me))->i##interfaceName##_Interface)->offset))
/* tag::macro[]
===== objectMethodCall_()
====
[source,c]
----
#define objectMethodCall_(className, methodName, ...)
----
Call a method through an object

.Params
* className - Name of the class
* methodName - Name of the method
* ...
** me - Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define objectMethodCall_(className, methodName, ...) \
    to_(className##_Class, classOf_(VaArgs_first_(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
===== classMethodCall_()
====
[source,c]
----
#define classMethodCall_(className, methodName, ...)
----
Call a method through a class

.Params
* className - Class name
* methodName - Name of the method
* ...
** me - Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define classMethodCall_(className, methodName, ...) \
    to_(className##_Class, class_(className))->methodName(__VA_ARGS__)
/* tag::macro[]
===== alloc_()
====
[source,c]
----
#define alloc_(className)
----
Syntactic sugar to allocate an object in heap memory

.Params
* className - Name of class

.Return
Reference of the allocated object
====
end::macro[] */
#define alloc_(className) \
    to_(className, Object_alloc(to_(Object_Class, class_(className))))
/* tag::macro[]
===== dealloc_()
====
[source,c]
----
#define dealloc_(me)
----
Syntactic sugar to free memory allocated for an object

.Params
* me - Object reference

.Return
Always returns NULL
====
end::macro[] */
#define dealloc_(me) \
    to_(Any, Object_dealloc(to_(Object, me)))
/* tag::macro[]
===== teardown_()
====
[source,c]
----
#define teardown_(me)
----
Syntactic sugar to teardown an object.

.Params
* me - Object reference

.Return
Always returns NULL
====
end::macro[] */
#define teardown_(me) \
    to_(Any, Object_teardown(to_(Object, me)))
/* tag::macro[]
===== copy_()
====
[source,c]
----
#define copy_(className, me, object)
----
Syntactic sugar to make a copy of an object.

.Params
* className - Name of class
* me - Object reference
* object - Reference of a new allocated object in which to copy the original one

.Return
Pointer to a new object (copy of the original one)
====
end::macro[] */
#define copy_(className, me, object) \
    to_(className, Object_copy(to_(Object, me), to_(Object, object)))
/* tag::macro[]
===== equals_()
====
[source,c]
----
#define equals_(me, other)
----
Syntactic sugar to compare two objects

.Params
* me - Object reference
* other - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::macro[] */
#define equals_(me, other) \
    Object_equals(to_(Object, me), to_(Object, other))
/* tag::function[]
===== hashCode_()
====
[source,c]
----
#define hashCode_(me)
----
Syntactic sugar to get hash code of object

.Params
* me - Object reference

.Return
Object hash code
====
end::function[] */
#define hashCode_(me) \
    Object_hashCode(to_(Object, me))
/* tag::macro[]
===== isOfClass_()
====
[source,c]
----
#define isOfClass_(me, className)
----
Syntactic sugar to check if an object is of a given class

.Params
* me - Object reference
* className - Class name

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::macro[] */
#define isOfClass_(me, className) \
    Object_isOfClass(to_(Object, me), to_(Object_Class, class_(className)))
#endif // OBJECT_H
