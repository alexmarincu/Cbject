#ifndef GREETING_H
#define GREETING_H
#include "../Cbject/Cbject.h"
typedefClass_(Greeting);
struct GreetingClass {
    extends_(ObjectClass);
};
GreetingClass const * GreetingClass_instance(void);
Greeting * Greeting_init(Greeting * greeting, char * const text);
void Greeting_print(Greeting * const greeting);
#endif // GREETING_H
