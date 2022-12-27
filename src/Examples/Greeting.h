#ifndef GREETING_H
#define GREETING_H
#include "../Cbject/Cbject.h"
x_typedefClass(Greeting);
struct GreetingClass {
    x_extends(x_ObjectClass);
};
GreetingClass const * GreetingClass_instance(void);
Greeting * Greeting_init(Greeting * const greeting, char * const text);
void Greeting_print(Greeting * const greeting);
#endif // GREETING_H
