/* tag::overview[]
The building block. All objects defined in Cbject need to extend Object.
end::overview[] */
#ifndef OBJECT_H
#define OBJECT_H
// #include "Trait.h"
#include "Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* tag::type[]
= ObjectClass
====
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
----
Object * Object_dealloc(Object * const object);
----
Free memory allocated for an object

.Params
* object - Object reference

.Return
NULL
====
end::function[] */
Object * Object_dealloc(Object * const object);
/* tag::function[]
= Object_init()
====
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
----
Object * Object_teardown(Object * object);
----
Teardown an object.

.Params
* object - Object reference

.Return
NULL
====
end::function[] */
Object * Object_teardown(Object * object);
/* tag::function[]
= Object_copy()
====
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
= setUpClass_()
====
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
= setUpInterfaceOf_()
====
----
#define setUpInterfaceOf_(className, interfaceName, class)
----
Interface setup in class (initialize super, set the trait offset in container object)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* class - Class instance
====
end::macro[] */
#define setUpInterfaceOf_(className, interfaceName, class)                                              \
    *to_(interfaceName##Interface, &(class)->i##interfaceName##Interface) = *interface_(interfaceName); \
    to_(TraitInterface, &(class)->i##interfaceName##Interface)->name = #interfaceName;                  \
    to_(TraitInterface, &(class)->i##interfaceName##Interface)->traitOffset = offsetof(className, i##interfaceName)
/* tag::macro[]
= bindInterfaceMethodOf_()
====
----
#define bindInterfaceMethodOf_(className, interfaceName, methodName, class)
----
Bind a method of an interface

.Params
* className - Name of the class
* interfaceName - Name of the interface
* methodName - Name of the method
* class - Class instance
====
end::macro[] */
#define bindInterfaceMethodOf_(className, interfaceName, methodName, class) \
    to_(interfaceName##Interface, &to_(className##Class, class)->i##interfaceName##Interface)->methodName = methodName
/* tag::macro[]
= alloc_()
====
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
= dealloc_()
====
----
#define dealloc_(object)
----
Syntactic sugar to free memory allocated for an object

.Params
* object - Object reference

.Return
NULL
====
end::macro[] */
#define dealloc_(object) \
    to_(Any, Object_dealloc(to_(Object, object)))
/* tag::macro[]
= init_()
====
----
#define init_(className, ...)
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
#define init_(className, ...) \
    className##_init(to_(className, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
/* tag::macro[]
= setUpObject_()
====
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
    init_(superClassName, __VA_ARGS__);              \
    classOf_(VaArgs_first_(__VA_ARGS__)) = to_(ObjectClass, class_(className))
/* tag::macro[]
= setUpTraitOf_()
====
----
#define setUpTraitOf_(className, interfaceName, ...)
----
Trait setup (initialize, set the trait offset and interface offset)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* ...
** object - Object reference
** ... - Init params
====
end::macro[] */
#define setUpTraitOf_(className, interfaceName, ...)                                                    \
    initTrait_(interfaceName, &VaArgs_first_(__VA_ARGS__)->i##interfaceName VaArgs_rest_(__VA_ARGS__)); \
    offsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className, i##interfaceName);   \
    interfaceOffsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className##Class, i##interfaceName##Interface)
/* tag::macro[]
= allocInit_()
====
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
    init_(className, VaArgs_first_(__VA_ARGS__) VaArgs_rest_(__VA_ARGS__))
/* tag::macro[]
= sallocInit_()
====
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
    init_(className, VaArgs_first_(__VA_ARGS__) VaArgs_rest_(__VA_ARGS__))
/* tag::macro[]
= teardown_()
====
----
#define teardown_(object)
----
Syntactic sugar to teardown an object.

.Params
* object - Object reference

.Return
NULL
====
end::macro[] */
#define teardown_(object) \
    to_(Any, Object_teardown(to_(Object, object)))
/* tag::macro[]
= copy_()
====
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
