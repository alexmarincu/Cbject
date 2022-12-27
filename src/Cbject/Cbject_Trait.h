/* tag::overview[]
TODO
end::overview[] */
#ifndef CBJECT_TRAIT_H
#define CBJECT_TRAIT_H
#include "Cbject_Utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* tag::type[]
= Cbject_TraitInterface
====
----
typedef struct Cbject_TraitInterface Cbject_TraitInterface;
----
Typedef for struct Cbject_TraitInterface
====
end::type[] */
typedef struct Cbject_TraitInterface Cbject_TraitInterface;
/* tag::type[]
= Cbject_Trait
====
----
typedef struct Cbject_Trait Cbject_Trait;
----
Typedef for struct Cbject_Trait
====
end::type[] */
typedef struct Cbject_Trait Cbject_Trait;
/* tag::type[]
= struct Cbject_TraitInterface
====
----
struct Cbject_TraitInterface {
    char * name;
    size_t traitOffset;
};
----
Definition of struct Cbject_TraitInterface

.Members
* traitOffset - Offset of trait in containing object
====
end::type[] */
/* @startuml(id=Cbject_TraitInterface)
object Cbject_TraitInterface {
    char * name;
    size_t traitOffset;
}
@enduml */
struct Cbject_TraitInterface {
    char * name;
    size_t traitOffset;
};
/* tag::type[]
= struct Cbject_Trait
====
----
struct Cbject_Trait {
    size_t offset;
    size_t interfaceOffset;
};
----
Definition of struct Cbject_Trait

.Members
* offset - Offset of Cbject_Trait in container Cbject_Object
* interfaceOffset - Offset of Cbject_TraitInterface in container Cbject_ObjectClass
====
end::type[] */
/* @startuml(id=Cbject_Trait)
object Cbject_Trait {
    size_t offset;
    size_t interfaceOffset;
}
@enduml */
struct Cbject_Trait {
    size_t offset;
    size_t interfaceOffset;
};
/* tag::function[]
= Cbject_TraitInterface_instance()
====
----
Cbject_TraitInterface const * Cbject_TraitInterface_instance(void);
----
Get Cbject_TraitInterface instance

.Return
Reference of the trait interface
====
end::function[] */
Cbject_TraitInterface const * Cbject_TraitInterface_instance(void);
/* tag::function[]
= Cbject_Trait_init()
====
----
Cbject_Trait * Cbject_Trait_init(Cbject_Trait * const trait);
----
Initialize a trait

.Params
* trait - Cbject_Trait reference

.Return
Initialized trait
====
end::function[] */
Cbject_Trait * Cbject_Trait_init(Cbject_Trait * const trait);
#endif // CBJECT_TRAIT_H
