#ifndef CLASS_H
#define CLASS_H
#include "Interface.h"
/**
 * @brief Class
 */
typedef struct Class_ Class;
struct Class_ {
    extends_(Interface);
    char const * name;
    size_t objectSize;
    Class const * superClass;
};
/**
 * @brief Initialize a class
 * @param me Class reference
 * @param name String containing the class name
 * @param objectSize Object instance size
 * @param operations Class operations
 * @param superClass Parent class
 * @return Class* Initialized class
 */
Class * Class_init(
    Class * const me,
    Operations const * const operations,
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
        toOperations_(className##_Operations_()), \
        #className,                               \
        sizeof(className),                        \
        toClass_(superClassName##_Class_())       \
    )
/**
 * @brief Cast to (Class *)
 */
#define toClass_(me) to_(Class, (me))
#endif // CLASS_H
