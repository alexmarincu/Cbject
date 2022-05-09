#ifndef GREETING_H
#define GREETING_H
#include "../Cbject/Cbject.h"

/**
 * @brief GreetingClass
 */
typedef struct {
    extends_(ObjectClass);
} GreetingClass;

typedef struct Greeting Greeting;

/**
 * @brief GreetingInterface
 */
typedef struct {
    extends_(ObjectInterface);
} GreetingInterface;

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
