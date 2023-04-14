/*************************************************************************************************** tag::overview[]
[plantuml, target=diag-object]
.Context diagram
----
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_Object_Class
cbject_Object -r-> cbject_Object_Class
----

The building block. All objects defined in Cbject need to extend cbject_Object.
end::overview[] ***********************************************************************************/
#ifndef CBJECT_OBJECT_H
#define CBJECT_OBJECT_H
#include "cbject_config.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*************************************************************************************************** tag::type[]
= cbject_Object
====
----
typedef struct cbject_Object cbject_Object;
----
Typedef for struct cbject_Object
====
end::type[] ***************************************************************************************/
typedef struct cbject_Object cbject_Object;

/*************************************************************************************************** tag::type[]
= cbject_Object_Class
====
----
typedef struct cbject_Object_Class cbject_Object_Class;
----
Typedef for struct cbject_Object_Class
====
end::type[] ***************************************************************************************/
typedef struct cbject_Object_Class cbject_Object_Class;

/*************************************************************************************************** tag::type[]
= cbject_Object_PoolUsageStatus
====
----
#if (cbject_config_useStaticPool == true)
typedef enum {
    cbject_Object_PoolUsageStatus_free = 0,
    cbject_Object_PoolUsageStatus_inUse
} cbject_Object_PoolUsageStatus;
#endif
----
Typedef and struct definition for cbject_Object_PoolUsageStatus

.Remark
Used for static pool functionality

.Values
* free
* inUse
====
end::type[] ***************************************************************************************/
#if (cbject_config_useStaticPool == true)
typedef enum {
    cbject_Object_PoolUsageStatus_free = 0,
    cbject_Object_PoolUsageStatus_inUse
} cbject_Object_PoolUsageStatus;
#endif

/*************************************************************************************************** tag::type[]
= cbject_Object_Source
====
----
#if ((cbject_config_useStaticPool == true) || (cbject_config_useHeap == true))
typedef enum {
    cbject_Object_Source_stack,
#if (cbject_config_useHeap == true)
    cbject_Object_Source_heap,
#endif
#if (cbject_config_useStaticPool == true)
    cbject_Object_Source_staticPool
#endif
} cbject_Object_Source;
#endif
----
Typedef and struct definition for cbject_Object_Source

.Remark
Used if heap or static pool usage is activated

.Values
* free
* inUse
====
end::type[] ***************************************************************************************/
#if ((cbject_config_useStaticPool == true) || (cbject_config_useHeap == true))
typedef enum {
    cbject_Object_Source_stack,
#if (cbject_config_useHeap == true)
    cbject_Object_Source_heap,
#endif
#if (cbject_config_useStaticPool == true)
    cbject_Object_Source_staticPool
#endif
} cbject_Object_Source;
#endif

/*************************************************************************************************** tag::type[]
= struct cbject_Object
====
----
struct cbject_Object {
    cbject_Object_Class * klass;
    uint64_t referenceCount;
#if ((cbject_config_useStaticPool == true) || (cbject_config_useHeap == true))
    cbject_Object_Source source;
#if (cbject_config_useStaticPool == true)
    cbject_Object_PoolUsageStatus poolUsageStatus;
#endif
#endif
};
----
Definition of struct cbject_Object

.Members
* klass - cbject_Object_Class reference
* referenceCount - The reference count (number of owners of the object)
* source - Source from where the object was created (stack/heap/staticPool)
* poolUsageStatus - Usage status of object (free/inUse)
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_Object)
object cbject_Object {
    cbject_Object_Class * klass;
    uint64_t referenceCount;
#if ((cbject_config_useStaticPool == true) || (cbject_config_useHeap == true))
    cbject_Object_Source source;
#if (cbject_config_useStaticPool == true)
    cbject_Object_PoolUsageStatus poolUsageStatus;
#endif
#endif
}
@enduml *******************************************************************************************/
struct cbject_Object {
    cbject_Object_Class * klass;
    uint64_t referenceCount;
#if ((cbject_config_useStaticPool == true) || (cbject_config_useHeap == true))
    cbject_Object_Source source;
#if (cbject_config_useStaticPool == true)
    cbject_Object_PoolUsageStatus poolUsageStatus;
#endif
#endif
};

