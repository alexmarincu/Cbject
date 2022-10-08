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
= ObjectClass
====
[source,c]
----
typedef struct ObjectClass ObjectClass;
----
Typedef for struct ObjectClass
====
end::type[] */
typedef struct ObjectClass ObjectClass;
/* tag::type[]
= Object
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
= struct ObjectClass
====
[source,c]
----
struct ObjectClass {
    char * name;
    size_t objectSize;
    ObjectClass const * superClass;
    Object * (*teardown)(Object * object);
    uint64_t (*hashCode)(Object const * const object);
    Object * (*copy)(Object const * const object, Object * const copyObject);
    bool (*equals)(Object const * const object, Object const * const otherObject);
};
----
Definition of struct ObjectClass

.Members
* name - Name of the class
* objectSize - Size in memory of object
* superClass - Super class of object
* teardown - Function pointer for the teardown method
* hashCode - Function pointer for the hash code method
* copy - Function pointer for the copy method
* equals - Function pointer for the equals method
====
end::type[] */
/* @startuml(id=ObjectClass)
object ObjectClass {
    char * name;
    size_t objectSize;
    ObjectClass * superClass;
    Object * (*teardown)(Object * object);
    uint64_t (*hashCode)(Object const * const object);
    Object * (*copy)(Object const * const object, Object * const copyObject);
    bool (*equals)(Object const * const object, Object const * const otherObject);
}
@enduml */
struct ObjectClass {
    char * name;
    size_t objectSize;
    ObjectClass * superClass;
    Object * (*teardown)(Object * object);
    uint64_t (*hashCode)(Object const * const object);
    Object * (*copy)(Object const * const object, Object * const copyObject);
    bool (*equals)(Object const * const object, Object const * const otherObject);
};
/* tag::type[]
= struct Object
====
[source,c]
----
struct Object {
    ObjectClass const * class;
};
----
Definition of struct Object

.Members
* class - Pointer to the class structure
====
end::type[] */
/* @startuml(id=Object)
object Object {
    ObjectClass const * class;
}
@enduml */
struct Object {
    ObjectClass const * class;
};
/* tag::function[]
= ObjectClass_instance()
====
[source,c]
----
ObjectClass const * ObjectClass_instance(void);
----
Get ObjectClass instance

.Return
Reference of the class instance
====
end::function[] */
ObjectClass const * ObjectClass_instance(void);
/* tag::function[]
= Object_alloc()
====
[source,c]
----
Object * Object_alloc(ObjectClass const * const class);
----
Allocate an object in heap memory

.Params
* class - Class reference

.Return
Reference of the allocated object
====
end::function[] */
Object * Object_alloc(ObjectClass const * const class);
/* tag::function[]
= Object_dealloc()
====
[source,c]
----
Object * Object_dealloc(Object * const object);
----
Free memory allocated for an object

.Params
* object - Object reference

.Return
Always returns NULL
====
end::function[] */
Object * Object_dealloc(Object * const object);
/* tag::function[]
= Object_init()
====
[source,c]
----
Object * Object_init(Object * const object);
----
Initialize an object

.Params
* object - Object reference

.Return
Initialized object
====
end::function[] */
Object * Object_init(Object * const object);
/* tag::function[]
= Object_teardown()
====
[source,c]
----
Object * Object_teardown(Object * object);
----
Teardown an object.

.Params
* object - Object reference

.Return
Always returns NULL
====
end::function[] */
Object * Object_teardown(Object * object);
/* tag::function[]
= Object_copy()
====
[source,c]
----
Object * Object_copy(Object const * const object, Object * const copyObject);
----
Make a copy of an object.

.Params
* object - Object reference
* copyObject - Reference of a new allocated object in which to copy the original one

.Return
Pointer to a new object (copy of the original one)
====
end::function[] */
Object * Object_copy(Object const * const object, Object * const copyObject);
/* tag::function[]
= Object_equals()
====
[source,c]
----
bool Object_equals(Object const * const object, Object const * const otherObject);
----
Compare two objects

.Params
* object - Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::function[] */
bool Object_equals(Object const * const object, Object const * const otherObject);
/* tag::function[]
= Object_hashCode()
====
[source,c]
----
uint64_t Object_hashCode(Object const * const object);
----
Get hash code of object

.Params
* object - Object reference

.Return
Object hash code
====
end::function[] */
uint64_t Object_hashCode(Object const * const object);
/* tag::function[]
= Object_isOfClass()
====
[source,c]
----
bool Object_isOfClass(Object const * const object, ObjectClass const * const class);
----
Check if an object is of a given class

.Params
* object - Object reference
* class - Class reference

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::function[] */
bool Object_isOfClass(Object const * const object, ObjectClass const * const class);
/* tag::macro[]
= typedefClass_()
====
[source,c]
----
#define typedefClass_(className)
----
Syntactic sugar to typedef class types

.Params
* className - Name of the class
====
end::macro[] */
#define typedefClass_(className)                      \
    typedef struct className##Class className##Class; \
    typedef struct className className
