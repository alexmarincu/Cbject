/*********************************************************************************** tag::overview[]
The building block. All objects defined in Cbject need to extend cbject_Object.
end::overview[] ***********************************************************************************/
#ifndef CBJECT_OBJECT_H
#define CBJECT_OBJECT_H
#include "cbject_utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*************************************************************************************** tag::type[]
= cbject_Object
====
----
typedef struct cbject_Object cbject_Object;
----
Typedef for struct cbject_Object
====
end::type[] ***************************************************************************************/
typedef struct cbject_Object cbject_Object;

/*************************************************************************************** tag::type[]
= cbject_ObjectClass
====
----
typedef struct cbject_ObjectClass cbject_ObjectClass;
----
Typedef for struct cbject_ObjectClass
====
end::type[] ***************************************************************************************/
typedef struct cbject_ObjectClass cbject_ObjectClass;

typedef enum {
    cbject_Object_UsageStatus_free = 0,
    cbject_Object_UsageStatus_inUse
} cbject_Object_UsageStatus;

/*************************************************************************************** tag::type[]
= struct cbject_Object
====
----
struct cbject_Object {
    cbject_ObjectClass const * objectClass;
};
----
Definition of struct cbject_Object

.Members
* objectClass - cbject_ObjectClass reference
====
end::type[] ***************************************************************************************/
/*********************************************************************** @startuml(id=cbject_Object)
object cbject_Object {
    cbject_ObjectClass const * objectClass;
}
@enduml *******************************************************************************************/
struct cbject_Object {
    cbject_ObjectClass const * objectClass;
    cbject_Object_UsageStatus usageStatus;
};

/*************************************************************************************** tag::type[]
= struct cbject_ObjectClass
====
----
struct cbject_ObjectClass {
    char const * name;
    size_t instanceSize;
    cbject_ObjectClass const * superClass;
    cbject_Object * (*alloc)(cbject_ObjectClass const * const objectClass);
    uint64_t (*hashCode)(cbject_Object const * const object);
    cbject_Object * (*copy)(cbject_Object const * const object, cbject_Object * const copyObject);
    bool (*equals)(cbject_Object const * const object, cbject_Object const * const otherObject);
    cbject_Object * (*terminate)(cbject_Object * object);
    void * (*dealloc)(cbject_Object * const object);
};
----
Definition of struct cbject_ObjectClass

.Members
* name - Name of the class
* instanceSize - Memory size for an instance of the class
* superClass - Super class reference
* alloc - Alloc method reference
* hashCode - Hash code method reference
* copy - Copy method reference
* equals - Equals method reference
* terminate - Terminate method reference
* dealloc - Dealloc method reference
====
end::type[] ***************************************************************************************/
/****************************************************************** @startuml(id=cbject_ObjectClass)
object cbject_ObjectClass {
    char const * name;
    size_t instanceSize;
    cbject_ObjectClass const * superClass;
    cbject_Object * (*alloc)(cbject_ObjectClass const * const objectClass);
    uint64_t (*hashCode)(cbject_Object const * const object);
    cbject_Object * (*copy)(cbject_Object const * const object, cbject_Object * const copyObject);
    bool (*equals)(cbject_Object const * const object, cbject_Object const * const otherObject);
    cbject_Object * (*terminate)(cbject_Object * object);
    void * (*dealloc)(cbject_Object * const object);
}
@enduml *******************************************************************************************/
struct cbject_ObjectClass {
    char const * name;
    size_t instanceSize;
    cbject_ObjectClass const * superClass;
    cbject_Object * pool;
    uint64_t poolSize;
    cbject_Object * (*acquire)(cbject_ObjectClass const * const objectClass);
    cbject_Object * (*alloc)(cbject_ObjectClass const * const objectClass);
    uint64_t (*hashCode)(cbject_Object const * const object);
    cbject_Object * (*copy)(cbject_Object const * const object, cbject_Object * const copyObject);
    bool (*equals)(cbject_Object const * const object, cbject_Object const * const otherObject);
    cbject_Object * (*terminate)(cbject_Object * object);
    void * (*release)(cbject_Object * const object);
    void * (*dealloc)(cbject_Object * const object);
};

