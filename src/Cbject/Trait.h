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
----
struct TraitInterface {
    char * name;
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
    char * name;
    size_t traitOffset;
}
@enduml */
struct TraitInterface {
    char * name;
    size_t traitOffset;
};
/* tag::type[]
= struct Trait
====
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
= setUpInterface_()
====
----
#define setUpInterface_(interfaceName, interface)
----
Interface setup (initialize super)

.Params
* interfaceName - Name of the interface
* interface - Interface instance
====
end::macro[] */
#define setUpInterface_(interfaceName, superInterfaceName, interface)                 \
    *to_(superInterfaceName##Interface, interface) = *interface_(superInterfaceName); \
    to_(TraitInterface, interface)->name = #interfaceName
/* tag::macro[]
= bindInterfaceMethod_()
====
----
#define bindInterfaceMethod_(interfaceName, methodName, interface)
----
Bind a method of an interface

.Params
* interfaceName - Name of the interface
* superInterfaceName - Name of the super interface
* methodName - Name of the method
* interface - Interface instance
====
end::macro[] */
#define bindInterfaceMethod_(interfaceName, methodName, interface) \
    to_(interfaceName##Interface, interface)->methodName = methodName
/* tag::macro[]
= initTrait_()
====
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
#endif // TRAIT_H
