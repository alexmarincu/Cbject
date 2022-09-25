#include "Greeting.h"
#include <stdio.h>
/**
 * @brief Greeting
 */
struct Greeting {
    extends_(Object);
    char * text;
};
Greeting_Class const * Greeting_Class_(void) {
    static Greeting_Class class;
    doOnce_ {
        setUpClass_(Greeting, Object, &class);
    }
    return &class;
}
Greeting * Greeting_init(Greeting * me, char * const text) {
    setUpObject_(Greeting, Object, me);
    me->text = text;
    return me;
}
void Greeting_print(Greeting * const me) {
    printf("%s\n", me->text);
}
