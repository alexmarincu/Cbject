#include "Application.h"
#include "../CO/super_CO.h"
#include "../Circle/Circle.h"
#include "../ColoredCircle/ColoredCircle.h"
#include "../Rectangle/Rectangle.h"
#include <stdio.h>

#undef Class
#define Class Application
#undef SuperClass
#define SuperClass CO

class_members(
    Circle * circle,
    Rectangle * rectangle,
    ColoredCircle * coloredCircle);

singleton_class_setup({});
init({});

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
    Application_printBeginMessage(_this);
    Application_circleExample(_this);
    Application_stackCircleExample(_this);
    Application_rectangleExample(_this);
    Application_stackRectangleExample(_this);
    Application_heapRectangleExample(_this);
    Application_coloredCircleExample(_this);
    Application_polymorphismExample(_this);
    Application_printEndMessage(_this);
}

private_fun(Void, printBeginMessage, ()) { printf("\nApplication started ->\n"); }
private_fun(Void, printEndMessage, ()) { printf("\nApplication ended <-\n"); }

private_fun(Void, circleExample, ())
{
    printf("\n= Circle example:\n");
    printf("Circle_pi = %.2f\n", Circle_pi);

    _this->circle = get_Circle(
        &((CircleInitParams){
            .origin.x = 0,
            .origin.y = 1,
            .radius = 1}));

    printf("circle.radius = %d\n", Circle_radius(_this->circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(_this->circle, 2);
    printf("circle.radius = %d\n", Circle_radius(_this->circle));
    printf("circle.area() = %.2f\n", Shape_area((Shape *) _this->circle));
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) _this->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) _this->circle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) _this->circle, (Point){2, 3});
    printf("circle.origin.x = %d\n", Shape_origin((Shape *) _this->circle).x);
    printf("circle.origin.y = %d\n", Shape_origin((Shape *) _this->circle).y);
    Shape_draw((Shape *) _this->circle, 5);
    printf("circle.class = %s\n", CO_classType((CO *) _this->circle));
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

    _this->rectangle = get_Rectangle(
        &((RectangleInitParams){
            .origin.x = 4,
            .origin.y = 5,
            .width = 1,
            .height = 2}));

    printf("rectangle.width = %d\n", Rectangle_width(_this->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(_this->rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(_this->rectangle, 2);
    Rectangle_heightSet(_this->rectangle, 3);
    printf("rectangle.width = %d\n", Rectangle_width(_this->rectangle));
    printf("rectangle.height = %d\n", Rectangle_height(_this->rectangle));
    printf("rectangle.area() = %.2f\n", Shape_area((Shape *) _this->rectangle));
    Shape_draw((Shape *) _this->rectangle, 6);
    printf("rectangle.class = %s\n", CO_classType((CO *) _this->rectangle));
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

    _this->coloredCircle = get_ColoredCircle(
        &((ColoredCircleInitParams){
            .radius = 10,
            .color = Color_red}));

    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) _this->coloredCircle));
    printf("Set radius to 3\n");
    Circle_radiusSet((Circle *) _this->coloredCircle, 3);
    printf("coloredCircle.radius = %d\n", Circle_radius((Circle *) _this->coloredCircle));
    printf("coloredCircle.area() = %.2f\n", Shape_area((Shape *) _this->coloredCircle));
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) _this->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) _this->coloredCircle).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet((Shape *) _this->coloredCircle, (Point){2, 3});
    printf("coloredCircle.origin.x = %d\n", Shape_origin((Shape *) _this->coloredCircle).x);
    printf("coloredCircle.origin.y = %d\n", Shape_origin((Shape *) _this->coloredCircle).y);
    Shape_draw((Shape *) _this->coloredCircle, 5);
}

private_fun(Void, polymorphismExample, ())
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        (Shape *) _this->circle,
        (Shape *) _this->rectangle,
        (Shape *) _this->coloredCircle};

    for (UInt8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].objectSize() = %d\n", i, CO_objectSize((CO *) shapes[i]));
    }
}
