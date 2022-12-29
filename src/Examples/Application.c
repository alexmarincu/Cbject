#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>
struct Application {
    x_is(x_Object);
    Circle * circle;
    Rectangle * rectangle;
};
static x_Object * teardown(x_Object * object);
static x_Object * copy(x_Object const * const object, x_Object * const copyObject);
ApplicationClass const * ApplicationClass_instance(void) {
    static ApplicationClass applicationClass;
    x_doOnce {
        x_setUpClass(Application, x_Object, &applicationClass);
        x_bindClassMethod(x_Object, teardown, &applicationClass);
        x_bindClassMethod(x_Object, copy, &applicationClass);
    }
    return &applicationClass;
}
Application * Application_instance(void) {
    static Application application;
    x_doOnce {
        x_setUpObject(Application, x_Object, &application);
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
    x_ignore(application);
    // Allocate and initialize a Greeting application
    Greeting * greeting = x_allocInit(Greeting, "Hello Cbject!");
    // Call Greeting print function on the greeting application
    Greeting_print(greeting);
    // Free memory allocated for the Greeting application
    x_dealloc(greeting);
}
static void circleExample(Application * const application) {
    // Allocate and initialize a Circle object
    application->circle = x_allocInit(Circle, (Point){ 0, 1 }, 2);
    // Get circle radius
    uint32_t radius = application->circle->radius;
    x_ignore(radius);
    // Set circle radius
    application->circle->radius = 3;
    // Get circle area through Shape object polymorphic call
    float area = Shape_area(x_castTo(Shape, application->circle));
    x_ignore(area);
    // Get circle shape origin
    Point origin = x_castTo(Shape, application->circle)->origin;
    x_ignore(origin);
    // set circle shape origin
    x_castTo(Shape, application->circle)->origin = (Point){ 4, 5 };
    // Draw circle through Drawable trait polymorphic call
    Drawable_draw(x_traitOf(Circle, Drawable, application->circle));
}
static void rectangleExample(Application * const application) {
    // Allocate and initialize a Rectangle object
    application->rectangle = x_allocInit(Rectangle, ((Point){ 0, 1 }), 2, 3);
    // Get rectangle width and height
    uint32_t width = Rectangle_getWidth(application->rectangle);
    x_ignore(width);
    uint32_t height = Rectangle_getHeight(application->rectangle);
    x_ignore(height);
    // Set rectangle with and height
    Rectangle_setWidth(application->rectangle, 4);
    Rectangle_setHeight(application->rectangle, 5);
    // Get rectangle area through Shape object polymorphic call
    float area = Shape_area(x_castTo(Shape, application->rectangle));
    x_ignore(area);
    // Get rectangle shape origin
    Point origin = x_castTo(Shape, application->rectangle)->origin;
    x_ignore(origin);
    // set rectangle shape origin
    x_castTo(Shape, application->rectangle)->origin = (Point){ 6, 7 };
    // Draw rectangle through Drawable trait polymorphic call
    Drawable_draw(x_traitOf(Rectangle, Drawable, application->rectangle));
}
static void polymorphismExample(Application * const application) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        x_castTo(Shape, application->circle),
        x_castTo(Shape, application->rectangle),
    };
    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < x_lengthOf(shapes); i++) {
        // Get area through Shape object polymorphic call
        float area = Shape_area(shapes[i]);
        x_ignore(area);
        // Get size of shape object
        size_t objectSize = x_objectSizeOf(shapes[i]);
        x_ignore(objectSize);
        // Get hash code of shape object
        uint64_t hashCode = x_hashCode(shapes[i]);
        x_ignore(hashCode);
        // Check class of chape object
        if (x_isOfClass(shapes[i], Circle)) {
            // Get circle radius
            uint32_t radius = x_castTo(Circle, shapes[i])->radius;
            x_ignore(radius);
        } else if (x_isOfClass(shapes[i], Rectangle)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth(x_castTo(Rectangle, shapes[i]));
            x_ignore(width);
            uint32_t height = Rectangle_getHeight(x_castTo(Rectangle, shapes[i]));
            x_ignore(height);
        }
    }
}
static x_Object * teardown(x_Object * const object) {
    Application * application = x_castTo(Application, object);
    x_dealloc(application->rectangle);
    x_dealloc(application->circle);
    return x_callClassMethod(x_Object, x_Object, teardown, object);
}
static x_Object * copy(x_Object const * const object, x_Object * const copyObject) {
    x_ignore(object);
    x_ignore(copyObject);
    assert(false);
    return NULL;
}
