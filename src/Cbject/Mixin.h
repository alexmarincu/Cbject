#ifndef MIXIN_H
#define MIXIN_H
#include "Type.h"

/**
 * @brief Interface
 * @remark To be used with pointers to Interface types
 */
typedef void Interface;

/**
 * @brief Mixin
 */
typedef struct {
    super_(Type);
    Interface const * interface;
} Mixin;

/**
 * @brief
 * @param me
 * @param offset
 * @param interface
 * @return Mixin*
 */
Mixin * Mixin_init(
    Mixin * const me,
    size_t const offset,
    Interface const * const interface
);

/**
 * @brief Initialize the mixin of a class
 * @param me
 * @param offset
 * @param interface
 */
#define initClassMixin_(me, interface) \
    Mixin_init(toMixin_(me), 0, toInterface_(interface))

/**
 * @brief Override a mixin
 * @param me
 * @param className
 * @param mixinClassName
 * @param mixinName
 */
#define overrideMixin_(me, className, mixinClassName, mixinName)                                        \
    Mixin_init(                                                                                         \
        toMixin_(&to_(mixinClassName##Class, me)->m##mixinName##Mixin),                                 \
        offsetof(mixinClassName, m##mixinName),                                                         \
        toInterface_(&to_(mixinClassName##Interface, className##Interface_())->m##mixinName##Interface) \
    )

/**
 * @brief Initialize a mixin
 * @param me
 * @param className
 * @param mixinName
 */
#define initMixin_(me, className, mixinName) \
    overrideMixin_(me, className, className, mixinName)

/**
 * @brief Cast to (Interface *)
 */
#define toInterface_(me) to_(Interface, (me))

/**
 * @brief Cast to (Mixin *)
 * @param me
 */
#define toMixin_(me) to_(Mixin, (me))

#endif // MIXIN_H
