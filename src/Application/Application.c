#include "Application.h"
#include "../Circle/Circle.h"
#include "../ColoredCircle/ColoredCircle.h"
#include "../Rectangle/Rectangle.h"
#include "../Shape/Shape.h"
#include <stdio.h>

#define class Application
#define superClass Cbject

SingletonMembers(
    Circle * circle,
    Rectangle * rectangle,
    Rectangle * heapRectangle,
    ColoredCircle * coloredCircle);

SingletonSetup({});
Init({});
Terminate({ delete_Rectangle(me->heapRectangle); });

PrivateFunctions(
    (void, printBeginMessage, ()),
    (void, printEndMessage, ()),
    (void, circleExample, ()),
    (void, stackCircleExample, ()),
    (void, rectangleExample, ()),
    (void, stackRectangleExample, ()),
    (void, heapRectangleExample, ()),
    (void, coloredCircleExample, ()),
    (void, polymorphismExample, ()));

Function(void, start, ())
{
    Application_printBeginMessage(me);
    Application_circleExample(me);
    Application_stackCircleExample(me);
    Application_rectangleExample(me);
    Application_stackRectangleExample(me);
    Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    Application_polymorphismExample(me);
    Application_printEndMessage(me);
}

PrivateFunction(void, printBeginMessage, ()) { printf("\nApplication started ->\n"); }
PrivateFunction(void, printEndMessage, ()) { printf("\nApplication ended <-\n"); }

PrivateFunction(void, circleExample, ())
{
    printf("\n= Circle example:\n");
    printf("Circle_pi = %.2f\n", Circle_pi);
    me->circle = get_Circle(&((CircleParams){.super.origin.x = 0, .super.origin.y = 1, .radius = 1}));
    printf("circle.radius = %d\n", Circle_radius(me->circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->circle, 2);
    printf("circle.radius = %d\n", Circle_radius(me->circle));
    printf("circle.area = %.2f\n", Shape_area((Shape *) me->circle));
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) me->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) me->circle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->circle, (Point){2, 3});
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) me->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) me->circle).y);
    Shape_draw((Shape *) me->circle, 5);
    Circle_rotate(me->circle);
    printf("circle.class.type = %s\n", Cbject_type((Cbject *) me->circle));
}

PrivateFunction(void, stackCircleExample, ())
{
    printf("\n= StackCircle example:\n");

    cbject(Circle, stackCircle,
                &((CircleParams){
                    .super.origin.x = 2,
                    .super.origin.y = 3,
                    .radius = 3}));

    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
}

PrivateFunction(void, rectangleExample, ())
{
    printf("\n= Rectangle example:\n");
    me->rectangle = get_Rectangle(
        &((RectangleParams){
            .super.origin.x = 4,
            .super.origin.y = 5,
            .width = 1,
            .height = 2}));

    printf("rectangle.width = %d\n", Rectangle_width(me->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->rectangle, 2);
    Rectangle_heightSet(me->rectangle, 3);
    printf("rectangle.width = %d\n", Rectangle_width(me->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->rectangle));
    printf("rectangle.area = %.2f\n", Shape_area((Shape *) me->rectangle));
    Shape_draw((Shape *) me->rectangle, 6);
    printf("rectangle.class.type = %s\n", Cbject_type((Cbject *) me->rectangle));
}

PrivateFunction(void, stackRectangleExample, ())
{
    printf("\n= StackRectangle example:\n");

    cbject(Rectangle, stackRectangle,
                &((RectangleParams){
                    .super.origin.x = 12,
                    .super.origin.y = 23,
                    .width = 34,
                    .height = 2}));

    printf("stackRectangle.width = %d\n", Rectangle_width(stackRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(stackRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(stackRectangle, 2);
    Rectangle_heightSet(stackRectangle, 3);
    printf("stackRectangle.width = %d\n", Rectangle_width(stackRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(stackRectangle));
}

PrivateFunction(void, heapRectangleExample, ())
{
    printf("\n= HeapRectangle example:\n");

    me->heapRectangle = new_Rectangle(
        &((RectangleParams){
            .super.origin.x = 12,
            .super.origin.y = 23,
            .width = 34,
            .height = 2}));

    printf("heapRectangle.width = %d\n", Rectangle_width(me->heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->heapRectangle, 2);
    Rectangle_heightSet(me->heapRectangle, 3);
    printf("heapRectangle.width = %d\n", Rectangle_width(me->heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->heapRectangle));
}

PrivateFunction(void, coloredCircleExample, ())
{
    printf("\n= ColoredCircle example:\n");
    me->coloredCircle = get_ColoredCircle(
        &((ColoredCircleParams){
            .super.super.origin.x = 12,
            .super.super.origin.y = 23,
            .super.radius = 10,
            .color = Color_red}));

    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) me->coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) me->coloredCircle, 3);
    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) me->coloredCircle));
    printf("coloredCircle.area = %.2f\n", Shape_area((Shape *) me->coloredCircle));
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) me->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) me->coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->coloredCircle, (Point){2, 3});
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) me->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) me->coloredCircle).y);
    Shape_draw((Shape *) me->coloredCircle, 5);
    Circle_rotate((Circle *) me->coloredCircle);
}

PrivateFunction(void, polymorphismExample, ())
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        (Shape *) me->circle,
        (Shape *) me->rectangle,
        (Shape *) me->heapRectangle,
        (Shape *) me->coloredCircle};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].size() = %d\n", i, Cbject_size((Cbject *) shapes[i]));
    }
}

#undef superClass
#undef class
