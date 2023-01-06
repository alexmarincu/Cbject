/* tag::overview[]
TODO
end::overview[] */
#ifndef CBJECT_TRAIT_H
#define CBJECT_TRAIT_H
#include "cbject/cbject_Object.h"
#include "cbject_utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* tag::type[]
= cbject_Trait, cbject_TraitInterface
====
----
cbject_utils_typedefInterface(cbject_Trait);
----
Typedef for struct cbject_Trait and struct cbject_TraitInterface
====
end::type[] */
cbject_utils_typedefInterface(cbject_Trait);
/* tag::type[]
= struct cbject_TraitInterface
====
----
struct cbject_TraitInterface {
    char * name;
    size_t traitOffset;
};
----
Definition of struct cbject_TraitInterface

.Members
* traitOffset - Offset of trait in containing object
====
end::type[] */
/* @startuml(id=cbject_TraitInterface)
object cbject_TraitInterface {
    char * name;
    size_t traitOffset;
}
@enduml */
struct cbject_TraitInterface {
    char * name;
    size_t traitOffset;
};
/* tag::type[]
= struct cbject_Trait
====
----
struct cbject_Trait {
    size_t offset;
    size_t interfaceOffset;
};
----
Definition of struct cbject_Trait

.Members
* offset - Offset of cbject_Trait in container cbject_Object
* interfaceOffset - Offset of cbject_TraitInterface in container cbject_ObjectClass
====
end::type[] */
/* @startuml(id=cbject_Trait)
object cbject_Trait {
    size_t offset;
    size_t interfaceOffset;
}
@enduml */
struct cbject_Trait {
    cbject_Object * object;
    void * interface;
};
/* tag::function[]
= cbject_TraitInterface_getInstance()
====
----
cbject_TraitInterface const * cbject_TraitInterface_getInstance(void);
----
Get cbject_TraitInterface instance

.Return
Reference of the trait interface
====
end::function[] */
cbject_TraitInterface const * cbject_TraitInterface_getInstance(void);
/* tag::function[]
= cbject_Trait_init()
====
----
cbject_Trait * cbject_Trait_init(cbject_Trait * const trait);
----
Initialize a trait

.Params
* trait - cbject_Trait reference

.Return
Initialized trait
====
end::function[] */
cbject_Trait * cbject_Trait_init(cbject_Trait * const trait);
#endif // CBJECT_TRAIT_H
