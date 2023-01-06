/* tag::overview[]
TODO
end::overview[] */
#ifndef CBJECT_UTILS_H
#define CBJECT_UTILS_H
#include <assert.h>
/* tag::macro[]
= cbject_utils_typedefClass()
====
----
cbject_utils_typedefClass(className)
----
Syntactic sugar to define types for a class

.Params
* className - Name of the class
====
end::macro[] */
#define cbject_utils_typedefClass(className)          \
    typedef struct className##Class className##Class; \
    typedef struct className className
/* tag::macro[]
= cbject_utils_typedefInterface()
====
----
cbject_utils_typedefInterface(interfaceName)
----
Syntactic sugar to define types for an interface

.Params
* interfaceName - Name of the interface
====
end::macro[] */
#define cbject_utils_typedefInterface(interfaceName)                  \
    typedef struct interfaceName##Interface interfaceName##Interface; \
    typedef struct interfaceName interfaceName
/* tag::macro[]
= cbject_utils_cast()
====
----
cbject_utils_cast(typeName, instance)
----
Cast an instance to the provided typeName

.Params
* typeName - Name of the type (class or interface)
* instance - Instance to cast

.Return
Instance cast to the provided typeName
====
end::macro[] */
#define cbject_utils_cast(typeName, instance) \
    ((typeName *)(instance))
/* tag::macro[]
= cbject_getClassOfObject()
====
----
cbject_getClassOfObject(object)
----
Get the class of an object

.Params
* object - cbject_Object reference

.Return
Class reference
====
end::macro[] */
#define cbject_getClassOfObject(object) \
    ((cbject_Object *)object)->objectClass
/* tag::macro[]
= cbject_getSizeOfObject()
====
----
cbject_getSizeOfObject(object)
----
Get the size in memory of an object

.Params
* object - cbject_Object reference

.Return
cbject_Object size
====
end::macro[] */
#define cbject_getSizeOfObject(object) \
    cbject_getClassOfObject(object)->objectSize
/* tag::macro[]
= cbject_getTraitOfObject()
====
----
cbject_getTraitOfObject(className, interfaceName, object)
----
Get trait of an object

.Params
* className - Name of the class
* interfaceName - Name of the interface
* object - cbject_Object reference

.Return
cbject_Trait reference
====
end::macro[] */
#define cbject_getTraitOfObject(className, interfaceName, object) \
    cbject_utils_cast(interfaceName, (((void *)(object)) + cbject_utils_cast(cbject_TraitInterface, &cbject_utils_cast(className##Class, cbject_getClassOfObject(object))->ss_##interfaceName##Interface)->traitOffset))
/* tag::macro[]
= cbject_callMethodOfObject()
====
----
cbject_callMethodOfObject(className, methodName, ...)
----
Call a method through an object

.Params
* className - Name of the class
* methodName - Name of the method
* ...
** object - cbject_Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define cbject_callMethodOfObject(className, methodName, ...) \
    cbject_utils_cast(className##Class, cbject_getClassOfObject(cbject_utils_VaArgs_first(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
= cbject_callMethodOfClass()
====
----
cbject_callMethodOfClass(className, superClassName, methodName, ...)
----
Call a method through a class

.Params
* className - Name of the class
* superClassName - Name of the super class
* methodName - Name of the method
* ...
** object - cbject_Object reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define cbject_callMethodOfClass(className, superClassName, methodName, ...) \
    cbject_utils_cast(superClassName##Class, className##Class_getInstance())->methodName(__VA_ARGS__)
/* tag::macro[]
= cbject_utils_getInterfaceOffsetOfTrait()
====
----
cbject_utils_getInterfaceOffsetOfTrait(trait)
----
Get the interface offset in container class

.Params
* trait - cbject_Trait reference

.Return
Offset of interface in container class
====
end::macro[] */
#define cbject_utils_getInterfaceOffsetOfTrait(trait) \
    cbject_utils_cast(cbject_Trait, trait)->interfaceOffset
/* tag::macro[]
= cbject_getObjectOfTrait()
====
----
cbject_getObjectOfTrait(trait)
----
Get container object from a trait

.Params
* trait - cbject_Trait reference

.Return
Reference of the container object
====
end::macro[] */
#define cbject_getObjectOfTrait(trait) \
    ((cbject_Trait *)(trait))->object
/* tag::macro[]
= cbject_utils_getInterfaceOfTrait()
====
----
cbject_utils_getInterfaceOfTrait(trait)
----
Get the interface of a trait

.Params
* trait - cbject_Trait reference

.Return
Interface reference
====
end::macro[] */
#define cbject_utils_getInterfaceOfTrait(trait) \
    ((cbject_TraitInterface *)((cbject_Trait *)(trait))->interface)
/* tag::macro[]
= cbject_callMethodOfTrait()
====
----
cbject_callMethodOfTrait(interfaceName, methodName, ...)
----
Call a method through a trait

.Params
* interfaceName - Name of the interface
* methodName - Name of the method
* ...
** trait - cbject_Trait reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define cbject_callMethodOfTrait(interfaceName, methodName, ...) \
    cbject_utils_cast(interfaceName##Interface, cbject_utils_getInterfaceOfTrait(cbject_utils_VaArgs_first(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
= cbject_callMethodOfInterface()
====
----
cbject_callMethodOfInterface(className, interfaceName, methodName, ...)
----
Call a method through an interface

.Params
* className - Name of the class
* interfaceName - Name of the interface
* methodName - Name of the method
* ...
** trait - cbject_Trait reference
** ... - Method params

.Return
Depends on the called method
====
end::macro[] */
#define cbject_callMethodOfInterface(className, interfaceName, methodName, ...)                             \
    cbject_utils_cast(                                                                                      \
        interfaceName##Interface,                                                                           \
        &cbject_utils_cast(className##Class, className##Class_getInstance())->ss_##interfaceName##Interface \
    )                                                                                                       \
        ->methodName(__VA_ARGS__)
/* tag::macro[]
= cbject_utils_VaArgs_first()
====
----
cbject_utils_VaArgs_first(...)
----
Get first argument from __VA_ARGS__

.Params
* ... - __VA_ARGS__
====
end::macro[] */
#define cbject_utils_VaArgs_first(...) \
    cbject_utils_VaArgs_first_helper_0(__VA_ARGS__, discard)
#define cbject_utils_VaArgs_first_helper_0(first, ...) \
    first
/* tag::macro[]
= cbject_utils_VaArgs_rest()
====
----
cbject_utils_VaArgs_rest(...)
----
Get list of arguments from __VA_ARGS__ except the first

.Remark
* Comma is added before the list
* Supports max 99 arguments

.Params
* ... - __VA_ARGS__
====
end::macro[] */
#define cbject_utils_VaArgs_rest(...) \
    cbject_utils_VaArgs_rest_helper_0(cbject_utils_VaArgs_case(__VA_ARGS__), __VA_ARGS__)
#define cbject_utils_VaArgs_rest_helper_0(case, ...) \
    cbject_utils_VaArgs_rest_helper_1(case, __VA_ARGS__)
#define cbject_utils_VaArgs_rest_helper_1(case, ...) \
    cbject_utils_VaArgs_rest_case_##case (__VA_ARGS__)
#define cbject_utils_VaArgs_rest_case_one(first)
#define cbject_utils_VaArgs_rest_case_more(first, ...) \
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
#endif // CBJECT_UTILS_H
