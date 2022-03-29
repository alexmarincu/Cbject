#include "Class.h"

/**
 * @brief
 *
 * @param this_
 * @param name
 * @param objectSize
 * @param operations
 * @param superClass
 * @return Class*
 */
Class * Class_init(
    Class * const this_,
    char const * const name,
    size_t const objectSize,
    Any const * const operations,
    Class const * const superClass) {
    this_->name = name;
    this_->objectSize = objectSize;
    this_->operations = operations;
    this_->superClass = superClass;
    return this_;
}