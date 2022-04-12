#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>

/**
 *
 */
struct Application {
    extends_(Object);
    Circle * circle;
    Rectangle * rectangle;
};

static void circleExample(Application * const me);
static void greetingExample(Application * const me);
static void rectangleExample(Application * const me);
static void polymorphismExample(Application * const me);

/**
 *
 */
void Application_main(Application * const me) {
    greetingExample(me);
    circleExample(me);
    rectangleExample(me);
    polymorphismExample(me);
}

/**
 *
 */
static void greetingExample(Application * const me) {
    // Allocate and initialize a Greeting object
    Greeting * greeting = init_(Greeting, new_(Greeting), "Hello Cbject!");

    // Call Greeting print function on the greeting object
    Greeting_print(greeting);

    // Free memory allocated for the Greeting object
    delete_(greeting);
}

/**
 *
 */
static void circleExample(Application * const me) {
    // Allocate and initialize a Circle object
    me->circle = init_(Circle, new_(Circle), (Point){ 0, 1 }, 2);

    // Get circle radius
    uint32_t radius = me->circle->radius;

    // Set circle radius
    me->circle->radius = 3;

    // Get circle area through Shape interface polymorphic call
    float area = Shape_area(&me->circle->iShape);

    // Get circle shape origin
    Point origin = me->circle->iShape.origin;

    // set circle shape origin
    me->circle->iShape.origin = (Point){ 4, 5 };

    // Draw circle through Drawable interface polymorphic call
    Drawable_draw(&me->circle->iDrawable);
}

/**
 *
 */
static void rectangleExample(Application * const me) {
    // Allocate and initialize a Rectangle object
    me->rectangle = init_(Rectangle, new_(Rectangle), (Point){ 0, 1 }, 2, 3);

    // Get rectangle width and height
    uint32_t width = Rectangle_getWidth(me->rectangle);
    uint32_t height = Rectangle_getHeight(me->rectangle);

    // Set rectangle with and height
    Rectangle_setWidth(me->rectangle, 4);
    Rectangle_setHeight(me->rectangle, 5);

    // Get rectangle area through Shape interface polymorphic call
    float area = Shape_area(Rectangle_getShape(me->rectangle));

    // Get rectangle shape origin
    Point origin = Rectangle_getShape(me->rectangle)->origin;

    // set rectangle shape origin
    Rectangle_getShape(me->rectangle)->origin = (Point){ 6, 7 };

    // Draw rectangle through Drawable interface polymorphic call
    Drawable_draw(Rectangle_getDrawable(me->rectangle));
}

/**
 *
 */
static void polymorphismExample(Application * const me) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        &me->circle->iShape,
        Rectangle_getShape(me->rectangle),
    };

    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < lengthOf_(shapes); i++) {
        // Get area through Shape interface polymorphic call
        float area = Shape_area(shapes[i]);

        // Get object from interface
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
            uint32_t radius = cast_(Circle, object)->radius;
        } else if (isOfClass_(Rectangle, object)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth(cast_(Rectangle, object));
            uint32_t height = Rectangle_getHeight(cast_(Rectangle, object));
        }
    }
}

/**
 *
 */
Application * init(Application * const me) {
    initObject_(me, Application);
}

/**
 *
 */
static void finalize(Object * const me) {
    Application * Me = cast_(Application, me);
    delete_(Me->rectangle);
    delete_(Me->circle);
}

/**
 * Override Object_copy to return the same singleton object instead of a copy
 */
static Object * copy(Object const * const me) {
    Application * Me = cast_(Application, me);
    return toObject_(Me);
}

/**
 *
 */
Application * Application_(void) {
    static Application me;

    doOnce_ {
        init(&me);
    }

    return &me;
}

/**
 *
 */
ApplicationOps const * ApplicationOps_(void) {
    static ApplicationOps ops;

    doOnce_ {
        ops.objectOps = *ObjectOps_();
        ops.objectOps.finalize = finalize;
        ops.objectOps.copy = copy;
    }

    return &ops;
}

/**
 *
 */
Class const * ApplicationClass_(void) {
    static Class cls;

    doOnce_ {
        initClass_(&cls, Application, Object);
    }

    return &cls;
}