#ifndef GREETING_H
#define GREETING_H
#include "../cbject/cbject.h"

typedef struct Greeting Greeting;
typedef struct GreetingClass GreetingClass;

struct GreetingClass {
    cbject_ObjectClass super;
};

Greeting * Greeting_init(Greeting * const self, char * const text);
void Greeting_print(Greeting * const self);
GreetingClass * GreetingClass_instance(void);

#endif // GREETING_H
