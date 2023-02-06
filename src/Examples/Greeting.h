#ifndef GREETING_H
#define GREETING_H
#include "../cbject/cbject.h"

typedef struct Greeting Greeting;
typedef struct GreetingClass GreetingClass;

struct GreetingClass {
    cbject_ObjectClass objectClass;
};

Greeting * Greeting_init(Greeting * const greeting, char * const text);
void Greeting_print(Greeting * const greeting);
GreetingClass const * GreetingClass_instance(void);

#endif // GREETING_H