/*********************************************************************************** tag::function[]
= cbject_Object_acquire()
====
----
cbject_Object * cbject_Object_acquire(cbject_ObjectClass const * const objectClass);
----
Acquires an object from the static pool

.Params
* objectClass - cbject_ObjectClass reference

.Return
Reference of the acquired object
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_acquire(cbject_ObjectClass const * const objectClass);

/*********************************************************************************** tag::function[]
= cbject_Object_alloc()
====
----
cbject_Object * cbject_Object_alloc(cbject_ObjectClass const * const objectClass);
----
Allocates an object in heap memory

.Params
* objectClass - cbject_ObjectClass reference

.Return
Reference of the allocated object
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_alloc(cbject_ObjectClass const * const objectClass);

/*********************************************************************************** tag::function[]
= cbject_Object_init()
====
----
cbject_Object * cbject_Object_init(cbject_Object * const object);
----
Initializes an object

.Params
* object - cbject_Object reference

.Return
Initialized object
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_init(cbject_Object * const object);

/*********************************************************************************** tag::function[]
= cbject_Object_copy()
====
----
cbject_Object * cbject_Object_copy(cbject_Object const * const object, cbject_Object * const copyObject);
----
Copies the object to the provided instance.

.Params
* object - cbject_Object reference
* copyObject - Reference of a new allocated object in which to copy the original one

.Return
Reference of copyObject
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_copy(cbject_Object const * const object, cbject_Object * const copyObject);

/*********************************************************************************** tag::function[]
= cbject_Object_equals()
====
----
bool cbject_Object_equals(cbject_Object const * const object, cbject_Object const * const otherObject);
----
Compares two objects

.Params
* object - cbject_Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::function[] ***********************************************************************************/
bool cbject_Object_equals(cbject_Object const * const object, cbject_Object const * const otherObject);

/*********************************************************************************** tag::function[]
= cbject_Object_hashCode()
====
----
uint64_t cbject_Object_hashCode(cbject_Object const * const object);
----
Gets the hash code of the object

.Params
* object - cbject_Object reference

.Return
The hash code of the object
====
end::function[] ***********************************************************************************/
uint64_t cbject_Object_hashCode(cbject_Object const * const object);

/*********************************************************************************** tag::function[]
= cbject_Object_terminate()
====
----
cbject_Object * cbject_Object_terminate(cbject_Object * const object);
----
Terminates an object.

.Params
* object - cbject_Object reference

.Return
NULL
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_terminate(cbject_Object * const object);

/*********************************************************************************** tag::function[]
= cbject_Object_release()
====
----
void * cbject_Object_release(cbject_Object * const object);
----
Releases the object in the static pool

.Params
* object - cbject_Object reference

.Return
NULL
====
end::function[] ***********************************************************************************/
void * cbject_Object_release(cbject_Object * const object);

/*********************************************************************************** tag::function[]
= cbject_Object_dealloc()
====
----
void * cbject_Object_dealloc(cbject_Object * const object);
----
Deallocates memory for an object

.Params
* object - cbject_Object reference

.Return
NULL
====
end::function[] ***********************************************************************************/
void * cbject_Object_dealloc(cbject_Object * const object);

/*********************************************************************************** tag::function[]
= cbject_Object_isOfClass()
====
----
bool cbject_Object_isOfClass(cbject_Object const * const object, cbject_ObjectClass const * const objectClass);
----
Checks if an object is of a given class

.Params
* object - cbject_Object reference
* objectClass - Class reference

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::function[] ***********************************************************************************/
bool cbject_Object_isOfClass(cbject_Object const * const object, cbject_ObjectClass const * const objectClass);

/*********************************************************************************** tag::function[]
= cbject_ObjectClass_instance()
====
----
cbject_ObjectClass const * cbject_ObjectClass_instance(void);
----
Gets cbject_ObjectClass instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_ObjectClass const * cbject_ObjectClass_instance(void);

/************************************************************************************** tag::macro[]
= cbject_Class_setup()
====
----
cbject_Class_setup(klass)
----
Populates the class instance

.Remark
cbject_Class must be defined before using this macro

.Params
* klass - Class reference
====
end::macro[] **************************************************************************************/
#define cbject_Class_setup(klass)                                                                                                                                       \
    *((cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class) *)(klass)) =                                                                 \
        *cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class_instance());                                                                \
    ((cbject_ObjectClass *)(klass))->name = cbject_utils_Token_stringify(cbject_utils_Pair_getFirst(cbject_Class));                                                     \
    ((cbject_ObjectClass *)(klass))->instanceSize = sizeof(cbject_utils_Pair_getFirst(cbject_Class));                                                                   \
    ((cbject_ObjectClass *)(klass))->superClass = (cbject_ObjectClass *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class_instance()); \
    ((cbject_ObjectClass *)(klass))->pool = (cbject_Object *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), _pool);                        \
    ((cbject_ObjectClass *)(klass))->poolSize = cbject_utils_Array_length(cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), _pool))

/************************************************************************************** tag::macro[]
= cbject_Object_class()
====
----
cbject_Object_class(object)
----
Gets the class of an object

.Params
* object - cbject_Object reference

.Return
Class reference
====
end::macro[] **************************************************************************************/
#define cbject_Object_class(object) \
    ((cbject_Object *)(object))->objectClass

/************************************************************************************** tag::macro[]
= cbject_Object_instanceSize()
====
----
cbject_Object_instanceSize(object)
----
Gets the size in memory of an object

.Params
* object - cbject_Object reference

.Return
The size in memory of the object
====
end::macro[] **************************************************************************************/
#define cbject_Object_instanceSize(object) \
    cbject_Object_class(object)->instanceSize

#endif // CBJECT_OBJECT_H