/*************************************************************************************************** tag::type[]
= struct cbject_Object_Class
====
----
struct cbject_Object_Class {
    char const * name;
    size_t instanceSize;
    cbject_Object_Class const * superClass;
#if (cbject_config_useStaticPool == true)
    cbject_Object * pool;
    uint64_t poolSize;
    cbject_Object * poolFirstFreeObject;
    cbject_Object * (*acquire)(cbject_Object_Class * const self);
#endif
#if (cbject_config_useHeap == true)
    cbject_Object * (*alloc)(cbject_Object_Class * const self);
#endif
    uint64_t (*hashCode)(cbject_Object const * const self);
    cbject_Object * (*copy)(cbject_Object const * const self, cbject_Object * const object);
    bool (*equals)(cbject_Object const * const self, cbject_Object const * const object);
    cbject_Object * (*terminate)(cbject_Object * self);
};
----
Definition of struct cbject_Object_Class

.Members
* name - Name of the class
* instanceSize - Memory size for an instance of the class
* superClass - Super class reference
* pool - Reference to the object static pool
* poolSize - Size of pool (number of objects in pool)
* poolFirstFreeObject - Reference to the first free object in the pool
* acquire - Acquire method reference
* alloc - Alloc method reference
* hashCode - Hash code method reference
* copy - Copy method reference
* equals - Equals method reference
* terminate - Terminate method reference
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_Object_Class)
object cbject_Object_Class {
    char const * name;
    size_t instanceSize;
    cbject_Object_Class const * superClass;
#if (cbject_config_useStaticPool == true)
    cbject_Object * pool;
    uint64_t poolSize;
    cbject_Object * poolFirstFreeObject;
    cbject_Object * (*acquire)(cbject_Object_Class * const self);
#endif
#if (cbject_config_useHeap == true)
    cbject_Object * (*alloc)(cbject_Object_Class * const self);
#endif
    uint64_t (*hashCode)(cbject_Object const * const self);
    cbject_Object * (*copy)(cbject_Object const * const self, cbject_Object * const object);
    bool (*equals)(cbject_Object const * const self, cbject_Object const * const object);
    cbject_Object * (*terminate)(cbject_Object * self);
}
@enduml *******************************************************************************************/
struct cbject_Object_Class {
    char const * name;
    size_t instanceSize;
    cbject_Object_Class const * superClass;
#if (cbject_config_useStaticPool == true)
    cbject_Object * pool;
    uint64_t poolSize;
    cbject_Object * poolFirstFreeObject;
    cbject_Object * (*acquire)(cbject_Object_Class * const self);
#endif
#if (cbject_config_useHeap == true)
    cbject_Object * (*alloc)(cbject_Object_Class * const self);
#endif
    uint64_t (*hashCode)(cbject_Object const * const self);
    cbject_Object * (*copy)(cbject_Object const * const self, cbject_Object * const object);
    bool (*equals)(cbject_Object const * const self, cbject_Object const * const object);
    cbject_Object * (*terminate)(cbject_Object * self);
};

/*************************************************************************************************** tag::function[]
= cbject_Object_Class_acquire()
====
----
#if (cbject_config_useStaticPool == true)
cbject_Object * cbject_Object_Class_acquire(cbject_Object_Class * const self);
#endif
----
Acquires an object from the static pool

.Params
* self - cbject_Object_Class reference

.Return
Reference of the acquired object
====
end::function[] ***********************************************************************************/
#if (cbject_config_useStaticPool == true)
cbject_Object * cbject_Object_Class_acquire(cbject_Object_Class * const self);
#endif

