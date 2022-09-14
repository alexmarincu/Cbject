#ifndef INTERFACE_H
#define INTERFACE_H
#include "Type.h"
/**
 * @brief Interface
 */
typedef struct {
    extends_(Type);
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
    size_t offset,
    Operations const * operations
);
/**
 * @brief Initialize a type
 * @param me Interface reference
 * @param offset Offset of included object inside parent object
 * @param operations Interface operations
 */
#define initInterface_(me, offset, operations) \
    Interface_init((Interface *)(me), offset, (Operations *)(operations))
/**
 * @brief Override a type contained in a class
 * @param me
 * @param className
 * @param typeContainerClassName
 * @param typeName
 */
#define overrideIncludedInterface_(me, className, typeContainerClassName, typeName)                                 \
    Interface_init(                                                                                                 \
        (Interface *)&((typeContainerClassName##_Class *)(me))->n##typeName##_Interface,                            \
        offsetof(typeContainerClassName, n##typeName),                                                              \
        (Operations *)&((typeContainerClassName##_Operations *)className##_Operations_())->n##typeName##_Operations \
    )
/**
 * @brief Initialize a type contained in a class
 * @param me
 * @param className
 * @param typeName
 */
#define initIncludedInterface_(me, className, typeName)                                                \
    Interface_init(                                                                                    \
        (Interface *)&((className##_Class *)(me))->n##typeName##_Interface,                            \
        offsetof(className, n##typeName),                                                              \
        (Operations *)&((className##_Operations *)className##_Operations_())->n##typeName##_Operations \
    )
#endif // INTERFACE_H
