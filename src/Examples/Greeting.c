#include "Greeting.h"
#include <stdio.h>

/**
 * @brief Greeting
 */
struct Greeting {
    super_(Object);
    char * text;
};

GreetingInterface const * GreetingInterface_(void) {
    static GreetingInterface interface;

    doOnce_ {
        inheritInterface_(&interface, Object);
    }

    return &interface;
}

GreetingClass const * GreetingClass_(void) {
    static GreetingClass cls;
    doOnce_ { initClass_(&cls, Greeting, Object); }
    return &cls;
}

Greeting * Greeting_init(Greeting * me, char * const text) {
    initObject_(me, Greeting);
    me->text = text;
    return me;
}

void Greeting_print(Greeting * const me) {
    printf("%s\n", me->text);
}
