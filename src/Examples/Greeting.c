#include "Greeting.h"
#include <stdio.h>

/**
 * @brief Greeting
 */
struct Greeting {
    extend_(Object);
    char * text;
};

GreetingOps const * GreetingOps_(void) {
    static GreetingOps ops;

    doOnce_ {
        ops.xObjectOps = *ObjectOps_();
    }

    return &ops;
}

GreetingClass const * GreetingClass_(void) {
    static GreetingClass cls;

    doOnce_ {
        initClass_(&cls, Greeting, ObjectClass_());
    }

    return &cls;
}

Greeting * Greeting_init(Greeting * me, char * const text) {
    initObject_(me, GreetingClass_());
    me->text = text;
    return me;
}

void Greeting_print(Greeting * const me) {
    printf("%s\n", me->text);
}
