#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>
/**
 * @brief Application
 */
struct Application {
    extends_(Object);
    Circle * circle;
    Rectangle * rectangle;
};
static Object * teardown(Object * me);
static Object * copy(Object const * const me);
static void init(Application * const me);
Application * Application_(void) {
    static Application me;
    doOnce_ {
        init(&me);
    }
    return &me;
}
Application_Class const * Application_Class_(void) {
    static Application_Class class;
    doOnce_ {
        setUpClass_(Application, Object, &class);
        overrideObjectMethod_(Object, &class, teardown);
        overrideObjectMethod_(Object, &class, copy);
    }
    return &class;
}
static void init(Application * const me) {
    setUpObject_(Application, Object, me);
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
    ignore_(me);
    // Allocate and initialize a Greeting object
    Greeting * greeting = initObject_(Greeting, alloc_(Greeting), "Hello Cbject!");
    // Call Greeting print function on the greeting object
    Greeting_print(greeting);
    // Free memory allocated for the Greeting object
    dealloc_(greeting);
}
static void circleExample(Application * const me) {
    // Allocate and initialize a Circle object
    me->circle = initObject_(Circle, alloc_(Circle), (Point){ 0, 1 }, 2);
    // Get circle radius
    uint32_t radius = me->circle->radius;
    ignore_(radius);
    // Set circle radius
    me->circle->radius = 3;
    // Get circle area through Shape object polymorphic call
    float area = Shape_area(traitOf_(me->circle, Circle, Shape));
    ignore_(area);
    // Get circle shape origin
    Point origin = traitOf_(me->circle, Circle, Shape)->origin;
    ignore_(origin);
    // set circle shape origin
    traitOf_(me->circle, Circle, Shape)->origin = (Point){ 4, 5 };
    // Draw circle through Drawable object polymorphic call
    Drawable_draw(traitOf_(me->circle, Circle, Drawable));
}
static void rectangleExample(Application * const me) {
    // Allocate and initialize a Rectangle object
    me->rectangle = initObject_(Rectangle, alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);
    // Get rectangle width and height
    uint32_t width = Rectangle_getWidth(me->rectangle);
    ignore_(width);
    uint32_t height = Rectangle_getHeight(me->rectangle);
    ignore_(height);
    // Set rectangle with and height
    Rectangle_setWidth(me->rectangle, 4);
    Rectangle_setHeight(me->rectangle, 5);
    // Get rectangle area through Shape object polymorphic call
    float area = Shape_area(traitOf_(me->rectangle, Rectangle, Shape));
    ignore_(area);
    // Get rectangle shape origin
    Point origin = traitOf_(me->rectangle, Rectangle, Shape)->origin;
    ignore_(origin);
    // set rectangle shape origin
    traitOf_(me->rectangle, Rectangle, Shape)->origin = (Point){ 6, 7 };
    // Draw rectangle through Drawable object polymorphic call
    Drawable_draw(traitOf_(me->rectangle, Rectangle, Drawable));
}
static void polymorphismExample(Application * const me) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        traitOf_(me->circle, Circle, Shape),
        traitOf_(me->rectangle, Rectangle, Shape),
    };
    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < lengthOf_(shapes); i++) {
        // Get area through Shape object polymorphic call
        float area = Shape_area(shapes[i]);
        ignore_(area);
        // Get parent object from included object
        Object * object = objectOf_(shapes[i]);
        // Get size of object
        size_t objectSize = objectSizeOf_(object);
        ignore_(objectSize);
        // Get hash code of object
        uint64_t hashCode = hashCode_(object);
        ignore_(hashCode);
        // Check class of object
        if (isOfClass_(object, Circle)) {
            // Get circle radius
            uint32_t radius = to_(Circle, object)->radius;
            ignore_(radius);
        } else if (isOfClass_(object, Rectangle)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth(to_(Rectangle, object));
            ignore_(width);
            uint32_t height = Rectangle_getHeight(to_(Rectangle, object));
            ignore_(height);
        }
    }
}
static Object * teardown(Object * const me) {
    Application * Me = to_(Application, me);
    dealloc_(Me->rectangle);
    dealloc_(Me->circle);
    return superObjectMethodCall_(Object, teardown, me);
}
/**
 * Override Object_copy to assert if used. Cannot copy a singleton.
 */
static Object * copy(Object const * const me) {
    assert_(false);
    return to_(Object, me);
}
