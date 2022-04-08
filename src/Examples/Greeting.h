#ifndef GREETING_H
#define GREETING_H
#include "Cbject.h"

/**
 * @brief
 */
typedef struct Greeting Greeting;

/**
 * @brief
 *
 * @param me
 * @param text
 * @return Greeting*
 */
Greeting * Greeting_init(Greeting * me, char * const text);

/**
 * @brief
 *
 * @param me
 */
void Greeting_print(Greeting * const me);

/**
 * @brief Contains Greeting's operations (aka virtual functions)
 */
typedef struct GreetingOperations {
    extends_(ObjectOperations);
} GreetingOperations;

/**
 * @brief
 *
 * @return GreetingOperations const*
 */
GreetingOperations const * GreetingOperations_(void);

/**
 * @brief
 *
 * @return Class const*
 */
Class const * GreetingClass_(void);

#endif // GREETING_H
