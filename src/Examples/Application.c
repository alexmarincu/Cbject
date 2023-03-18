#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>

#define cbject_Class (Application, cbject_Singleton)

struct Application {
    cbject_Singleton singleton;
    Circle * circle;
    Rectangle * rectangle;
};

cbject_utils_allocPool(0);

Application * Application_instance(void) {
    static Application application;
    cbject_utils_doOnce {
        cbject_Singleton_init((cbject_Singleton *)&application);
    }
    return &application;
}

static void greetingExample(Application * const application) {
    (void)(application);
    // Allocate and initialize a Greeting application
    Greeting * greeting = Greeting_init(cbject_utils_alloc(Greeting), "Hello Cbject!");
    // Call Greeting print function on the greeting application
    Greeting_print(greeting);
    // Free memory allocated for the Greeting application
    cbject_utils_dealloc(greeting);
}

static void circleExample(Application * const application) {
    // Allocate and initialize a Circle object
    application->circle = Circle_init(cbject_utils_alloc(Circle), (Point){ 0, 1 }, 2);
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
    Drawable_draw(&application->circle->drawable);
}

static void rectangleExample(Application * const application) {
    // Allocate and initialize a Rectangle object
    application->rectangle = Rectangle_init(cbject_utils_alloc(Rectangle), ((Point){ 0, 1 }), 2, 3);
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
    Drawable_draw(&application->rectangle->drawable);
}

static void polymorphismExample(Application * const application) {
    // Prepare a list of shapes
    Shape * const shapes[] = {
        (Shape *)application->circle,
        (Shape *)application->rectangle,
    };
    // Loop through the list of shapes and call various polymorphic functions
    for (uint8_t i = 0; i < cbject_utils_Array_length(shapes); i++) {
        // Get area through Shape object polymorphic call
        float area = Shape_area(shapes[i]);
        (void)(area);
        // Get size of shape object
        size_t instanceSize = cbject_Object_instanceSize(shapes[i]);
        (void)(instanceSize);
        // Get hash code of shape object
        uint64_t hashCode = cbject_utils_hashCode(shapes[i]);
        (void)(hashCode);
        // Check class of chape object
        if (cbject_utils_isOfClass(shapes[i], Circle)) {
            // Get circle radius
            uint32_t radius = ((Circle *)shapes[i])->radius;
            (void)(radius);
        } else if (cbject_utils_isOfClass(shapes[i], Rectangle)) {
            // Get rectangle width and height
            uint32_t width = Rectangle_getWidth((Rectangle *)shapes[i]);
            (void)(width);
            uint32_t height = Rectangle_getHeight((Rectangle *)shapes[i]);
            (void)(height);
        }
    }
}

void Application_main(Application * const application) {
    greetingExample(application);
    circleExample(application);
    rectangleExample(application);
    polymorphismExample(application);
}

static cbject_Object * terminate(cbject_Object * const object) {
    Application * application = (Application *)object;
    cbject_utils_dealloc(application->rectangle);
    cbject_utils_dealloc(application->circle);
    return cbject_utils_invokeSuperMethod(cbject_Object, terminate, object);
}

ApplicationClass * ApplicationClass_instance(void) {
    static ApplicationClass klass;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&klass);
        klass.singletonClass.objectClass.terminate = terminate;
    }
    return &klass;
}

#undef cbject_Class
