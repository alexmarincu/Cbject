/*************************************************************************************************** tag::overview[]
[plantuml, target=diag-object]
.Context diagram
----
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_ObjectClass
cbject_Object -r-> cbject_ObjectClass
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
= cbject_ObjectClass
====
----
typedef struct cbject_ObjectClass cbject_ObjectClass;
----
Typedef for struct cbject_ObjectClass
====
end::type[] ***************************************************************************************/
typedef struct cbject_ObjectClass cbject_ObjectClass;

/*************************************************************************************************** tag::type[]
= cbject_Object_PoolUsageStatus
====
----
typedef enum {
    cbject_Object_PoolUsageStatus_free = 0,
    cbject_Object_PoolUsageStatus_inUse
} cbject_Object_PoolUsageStatus;
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
typedef enum {
    cbject_Object_Source_stack,
    cbject_Object_Source_heap,
    cbject_Object_Source_staticPool
} cbject_Object_Source;
----
Typedef and struct definition for cbject_Object_Source

.Remark
Used if heap or static pool usage is activated

.Values
* free
* inUse
====
end::type[] ***************************************************************************************/
#if (cbject_config_useStaticPool == true) || (cbject_config_useHeap == true)
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
    cbject_ObjectClass * klass;
    uint64_t referenceCount;
    cbject_Object_Source source;
    cbject_Object_PoolUsageStatus poolUsageStatus;
};
----
Definition of struct cbject_Object

.Members
* klass - cbject_ObjectClass reference
* referenceCount - The reference count (number of owners of the object)
* source - Source from where the object was created (stack/heap/staticPool)
* poolUsageStatus - Usage status of object (free/inUse)
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_Object)
object cbject_Object {
    cbject_ObjectClass * klass;
    uint64_t referenceCount;
    cbject_Object_Source source;
    cbject_Object_PoolUsageStatus poolUsageStatus;
}
@enduml *******************************************************************************************/
struct cbject_Object {
    cbject_ObjectClass * klass;
    uint64_t referenceCount;
#if (cbject_config_useStaticPool == true) || (cbject_config_useHeap == true)
    cbject_Object_Source source;
#if (cbject_config_useStaticPool == true)
    cbject_Object_PoolUsageStatus poolUsageStatus;
#endif
#endif
};

/*************************************************************************************************** tag::type[]
= struct cbject_ObjectClass
====
----
struct cbject_ObjectClass {
    char const * name;
    size_t instanceSize;
    cbject_ObjectClass const * superClass;
    cbject_Object * pool;
    uint64_t poolSize;
    cbject_Object * poolFirstFreeObject;
    cbject_Object * (*acquire)(cbject_ObjectClass * const self);
    cbject_Object * (*alloc)(cbject_ObjectClass * const self);
    uint64_t (*hashCode)(cbject_Object const * const self);
    cbject_Object * (*copy)(cbject_Object const * const self, cbject_Object * const object);
    bool (*equals)(cbject_Object const * const self, cbject_Object const * const object);
    cbject_Object * (*terminate)(cbject_Object * self);
};
----
Definition of struct cbject_ObjectClass

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
/*************************************************************************************************** @startuml(id=cbject_ObjectClass)
object cbject_ObjectClass {
    char const * name;
    size_t instanceSize;
    cbject_ObjectClass const * superClass;
    cbject_Object * pool;
    uint64_t poolSize;
    cbject_Object * poolFirstFreeObject;
    cbject_Object * (*acquire)(cbject_ObjectClass * const self);
    cbject_Object * (*alloc)(cbject_ObjectClass * const self);
    uint64_t (*hashCode)(cbject_Object const * const self);
    cbject_Object * (*copy)(cbject_Object const * const self, cbject_Object * const object);
    bool (*equals)(cbject_Object const * const self, cbject_Object const * const object);
    cbject_Object * (*terminate)(cbject_Object * self);
}
@enduml *******************************************************************************************/
struct cbject_ObjectClass {
    char const * name;
    size_t instanceSize;
    cbject_ObjectClass const * superClass;
#if (cbject_config_useStaticPool == true)
    cbject_Object * pool;
    uint64_t poolSize;
    cbject_Object * poolFirstFreeObject;
    cbject_Object * (*acquire)(cbject_ObjectClass * const self);
#endif
#if (cbject_config_useHeap == true)
    cbject_Object * (*alloc)(cbject_ObjectClass * const self);
#endif
    uint64_t (*hashCode)(cbject_Object const * const self);
    cbject_Object * (*copy)(cbject_Object const * const self, cbject_Object * const object);
    bool (*equals)(cbject_Object const * const self, cbject_Object const * const object);
    cbject_Object * (*terminate)(cbject_Object * self);
};

