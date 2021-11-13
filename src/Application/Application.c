#include "Application.h"
#include <stdio.h>

#undef Type
#define Type Application

SingletonSetup(
    NA,
    NA);

Init {}
Terminate { Delete(me->data.heapRectangle, Rectangle); }

static Fun(void, printBeginMessage, NA);
static Fun(void, printEndMessage, NA);
static Fun(void, circleExample, NA);
static Fun(void, stackCircleExample, NA);
static Fun(void, rectangleExample, NA);
static Fun(void, stackRectangleExample, NA);
static Fun(void, heapRectangleExample, NA);
static Fun(void, coloredCircleExample, NA);
static Fun(void, polymorphismExample, NA);

Fun(void, start, NA)
{
    Application_circleExample(me);
    Application_stackCircleExample(me);
    Application_rectangleExample(me);
    Application_stackRectangleExample(me);
    Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    Application_polymorphismExample(me);
}

static Fun(void, circleExample, NA)
{
    printf("\n= Circle example:\n");
    me->data.circle = Get(Circle, &(CircleParams){{0, 1}, 1});
    printf("radius = %d\n", Circle_radius(me->data.circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->data.circle, 2);
    printf("radius = %d\n", Circle_radius(me->data.circle));
    printf("area = %.2f\n", Shape_area(Cast(me->data.circle, Shape)));
    printf("origin.x = %d\n", Shape_origin(Cast(me->data.circle, Shape)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(me->data.circle, Shape)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet(Cast(me->data.circle, Shape), (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Cast(me->data.circle, Shape)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(me->data.circle, Shape)).y);
    Shape_draw(Cast(me->data.circle, Shape));
    Circle_rotate(me->data.circle, 30);

    if (Object_isTypeOf(me->data.circle, Circle))
    {
        printf("is circle\n");
    }

    printf("type name = %s\n", Object_typeName(Cast(me->data.circle, Object)));
}

static Fun(void, stackCircleExample, NA)
{
    printf("\n= StackCircle example:\n");
    Circle * stackCircle = StackCreate(Circle, &(CircleParams){{2, 3}, 3});
    printf("radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("radius = %d\n", Circle_radius(stackCircle));
}

static Fun(void, rectangleExample, NA)
{
    printf("\n= Rectangle example:\n");
    me->data.rectangle = Get(Rectangle, &(RectangleParams){{4, 5}, 1, 2});
    printf("width = %d\n", Rectangle_width(me->data.rectangle));
    printf("height = %d\n", Rectangle_height(me->data.rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->data.rectangle, 2);
    Rectangle_heightSet(me->data.rectangle, 3);
    printf("width = %d\n", Rectangle_width(me->data.rectangle));
    printf("height = %d\n", Rectangle_height(me->data.rectangle));
    printf("area = %.2f\n", Shape_area(Cast(me->data.rectangle, Shape)));
    Rectangle_makeSquare(me->data.rectangle, 5);
    printf("width = %d\n", Rectangle_width(me->data.rectangle));
    printf("height = %d\n", Rectangle_height(me->data.rectangle));
    printf("area = %.2f\n", Shape_area(Cast(me->data.rectangle, Shape)));
    Shape_draw(Cast(me->data.rectangle, Shape));
    printf("type name = %s\n", Object_typeName(Cast(me->data.rectangle, Object)));
}

static Fun(void, stackRectangleExample, NA)
{
    printf("\n= StackRectangle example:\n");
    Rectangle * stackRectangle = StackCreate(Rectangle, &(RectangleParams){{12, 23}, 34, 2});
    printf("width = %d\n", Rectangle_width(stackRectangle));
    printf("height = %d\n", Rectangle_height(stackRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(stackRectangle, 2);
    Rectangle_heightSet(stackRectangle, 3);
    printf("width = %d\n", Rectangle_width(stackRectangle));
    printf("height = %d\n", Rectangle_height(stackRectangle));
}

static Fun(void, heapRectangleExample, NA)
{
    printf("\n= HeapRectangle example:\n");
    me->data.heapRectangle = Create(Rectangle, &(RectangleParams){{12, 23}, 34, 2});
    printf("width = %d\n", Rectangle_width(me->data.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->data.heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->data.heapRectangle, 2);
    Rectangle_heightSet(me->data.heapRectangle, 3);
    printf("width = %d\n", Rectangle_width(me->data.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->data.heapRectangle));
}

static Fun(void, coloredCircleExample, NA)
{
    printf("\n= ColoredCircle example:\n");
    me->data.coloredCircle = Get(ColoredCircle, &(ColoredCircleParams){{12, 23}, 10, Color_red});
    printf("radius = %d\n", Circle_radius(Cast(me->data.coloredCircle, Circle)));
    printf("Set radius to 3\n");
    Circle_radiusSet(Cast(me->data.coloredCircle, Circle), 3);
    printf("radius = %d\n", Circle_radius(Cast(me->data.coloredCircle, Circle)));
    printf("area = %.2f\n", Shape_area(Cast(me->data.coloredCircle, Shape)));
    printf("origin.x = %d\n", Shape_origin(Cast(me->data.coloredCircle, Shape)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(me->data.coloredCircle, Shape)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet(Cast(me->data.coloredCircle, Shape), (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Cast(me->data.coloredCircle, Shape)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(me->data.coloredCircle, Shape)).y);
    Shape_draw(Cast(me->data.coloredCircle, Shape));
    Circle_rotate(Cast(me->data.coloredCircle, Circle), 30);
}

static Fun(void, polymorphismExample, NA)
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        Cast(me->data.circle, Shape),
        Cast(me->data.rectangle, Shape),
        Cast(me->data.heapRectangle, Shape),
        Cast(me->data.coloredCircle, Shape)};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(Cast(shapes[i], Shape)));
        printf("shapes[%d].size() = %d\n", i, Object_size(Cast(shapes[i], Object)));
    }
}
