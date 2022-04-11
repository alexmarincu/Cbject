#include "Greeting.h"
#include <stdio.h>

/**
 * @brief
 */
struct Greeting {
    extends_(Object);
    char * text;
};

/**
 * @brief
 * @param me
 */
void Greeting_print(Greeting * const me) {
    printf("%s\n", me->text);
}

/**
 * @brief
 * @param me
 * @param text
 * @return Greeting*
 */
Greeting * Greeting_init(Greeting * me, char * const text) {
    initObject_(me, Greeting);
    me->text = text;
    return me;
}

/**
 * @brief
 * @return GreetingOperations const*
 */
GreetingOperations const * GreetingOperations_(void) {
    static GreetingOperations operations;

    doOnce_ {
        operations.xObjectOperations = *ObjectOperations_();
    }

    return &operations;
}

/**
 * @brief
 * @return Class const*
 */
Class const * GreetingClass_(void) {
    static Class class_;

    doOnce_ {
        initClass_(&class_, Greeting, Object);
    }

    return &class_;
}
