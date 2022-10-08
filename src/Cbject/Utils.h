/* tag::overview[]
TODO
end::overview[] */
#ifndef UTILS_H
#define UTILS_H
#include <assert.h>
/* tag::type[]
= Any
====
[source,c]
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
[source,c]
----
#define doOnce_
----
Run a block of code only once

.Usage
[source,c]
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
[source,c]
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
[source,c]
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
= extends_()
====
[source,c]
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
= extends_()
====
[source,c]
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
= lengthOf_()
====
[source,c]
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
= lengthOf_()
====
[source,c]
----
#define salloc_(typeName)
----
Syntactic sugar to allocate memory on the stack

.Params
* typeName - Name of type
====
end::macro[] */
#define salloc_(typeName) \
    (&(typeName){ 0 })
/* tag::macro[]
= ignore_()
====
[source,c]
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
= VaArgs_first_()
====
[source,c]
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
[source,c]
----
#define VaArgs_rest_(...)
----
Get list of arguments from __VA_ARGS__ except the first

.Remark
* Comma is added before the list
* Supports max 10 arguments

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
