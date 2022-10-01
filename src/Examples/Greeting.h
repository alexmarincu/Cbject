#ifndef GREETING_H
#define GREETING_H
#include "../Cbject/Cbject.h"
typedef struct Greeting_Class Greeting_Class;
typedef struct Greeting Greeting;
struct Greeting_Class {
    extends_(Object_Class);
};
Greeting_Class const * Greeting_Class_(void);
Greeting * Greeting_init(Greeting * me, char * const text);
void Greeting_print(Greeting * const me);
#endif // GREETING_H
