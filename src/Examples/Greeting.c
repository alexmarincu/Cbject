#include "Greeting.h"
#include <stdio.h>

/**
 * @brief Greeting
 */
struct Greeting {
    extend_(Object);
    char * text;
};

GreetingOperations const * GreetingOperations_(void) {
    static GreetingOperations operations;

    doOnce_ {
        inheritOperationsOf_(Object, &operations);
    }

    return &operations;
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
