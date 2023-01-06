#ifndef GREETING_H
#define GREETING_H
#include "../cbject/cbject.h"
cbject_typedefClass(Greeting);
struct GreetingClass {
    cbject_is(cbject_ObjectClass);
};
GreetingClass const * GreetingClass_getInstance(void);
Greeting * Greeting_init(Greeting * const greeting, char * const text);
void Greeting_print(Greeting * const greeting);
#endif // GREETING_H
