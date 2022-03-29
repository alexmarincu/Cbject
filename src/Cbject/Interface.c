#include "Interface.h"

/**
 * @brief
 *
 * @param this_
 * @param object
 * @param operations
 */
Interface * Interface_init(
    Interface * const this_,
    Object * const object,
    Any const * const operations) {
    this_->object = object;
    this_->operations = operations;
}
