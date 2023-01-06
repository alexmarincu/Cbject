#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include "cbject_Object.h"
#include "cbject_utils.h"
#include <stdio.h>
struct Application {
    cbject_is(cbject_Object);
    Circle * circle;
    Rectangle * rectangle;
};
static cbject_Object * teardown(cbject_Object * object);
static cbject_Object * copy(cbject_Object const * const object, cbject_Object * const copyObject);
ApplicationClass const * ApplicationClass_getInstance(void) {
    static ApplicationClass applicationClass;
    cbject_doOnce {
        cbject_setUpClass(Application, cbject_Object, &applicationClass);
        cbject_bindClassMethod(cbject_Object, teardown, &applicationClass);
        cbject_bindClassMethod(cbject_Object, copy, &applicationClass);
    }
    return &applicationClass;
}
Application * Application_getInstance(void) {
    static Application application;
    cbject_doOnce {
        cbject_Object_init((cbject_Object *)&application);
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
    (void)(application);
    // Allocate and initialize a Greeting application
    Greeting * greeting = Greeting_init(cbject_alloc(Greeting), "Hello Cbject!");
    // Call Greeting print function on the greeting application
    Greeting_print(greeting);
    // Free memory allocated for the Greeting application
    cbject_dealloc(greeting);
}
static void circleExample(Application * const application) {
    // Allocate and initialize a Circle object
    application->circle = Circle_init(cbject_alloc(Circle), (Point){ 0, 1 }, 2);
    // Get circle radius
    uint32_t radius = application->circle->radius;
    (void)(radius);
    // Set circle radius
    application->circle->radius = 3;
    // Get circle area through Shape object polymorphic call
    float area = Shape_area((Shape *)application->circle);
    (void)(area);
    // Get circle shape origin
    Point origin = ((Shape *)application->circle)->origin;
    (void)(origin);
    // set circle shape origin
    ((Shape *)application->circle)->origin = (Point){ 4, 5 };
    // Draw circle through Drawable trait polymorphic call
    Drawable_draw(cbject_getTraitOfObject(Circle, Drawable, application->circle));
}
static void rectangleExample(Application * const application) {
    // Allocate and initialize a Rectangle object
    application->rectangle = Rectangle_init(cbject_alloc(Rectangle), ((Point){ 0, 1 }), 2, 3);
    // Get rectangle width and height
    uint32_t width = Rectangle_getWidth(application->rectangle);
    (void)(width);
    uint32_t height = Rectangle_getHeight(application->rectangle);
    (void)(height);
    // Set rectangle with and height
    Rectangle_setWidth(application->rectangle, 4);
    Rectangle_setHeight(application->rectangle, 5);
    // Get rectangle area through Shape object polymorphic call
    float area = Shape_area((Shape *)application->rectangle);
    (void)(area);
    // Get rectangle shape origin
    Point origin = ((Shape *)application->rectangle)->origin;
    (void)(origin);
    // set rectangle shape origin
    ((Shape *)application->rectangle)->origin = (Point){ 6, 7 };
    // Draw rectangle through Drawable trait polymorphic call
    Drawable_draw(cbject_getTraitOfObject(Rectangle, Drawable, application->rectangle));
}
static void polymorphismExample(Application * const application) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        (Shape *)application->circle,
        (Shape *)application->rectangle,
    };
    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < cbject_lengthOfArray(shapes); i++) {
        // Get area through Shape object polymorphic call
        float area = Shape_area(shapes[i]);
        (void)(area);
        // Get size of shape object
        size_t objectSize = cbject_getSizeOfObject(shapes[i]);
        (void)(objectSize);
        // Get hash code of shape object
        uint64_t hashCode = cbject_hashCode(shapes[i]);
        (void)(hashCode);
        // Check class of chape object
        if (cbject_isOfClass(shapes[i], Circle)) {
            // Get circle radius
            uint32_t radius = ((Circle *)shapes[i])->radius;
            (void)(radius);
        } else if (cbject_isOfClass(shapes[i], Rectangle)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth((Rectangle *)shapes[i]);
            (void)(width);
            uint32_t height = Rectangle_getHeight((Rectangle *)shapes[i]);
            (void)(height);
        }
    }
}
static cbject_Object * teardown(cbject_Object * const object) {
    Application * application = (Application *)object;
    cbject_dealloc(application->rectangle);
    cbject_dealloc(application->circle);
    return cbject_callMethodOfClass(cbject_Object, cbject_Object, teardown, object);
}
static cbject_Object * copy(cbject_Object const * const object, cbject_Object * const copyObject) {
    (void)(object);
    (void)(copyObject);
    assert(false);
    return NULL;
}
