/* tag::overview[]
TODO


end::overview[] */
#ifndef TRAIT_H
#define TRAIT_H
#include "Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* tag::type[]
===== Trait_Interface
====
[source,c]
----
typedef struct {
    size_t traitOffset;
} Trait_Interface;
----
Typedef and definition of Trait_Interface

.Members
* traitOffset - Offset of trait in containing object
====
end::type[] */
typedef struct {
    size_t traitOffset;
} Trait_Interface;
/* tag::function[]
===== Trait_Interface_
====
[source,c]
----
Trait_Interface const * Trait_Interface_(void);
----
Get Trait_Interface instance

.Return
Reference of the trait interface
====
end::function[] */
Trait_Interface const * Trait_Interface_(void);
/* tag::type[]
===== Trait
====
[source,c]
----
typedef struct {
    size_t offset;
    size_t interfaceOffset;
} Trait;
----
Typedef and definition of Trait

.Members
* offset - Offset of Trait in container Object
* interfaceOffset - Offset of Trait_Interface in container Object_Class
====
end::type[] */
typedef struct {
    size_t offset;
    size_t interfaceOffset;
} Trait;
/* tag::function[]
===== Trait_init
====
[source,c]
----
Trait * Trait_init(Trait * const trait);
----
Initialize a trait

.Params
* trait - Trait reference

.Return
Initialized trait
====
end::function[] */
Trait * Trait_init(Trait * const trait);
/* tag::macro[]
===== interface_()
====
[source,c]
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
    interfaceName##_Interface_()
/* tag::macro[]
===== initInterface_()
====
[source,c]
----
#define initInterface_(interfaceName, interface)
----
Initialize an interface

.Params
* interfaceName - Name of the interface
* interface - Interface reference
====
end::macro[] */
#define initInterface_(interfaceName, interface) \
    *to_(interfaceName##_Interface, interface) = *interface_(interfaceName);
/* tag::macro[]
===== setUpInterface_()
====
[source,c]
----
#define setUpInterface_(className, interfaceName, interface)
----
Interface setup (initialize, set the trait offset in container object)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* interface - Interface reference
====
end::macro[] */
#define setUpInterface_(className, interfaceName, interface)                   \
    initInterface_(interfaceName, &(interface)->i##interfaceName##_Interface); \
    to_(Trait_Interface, &(interface)->i##interfaceName##_Interface)->traitOffset = offsetof(className, i##interfaceName)
/* tag::macro[]
===== overrideInterfaceMethod_()
====
[source,c]
----
#define overrideInterfaceMethod_(className, interfaceName, interface, methodName)
----
Override a method of an interface

.Params
* className - Name of the class
* interfaceName - Name of the interface
* interface - Interface reference
* methodName - Name of the method
====
end::macro[] */
#define overrideInterfaceMethod_(className, interfaceName, interface, methodName) \
    to_(interfaceName##_Interface, &to_(className##_Class, interface)->i##interfaceName##_Interface)->methodName = methodName
/* tag::macro[]
===== offsetOf_()
====
[source,c]
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
===== objectOf_()
====
[source,c]
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
===== interfaceOffsetOf_()
====
[source,c]
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
===== interfaceOf_()
====
[source,c]
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
#define interfaceOf_(trait)                                              \
    to_(                                                                 \
        Trait_Interface,                                                 \
        to_(Any, classOf_(objectOf_(trait))) + interfaceOffsetOf_(trait) \
    )
/* tag::macro[]
===== initTrait_()
====
[source,c]
----
#define initTrait_(interfaceName, ...)
----
Syntactic sugar for trait initialization

.Params
* interfaceName - Name of the interface
* ...
** trait - Trait reference
** ... - Init params

.Return
Initialized trait
====
end::macro[] */
#define initTrait_(interfaceName, ...) \
    interfaceName##_init(to_(interfaceName, VaArgs_first_(__VA_ARGS__)) VaArgs_rest_(__VA_ARGS__))
/* tag::macro[]
===== setUpTrait_()
====
[source,c]
----
#define setUpTrait_(className, interfaceName, ...)
----
Trait setup (initialize, set the trait offset and interface offset)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* ...
** trait - Trait reference
** ... - Init params
====
end::macro[] */
#define setUpTrait_(className, interfaceName, ...)                                                      \
    initTrait_(interfaceName, &VaArgs_first_(__VA_ARGS__)->i##interfaceName VaArgs_rest_(__VA_ARGS__)); \
    offsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className, i##interfaceName);   \
    interfaceOffsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className##_Class, i##interfaceName##_Interface)
/* tag::macro[]
===== traitMethodCall_()
====
[source,c]
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
    to_(interfaceName##_Interface, interfaceOf_(VaArgs_first_(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
===== interfaceMethodCall_()
====
[source,c]
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
    to_(interfaceName##_Interface, &to_(className##_Class, class_(className))->i##interfaceName##_Interface)->methodName(__VA_ARGS__)
#endif // TRAIT_H
