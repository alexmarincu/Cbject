#ifndef GREETING_H
#define GREETING_H
#include "Cbject.h"

defClass_(Greeting);

/**
 * @brief GreetingInterface
 */
struct GreetingInterface {
    super_(ObjectInterface);
};

/**
 * @brief GreetingClass
 */
struct GreetingClass {
    super_(ObjectClass);
};

/**
 * @brief Get GreetingInterface
 * @return GreetingInterface const*
 */
GreetingInterface const * GreetingInterface_(void);

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
