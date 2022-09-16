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
 * @brief Override a type contained in a class
 * @param me
 * @param className
 * @param typeContainerClassName
 * @param typeName
 */
#define overrideInterface_(me, className, typeContainerClassName, typeName)                                         \
    Interface_init(                                                                                                 \
        (Interface *)&((typeContainerClassName##_Class *)(me))->i##typeName##_Interface,                            \
        offsetof(typeContainerClassName, i##typeName),                                                              \
        (Operations *)&((typeContainerClassName##_Operations *)className##_Operations_())->i##typeName##_Operations \
    )
/**
 * @brief Initialize a type contained in a class
 * @param me
 * @param className
 * @param typeName
 */
#define initInterface_(me, className, typeName)                                                        \
    Interface_init(                                                                                    \
        (Interface *)&((className##_Class *)(me))->i##typeName##_Interface,                            \
        offsetof(className, i##typeName),                                                              \
        (Operations *)&((className##_Operations *)className##_Operations_())->i##typeName##_Operations \
    )
#endif // INTERFACE_H
