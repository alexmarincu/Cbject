#ifndef CLASS_H
#define CLASS_H
#include "Type.h"
/**
 * @brief Class
 */
typedef struct Class_ Class;
struct Class_ {
    extends_(Type);
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
        (Class *)(me),                            \
        (Operations *)className##_Operations_(),  \
        #className,                               \
        sizeof(className),                        \
        (Class *)superClassName##_Class_()        \
    )
#endif // CLASS_H
