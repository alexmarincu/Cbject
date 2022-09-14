#ifndef ANY_H
#define ANY_H
#include "Utils.h"
/**
 * @brief Any
 * @remark To be used with pointers to anything
 */
typedef void Any;
/**
 * @brief Cast to (Any *)
 */
#define toAny_(me) to_(Any, (me))
#endif // ANY_H
