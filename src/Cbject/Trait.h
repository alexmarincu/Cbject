#ifndef TRAIT_H
#define TRAIT_H
#include "Type.h"

/**
 * @brief Interface
 * @remark To be used with pointers to Interface types
 */
typedef void Interface;

/**
 * @brief Trait
 */
typedef struct {
    extends_(Type);
    Interface const * interface;
} Trait;

/**
 * @brief Initialize a trait
 * @param me Trait reference
 * @param offset Offset of trait object inside container object
 * @param interface Trait interface
 * @return Trait* Initialized trait
 */
Trait * Trait_init(
    Trait * const me,
    size_t const offset,
    Interface const * const interface
);

/**
 * @brief Initialize a trait
 * @param me Trait reference
 * @param offset Offset of trait object inside container object
 * @param interface Trait interface
 */
#define initTrait_(me, offset, interface) \
    Trait_init(toTrait_(me), offset, toInterface_(interface))

/**
 * @brief Override a trait
 * @param me
 * @param className
 * @param traitContainerClassName
 * @param traitName
 */
#define overrideTraitIn_(me, className, traitContainerClassName, traitName)                                      \
    Trait_init(                                                                                                  \
        toTrait_(&to_(traitContainerClassName##Class, me)->m##traitName##Trait),                                 \
        offsetof(traitContainerClassName, m##traitName),                                                         \
        toInterface_(&to_(traitContainerClassName##Interface, className##Interface_())->m##traitName##Interface) \
    )

/**
 * @brief Initialize a trait
 * @param me
 * @param className
 * @param traitName
 */
#define initTraitIn_(me, className, traitName)                                                     \
    Trait_init(                                                                                    \
        toTrait_(&to_(className##Class, me)->m##traitName##Trait),                                 \
        offsetof(className, m##traitName),                                                         \
        toInterface_(&to_(className##Interface, className##Interface_())->m##traitName##Interface) \
    )

/**
 * @brief Cast to (Interface *)
 */
#define toInterface_(me) to_(Interface, (me))

/**
 * @brief Cast to (Trait *)
 * @param me
 */
#define toTrait_(me) to_(Trait, (me))

#endif // TRAIT_H
