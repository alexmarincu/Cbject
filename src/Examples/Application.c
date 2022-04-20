#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>

/**
 * @brief Application
 */
struct Application {
    super_(Object);
    Circle * circle;
    Rectangle * rectangle;
};

static Object * deinit(Object * me);
static Object * copy(Object const * const me);
static void init(Application * const me);

ApplicationInterface const * ApplicationInterface_(void) {
    static ApplicationInterface interface;

    doOnce_ {
        inheritInterface_(&interface, Object);
        overrideOperation_(&interface, Object, deinit);
        overrideOperation_(&interface, Object, copy);
    }

    return &interface;
}

ApplicationClass const * ApplicationClass_(void) {
    static ApplicationClass cls;
    doOnce_ { initClass_(&cls, Application, Object); }
    return &cls;
}

Application * Application_(void) {
    static Application me;
    doOnce_ { init(&me); }
    return &me;
}

static void init(Application * const me) {
    initObject_(me, Application);
}

static void circleExample(Application * const me);
static void greetingExample(Application * const me);
static void rectangleExample(Application * const me);
static void polymorphismExample(Application * const me);

void Application_main(Application * const me) {
    greetingExample(me);
    circleExample(me);
    rectangleExample(me);
    polymorphismExample(me);
}

static void greetingExample(Application * const me) {
    // Allocate and initialize a Greeting object
    Greeting * greeting = init_(Greeting, alloc_(Greeting), "Hello Cbject!");

    // Call Greeting print function on the greeting object
    Greeting_print(greeting);

    // Free memory allocated for the Greeting object
    dealloc_(greeting);
}

static void circleExample(Application * const me) {
    // Allocate and initialize a Circle object
    me->circle = init_(Circle, alloc_(Circle), (Point){ 0, 1 }, 2);

    // Get circle radius
    uint32_t radius = me->circle->radius;

    // Set circle radius
    me->circle->radius = 3;

    // Get circle area through Shape mixin polymorphic call
    float area = Shape_area(mixinObjectOf_(Circle, Shape, me->circle));

    // Get circle shape origin
    Point origin = mixinObjectOf_(Circle, Shape, me->circle)->origin;

    // set circle shape origin
    mixinObjectOf_(Circle, Shape, me->circle)->origin = (Point){ 4, 5 };

    // Draw circle through Drawable mixin polymorphic call
    Drawable_draw(mixinObjectOf_(Circle, Drawable, me->circle));
}

static void rectangleExample(Application * const me) {
    // Allocate and initialize a Rectangle object
    me->rectangle = init_(Rectangle, alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);

    // Get rectangle width and height
    uint32_t width = Rectangle_getWidth(me->rectangle);
    uint32_t height = Rectangle_getHeight(me->rectangle);

    // Set rectangle with and height
    Rectangle_setWidth(me->rectangle, 4);
    Rectangle_setHeight(me->rectangle, 5);

    // Get rectangle area through Shape mixin polymorphic call
    float area = Shape_area(mixinObjectOf_(Rectangle, Shape, me->rectangle));

    // Get rectangle shape origin
    Point origin = mixinObjectOf_(Rectangle, Shape, me->rectangle)->origin;

    // set rectangle shape origin
    mixinObjectOf_(Rectangle, Shape, me->rectangle)->origin = (Point){ 6, 7 };

    // Draw rectangle through Drawable mixin polymorphic call
    Drawable_draw(mixinObjectOf_(Rectangle, Drawable, me->rectangle));
}

static void polymorphismExample(Application * const me) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        mixinObjectOf_(Circle, Shape, me->circle),
        mixinObjectOf_(Rectangle, Shape, me->rectangle),
    };

    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < lengthOf_(shapes); i++) {
        // Get area through Shape mixin polymorphic call
        float area = Shape_area(shapes[i]);

        // Get object from mixin
        Object * object = objectOf_(shapes[i]);

        // Get size of object
        size_t objectSize = objectSizeOf_(object);

        // Get hash code of object
        uint64_t hashCode = hashCode_(object);

        // Get className of object
        char const * className = classNameOf_(me->circle);

        // Check class of object
        if (isOfClass_(Circle, object)) {
            // Get circle radius
            uint32_t radius = to_(Circle, object)->radius;
        } else if (isOfClass_(Rectangle, object)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth(to_(Rectangle, object));
            uint32_t height = Rectangle_getHeight(to_(Rectangle, object));
        }
    }
}

static Object * deinit(Object * const me) {
    Application * Me = to_(Application, me);
    dealloc_(Me->rectangle);
    dealloc_(Me->circle);
    return superCall_(Object, deinit, me);
}

/**
 * Override Object_copy to assert if used. Cannot copy a singleton.
 */
static Object * copy(Object const * const me) {
    assert_(false);
    return toObject_(me);
}
