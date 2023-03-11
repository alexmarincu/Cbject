/*********************************************************************************** tag::overview[]
TODO
end::overview[] ***********************************************************************************/
#ifndef CBJECT_UTILS_H
#define CBJECT_UTILS_H
#include <assert.h>

#define cbject_utils_doOnce     \
    static bool isDone = false; \
    for (; isDone == false; isDone = true)

#define cbject_utils_invokeMethod(method, ...) \
    ((cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), Class) *)((cbject_Object *)cbject_utils_VaArgs_getFirst(__VA_ARGS__))->objectClass)->method(__VA_ARGS__)

#define cbject_utils_invokeClassMethod(method, ...) \
    ((cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), Class) *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), Class_instance()))->method(__VA_ARGS__)

#define cbject_utils_invokeSuperMethod(klass, method, ...) \
    ((klass##Class *)((cbject_ObjectClass *)cbject_utils_Token_concatIndirect(cbject_utils_Pair_getFirst(cbject_Class), Class_instance()))->superClass)->method(__VA_ARGS__)

#define cbject_utils_Array_length(array) \
    (sizeof(array) / sizeof(array[0]))

#define cbject_utils_assertStatic(expression, identifier) \
    typedef char identifier[(!!(expression)) * 2 - 1]

/************************************************************************************** tag::macro[]
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

/************************************************************************************** tag::macro[]
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

/************************************************************************************** tag::macro[]
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

/************************************************************************************** tag::macro[]
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

/************************************************************************************** tag::macro[]
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

/************************************************************************************** tag::macro[]
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

/************************************************************************************** tag::macro[]
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

/************************************************************************************** tag::macro[]
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

/************************************************************************************** tag::macro[]
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
