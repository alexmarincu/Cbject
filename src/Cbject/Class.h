#ifndef CLASS_H
#define CLASS_H
#include "Mixin.h"

typedef struct Class Class;

/**
 * @brief Class
 */
struct Class {
    super_(Mixin);
    char const * name;
    size_t objectSize;
    Class const * superClass;
};

/**
 * @brief
 * @param me
 * @param name
 * @param objectSize
 * @param interface
 * @param superClass
 * @return Class*
 */
Class * Class_init(
    Class * const me,
    Interface const * const interface,
    char const * const name,
    size_t const objectSize,
    Class const * const superClass
);

/**
 * @brief
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
 * @brief Declare a class
 * @param name The class name
 */
#define defineClass_(name)                          \
    typedef struct name##Interface name##Interface; \
    typedef struct name##Class name##Class;         \
    typedef struct name name

/**
 * @brief Cast to (Class *)
 */
#define toClass_(me) to_(Class, (me))

#endif // CLASS_H
