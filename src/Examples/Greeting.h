#ifndef GREETING_H
#define GREETING_H
#include "Cbject.h"

class_(Greeting);

/**
 * @brief GreetingOperations
 */
struct GreetingOperations {
    extend_(ObjectOperations);
};

/**
 * @brief GreetingClass
 */
struct GreetingClass {
    extend_(ObjectClass);
};

/**
 * @brief Get GreetingOperations
 * @return GreetingOperations const*
 */
GreetingOperations const * GreetingOperations_(void);

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
