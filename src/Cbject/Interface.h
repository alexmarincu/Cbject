#ifndef INTERFACE_H
#define INTERFACE_H
#include "Operations.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/**
 * @brief Interface
 */
typedef struct {
    size_t offset;
    Operations const * operations;
} Interface;
/**
 * @brief Initialize a Interface
 * @param me Interface reference
 * @param offset Offset of included object inside parent object
 * @param operations Interface operations
 * @return Interface* Initialized type
 */
Interface * Interface_init(
    Interface * const me,
    size_t const offset,
    Operations const * const operations
);
/**
 * @brief Initialize a type
 * @param me Interface reference
 * @param offset Offset of included object inside parent object
 * @param operations Interface operations
 */
#define initInterface_(me, offset, operations) \
    Interface_init(toInterface_(me), offset, toOperations_(operations))
/**
 * @brief Override a type contained in a class
 * @param me
 * @param className
 * @param typeContainerClassName
 * @param typeName
 */
#define overrideIncludedInterface_(me, className, typeContainerClassName, typeName)                                   \
    Interface_init(                                                                                                   \
        toInterface_(&to_(typeContainerClassName##_Class, me)->n##typeName##_Interface),                              \
        offsetof(typeContainerClassName, n##typeName),                                                                \
        toOperations_(&to_(typeContainerClassName##_Operations, className##_Operations_())->n##typeName##_Operations) \
    )
/**
 * @brief Initialize a type contained in a class
 * @param me
 * @param className
 * @param typeName
 */
#define initIncludedInterface_(me, className, typeName)                                                  \
    Interface_init(                                                                                      \
        toInterface_(&to_(className##_Class, me)->n##typeName##_Interface),                              \
        offsetof(className, n##typeName),                                                                \
        toOperations_(&to_(className##_Operations, className##_Operations_())->n##typeName##_Operations) \
    )
/**
 * @brief Cast to (Interface *)
 */
#define toInterface_(me) to_(Interface, (me))
#endif // INTERFACE_H
