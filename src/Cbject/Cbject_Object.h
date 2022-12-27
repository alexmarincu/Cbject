/* tag::overview[]
The building block. All objects defined in Cbject need to extend Cbject_Object.
end::overview[] */
#ifndef CBJECT_OBJECT_H
#define CBJECT_OBJECT_H
// #include "Cbject_Trait.h"
#include "Cbject_Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* tag::type[]
= Cbject_ObjectClass
====
----
typedef struct Cbject_ObjectClass Cbject_ObjectClass;
----
Typedef for struct Cbject_ObjectClass
====
end::type[] */
typedef struct Cbject_ObjectClass Cbject_ObjectClass;
/* tag::type[]
= Cbject_Object
====
----
typedef struct Cbject_Object Cbject_Object;
----
Typedef for struct Cbject_Object
====
end::type[] */
typedef struct Cbject_Object Cbject_Object;
/* tag::type[]
= struct Cbject_ObjectClass
====
----
struct Cbject_ObjectClass {
    char * name;
    size_t objectSize;
    Cbject_ObjectClass const * superClass;
    Cbject_Object * (*teardown)(Cbject_Object * object);
    uint64_t (*hashCode)(Cbject_Object const * const object);
    Cbject_Object * (*copy)(Cbject_Object const * const object, Cbject_Object * const copyObject);
    bool (*equals)(Cbject_Object const * const object, Cbject_Object const * const otherObject);
};
----
Definition of struct Cbject_ObjectClass

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
/* @startuml(id=Cbject_ObjectClass)
object Cbject_ObjectClass {
    char * name;
    size_t objectSize;
    Cbject_ObjectClass * superClass;
    Cbject_Object * (*teardown)(Cbject_Object * object);
    uint64_t (*hashCode)(Cbject_Object const * const object);
    Cbject_Object * (*copy)(Cbject_Object const * const object, Cbject_Object * const copyObject);
    bool (*equals)(Cbject_Object const * const object, Cbject_Object const * const otherObject);
}
@enduml */
struct Cbject_ObjectClass {
    char * name;
    size_t objectSize;
    Cbject_ObjectClass * superClass;
    Cbject_Object * (*teardown)(Cbject_Object * object);
    uint64_t (*hashCode)(Cbject_Object const * const object);
    Cbject_Object * (*copy)(Cbject_Object const * const object, Cbject_Object * const copyObject);
    bool (*equals)(Cbject_Object const * const object, Cbject_Object const * const otherObject);
};
/* tag::type[]
= struct Cbject_Object
====
----
struct Cbject_Object {
    Cbject_ObjectClass const * class;
};
----
Definition of struct Cbject_Object

.Members
* objectClass - Pointer to the class structure
====
end::type[] */
/* @startuml(id=Cbject_Object)
object Cbject_Object {
    Cbject_ObjectClass const * objectClass;
}
@enduml */
struct Cbject_Object {
    Cbject_ObjectClass const * objectClass;
};
/* tag::function[]
= Cbject_ObjectClass_instance()
====
----
Cbject_ObjectClass const * Cbject_ObjectClass_instance(void);
----
Get Cbject_ObjectClass instance

.Return
Reference of the class instance
====
end::function[] */
Cbject_ObjectClass const * Cbject_ObjectClass_instance(void);
/* tag::function[]
= Cbject_Object_alloc()
====
----
Cbject_Object * Cbject_Object_alloc(Cbject_ObjectClass const * const objectClass);
----
Allocate an object in heap memory

.Params
* objectClass - Class reference

.Return
Reference of the allocated object
====
end::function[] */
Cbject_Object * Cbject_Object_alloc(Cbject_ObjectClass const * const objectClass);
/* tag::function[]
= Cbject_Object_dealloc()
====
----
Cbject_Object * Cbject_Object_dealloc(Cbject_Object * const object);
----
Free memory allocated for an object

.Params
* object - Cbject_Object reference

.Return
NULL
====
end::function[] */
Cbject_Object * Cbject_Object_dealloc(Cbject_Object * const object);
/* tag::function[]
= Cbject_Object_init()
====
----
Cbject_Object * Cbject_Object_init(Cbject_Object * const object);
----
Initialize an object

.Params
* object - Cbject_Object reference

.Return
Initialized object
====
end::function[] */
Cbject_Object * Cbject_Object_init(Cbject_Object * const object);
/* tag::function[]
= Cbject_Object_teardown()
====
----
Cbject_Object * Cbject_Object_teardown(Cbject_Object * object);
----
Teardown an object.

.Params
* object - Cbject_Object reference

.Return
NULL
====
end::function[] */
Cbject_Object * Cbject_Object_teardown(Cbject_Object * object);
/* tag::function[]
= Cbject_Object_copy()
====
----
Cbject_Object * Cbject_Object_copy(Cbject_Object const * const object, Cbject_Object * const copyObject);
----
Make a copy of an object.

.Params
* object - Cbject_Object reference
* copyObject - Reference of a new allocated object in which to copy the original one

.Return
Pointer to a new object (copy of the original one)
====
end::function[] */
Cbject_Object * Cbject_Object_copy(Cbject_Object const * const object, Cbject_Object * const copyObject);
/* tag::function[]
= Cbject_Object_equals()
====
----
bool Cbject_Object_equals(Cbject_Object const * const object, Cbject_Object const * const otherObject);
----
Compare two objects

.Params
* object - Cbject_Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::function[] */
bool Cbject_Object_equals(Cbject_Object const * const object, Cbject_Object const * const otherObject);
/* tag::function[]
= Cbject_Object_hashCode()
====
----
uint64_t Cbject_Object_hashCode(Cbject_Object const * const object);
----
Get hash code of object

.Params
* object - Cbject_Object reference

.Return
Cbject_Object hash code
====
end::function[] */
uint64_t Cbject_Object_hashCode(Cbject_Object const * const object);
/* tag::function[]
= Cbject_Object_isOfClass()
====
----
bool Cbject_Object_isOfClass(Cbject_Object const * const object, Cbject_ObjectClass const * const objectClass);
----
Check if an object is of a given class

.Params
* object - Cbject_Object reference
* objectClass - Class reference

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::function[] */
bool Cbject_Object_isOfClass(Cbject_Object const * const object, Cbject_ObjectClass const * const objectClass);
#endif // CBJECT_OBJECT_H
