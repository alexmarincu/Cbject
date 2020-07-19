#include "Application.h"
#include "../CO/super_CO.h"
#include "../Circle/Circle.h"
#include "../ColoredCircle/ColoredCircle.h"
#include "../Rectangle/Rectangle.h"
#include <stdio.h>

#undef Class_
#define Class_ Application
#undef super_Class_
#define super_Class_ CO

class_members(
    Circle * circle,
    Rectangle * rectangle,
    Rectangle * heapRectangle,
    ColoredCircle * coloredCircle);

singleton_class_setup({});
init({});
clear({ delete_Rectangle(this_->heapRectangle); });

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
    Application_printBeginMessage(this_);
    Application_circleExample(this_);
    Application_stackCircleExample(this_);
    Application_rectangleExample(this_);
    Application_stackRectangleExample(this_);
    Application_heapRectangleExample(this_);
    Application_coloredCircleExample(this_);
    Application_polymorphismExample(this_);
    Application_printEndMessage(this_);
}

private_fun(Void, printBeginMessage, ()) { printf("\nApplication started ->\n"); }
private_fun(Void, printEndMessage, ()) { printf("\nApplication ended <-\n"); }

private_fun(Void, circleExample, ())
{
    printf("\n= Circle example:\n");
    printf("Circle_pi = %.2f\n", Circle_pi);

    this_->circle = get_Circle(
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 1,
            .radius = 1}));

    printf("circle.radius = %d\n", Circle_radius(this_->circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(this_->circle, 2);
    printf("circle.radius = %d\n", Circle_radius(this_->circle));
    printf("circle.area() = %.2f\n", Shape_area((Shape *) this_->circle));
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) this_->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) this_->circle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) this_->circle, (Point){2, 3});
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) this_->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) this_->circle).y);
    Shape_draw((Shape *) this_->circle, 5);
    Circle_rotate(this_->circle);
    printf("circle.class = %s\n", CO_classType((CO *) this_->circle));
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

    this_->rectangle = get_Rectangle(
        &((RectangleInitParams){
            .origin.x = 4,
            .origin.y = 5,
            .width = 1,
            .height = 2}));

    printf("rectangle.width = %d\n", Rectangle_width(this_->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(this_->rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(this_->rectangle, 2);
    Rectangle_heightSet(this_->rectangle, 3);
    printf("rectangle.width = %d\n", Rectangle_width(this_->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(this_->rectangle));
    printf("rectangle.area() = %.2f\n", Shape_area((Shape *) this_->rectangle));
    Shape_draw((Shape *) this_->rectangle, 6);
    printf("rectangle.class = %s\n", CO_classType((CO *) this_->rectangle));
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

    this_->heapRectangle = new_Rectangle(
        &((RectangleInitParams){
            .origin.x = 12,
            .origin.y = 23,
            .width = 34,
            .height = 2}));

    printf("heapRectangle.width = %d\n", Rectangle_width(this_->heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(this_->heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(this_->heapRectangle, 2);
    Rectangle_heightSet(this_->heapRectangle, 3);
    printf("heapRectangle.width = %d\n", Rectangle_width(this_->heapRectangle));
    printf("rectangle.height = %d\n", Rectangle_height(this_->heapRectangle));
}

private_fun(Void, coloredCircleExample, ())
{
    printf("\n= ColoredCircle example:\n");

    this_->coloredCircle = get_ColoredCircle(
        &((ColoredCircleInitParams){
            .radius = 10,
            .color = Color_red}));

    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) this_->coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) this_->coloredCircle, 3);
    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) this_->coloredCircle));
    printf("coloredCircle.area() = %.2f\n", Shape_area((Shape *) this_->coloredCircle));
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) this_->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) this_->coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) this_->coloredCircle, (Point){2, 3});
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) this_->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) this_->coloredCircle).y);
    Shape_draw((Shape *) this_->coloredCircle, 5);
    Circle_rotate((Circle *) this_->coloredCircle);
}

private_fun(Void, polymorphismExample, ())
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        (Shape *) this_->circle,
        (Shape *) this_->rectangle,
        (Shape *) this_->coloredCircle};

    for (UInt8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].objectSize() = %d\n", i, CO_objectSize((CO *) shapes[i]));
    }
}
