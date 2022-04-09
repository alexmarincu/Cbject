#include "Application.h"
#include "Circle.h"
#include "Greeting.h"
#include "Rectangle.h"
#include <stdio.h>

/**
 * @brief
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
 * @brief
 * @param me
 */
void Application_main(Application * const me) {
    greetingExample(me);
    circleExample(me);
    rectangleExample(me);
    polymorphismExample(me);
}

/**
 * @brief
 * @param me
 */
static void greetingExample(Application * const me) {
    Greeting * greeting = init_(Greeting, new_(Greeting), "Hello Cbject!");
    Greeting_print(greeting);
    delete_(greeting);
}

/**
 * @brief
 * @param me
 */
static void circleExample(Application * const me) {
    printf("\n= Circle example:\n");
    me->circle = init_(Circle, new_(Circle), (Point){ 0, 1 }, 1);

    printf("radius = %d\n", me->circle->radius);
    printf("Set radius to 2\n");
    me->circle->radius = 10;
    printf("radius = %d\n", me->circle->radius);
    printf("area = %.2f\n", Shape_area(&me->circle->_iShape));
    printf("origin.x = %d\n", me->circle->_iShape.origin.x);
    printf("origin.y = %d\n", me->circle->_iShape.origin.y);
    printf("Set origin to {2, 3}\n");
    me->circle->_iShape.origin = (Point){ 2, 3 };
    printf("origin.x = %d\n", me->circle->_iShape.origin.x);
    printf("origin.y = %d\n", me->circle->_iShape.origin.y);
    Drawable_draw(&me->circle->_iDrawable);
    Circle_rotate(me->circle, 30);

    if (isOfClass_(me->circle, CircleClass_())) {
        printf("is Circle\n");
    }

    printf("type name = %s\n", classNameOf_(me->circle));
}

/**
 * @brief
 * @param me
 */
static void rectangleExample(Application * const me) {
    printf("\n= rectangle example:\n");
    me->rectangle = init_(Rectangle, new_(Rectangle), (Point){ 12, 23 }, 34, 2);
    printf("width = %d\n", Rectangle_getWidth(me->rectangle));
    printf("height = %d\n", Rectangle_getHeight(me->rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_setWidth(me->rectangle, 2);
    Rectangle_setHeight(me->rectangle, 3);
    printf("width = %d\n", Rectangle_getWidth(me->rectangle));
    printf("height = %d\n", Rectangle_getHeight(me->rectangle));
    Rectangle * rectangle = init_(Rectangle, new_(Rectangle), (Point){ 0, 0 }, 5, 10);
    printf("area = %.2f\n", Shape_area(Rectangle_getShape(rectangle)));
    Drawable_draw(Rectangle_getDrawable(rectangle));
    delete_(rectangle);
}

/**
 * @brief
 * @param me
 */
static void polymorphismExample(Application * const me) {
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        &me->circle->_iShape,
        Rectangle_getShape(me->rectangle),
    };

    for (uint8_t i = 0; i < lengthOf_(shapes); i++) {
        printf("shapes[%d] area = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d] objectSize = %d\n", i, objectSizeOf_(interfaceObjectOf_(shapes[i])));
        printf("shapes[%d] hashCode = %d\n", i, hashCode_(interfaceObjectOf_(shapes[i])));
    }
}

/**
 * @brief
 * @param me
 * @param params
 */
Application * init(Application * const me) {
    initObject_(me, ApplicationClass_());
}

/**
 * @brief
 * @param me
 */
static void finalize(Application * const me) {
    delete_(me->rectangle);
    delete_(me->circle);
}

/**
 * @brief Returns the same singleton object instead of a copy
 * @param me The singleton Application object
 * @return Application*
 */
static Application * copy(Application * const me) {
    return me;
}

/**
 * @brief
 * @param params
 * @return Application*
 */
Application * Application_(void) {
    static Application me;

    doOnce_({
        init(&me);
    });

    return &me;
}

/**
 * @brief
 * @return ApplicationOperations const*
 */
ApplicationOperations const * ApplicationOperations_(void) {
    static ApplicationOperations operations;

    doOnce_({
        operations.objectOperations = *ObjectOperations_();
        operations.objectOperations.finalize = (ObjectOperation_finalize)finalize;
        operations.objectOperations.copy = (ObjectOperation_copy)copy;
    });

    return &operations;
}

/**
 * @brief
 * @return Class const*
 */
Class const * ApplicationClass_(void) {
    static Class class_;

    doOnce_({
        initClass_(&class_, Application, ObjectClass_());
    });

    return &class_;
}