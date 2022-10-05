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
= TraitInterface
====
[source,c]
----
typedef struct TraitInterface TraitInterface;
----
Typedef for struct TraitInterface
====
end::type[] */
typedef struct TraitInterface TraitInterface;
/* tag::type[]
= Trait
====
[source,c]
----
typedef struct Trait Trait;
----
Typedef for struct Trait
====
end::type[] */
typedef struct Trait Trait;
/* tag::type[]
= struct TraitInterface
====
[source,c]
----
struct TraitInterface {
    size_t traitOffset;
};
----
Definition of struct TraitInterface

.Members
* traitOffset - Offset of trait in containing object
====
end::type[] */
/* @startuml(id=TraitInterface)
object TraitInterface {
    size_t traitOffset;
}
@enduml */
struct TraitInterface {
    size_t traitOffset;
};
/* tag::type[]
= struct Trait
====
[source,c]
----
struct Trait {
    size_t offset;
    size_t interfaceOffset;
};
----
Definition of struct Trait

.Members
* offset - Offset of Trait in container Object
* interfaceOffset - Offset of TraitInterface in container ObjectClass
====
end::type[] */
/* @startuml(id=Trait)
object Trait {
    size_t offset;
    size_t interfaceOffset;
}
@enduml */
struct Trait {
    size_t offset;
    size_t interfaceOffset;
};
/* tag::function[]
= TraitInterface_instance()
====
[source,c]
----
TraitInterface const * TraitInterface_instance(void);
----
Get TraitInterface instance

.Return
Reference of the trait interface
====
end::function[] */
TraitInterface const * TraitInterface_instance(void);
/* tag::function[]
= Trait_init()
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
= typedefInterface_()
====
[source,c]
----
#define typedefInterface_(interfaceName)
----
Syntactic sugar to typedef interface types

.Params
* interfaceName - Name of the interface

.Return
Interface reference
====
end::macro[] */
#define typedefInterface_(interfaceName)                              \
    typedef struct interfaceName##Interface interfaceName##Interface; \
    typedef struct interfaceName interfaceName
/* tag::macro[]
= interface_()
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
    interfaceName##Interface_instance()
/* tag::macro[]
= initInterface_()
====
[source,c]
----
#define initInterface_(interfaceName)
----
Initialize a class

.Params
* interfaceName - Name of the interface
====
end::macro[] */
#define initInterface_(interfaceName) \
    interfaceName##Interface_init()
/* tag::macro[]
= setUpInterface_()
====
[source,c]
----
#define setUpInterface_(interfaceName, interfaceInstance)
----
Interface setup (initialize super)

.Params
* interfaceName - Name of the interface
* interfaceInstance - Interface instance
====
end::macro[] */
#define setUpInterface_(interfaceName, interfaceInstance) \
    *to_(interfaceName##Interface, interfaceInstance) = *interface_(interfaceName)
/* tag::macro[]
= bindInterfaceMethod_()
====
[source,c]
----
#define bindInterfaceMethod_(interfaceName, methodName, interfaceInstance)
----
Bind a method of an interface

.Params
* interfaceName - Name of the interface
* superInterfaceName - Name of the super interface
* methodName - Name of the method
* interfaceInstance - Interface instance
====
end::macro[] */
#define bindInterfaceMethod_(interfaceName, methodName, interfaceInstance) \
    to_(interfaceName##Interface, interfaceInstance)->methodName = methodName
/* tag::macro[]
= setUpInterfaceOf_()
====
[source,c]
----
#define setUpInterfaceOf_(className, interfaceName, classInstance)
----
Interface setup in class (initialize super, set the trait offset in container object)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* classInstance - Class instance
====
end::macro[] */
#define setUpInterfaceOf_(className, interfaceName, classInstance)                                              \
    *to_(interfaceName##Interface, &(classInstance)->i##interfaceName##Interface) = *interface_(interfaceName); \
    to_(TraitInterface, &(classInstance)->i##interfaceName##Interface)->traitOffset = offsetof(className, i##interfaceName)
/* tag::macro[]
= bindInterfaceMethodOf_()
====
[source,c]
----
#define bindInterfaceMethodOf_(className, interfaceName, methodName, classInstance)
----
Bind a method of an interface

.Params
* className - Name of the class
* interfaceName - Name of the interface
* methodName - Name of the method
* classInstance - Class instance
====
end::macro[] */
#define bindInterfaceMethodOf_(className, interfaceName, methodName, classInstance) \
    to_(interfaceName##Interface, &to_(className##Class, classInstance)->i##interfaceName##Interface)->methodName = methodName
/* tag::macro[]
= offsetOf_()
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
= objectOf_()
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
= interfaceOffsetOf_()
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
= interfaceOf_()
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
        TraitInterface,                                                  \
        to_(Any, classOf_(objectOf_(trait))) + interfaceOffsetOf_(trait) \
    )
/* tag::macro[]
= initTrait_()
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
= setUpTraitOf_()
====
[source,c]
----
#define setUpTraitOf_(className, interfaceName, ...)
----
Trait setup (initialize, set the trait offset and interface offset)

.Params
* className - Name of the class
* interfaceName - Name of the interface
* ...
** object - Object reference
** ... - Init params
====
end::macro[] */
#define setUpTraitOf_(className, interfaceName, ...)                                                    \
    initTrait_(interfaceName, &VaArgs_first_(__VA_ARGS__)->i##interfaceName VaArgs_rest_(__VA_ARGS__)); \
    offsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className, i##interfaceName);   \
    interfaceOffsetOf_(&VaArgs_first_(__VA_ARGS__)->i##interfaceName) = offsetof(className##Class, i##interfaceName##Interface)
/* tag::macro[]
= traitMethodCall_()
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
    to_(interfaceName##Interface, interfaceOf_(VaArgs_first_(__VA_ARGS__)))->methodName(__VA_ARGS__)
/* tag::macro[]
= interfaceMethodCall_()
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
    to_(interfaceName##Interface, &to_(className##Class, class_(className))->i##interfaceName##Interface)->methodName(__VA_ARGS__)
#endif // TRAIT_H
