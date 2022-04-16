#ifndef INTERFACE_H
#define INTERFACE_H
#include "Type.h"

/**
 * @brief Operations
 * @remark To be used with pointers to Operations types
 */
typedef void Operations;

typedef struct Interface Interface;

/**
 * @brief Interface
 */
struct Interface {
    extend_(Type);
    Operations const * operations;
};

/**
 * @brief
 * @param me
 * @param offset
 * @param operations
 * @return Interface*
 */
Interface * Interface_init(
    Interface * const me,
    size_t const offset,
    Operations const * const operations
);

/**
 * @brief Initialize an interface
 * @param me
 * @param offset
 * @param operations
 */
#define initInterface_(me, offset, operations) \
    Interface_init(toInterface_(me), offset, toOperations_(operations))

/**
 * @brief Declare an interface
 * @param name The interface name
 */
#define interface_(name)                              \
    typedef struct name##Operations name##Operations; \
    typedef struct name##Interface name##Interface;   \
    typedef struct name name

/**
 * @brief Cast to (Operations *)
 */
#define toOperations_(me) to_(Operations, (me))

/**
 * @brief Cast to (Interface *)
 * @param me
 */
#define toInterface_(me) to_(Interface, (me))

#endif // INTERFACE_H
