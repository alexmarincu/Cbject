#ifndef CLASS_H
#define CLASS_H
#include "Trait.h"

/**
 * @brief Class
 */
typedef struct Class_ Class;
struct Class_ {
    extends_(Trait);
    char const * name;
    size_t objectSize;
    Class const * superClass;
};

/**
 * @brief Initialize a class
 * @param me Class reference
 * @param name String containing the class name
 * @param objectSize Object instance size
 * @param interface Class interface
 * @param superClass Parent class
 * @return Class* Initialized class
 */
Class * Class_init(
    Class * const me,
    Interface const * const interface,
    char const * const name,
    size_t const objectSize,
    Class const * const superClass
);

/**
 * @brief Initialize a class
 * @param me Class reference
 * @param className Class name
 * @param superClassName Parent class name
 */
#define initClass_(me, className, superClassName) \
    Class_init(                                   \
        toClass_(me),                             \
        toInterface_(className##Interface_()),    \
        #className,                               \
        sizeof(className),                        \
        toClass_(superClassName##Class_())        \
    )

/**
 * @brief Cast to (Class *)
 */
#define toClass_(me) to_(Class, (me))

#endif // CLASS_H
