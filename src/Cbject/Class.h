#ifndef CLASS_H
#define CLASS_H
#include "Interface.h"

typedef struct Class Class;

/**
 * @brief Class
 */
struct Class {
    extend_(Interface);
    char const * name;
    size_t objectSize;
    Class const * superClass;
};

/**
 * @brief
 * @param me
 * @param name
 * @param objectSize
 * @param operations
 * @param superClass
 * @return Class*
 */
Class * Class_init(
    Class * const me,
    Operations const * const operations,
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
        toOperations_(className##Operations_()),  \
        #className,                               \
        sizeof(className),                        \
        toClass_(superClassName##Class_())        \
    )

/**
 * @brief Declare a class
 * @param name The class name
 */
#define class_(name)                                  \
    typedef struct name##Operations name##Operations; \
    typedef struct name##Class name##Class;           \
    typedef struct name name

/**
 * @brief Cast to (Class *)
 */
#define toClass_(me) to_(Class, (me))

#endif // CLASS_H
