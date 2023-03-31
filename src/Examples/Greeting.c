// tag::usageImplementCustomClass[]
#include "Greeting.h"
#include <stdio.h>

#define cbject_Class (Greeting, cbject_Object)

struct Greeting {
    cbject_Object super;
    char * text;
};

cbject_noPool;

Greeting * Greeting_init(Greeting * const self, char * const text) {
    cbject_init(self);
    self->text = text;
    return self;
}

void Greeting_print(Greeting * const self) {
    printf("%s\n", self->text);
}

Greeting_Class * Greeting_Class_instance(void) {
    static Greeting_Class self;
    cbject_doOnce {
        cbject_Class_setup(&self);
    }
    return &self;
}

#undef cbject_Class
// end::usageImplementCustomClass[]