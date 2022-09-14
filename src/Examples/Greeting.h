#ifndef GREETING_H
#define GREETING_H
#include "../Cbject/Cbject.h"
/**
 * @brief Greeting_Class
 */
typedef struct {
    extends_(Object_Class);
} Greeting_Class;
typedef struct Greeting Greeting;
/**
 * @brief Greeting_Operations
 */
typedef struct {
    extends_(Object_Operations);
} Greeting_Operations;
/**
 * @brief Get Greeting_Operations
 * @return Greeting_Operations const*
 */
Greeting_Operations const * Greeting_Operations_(void);
/**
 * @brief Get Greeting_Class
 * @return Greeting_Class const*
 */
Greeting_Class const * Greeting_Class_(void);
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
