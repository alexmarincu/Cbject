#ifndef GREETING_H
#define GREETING_H
#include "Cbject.h"

class_(Greeting);

/**
 * @brief GreetingOps
 */
struct GreetingOps {
    extend_(ObjectOps);
};

/**
 * @brief GreetingClass
 */
struct GreetingClass {
    extend_(ObjectClass);
};

/**
 * @brief Get GreetingOps
 * @return GreetingOps const*
 */
GreetingOps const * GreetingOps_(void);

/**
 * @brief Get GreetingClass
 * @return GreetingClass const*
 */
GreetingClass const * GreetingClass_(void);

/**
 * @brief
 * @param me
 * @param text
 * @return Greeting*
 */
Greeting * Greeting_init(Greeting * me, char * const text);

/**
 * @brief
 * @param me
 */
void Greeting_print(Greeting * const me);

#endif // GREETING_H
