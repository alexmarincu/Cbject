#include "Greeting.h"
#include <stdio.h>
struct Greeting {
    extends_(Object);
    char * text;
};
GreetingClass const * GreetingClass_instance(void) {
    static GreetingClass class;
    doOnce_ {
        setUpClass_(Greeting, Object, &class);
    }
    return &class;
}
Greeting * Greeting_init(Greeting * greeting, char * const text) {
    setUpObject_(Greeting, Object, greeting);
    greeting->text = text;
    return greeting;
}
void Greeting_print(Greeting * const greeting) {
    printf("%s\n", greeting->text);
}
