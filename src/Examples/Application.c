#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>
struct Application {
    extends_(Object);
    Circle * circle;
    Rectangle * rectangle;
};
static Object * teardown(Object * application);
static Object * copy(Object const * const application, Object * const copyObject);
ApplicationClass const * ApplicationClass_instance(void) {
    static ApplicationClass class;
    doOnce_ {
        setUpClass_(Application, Object, &class);
        bindClassMethod_(Object, teardown, &class);
        bindClassMethod_(Object, copy, &class);
    }
    return &class;
}
Application * Application_instance(void) {
    static Application application;
    doOnce_ {
        setUpObject_(Application, Object, &application);
    }
    return &application;
}
static void circleExample(Application * const application);
static void greetingExample(Application * const application);
static void rectangleExample(Application * const application);
static void polymorphismExample(Application * const application);
void Application_main(Application * const application) {
    greetingExample(application);
    circleExample(application);
    rectangleExample(application);
    polymorphismExample(application);
}
static void greetingExample(Application * const application) {
    ignore_(application);
    // Allocate and initialize a Greeting application
    Greeting * greeting = allocInit_(Greeting, "Hello Cbject!");
    // Call Greeting print function on the greeting application
    Greeting_print(greeting);
    // Free memory allocated for the Greeting application
    dealloc_(greeting);
}
static void circleExample(Application * const application) {
    // Allocate and initialize a Circle application
    application->circle = allocInit_(Circle, (Point){ 0, 1 }, 2);
    // Get circle radius
    uint32_t radius = application->circle->radius;
    ignore_(radius);
    // Set circle radius
    application->circle->radius = 3;
    // Get circle area through Shape application polymorphic call
    float area = Shape_area(to_(Shape, application->circle));
    ignore_(area);
    // Get circle shape origin
    Point origin = to_(Shape, application->circle)->origin;
    ignore_(origin);
    // set circle shape origin
    to_(Shape, application->circle)->origin = (Point){ 4, 5 };
    // Draw circle through Drawable application polymorphic call
    Drawable_draw(traitOf_(Circle, Drawable, application->circle));
}
static void rectangleExample(Application * const application) {
    // Allocate and initialize a Rectangle application
    application->rectangle = allocInit_(Rectangle, ((Point){ 0, 1 }), 2, 3);
    // Get rectangle width and height
    uint32_t width = Rectangle_getWidth(application->rectangle);
    ignore_(width);
    uint32_t height = Rectangle_getHeight(application->rectangle);
    ignore_(height);
    // Set rectangle with and height
    Rectangle_setWidth(application->rectangle, 4);
    Rectangle_setHeight(application->rectangle, 5);
    // Get rectangle area through Shape application polymorphic call
    float area = Shape_area(to_(Shape, application->rectangle));
    ignore_(area);
    // Get rectangle shape origin
    Point origin = to_(Shape, application->rectangle)->origin;
    ignore_(origin);
    // set rectangle shape origin
    to_(Shape, application->rectangle)->origin = (Point){ 6, 7 };
    // Draw rectangle through Drawable application polymorphic call
    Drawable_draw(traitOf_(Rectangle, Drawable, application->rectangle));
}
static void polymorphismExample(Application * const application) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        to_(Shape, application->circle),
        to_(Shape, application->rectangle),
    };
    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < lengthOf_(shapes); i++) {
        // Get area through Shape application polymorphic call
        float area = Shape_area(shapes[i]);
        ignore_(area);
        // Get parent application from included application
        Object * application = objectOf_(shapes[i]);
        // Get size of application
        size_t objectSize = objectSizeOf_(application);
        ignore_(objectSize);
        // Get hash code of application
        uint64_t hashCode = hashCode_(application);
        ignore_(hashCode);
        // Check class of application
        if (isOfClass_(application, Circle)) {
            // Get circle radius
            uint32_t radius = to_(Circle, application)->radius;
            ignore_(radius);
        } else if (isOfClass_(application, Rectangle)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth(to_(Rectangle, application));
            ignore_(width);
            uint32_t height = Rectangle_getHeight(to_(Rectangle, application));
            ignore_(height);
        }
    }
}
static Object * teardown(Object * const object) {
    Application * application = to_(Application, object);
    dealloc_(application->rectangle);
    dealloc_(application->circle);
    return classMethodCall_(Object, Object, teardown, object);
}
static Object * copy(Object const * const object, Object * const copyObject) {
    ignore_(object);
    ignore_(copyObject);
    assert(false);
    return NULL;
}
