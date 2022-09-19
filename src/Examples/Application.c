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
static Object * deinit(Object * me);
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
        initClass_(&class, Application, Object);
    }
    return &class;
}
Application_Operations const * Application_Operations_(void) {
    static Application_Operations operations;
    doOnce_ {
        inheritOperations_(&operations, Object);
        overrideOperation_(&operations, Object, deinit);
        overrideOperation_(&operations, Object, copy);
    }
    return &operations;
}
static void init(Application * const me) {
    Object_init((Object *)me, (Object_Interface *)Application_Class_());
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
    (void)me;
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
    (void)radius;
    // Set circle radius
    me->circle->radius = 3;
    // Get circle area through Shape object polymorphic call
    float area = Shape_area(iObjectOf_(me->circle, Circle, Shape));
    (void)area;
    // Get circle shape origin
    Point origin = iObjectOf_(me->circle, Circle, Shape)->origin;
    (void)origin;
    // set circle shape origin
    iObjectOf_(me->circle, Circle, Shape)->origin = (Point){ 4, 5 };
    // Draw circle through Drawable object polymorphic call
    Drawable_draw(iObjectOf_(me->circle, Circle, Drawable));
}
static void rectangleExample(Application * const me) {
    // Allocate and initialize a Rectangle object
    me->rectangle = init_(Rectangle, alloc_(Rectangle), (Point){ 0, 1 }, 2, 3);
    // Get rectangle width and height
    uint32_t width = Rectangle_getWidth(me->rectangle);
    (void)width;
    uint32_t height = Rectangle_getHeight(me->rectangle);
    (void)height;
    // Set rectangle with and height
    Rectangle_setWidth(me->rectangle, 4);
    Rectangle_setHeight(me->rectangle, 5);
    // Get rectangle area through Shape object polymorphic call
    float area = Shape_area(iObjectOf_(me->rectangle, Rectangle, Shape));
    (void)area;
    // Get rectangle shape origin
    Point origin = iObjectOf_(me->rectangle, Rectangle, Shape)->origin;
    (void)origin;
    // set rectangle shape origin
    iObjectOf_(me->rectangle, Rectangle, Shape)->origin = (Point){ 6, 7 };
    // Draw rectangle through Drawable object polymorphic call
    Drawable_draw(iObjectOf_(me->rectangle, Rectangle, Drawable));
}
static void polymorphismExample(Application * const me) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        iObjectOf_(me->circle, Circle, Shape),
        iObjectOf_(me->rectangle, Rectangle, Shape),
    };
    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < lengthOf_(shapes); i++) {
        // Get area through Shape object polymorphic call
        float area = Shape_area(shapes[i]);
        (void)area;
        // Get parent object from included object
        Object * object = rObjectOf_(shapes[i]);
        // Get size of object
        size_t objectSize = objectSizeOf_(object);
        (void)objectSize;
        // Get hash code of object
        uint64_t hashCode = hashCode_(object);
        (void)hashCode;
        // Get className of object
        char const * className = classNameOf_(me->circle);
        (void)className;
        // Check class of object
        if (isOfClass_(object, Circle)) {
            // Get circle radius
            uint32_t radius = ((Circle *)object)->radius;
            (void)radius;
        } else if (isOfClass_(object, Rectangle)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth((Rectangle *)object);
            (void)width;
            uint32_t height = Rectangle_getHeight((Rectangle *)object);
            (void)height;
        }
    }
}
static Object * deinit(Object * const me) {
    Application * Me = (Application *)me;
    dealloc_(Me->rectangle);
    dealloc_(Me->circle);
    return superCall_(Object, deinit, me);
}
/**
 * Override Object_copy to assert if used. Cannot copy a singleton.
 */
static Object * copy(Object const * const me) {
    assert_(false);
    return (Object *)me;
}
