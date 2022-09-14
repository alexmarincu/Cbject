#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "Any.h"
/**
 * @brief Operations
 * @remark To be used with pointers to Operations types
 */
typedef Any Operations;
/**
 * @brief Cast to (Operations *)
 */
#define toOperations_(me) to_(Operations, (me))
#endif // OPERATIONS_H
