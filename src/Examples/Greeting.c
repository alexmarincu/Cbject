#include "Greeting.h"
#include <stdio.h>

#define cbject_Class (Greeting, cbject_Object)

struct Greeting {
    cbject_Object object;
    char * text;
};

cbject_utils_allocPool(0);

Greeting * Greeting_init(Greeting * const greeting, char * const text) {
    cbject_utils_init(greeting);
    greeting->text = text;
    return greeting;
}

void Greeting_print(Greeting * const greeting) {
    printf("%s\n", greeting->text);
}

GreetingClass * GreetingClass_instance(void) {
    static GreetingClass klass;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&klass);
    }
    return &klass;
}

#undef cbject_Class
