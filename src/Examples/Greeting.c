#include "Greeting.h"
#include <stdio.h>

/**
 *
 */
struct Greeting {
    extends_(Object);
    char * text;
};

/**
 *
 */
void Greeting_print(Greeting * const me) {
    printf("%s\n", me->text);
}

/**
 *
 */
Greeting * Greeting_init(Greeting * me, char * const text) {
    initObject_(me, Greeting);
    me->text = text;
    return me;
}

/**
 *
 */
GreetingOps const * GreetingOps_(void) {
    static GreetingOps ops;

    doOnce_ {
        ops.xObjectOps = *ObjectOps_();
    }

    return &ops;
}

/**
 *
 */
Class const * GreetingClass_(void) {
    static Class cls;

    doOnce_ {
        initClass_(&cls, Greeting, Object);
    }

    return &cls;
}
