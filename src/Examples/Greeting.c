#include "Greeting.h"
#include "cbject_Object.h"
#include <stdio.h>
struct Greeting {
    cbject_is(cbject_Object);
    char * text;
};
GreetingClass const * GreetingClass_getInstance(void) {
    static GreetingClass greetingClass;
    cbject_doOnce {
        cbject_setUpClass(Greeting, cbject_Object, &greetingClass);
    }
    return &greetingClass;
}
Greeting * Greeting_init(Greeting * const greeting, char * const text) {
    cbject_Object_init((cbject_Object *)greeting);
    greeting->text = text;
    return greeting;
}
void Greeting_print(Greeting * const greeting) {
    printf("%s\n", greeting->text);
}
