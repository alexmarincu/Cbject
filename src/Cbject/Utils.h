/* tag::overview[]
TODO
end::overview[] */
#ifndef UTILS_H
#define UTILS_H
#include <assert.h>
/* tag::type[]
= Any
====
----
typedef void Any;
----
Typedef for Any

.Remark
To be used with pointers to anything
====
end::type[] */
typedef void Any;
/* tag::macro[]
= doOnce_
====
----
#define doOnce_
----
Run a block of code only once

.Usage
----
doOnce_ {
    functionCall();
    anotherFunctionCall();
}
----

.Remark
Not thread safe
====
end::macro[] */
#define doOnce_                 \
    static bool isDone = false; \
    for (; isDone == false; isDone = true)
/* tag::macro[]
= assertStatic_()
====
----
#define assertStatic_(expression, identifier)
----
Compile time assert

.Params
* expression - Expression to assert
* identifier - An identifier to describe the assertion
====
end::macro[] */
#define assertStatic_(expression, identifier) \
    typedef char identifier[(!!(expression)) * 2 - 1]
/* tag::macro[]
= to_()
====
----
#define to_(typeName, instance)
----
Cast an instance to the provided typeName

.Params
* typeName - Name of the type (class or interface)
* instance - Instance to cast

.Return
Instance cast to the provided typeName
====
end::macro[] */
#define to_(typeName, instance) \
    ((typeName *)(instance))
/* tag::macro[]
= lengthOf_()
====
----
#define lengthOf_(array)
----
Get length of an array

.Params
* array - Array for which to get the length
====
end::macro[] */
#define lengthOf_(array) \
    (sizeof(array) / sizeof(array[0]))
/* tag::macro[]
= salloc_()
====
----
#define salloc_(typeName)
----
Syntactic sugar to allocate memory on the stack

.Params
* typeName - Name of type

.Return
Reference of the allocated memory
====
end::macro[] */
#define salloc_(typeName) \
    (&(typeName){ 0 })
/* tag::macro[]
= ignore_()
====
----
#define ignore_(var)
----
Syntactic sugar to ignore unused variables

.Params
* var - Variable to be ignored
====
end::macro[] */
#define ignore_(var) \
    (void)var
/* tag::macro[]
= extends_()
====
----
#define extends_(typeName)
----
Syntactic sugar to extend a type

.Remark
Should be used as the first member in the structure

.Params
* typeName - Name of the type
====
end::macro[] */
#define extends_(typeName) \
    typeName e##typeName
/* tag::macro[]
= implements_()
====
----
#define implements_(typeName)
----
Syntactic sugar to compose a type with the provided typeName

.Remark
Should be used after extends_() macro

.Params
* typeName - Name of the type
====
end::macro[] */
#define implements_(typeName) \
    typeName i##typeName
/* tag::macro[]
= class_()
====
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
= singleton_()
====
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
= classOf_()
====
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
= objectSizeOf_()
====
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
= offsetOf_()
====
----
#define offsetOf_(trait)
----
Get offset of a trait in container object

.Params
* trait - Trait reference

.Return
Offset of trait in container object
====
end::macro[] */
#define offsetOf_(trait) \
    to_(Trait, trait)->offset
/* tag::macro[]
= interfaceOffsetOf_()
====
----
#define interfaceOffsetOf_(trait)
----
Get the interface offset in container class

.Params
* trait - Trait reference

.Return
Offset of interface in container class
====
end::macro[] */
#define interfaceOffsetOf_(trait) \
    to_(Trait, trait)->interfaceOffset
/* tag::macro[]
= objectOf_()
====
----
#define objectOf_(trait)
----
Get container object from a trait

.Params
* trait - Trait reference

.Return
Reference of the container object
====
end::macro[] */
#define objectOf_(trait) \
    to_(Object, to_(Any, trait) - offsetOf_(trait))
/* tag::macro[]
= interfaceOf_()
====
----
#define interfaceOf_(trait)
----
Get the interface of a trait

.Params
* trait - Trait reference

.Return
Interface reference
====
end::macro[] */
#define interfaceOf_(trait) \
    to_(TraitInterface, to_(Any, classOf_(objectOf_(trait))) + interfaceOffsetOf_(trait))
/* tag::macro[]
= interface_()
====
----
#define interface_(interfaceName)
----
Syntactic sugar to get interface reference

.Params
* interfaceName - Name of the interface

.Return
Interface reference
====
end::macro[] */
#define interface_(interfaceName) \
    interfaceName##Interface_instance()
/* tag::macro[]
= traitMethodCall_()
====
----
#define traitMethodCall_(interfaceName, methodName, ...)
----
Call a method through a trait

.Params
* interfaceName - Name of the interface
* methodName - Name of the method
* ...
** trait - Trait reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define traitMethodCall_(interfaceName, methodName, ...) \
    to_(interfaceName##Interface, interfaceOf_(VaArgs_first_(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
= interfaceMethodCall_()
====
----
#define interfaceMethodCall_(className, interfaceName, methodName, ...)
----
Call a method through an interface

.Params
* className - Name of the class
* interfaceName - Name of the interface
* methodName - Name of the method
* ...
** trait - Trait reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define interfaceMethodCall_(className, interfaceName, methodName, ...) \
    to_(interfaceName##Interface, &to_(className##Class, class_(className))->i##interfaceName##Interface)->methodName(__VA_ARGS__)
/* tag::macro[]
= VaArgs_first_()
====
----
#define VaArgs_first_(...)
----
Get first argument from __VA_ARGS__

.Params
* ... - __VA_ARGS__
====
end::macro[] */
#define VaArgs_first_(...) \
    VaArgs_first_h0(__VA_ARGS__, discard)
#define VaArgs_first_h0(first, ...) \
    first
/* tag::macro[]
= VaArgs_rest_()
====
----
#define VaArgs_rest_(...)
----
Get list of arguments from __VA_ARGS__ except the first

.Remark
* Comma is added before the list
* Supports max 99 arguments

.Params
* ... - __VA_ARGS__
====
end::macro[] */
#define VaArgs_rest_(...) \
    VaArgs_rest_h0(VaArgs_case_(__VA_ARGS__), __VA_ARGS__)
#define VaArgs_rest_h0(case, ...) \
    VaArgs_rest_h1(case, __VA_ARGS__)
#define VaArgs_rest_h1(case, ...) \
    VaArgs_rest_case_##case (__VA_ARGS__)
#define VaArgs_rest_case_one(first)
#define VaArgs_rest_case_more(first, ...) \
    , __VA_ARGS__
#define VaArgs_case_(...)                                                  \
    VaArgs_get99th_(                                                       \
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
#define VaArgs_get99th_(                              \
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
#endif // UTILS_H