/*************************************************************************************************** tag::function[]
= cbject_Object_Class_alloc()
====
----
#if (cbject_config_useHeap == true)
cbject_Object * cbject_Object_Class_alloc(cbject_Object_Class * const self);
#endif
----
Allocates an object in heap memory

.Params
* self - cbject_Object_Class reference

.Return
Reference of the allocated object
====
end::function[] ***********************************************************************************/
#if (cbject_config_useHeap == true)
cbject_Object * cbject_Object_Class_alloc(cbject_Object_Class * const self);
#endif

/*************************************************************************************************** tag::function[]
= cbject_Object_init()
====
----
cbject_Object * cbject_Object_init(cbject_Object * const self);
----
Initializes an object

.Params
* self - cbject_Object reference

.Return
Initialized object
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_init(cbject_Object * const self);

/*************************************************************************************************** tag::function[]
= cbject_Object_allocHelper()
====
----
cbject_Object * cbject_Object_allocHelper(
    cbject_Object * const self, cbject_Object_Class * const klass,
#if ((cbject_config_useStaticPool == true) || (cbject_config_useHeap == true))
    cbject_Object_Source const source
#endif
);
----
Sets the class of the object and other proprieties needed for allocation

.Params
* self - cbject_Object reference
* klass - cbject_Object_Class reference
* source - cbject_Object_Source (optional - depends on heap and static pool config)

.Return
Reference to the object
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_allocHelper(
    cbject_Object * const self, cbject_Object_Class * const klass,
#if ((cbject_config_useStaticPool == true) || (cbject_config_useHeap == true))
    cbject_Object_Source const source
#endif
);

/*************************************************************************************************** tag::function[]
= cbject_Object_copy()
====
----
cbject_Object * cbject_Object_copy(cbject_Object const * const self, cbject_Object * const object);
----
Copies the object to the provided instance.

.Params
* self - cbject_Object reference
* object - Reference of a new object in which to copy the original one

.Return
Reference of object
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_copy(cbject_Object const * const self, cbject_Object * const object);

/*************************************************************************************************** tag::function[]
= cbject_Object_equals()
====
----
bool cbject_Object_equals(cbject_Object const * const self, cbject_Object const * const object);
----
Compares two objects

.Params
* self - cbject_Object reference
* object - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::function[] ***********************************************************************************/
bool cbject_Object_equals(cbject_Object const * const self, cbject_Object const * const object);

/*************************************************************************************************** tag::function[]
= cbject_Object_hashCode()
====
----
uint64_t cbject_Object_hashCode(cbject_Object const * const self);
----
Gets the hash code of the object

.Params
* self - cbject_Object reference

.Return
The hash code of the object
====
end::function[] ***********************************************************************************/
uint64_t cbject_Object_hashCode(cbject_Object const * const self);

/*************************************************************************************************** tag::function[]
= cbject_Object_retain()
====
----
cbject_Object * cbject_Object_retain(cbject_Object * const self);
----
Increases the reference count of the object

.Params
* self - cbject_Object reference

.Return
Reference to object
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_retain(cbject_Object * const self);

/*************************************************************************************************** tag::function[]
= cbject_Object_release()
====
----
void * cbject_Object_release(cbject_Object * const self);
----
Decreases the reference count of the object and performs deallocation if reference count reaches 0

.Params
* self - cbject_Object reference

.Return
NULL
====
end::function[] ***********************************************************************************/
void * cbject_Object_release(cbject_Object * const self);

/*************************************************************************************************** tag::function[]
= cbject_Object_isOfClass()
====
----
bool cbject_Object_isOfClass(
    cbject_Object const * const self, cbject_Object_Class const * const klass
);
----
Checks if an object is of a given class

.Params
* self - cbject_Object reference
* klass - Class reference

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::function[] ***********************************************************************************/
bool cbject_Object_isOfClass(
    cbject_Object const * const self, cbject_Object_Class const * const klass
);

/*************************************************************************************************** tag::function[]
= cbject_Object_Class_instance()
====
----
cbject_Object_Class * cbject_Object_Class_instance(void);
----
Gets cbject_Object_Class instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_Object_Class * cbject_Object_Class_instance(void);

#endif // CBJECT_OBJECT_H
