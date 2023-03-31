#ifndef GREETING_H
#define GREETING_H
// tag::usageDeclareCustomClass[]
#include "../cbject/cbject.h"

typedef struct Greeting Greeting;
typedef struct Greeting_Class Greeting_Class;

struct Greeting_Class {
    cbject_Object_Class super;
};

Greeting * Greeting_init(Greeting * const self, char * const text);
void Greeting_print(Greeting * const self);
Greeting_Class * Greeting_Class_instance(void);
// end::usageDeclareCustomClass[]

#endif // GREETING_H
