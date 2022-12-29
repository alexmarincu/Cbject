#include "Greeting.h"
#include <stdio.h>
struct Greeting {
    x_is(x_Object);
    char * text;
};
GreetingClass const * GreetingClass_instance(void) {
    static GreetingClass greetingClass;
    x_doOnce {
        x_setUpClass(Greeting, x_Object, &greetingClass);
    }
    return &greetingClass;
}
Greeting * Greeting_init(Greeting * const greeting, char * const text) {
    x_setUpObject(Greeting, x_Object, greeting);
    greeting->text = text;
    return greeting;
}
void Greeting_print(Greeting * const greeting) {
    printf("%s\n", greeting->text);
}
