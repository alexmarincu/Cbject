#include "Greeting.h"
#include <stdio.h>
struct Greeting {
    extends_(Object);
    char * text;
};
GreetingClass const * GreetingClass_instance(void) {
    static GreetingClass class;
    return &class;
}
void GreetingClass_init(void) {
    setUpClass_(Greeting, Object);
}
Greeting * Greeting_init(Greeting * greeting, char * const text) {
    setUpObject_(Greeting, Object, greeting);
    greeting->text = text;
    return greeting;
}
void Greeting_print(Greeting * const greeting) {
    printf("%s\n", greeting->text);
}
