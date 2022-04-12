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
GreetingOperations const * GreetingOperations_(void) {
    static GreetingOperations operations;

    doOnce_ {
        operations.xObjectOperations = *ObjectOperations_();
    }

    return &operations;
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
