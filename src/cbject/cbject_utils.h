/*************************************************************************************************** tag::overview[]
TODO
end::overview[] ***********************************************************************************/
#ifndef CBJECT_UTILS_H
#define CBJECT_UTILS_H
#include <assert.h>

/*************************************************************************************************** tag::macro[]
= cbject_utils_acquire()
====
----
cbject_utils_acquire(klass)
----
Acquires an object from the static pool

.Remarks
Calls cbject_Object_acquire() and does the necessary casting

.Params
* klass - Name of class

.Return
Reference of the acquired object
====
end::macro[] **************************************************************************************/
#define cbject_utils_acquire(klass) \
    ((klass *)cbject_Object_acquire((cbject_ObjectClass *)klass##Class_instance()))

/*************************************************************************************************** tag::macro[]
= cbject_utils_alloc()
====
----
cbject_utils_alloc(klass)
----
Allocates an object in heap memory

.Remarks
Calls cbject_Object_alloc() and does the necessary casting

.Params
* klass - Name of class

.Return
Reference of the allocated object
====
end::macro[] **************************************************************************************/
#define cbject_utils_alloc(klass) \
    ((klass *)cbject_Object_alloc((cbject_ObjectClass *)klass##Class_instance()))

/*************************************************************************************************** tag::macro[]
= cbject_utils_stackAlloc()
====
----
cbject_utils_stackAlloc(klass)
----
Allocates an object on the stack

.Params
* klass - Name of class

.Return
Reference of the allocated memory
====
end::macro[] **************************************************************************************/
#define cbject_utils_stackAlloc(klass) \
    ((klass *)cbject_Object_allocHelper((cbject_Object *)&(klass){}, (cbject_ObjectClass *)klass##Class_instance()))

/*************************************************************************************************** tag::function[]
= cbject_utils_init()
====
----
cbject_utils_init(object)
----
Initializes an object

.Remarks
Calls cbject_Object_init() and does the necessary casting

.Params
* object - cbject_Object reference

.Return
Initialized object
====
end::function[] ***********************************************************************************/
#define cbject_utils_init(object) \
    cbject_Object_init((cbject_Object *)(object))

/*************************************************************************************************** tag::macro[]
= cbject_utils_hashCode()
====
----
cbject_utils_hashCode(object)
----
Gets the hash code of the object

.Remarks
Calls cbject_Object_hashCode() and does the necessary casting

.Params
* object - cbject_Object reference

.Return
The hash code of the object
====
end::macro[] **************************************************************************************/
#define cbject_utils_hashCode(object) \
    cbject_Object_hashCode((cbject_Object *)(object))

/*************************************************************************************************** tag::macro[]
= cbject_utils_equals()
====
----
cbject_utils_equals(object, otherObject)
----
Compares two objects

.Remarks
Calls cbject_Object_equals() and does the necessary casting

.Params
* object - cbject_Object reference
* otherObject - Reference for the compared object

.Return
* true - If the objects are equal
* false - If the objects are different
====
end::macro[] **************************************************************************************/
#define cbject_utils_equals(object, otherObject) \
    cbject_Object_equals((cbject_Object *)(object), (cbject_Object *)(otherObject))

/*************************************************************************************************** tag::macro[]
= cbject_utils_copy()
====
----
cbject_utils_copy(object, copyObject)
----
Copies the object to the provided instance.

.Remarks
Calls cbject_Object_copy() and does the necessary casting

.Params
* object - cbject_Object reference
* copyObject - Reference of a new object in which to copy the original one

.Return
Reference of copyObject
====
end::macro[] **************************************************************************************/
#define cbject_utils_copy(object, copyObject) \
    cbject_Object_copy((cbject_Object *)(object), (cbject_Object *)(copyObject))

/*************************************************************************************************** tag::macro[]
= cbject_utils_retain()
====
----
cbject_utils_retain(object)
----
Increases the reference count of the object

.Remarks
Calls cbject_Object_retain() and does the necessary casting

.Params
* object - cbject_Object reference

.Return
Reference to object
====
end::macro[] **************************************************************************************/
#define cbject_utils_retain(object) \
    cbject_Object_retain((cbject_Object *)(object))

/*************************************************************************************************** tag::macro[]
= cbject_utils_release()
====
----
cbject_utils_release(object)
----
Decreases the reference count of the object and performs deallocation if reference count reaches 0

.Remarks
Calls cbject_Object_release() and does the necessary casting

.Params
* object - cbject_Object reference

.Return
NULL
====
end::macro[] **************************************************************************************/
#define cbject_utils_release(object) \
    cbject_Object_release((cbject_Object *)(object))

/*************************************************************************************************** tag::function[]
= cbject_utils_isOfClass()
====
----
cbject_utils_isOfClass(object, klass)
----
Checks if an object is of a given class

.Remarks
Calls cbject_Object_isOfClass() and does the necessary casting

.Params
* object - cbject_Object reference
* klass - Name of class

.Return
* true - If the object is of the provided class
* false - If the object is of a different class
====
end::function[] ***********************************************************************************/
#define cbject_utils_isOfClass(object, klass) \
    cbject_Object_isOfClass((cbject_Object *)(object), (cbject_ObjectClass *)klass##Class_instance())

/*************************************************************************************************** tag::macro[]
= cbject_utils_allocPool()
====
----
cbject_utils_allocPool(poolSize)
----
Allocates a static pool

.Remarks
cbject_Class must be defined before using this macro

.Params
* poolSize - Size of pool (number of objects in pool)
====
end::macro[] **************************************************************************************/
#define cbject_utils_allocPool(poolSize) \
    static cbject_utils_Pair_getFirst(cbject_Class) cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), _pool)[poolSize]

/*************************************************************************************************** tag::macro[]
= cbject_utils_doOnce
====
----
cbject_utils_doOnce
----
Runs a block of code only once

.Usage
----
cbject_utils_doOnce {
    functionCall();
    anotherFunctionCall();
}
----

.Remark
Not thread safe
====
end::macro[] **************************************************************************************/
#define cbject_utils_doOnce     \
    static bool isDone = false; \
    for (; isDone == false; isDone = true)

/*************************************************************************************************** tag::macro[]
= cbject_utils_invokeMethod()
====
----
cbject_utils_invokeMethod(method, ...)
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
#define cbject_utils_invokeMethod(method, ...) \
    ((cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), Class) *)((cbject_Object *)cbject_utils_VaArgs_getFirst(__VA_ARGS__))->objectClass)->method(__VA_ARGS__)

/*************************************************************************************************** tag::macro[]
= cbject_utils_invokeClassMethod()
====
----
cbject_utils_invokeClassMethod(method, ...)
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
#define cbject_utils_invokeClassMethod(method, ...) \
    ((cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), Class) *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), Class_instance()))->method(__VA_ARGS__)

/*************************************************************************************************** tag::macro[]
= cbject_utils_invokeSuperMethod()
====
----
cbject_utils_invokeSuperMethod(type, method, ...)
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
#define cbject_utils_invokeSuperMethod(klass, method, ...) \
    ((klass##Class *)((cbject_ObjectClass *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), Class_instance()))->superClass)->method(__VA_ARGS__)

/*************************************************************************************************** tag::macro[]
= cbject_utils_Array_length()
====
----
cbject_utils_Array_length(array)
----
Gets length of an array

.Params
* array - Array for which to get the length
====
end::macro[] **************************************************************************************/
#define cbject_utils_Array_length(array) \
    (sizeof(array) / sizeof(array[0]))

/*************************************************************************************************** tag::macro[]
= cbject_utils_assertStatic()
====
----
cbject_utils_assertStatic(expression, identifier)
----
Compile time assert

.Params
* expression - Expression to assert
* identifier - An identifier to describe the assertion
====
end::macro[] **************************************************************************************/
#define cbject_utils_assertStatic(expression, identifier) \
    typedef char identifier[(!!(expression)) * 2 - 1]

/*************************************************************************************************** tag::macro[]
= cbject_utils_Token_concat()
====
----
cbject_utils_Token_concat(token, otherToken)
----
Concatenates otherToken after the provided token

.Params
* token - Token
* otherToken - Token to add after the provided token
====
end::macro[] **************************************************************************************/
#define cbject_utils_Token_concat(token, otherToken) \
    token##otherToken

/*************************************************************************************************** tag::macro[]
= cbject_utils_Token_concatIndirect()
====
----
cbject_utils_Token_concatIndirect(token, otherToken)
----
Concatenates otherToken after the provided token indirectly

.Params
* token - Token
* otherToken - Token to add after the provided token
====
end::macro[] **************************************************************************************/
#define cbject_utils_Token_concatIndirect(token, otherToken) \
    cbject_utils_Token_concat(token, otherToken)

/*************************************************************************************************** tag::macro[]
= cbject_utils_Token_stringify()
====
----
cbject_utils_Token_stringify(token)
----
Stringifies the provided token

.Params
* token - Token
====
end::macro[] **************************************************************************************/
#define cbject_utils_Token_stringify(token) \
#token

/*************************************************************************************************** tag::macro[]
= cbject_utils_Token_stringifyIndirect()
====
----
cbject_utils_Token_stringifyIndirect(token)
----
Stringifies the provided token indirectly

.Params
* token - Token
====
end::macro[] **************************************************************************************/
#define cbject_utils_Token_stringifyIndirect(token) \
    cbject_utils_Token_stringify(token)

/*************************************************************************************************** tag::macro[]
= cbject_utils_VaArgs_getFirst()
====
----
cbject_utils_VaArgs_getFirst(...)
----
Gets first argument from __VA_ARGS__

.Params
* ... - __VA_ARGS__
====
end::macro[] **************************************************************************************/
#define cbject_utils_VaArgs_getFirst(...) \
    cbject_utils_VaArgs_getFirst_(__VA_ARGS__, discard)
#define cbject_utils_VaArgs_getFirst_(first, ...) \
    first

/*************************************************************************************************** tag::macro[]
= cbject_utils_VaArgs_getSecond()
====
----
cbject_utils_VaArgs_getSecond(...)
----
Gets second argument from __VA_ARGS__

.Params
* ... - __VA_ARGS__
====
end::macro[] **************************************************************************************/
#define cbject_utils_VaArgs_getSecond(...) \
    cbject_utils_VaArgs_getSecond_(__VA_ARGS__, discard)
#define cbject_utils_VaArgs_getSecond_(first, second, ...) \
    second

/*************************************************************************************************** tag::macro[]
= cbject_utils_VaArgs_getRest()
====
----
cbject_utils_VaArgs_getRest(...)
----
Gets list of arguments from __VA_ARGS__ except the first

.Remark
* Comma is added before the list
* Supports max 99 arguments

.Params
* ... - __VA_ARGS__
====
end::macro[] **************************************************************************************/
#define cbject_utils_VaArgs_getRest(...) \
    cbject_utils_VaArgs_getRest_(cbject_utils_VaArgs_case(__VA_ARGS__), __VA_ARGS__)
#define cbject_utils_VaArgs_getRest_(case, ...) \
    cbject_utils_VaArgs_getRest__(case, __VA_ARGS__)
#define cbject_utils_VaArgs_getRest__(case, ...) \
    cbject_utils_VaArgs_getRest_case_##case (__VA_ARGS__)
#define cbject_utils_VaArgs_getRest_case_one(first)
#define cbject_utils_VaArgs_getRest_case_more(first, ...) \
    , __VA_ARGS__
#define cbject_utils_VaArgs_case(...)                                      \
    cbject_utils_VaArgs_get99th(                                           \
        __VA_ARGS__, more, more, more, more, more, more, more, more, more, \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, more, more,        \
        more, more, more, more, more, more, more, more, one, discard       \
    )
#define cbject_utils_VaArgs_get99th(                  \
    a01, a02, a03, a04, a05, a06, a07, a08, a09, a10, \
    a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, \
    a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, \
    a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, \
    a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, \
    a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, \
    a61, a62, a63, a64, a65, a66, a67, a68, a69, a70, \
    a71, a72, a73, a74, a75, a76, a77, a78, a79, a80, \
    a81, a82, a83, a84, a85, a86, a87, a88, a89, a90, \
    a91, a92, a93, a94, a95, a96, a97, a98, a99, ...  \
)                                                     \
    a99

/*************************************************************************************************** tag::macro[]
= cbject_utils_Pair_getFirst()
====
----
cbject_utils_Pair_getFirst(pair)
----
Gets first element from pair

.Params
* pair - (first, second)
====
end::macro[] **************************************************************************************/
#define cbject_utils_Pair_getFirst(pair) \
    cbject_utils_VaArgs_getFirst pair

/*************************************************************************************************** tag::macro[]
= cbject_utils_Pair_getSecond()
====
----
cbject_utils_Pair_getSecond(pair)
----
Gets second element from pair

.Params
* pair - (first, second)
====
end::macro[] **************************************************************************************/
#define cbject_utils_Pair_getSecond(pair) \
    cbject_utils_VaArgs_getSecond pair

#endif // CBJECT_UTILS_H
