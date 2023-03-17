/*********************************************************************************** tag::overview[]
todo
end::overview[] ***********************************************************************************/
#ifndef CBJECT_H
#define CBJECT_H
#include "cbject_Object.h"
#include "cbject_Singleton.h"

/************************************************************************************** tag::macro[]
= cbject_acquire()
====
----
cbject_acquire(klass)
----
Syntactic sugar to acquire an object from the static pool

.Params
* klass - Name of class

.Return
Reference of the acquired object
====
end::macro[] **************************************************************************************/
#define cbject_acquire(klass) \
    ((klass *)cbject_Object_acquire((cbject_ObjectClass *)klass##Class_instance()))

/************************************************************************************** tag::macro[]
= cbject_alloc()
====
----
cbject_alloc(klass)
----
Syntactic sugar to allocate an object in heap memory

.Params
* klass - Name of class

.Return
Reference of the allocated object
====
end::macro[] **************************************************************************************/
#define cbject_alloc(klass) \
    ((klass *)cbject_Object_alloc((cbject_ObjectClass *)klass##Class_instance()))

/************************************************************************************** tag::macro[]
= cbject_stackalloc()
====
----
cbject_stackalloc(klass)
----
Syntactic sugar to allocate object on the stack

.Params
* klass - Name of class

.Return
Reference of the allocated memory
====
end::macro[] **************************************************************************************/
#define cbject_stackalloc(klass) \
    (&(klass){ .objectClass = klass##Class_instance() })

/************************************************************************************** tag::macro[]
= cbject_hashCode()
====
----
cbject_hashCode(object)
----
Syntactic sugar to get the hash code of the object

.Params
* object - cbject_Object reference

.Return
The hash code of the object
====
end::macro[] **************************************************************************************/
#define cbject_hashCode(object) \
    cbject_Object_hashCode((cbject_Object *)(object))

/************************************************************************************** tag::macro[]
= cbject_equals()
====
----
cbject_equals(object, otherObject)
----
Syntactic sugar to compare two objects

.Params
* object - cbject_Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::macro[] **************************************************************************************/
#define cbject_equals(object, otherObject) \
    cbject_Object_equals((cbject_Object *)(object), (cbject_Object *)(otherObject))

/************************************************************************************** tag::macro[]
= cbject_copy()
====
----
cbject_copy(object, copyObject)
----
Syntactic sugar to copy the object to the provided instance.

.Params
* object - cbject_Object reference
* copyObject - Reference of a new allocated object in which to copy the original one

.Return
Reference of copyObject
====
end::macro[] **************************************************************************************/
#define cbject_copy(object, copyObject) \
    cbject_Object_copy((cbject_Object *)(object), (cbject_Object *)(copyObject))

/************************************************************************************** tag::macro[]
= cbject_terminate()
====
----
cbject_terminate(object)
----
Syntactic sugar to terminate an object.

.Params
* object - cbject_Object reference

.Return
NULL
====
end::macro[] **************************************************************************************/
#define cbject_terminate(object) \
    cbject_Object_terminate((cbject_Object *)(object))

/************************************************************************************** tag::macro[]
= cbject_release()
====
----
cbject_release(object)
----
Syntactic sugar to release an object in the static pool

.Params
* object - cbject_Object reference

.Return
NULL
====
end::macro[] **************************************************************************************/
#define cbject_release(object) \
    cbject_Object_release((cbject_Object *)(object))

/************************************************************************************** tag::macro[]
= cbject_dealloc()
====
----
cbject_dealloc(object)
----
Syntactic sugar to free memory allocated for an object

.Params
* object - cbject_Object reference

.Return
NULL
====
end::macro[] **************************************************************************************/
#define cbject_dealloc(object) \
    cbject_Object_dealloc((cbject_Object *)(object))

/************************************************************************************** tag::macro[]
= cbject_Array_length()
====
----
cbject_Array_length(array)
----
Gets length of an array

.Params
* array - Array for which to get the length
====
end::macro[] **************************************************************************************/
#define cbject_Array_length(array) \
    cbject_utils_Array_length(array)

/************************************************************************************** tag::macro[]
= cbject_assertStatic()
====
----
cbject_assertStatic(expression, identifier)
----
Compile time assert

.Params
* expression - Expression to assert
* identifier - An identifier to describe the assertion
====
end::macro[] **************************************************************************************/
#define cbject_assertStatic(expression, identifier) \
    cbject_utils_assertStatic(expression, identifier)

/************************************************************************************** tag::macro[]
= cbject_doOnce
====
----
cbject_doOnce
----
Runs a block of code only once

.Usage
----
cbject_doOnce {
    functionCall();
    anotherFunctionCall();
}
----

.Remark
Not thread safe
====
end::macro[] **************************************************************************************/
#define cbject_doOnce \
    cbject_utils_doOnce

/************************************************************************************** tag::macro[]
= cbject_invokeMethod()
====
----
cbject_invokeMethod(method, ...)
----
Polymorphic call of an object method

.Remarks
cbject_Class must be defined before using this macro

.Params
* method - Name of the method
* ...
** object - cbject_Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] **************************************************************************************/
#define cbject_invokeMethod(method, ...) \
    cbject_utils_invokeMethod(method, __VA_ARGS__)

/************************************************************************************** tag::macro[]
= cbject_invokeClassMethod()
====
----
cbject_invokeClassMethod(method, ...)
----
Polymorphic call of a class method

.Remarks
cbject_Class must be defined before using this macro

.Params
* method - Name of the method
* ... - Method params

.Return
Depends on the called method
====
end::macro[] **************************************************************************************/
#define cbject_invokeClassMethod(method, ...) \
    cbject_utils_invokeClassMethod(method, __VA_ARGS__)

/************************************************************************************** tag::macro[]
= cbject_invokeSuperMethod()
====
----
cbject_invokeSuperMethod(type, method, ...)
----
Polymorphic call of a super method (object or class)

.Remarks
cbject_Class must be defined before using this macro

.Params
* klass - Name of the class
* method - Name of the method
* ...
** object - cbject_Object reference (optional - in case of object method)
** ... - Method params

.Return
Depends on the called method
====
end::macro[] **************************************************************************************/
#define cbject_invokeSuperMethod(klass, method, ...) \
    cbject_utils_invokeSuperMethod(klass, method, __VA_ARGS__)

/************************************************************************************** tag::macro[]
= cbject_allocPool()
====
----
cbject_allocPool(poolSize)
----
Allocates a static pool

.Remarks
cbject_Class must be defined before using this macro

.Params
* poolSize - Size of pool (number of objects in pool)
====
end::macro[] **************************************************************************************/
#define cbject_allocPool(poolSize) \
    cbject_utils_allocPool(poolSize)

#endif // CBJECT_H