/*************************************************************************************************** tag::function[]
= cbject_ObjectClass_acquire()
====
----
cbject_Object * cbject_ObjectClass_acquire(cbject_ObjectClass * const self);
----
Acquires an object from the static pool

.Params
* self - cbject_ObjectClass reference

.Return
Reference of the acquired object
====
end::function[] ***********************************************************************************/
#if (cbject_config_useStaticPool == true)
cbject_Object * cbject_ObjectClass_acquire(cbject_ObjectClass * const self);
#endif

/*************************************************************************************************** tag::function[]
= cbject_ObjectClass_alloc()
====
----
cbject_Object * cbject_ObjectClass_alloc(cbject_ObjectClass * const self);
----
Allocates an object in heap memory

.Params
* self - cbject_ObjectClass reference

.Return
Reference of the allocated object
====
end::function[] ***********************************************************************************/
#if (cbject_config_useHeap == true)
cbject_Object * cbject_ObjectClass_alloc(cbject_ObjectClass * const self);
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
    cbject_Object * const self,
    cbject_ObjectClass * const klass,
    cbject_Object_Source const source
);
----
Sets the class of the object and other proprieties needed for allocation

.Params
* self - cbject_Object reference
* klass - cbject_ObjectClass reference
* source - cbject_Object_Source (optional - depends on heap and static pool config)

.Return
Reference to the object
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Object_allocHelper(
    cbject_Object * const self,
    cbject_ObjectClass * const klass,
#if (cbject_config_useStaticPool == true) || (cbject_config_useHeap == true)
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
bool cbject_Object_isOfClass(cbject_Object const * const self, cbject_ObjectClass const * const klass);
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
bool cbject_Object_isOfClass(cbject_Object const * const self, cbject_ObjectClass const * const klass);

/*************************************************************************************************** tag::function[]
= cbject_ObjectClass_instance()
====
----
cbject_ObjectClass * cbject_ObjectClass_instance(void);
----
Gets cbject_ObjectClass instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_ObjectClass * cbject_ObjectClass_instance(void);

/*************************************************************************************************** tag::macro[]
= cbject_ObjectClass_setup()
====
----
cbject_ObjectClass_setup(self)
----
Populates the class instance

.Remark
cbject_Class must be defined before using this macro

.Params
* self - Class reference
====
end::macro[] **************************************************************************************/
#if (cbject_config_useStaticPool == true)
#define cbject_ObjectClass_setup(self)                                                                                                                                 \
    *((cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class) *)(self)) =                                                                 \
        *cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class_instance());                                                               \
    ((cbject_ObjectClass *)(self))->name = cbject_utils_Token_stringifyIndirect(cbject_utils_Pair_getFirst(cbject_Class));                                             \
    ((cbject_ObjectClass *)(self))->instanceSize = sizeof(cbject_utils_Pair_getFirst(cbject_Class));                                                                   \
    ((cbject_ObjectClass *)(self))->superClass = (cbject_ObjectClass *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class_instance()); \
    ((cbject_ObjectClass *)(self))->pool = (cbject_Object *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), _pool);                        \
    ((cbject_ObjectClass *)(self))->poolSize = cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), _poolSize);                                 \
    ((cbject_ObjectClass *)(self))->poolFirstFreeObject = (cbject_Object *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), _pool)
#else
#define cbject_ObjectClass_setup(self)                                                                                     \
    *((cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class) *)(self)) =                     \
        *cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class_instance());                   \
    ((cbject_ObjectClass *)(self))->name = cbject_utils_Token_stringifyIndirect(cbject_utils_Pair_getFirst(cbject_Class)); \
    ((cbject_ObjectClass *)(self))->instanceSize = sizeof(cbject_utils_Pair_getFirst(cbject_Class));                       \
    ((cbject_ObjectClass *)(self))->superClass = (cbject_ObjectClass *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getSecond(cbject_Class), Class_instance())
#endif

/*************************************************************************************************** tag::macro[]
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
#define cbject_Object_class(self) \
    ((cbject_Object *)(self))->klass

/*************************************************************************************************** tag::macro[]
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
#define cbject_Object_instanceSize(self) \
    cbject_Object_class(self)->instanceSize

#endif // CBJECT_OBJECT_H
