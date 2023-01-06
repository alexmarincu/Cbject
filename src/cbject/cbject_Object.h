/* tag::overview[]
The building block. All objects defined in Cbject need to extend cbject_Object.
end::overview[] */
#ifndef CBJECT_OBJECT_H
#define CBJECT_OBJECT_H
// #include "cbject_Trait.h"
#include "cbject_utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* tag::type[]
= cbject_Object, cbject_ObjectClass
====
----
cbject_utils_typedefClass(cbject_Object);
----
Typedef for struct cbject_ObjectClass and struct cbject_Object
====
end::type[] */
cbject_utils_typedefClass(cbject_Object);
typedef struct ObjectInterface ObjectInterface;
/* tag::type[]
= struct cbject_ObjectClass
====
----
struct cbject_ObjectClass {
    char * name;
    size_t objectSize;
    cbject_ObjectClass const * superClass;
    cbject_Object * (*teardown)(cbject_Object * object);
    uint64_t (*hashCode)(cbject_Object const * const object);
    cbject_Object * (*copy)(cbject_Object const * const object, cbject_Object * const copyObject);
    bool (*equals)(cbject_Object const * const object, cbject_Object const * const otherObject);
};
----
Definition of struct cbject_ObjectClass

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
/* @startuml(id=cbject_ObjectClass)
object cbject_ObjectClass {
    char * name;
    size_t objectSize;
    cbject_ObjectClass * superClass;
    cbject_Object * (*teardown)(cbject_Object * object);
    uint64_t (*hashCode)(cbject_Object const * const object);
    cbject_Object * (*copy)(cbject_Object const * const object, cbject_Object * const copyObject);
    bool (*equals)(cbject_Object const * const object, cbject_Object const * const otherObject);
}
@enduml */
struct cbject_ObjectClass {
    char * name;
    size_t objectSize;
    cbject_ObjectClass * superClass;
    cbject_Object * (*teardown)(cbject_Object * object);
    uint64_t (*hashCode)(cbject_Object const * const object);
    cbject_Object * (*copy)(cbject_Object const * const object, cbject_Object * const copyObject);
    bool (*equals)(cbject_Object const * const object, cbject_Object const * const otherObject);
};
/* tag::type[]
= struct cbject_Object
====
----
struct cbject_Object {
    cbject_ObjectClass const * class;
};
----
Definition of struct cbject_Object

.Members
* objectClass - Pointer to the class structure
====
end::type[] */
/* @startuml(id=cbject_Object)
object cbject_Object {
    cbject_ObjectClass const * objectClass;
}
@enduml */
struct cbject_Object {
    void * interface;
    cbject_ObjectClass const * objectClass;
};
/* tag::function[]
= cbject_ObjectClass_getInstance()
====
----
cbject_ObjectClass const * cbject_ObjectClass_getInstance(void);
----
Get cbject_ObjectClass instance

.Return
Reference of the class instance
====
end::function[] */
cbject_ObjectClass const * cbject_ObjectClass_getInstance(void);
/* tag::function[]
= cbject_ObjectClass_alloc()
====
----
cbject_Object * cbject_ObjectClass_alloc(cbject_ObjectClass const * const objectClass);
----
Allocate an object in heap memory

.Params
* objectClass - Class reference

.Return
Reference of the allocated object
====
end::function[] */
cbject_Object * cbject_ObjectClass_alloc(cbject_ObjectClass const * const objectClass);
/* tag::function[]
= cbject_Object_dealloc()
====
----
cbject_Object * cbject_Object_dealloc(cbject_Object * const object);
----
Free memory allocated for an object

.Params
* object - cbject_Object reference

.Return
NULL
====
end::function[] */
cbject_Object * cbject_Object_dealloc(cbject_Object * const object);
/* tag::function[]
= cbject_Object_init()
====
----
cbject_Object * cbject_Object_init(cbject_Object * const object);
----
Initialize an object

.Params
* object - cbject_Object reference

.Return
Initialized object
====
end::function[] */
cbject_Object * cbject_Object_init(cbject_Object * const object);
/* tag::function[]
= cbject_Object_teardown()
====
----
cbject_Object * cbject_Object_teardown(cbject_Object * object);
----
Teardown an object.

.Params
* object - cbject_Object reference

.Return
NULL
====
end::function[] */
cbject_Object * cbject_Object_teardown(cbject_Object * object);
/* tag::function[]
= cbject_Object_copy()
====
----
cbject_Object * cbject_Object_copy(cbject_Object const * const object, cbject_Object * const copyObject);
----
Make a copy of an object.

.Params
* object - cbject_Object reference
* copyObject - Reference of a new allocated object in which to copy the original one

.Return
Pointer to a new object (copy of the original one)
====
end::function[] */
cbject_Object * cbject_Object_copy(cbject_Object const * const object, cbject_Object * const copyObject);
/* tag::function[]
= cbject_Object_equals()
====
----
bool cbject_Object_equals(cbject_Object const * const object, cbject_Object const * const otherObject);
----
Compare two objects

.Params
* object - cbject_Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::function[] */
bool cbject_Object_equals(cbject_Object const * const object, cbject_Object const * const otherObject);
/* tag::function[]
= cbject_Object_hashCode()
====
----
uint64_t cbject_Object_hashCode(cbject_Object const * const object);
----
Get hash code of object

.Params
* object - cbject_Object reference

.Return
cbject_Object hash code
====
end::function[] */
uint64_t cbject_Object_hashCode(cbject_Object const * const object);
/* tag::function[]
= cbject_Object_isOfClass()
====
----
bool cbject_Object_isOfClass(cbject_Object const * const object, cbject_ObjectClass const * const objectClass);
----
Check if an object is of a given class

.Params
* object - cbject_Object reference
* objectClass - Class reference

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::function[] */
bool cbject_Object_isOfClass(cbject_Object const * const object, cbject_ObjectClass const * const objectClass);
#endif // CBJECT_OBJECT_H