/* tag::macro[]
= class_()
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
    className##Class_instance()
/* tag::macro[]
= setUpClass_()
====
[source,c]
----
#define setUpClass_(className, superClassName, class)
----
Class setup (initialize super, set the object size and super class)

.Params
* className - Name of the class
* superClassName - Name of the super class
* class - Class instance
====
end::macro[] */
#define setUpClass_(className, superClassName, class)             \
    *to_(superClassName##Class, class) = *class_(superClassName); \
    to_(ObjectClass, class)->name = #className;                   \
    to_(ObjectClass, class)->objectSize = sizeof(className);      \
    to_(ObjectClass, class)->superClass = to_(ObjectClass, class_(superClassName))
/* tag::macro[]
= bindClassMethod_()
====
[source,c]
----
#define bindClassMethod_(className, methodName, class)
----
Bind a method of a class

.Params
* className - Name of the class
* methodName - Name of the method
* class - Class instance
====
end::macro[] */
#define bindClassMethod_(className, methodName, class) \
    to_(className##Class, class)->methodName = methodName
/* tag::macro[]
= singleton_()
====
[source,c]
----
#define singleton_(className)
----
Syntactic sugar to get a singleton reference

.Params
* className - Name of the class

.Return
Singleton reference
====
end::macro[] */
#define singleton_(className) \
    className##_instance()
/* tag::macro[]
= initObject_()
====
[source,c]
----
#define initObject_(className, ...)
----
Syntactic sugar for object initialization

.Params
* className - Name of the class
* ...
** object - Object reference
** ... - Init params

.Return
Initialized object
====
end::macro[] */
#define initObject_(className, ...) \
    className##_init(to_(className, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
/* tag::macro[]
= sallocInit_()
====
[source,c]
----
#define sallocInit_(...)
----
Syntactic sugar to allocate and init an object in stack memory

.Params
* ...
** className - Name of class
** ... - Init params

.Return
Reference of the allocated and initialized object
====
end::macro[] */
#define sallocInit_(...) \
    sallocInit_h0(VaArgs_first_(__VA_ARGS__), salloc_(VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
#define sallocInit_h0(className, ...) \
    initObject_(className, VaArgs_first_(__VA_ARGS__) VaArgs_rest_(__VA_ARGS__))
/* tag::macro[]
= classOf_()
====
[source,c]
----
#define classOf_(object)
----
Get the class of an object

.Params
* object - Object reference

.Return
Class reference
====
end::macro[] */
#define classOf_(object) \
    to_(Object, object)->class
/* tag::macro[]
= setUpObject_()
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
** object - Object reference
** ... - Init params
====
end::macro[] */
#define setUpObject_(className, superClassName, ...) \
    initObject_(superClassName, __VA_ARGS__);        \
    classOf_(VaArgs_first_(__VA_ARGS__)) = to_(ObjectClass, class_(className))
/* tag::macro[]
= classNameOf_()
====
[source,c]
----
#define classNameOf_(object)
----
Get the class name of an object

.Params
* object - Object reference

.Return
(char *) Name of the class
====
end::macro[] */
#define classNameOf_(object) \
    classOf_(object)->name
/* tag::macro[]
= objectSizeOf_()
====
[source,c]
----
#define objectSizeOf_(object)
----
Get the size in memory of an object

.Params
* object - Object reference

.Return
Object size
====
end::macro[] */
#define objectSizeOf_(object) \
    classOf_(object)->objectSize
/* tag::macro[]
= traitOf_()
====
[source,c]
----
#define traitOf_(className, interfaceName, object)
----
Get trait of an object

.Params
* className - Name of the class
* interfaceName - Name of the interface
* object - Object reference

.Return
Trait reference
====
end::macro[] */
#define traitOf_(className, interfaceName, object) \
    to_(interfaceName, (to_(Any, object) + to_(TraitInterface, &to_(className##Class, classOf_(object))->i##interfaceName##Interface)->traitOffset))
/* tag::macro[]
= objectMethodCall_()
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
** object - Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define objectMethodCall_(className, methodName, ...) \
    to_(className##Class, classOf_(VaArgs_first_(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
= classMethodCall_()
====
[source,c]
----
#define classMethodCall_(className, superClassName, methodName, ...)
----
Call a method through a class

.Params
* className - Name of the class
* superClassName - Name of the super class
* methodName - Name of the method
* ...
** object - Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define classMethodCall_(className, superClassName, methodName, ...) \
    to_(superClassName##Class, class_(className))->methodName(__VA_ARGS__)
/* tag::macro[]
= alloc_()
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
    to_(className, Object_alloc(to_(ObjectClass, class_(className))))
/* tag::macro[]
= allocInit_()
====
[source,c]
----
#define allocInit_(...)
----
Syntactic sugar to allocate and init an object in heap memory

.Params
* ...
** className - Name of class
** ... - Init params

.Return
Reference of the allocated and initialized object
====
end::macro[] */
#define allocInit_(...) \
    allocInit_h0(VaArgs_first_(__VA_ARGS__), alloc_(VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
#define allocInit_h0(className, ...) \
    initObject_(className, VaArgs_first_(__VA_ARGS__) VaArgs_rest_(__VA_ARGS__))
/* tag::macro[]
= dealloc_()
====
[source,c]
----
#define dealloc_(object)
----
Syntactic sugar to free memory allocated for an object

.Params
* object - Object reference

.Return
Always returns NULL
====
end::macro[] */
#define dealloc_(object) \
    to_(Any, Object_dealloc(to_(Object, object)))
/* tag::macro[]
= teardown_()
====
[source,c]
----
#define teardown_(object)
----
Syntactic sugar to teardown an object.

.Params
* object - Object reference

.Return
Always returns NULL
====
end::macro[] */
#define teardown_(object) \
    to_(Any, Object_teardown(to_(Object, object)))
/* tag::macro[]
= copy_()
====
[source,c]
----
#define copy_(className, object, copyObject)
----
Syntactic sugar to make a copy of an object.

.Params
* className - Name of class
* object - Object reference
* copyObject - Reference of a new allocated object in which to copy the original one

.Return
Pointer to a new object (copy of the original one)
====
end::macro[] */
#define copy_(className, object, copyObject) \
    to_(className, Object_copy(to_(Object, object), to_(Object, copyObject)))
/* tag::macro[]
= allocCopy_()
====
[source,c]
----
#define allocCopy_(className, object)
----
Syntactic sugar to copy object in new object allocated in heap memory

.Params
* className - Name of class
* object - Object reference

.Return
Reference of the allocated object (copy of the original one)
====
end::macro[] */
#define allocCopy_(className, object) \
    copy_(className, object, alloc_(className))
/* tag::macro[]
= sallocCopy_()
====
[source,c]
----
#define sallocCopy_(className, object)
----
Syntactic sugar to copy object in new object allocated in stack memory

.Params
* className - Name of class
* object - Object reference

.Return
Reference of the allocated object (copy of the original one)
====
end::macro[] */
#define sallocCopy_(className, object) \
    copy_(className, object, salloc_(className))
/* tag::macro[]
= equals_()
====
[source,c]
----
#define equals_(object, otherObject)
----
Syntactic sugar to compare two objects

.Params
* object - Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::macro[] */
#define equals_(object, otherObject) \
    Object_equals(to_(Object, object), to_(Object, otherObject))
/* tag::macro[]
= hashCode_()
====
[source,c]
----
#define hashCode_(object)
----
Syntactic sugar to get hash code of object

.Params
* object - Object reference

.Return
Object hash code
====
end::macro[] */
#define hashCode_(object) \
    Object_hashCode(to_(Object, object))
/* tag::macro[]
= isOfClass_()
====
[source,c]
----
#define isOfClass_(object, className)
----
Syntactic sugar to check if an object is of a given class

.Params
* object - Object reference
* className - Class name

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::macro[] */
#define isOfClass_(object, className) \
    Object_isOfClass(to_(Object, object), to_(ObjectClass, class_(className)))
#endif // OBJECT_H
