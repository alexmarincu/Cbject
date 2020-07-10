#include "Application.h"
#include "../CObject/CObjectSuper.h"
#include "../Circle/Circle.h"
#include "../ColoredCircle/ColoredCircle.h"
#include "../Rectangle/Rectangle.h"
#include <stdio.h>

#undef class
#define class Application
#undef super_class
#define super_class CObject

singleton_class_members(
    Circle * circle,
    Rectangle * rectangle,
    ColoredCircle * coloredCircle);

singleton_class_init({ setup_virtual_functions({}); });

private_functions(
    (Void, printBeginMessage, ()),
    (Void, printEndMessage, ()),
    (Void, circleExample, ()),
    (Void, stackCircleExample, ()),
    (Void, rectangleExample, ()),
    (Void, stackRectangleExample, ()),
    (Void, heapRectangleExample, ()),
    (Void, coloredCircleExample, ()),
    (Void, polymorphismExample, ()));

fun(Void, start, ())
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

private_fun(Void, printBeginMessage, ()) { printf("\nApplication started ->\n"); }
private_fun(Void, printEndMessage, ()) { printf("\nApplication ended <-\n"); }

private_fun(Void, circleExample, ())
{
    printf("\n= Circle example:\n");
    printf("Circle_pi = %.2f\n", Circle_pi);

    me->circle = get_Circle(
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 1,
            .radius = 1}));

    printf("circle.radius = %d\n", Circle_radius(me->circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->circle, 2);
    printf("circle.radius = %d\n", Circle_radius(me->circle));
    printf("circle.area() = %.2f\n", Shape_area((Shape *) me->circle));
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) me->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) me->circle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->circle, (Point){2, 3});
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) me->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) me->circle).y);
    Shape_draw((Shape *) me->circle, 5);
}

private_fun(Void, stackCircleExample, ())
{
    printf("\n= StackCircle example:\n");

    Object(Circle, stackCircle,
           &((CircleInitParams){
               .origin.x = 2,
               .origin.y = 3,
               .radius = 3}));

    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("stackCircle.radius = %d\n", Circle_radius(stackCircle));
}

private_fun(Void, rectangleExample, ())
{
    printf("\n= Rectangle example:\n");

    me->rectangle = get_Rectangle(
        &((RectangleInitParams){
            .origin.x = 4,
            .origin.y = 5,
            .width = 1,
            .height = 2}));

    printf("rectangle.width = %d\n", Rectangle_width(me->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->rectangle, 2);
    Rectangle_heightSet(me->rectangle, 3);
    printf("rectangle.width = %d\n", Rectangle_width(me->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(me->rectangle));
    printf("rectangle.area() = %.2f\n", Shape_area((Shape *) me->rectangle));
    Shape_draw((Shape *) me->rectangle, 6);
}

private_fun(Void, stackRectangleExample, ())
{
    printf("\n= StackRectangle example:\n");

    Object(Rectangle, stackRectangle,
           &((RectangleInitParams){
               .origin.x = 12,
               .origin.y = 23,
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

private_fun(Void, heapRectangleExample, ())
{
    printf("\n= HeapRectangle example:\n");

    Rectangle * const heapRectangle = new_Rectangle(
        &((RectangleInitParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    printf("heapRectangle.width = %d\n", Rectangle_width(heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(heapRectangle, 2);
    Rectangle_heightSet(heapRectangle, 3);
    printf("heapRectangle.width = %d\n", Rectangle_width(heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(heapRectangle));
    free(heapRectangle);
}

private_fun(Void, coloredCircleExample, ())
{
    printf("\n= ColoredCircle example:\n");

    me->coloredCircle = get_ColoredCircle(
        &((ColoredCircleInitParams){
            .radius = 10,
            .color = Color_red}));

    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) me->coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) me->coloredCircle, 3);
    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) me->coloredCircle));
    printf("coloredCircle.area() = %.2f\n", Shape_area((Shape *) me->coloredCircle));
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) me->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) me->coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) me->coloredCircle, (Point){2, 3});
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) me->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) me->coloredCircle).y);
    Shape_draw((Shape *) me->coloredCircle, 5);
}

private_fun(Void, polymorphismExample, ())
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        (Shape *) me->circle,
        (Shape *) me->rectangle,
        (Shape *) me->coloredCircle};

    for (UInt8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].objectSize() = %d\n", i, CObject_objectSize((CObject *) shapes[i]));
    }
}
