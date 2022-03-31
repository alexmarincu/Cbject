#include "Greeting.h"
#include <stdio.h>

/**
 * @brief
 *
 */
struct Greeting {
    extends_(Object);
    char * text;
};

/**
 * @brief
 *
 * @param this_
 */
void Greeting_print(Greeting * const this_) {
    printf("%s\n", this_->text);
}

/**
 * @brief
 *
 * @param this_
 * @param text
 * @return Greeting*
 */
Greeting * Greeting_init(Greeting * this_, char * const text) {
    initObject_(this_, GreetingClass_());
    this_->text = text;
    return this_;
}

/**
 * @brief
 *
 * @return GreetingOperations const*
 */
GreetingOperations const * GreetingOperations_(void) {
    static GreetingOperations operations;
    static bool isInitialized = false;

    if (!isInitialized) {
        operations._xObjectOperations = *ObjectOperations_();
        isInitialized = true;
    }

    return &operations;
}

/**
 * @brief
 *
 * @return Class const*
 */
Class const * GreetingClass_(void) {
    static Class class_;
    static bool isInitialized = false;

    if (!isInitialized) {
        initClass_(&class_, Greeting, ObjectClass_());
        isInitialized = true;
    }

    return &class_;
}
