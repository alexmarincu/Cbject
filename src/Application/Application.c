#include "Application.h"
#include <stdio.h>

#define Type Application
#define Parent Object

SingletonSetup(());

Init {}
Terminate {}

static Fun(void, printBeginMessage, ());
static Fun(void, printEndMessage, ());
static Fun(void, circleExample, ());
static Fun(void, stackCircleExample, ());
static Fun(void, rectangleExample, ());
static Fun(void, stackRectangleExample, ());
static Fun(void, heapRectangleExample, ());
static Fun(void, coloredCircleExample, ());
static Fun(void, polymorphismExample, ());

Fun(void, start, ())
{
    Application_circleExample(me);
    Application_stackCircleExample(me);
    Application_rectangleExample(me);
    Application_stackRectangleExample(me);
    Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    Application_polymorphismExample(me);
    Rectangle_delete(me->data.heapRectangle);
}

static Fun(void, circleExample, ())
{
    printf("\n= Circle example:\n");
    me->data.circle = Circle_getFromStaticPool((CircleParams){{0, 1}, 1});
    printf("radius = %d\n", Circle_radius(me->data.circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->data.circle, 2);
    printf("radius = %d\n", Circle_radius(me->data.circle));
    printf("area = %.2f\n", Shape_area(Cast(Shape, me->data.circle)));
    printf("origin.x = %d\n", Shape_origin(Cast(Shape, me->data.circle)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(Shape, me->data.circle)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet(Cast(Shape, me->data.circle), (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Cast(Shape, me->data.circle)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(Shape, me->data.circle)).y);
    Shape_draw(Cast(Shape, me->data.circle));
    Circle_rotate(me->data.circle);

    if (Object_isTypeOf(me->data.circle, Circle))
    {
        printf("is circle\n");
    }

    // printf("type name = %s\n", Object_type((Object *) me->data.circle)->name);
}

static Fun(void, stackCircleExample, ())
{
    printf("\n= StackCircle example:\n");
    Circle * stackCircle = Circle_createOnStack((Circle *)&(CircleContainer){}, (CircleParams){{2, 3}, 3});
    printf("radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("radius = %d\n", Circle_radius(stackCircle));
}

static Fun(void, rectangleExample, ())
{
    printf("\n= Rectangle example:\n");
    me->data.rectangle = Rectangle_getFromStaticPool((RectangleParams){{4, 5}, 1, 2});
    printf("width = %d\n", Rectangle_width(me->data.rectangle));
    printf("height = %d\n", Rectangle_height(me->data.rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->data.rectangle, 2);
    Rectangle_heightSet(me->data.rectangle, 3);
    printf("width = %d\n", Rectangle_width(me->data.rectangle));
    printf("height = %d\n", Rectangle_height(me->data.rectangle));
    printf("area = %.2f\n", Shape_area(Cast(Shape, me->data.rectangle)));
    Shape_draw(Cast(Shape, me->data.rectangle));
    // printf("type name = %s\n", Object_type((Object *) me->data.rectangle)->name);
}

static Fun(void, stackRectangleExample, ())
{
    printf("\n= StackRectangle example:\n");
    Rectangle * stackRectangle = Rectangle_createOnStack((Rectangle *)&(RectangleContainer){}, (RectangleParams){{12, 23}, 34, 2});
    printf("width = %d\n", Rectangle_width(stackRectangle));
    printf("height = %d\n", Rectangle_height(stackRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(stackRectangle, 2);
    Rectangle_heightSet(stackRectangle, 3);
    printf("width = %d\n", Rectangle_width(stackRectangle));
    printf("height = %d\n", Rectangle_height(stackRectangle));
}

static Fun(void, heapRectangleExample, ())
{
    printf("\n= HeapRectangle example:\n");
    me->data.heapRectangle = Rectangle_createOnHeap((RectangleParams){{12, 23}, 34, 2});
    printf("width = %d\n", Rectangle_width(me->data.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->data.heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->data.heapRectangle, 2);
    Rectangle_heightSet(me->data.heapRectangle, 3);
    printf("width = %d\n", Rectangle_width(me->data.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->data.heapRectangle));
}

static Fun(void, coloredCircleExample, ())
{
    printf("\n= ColoredCircle example:\n");
    me->data.coloredCircle = ColoredCircle_getFromStaticPool((ColoredCircleParams){{12, 23}, 10, Color_red});
    printf("radius = %d\n", Circle_radius(Cast(Circle, me->data.coloredCircle)));
    printf("Set radius to 3\n");
    Circle_radiusSet(Cast(Circle, me->data.coloredCircle), 3);
    printf("radius = %d\n", Circle_radius(Cast(Circle, me->data.coloredCircle)));
    printf("area = %.2f\n", Shape_area(Cast(Shape, me->data.coloredCircle)));
    printf("origin.x = %d\n", Shape_origin(Cast(Shape, me->data.coloredCircle)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(Shape, me->data.coloredCircle)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet(Cast(Shape, me->data.coloredCircle), (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Cast(Shape, me->data.coloredCircle)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(Shape, me->data.coloredCircle)).y);
    Shape_draw(Cast(Shape, me->data.coloredCircle));
    Circle_rotate(Cast(Circle, me->data.coloredCircle));
}

static Fun(void, polymorphismExample, ())
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        Cast(Shape, me->data.circle),
        Cast(Shape, me->data.rectangle),
        Cast(Shape, me->data.heapRectangle),
        Cast(Shape, me->data.coloredCircle)};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].size() = %d\n", i, Object_size((Object *)shapes[i]));
    }
}

#undef Parent
#undef Type
