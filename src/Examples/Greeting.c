#include "Greeting.h"
#include <stdio.h>
/**
 * @brief Greeting
 */
struct Greeting {
    extends_(Object);
    char * text;
};
Greeting_Operations const * Greeting_Operations_(void) {
    static Greeting_Operations operations;
    doOnce_ {
        inheritOperations_(&operations, Object);
    }
    return &operations;
}
Greeting_Class const * Greeting_Class_(void) {
    static Greeting_Class cls;
    doOnce_ {
        initClass_(&cls, Greeting, Object);
    }
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
