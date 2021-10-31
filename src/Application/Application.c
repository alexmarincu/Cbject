#include "Application.h"
#include <stdio.h>

#define Type Application
#define Parent Cbject

ObjectSetup((void));
Init {}
Terminate {}

static Fun(void, printBeginMessage, (void));
static Fun(void, printEndMessage, (void));
static Fun(void, circleExample, (void));
static Fun(void, stackCircleExample, (void));
static Fun(void, rectangleExample, (void));
static Fun(void, stackRectangleExample, (void));
static Fun(void, heapRectangleExample, (void));
static Fun(void, coloredCircleExample, (void));
static Fun(void, polymorphismExample, (void));

Fun(void, start, (void))
{
    Application_circleExample(me);
    Application_stackCircleExample(me);
    Application_rectangleExample(me);
    Application_stackRectangleExample(me);
    Application_heapRectangleExample(me);
    Application_coloredCircleExample(me);
    Application_polymorphismExample(me);
    Rectangle_delete(me->d.heapRectangle);
}

static Fun(void, circleExample, (void))
{
    printf("\n= Circle example:\n");
    me->d.circle = Circle_getFromStaticPool((CircleParams){{0, 1}, 1});
    printf("radius = %d\n", Circle_radius(me->d.circle));
    printf("Set radius to 2\n");
    Circle_radiusSet(me->d.circle, 2);
    printf("radius = %d\n", Circle_radius(me->d.circle));
    printf("area = %.2f\n", Shape_area(Cast(Shape, me->d.circle)));
    printf("origin.x = %d\n", Shape_origin(Cast(Shape, me->d.circle)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(Shape, me->d.circle)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet(Cast(Shape, me->d.circle), (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Cast(Shape, me->d.circle)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(Shape, me->d.circle)).y);
    Shape_draw(Cast(Shape, me->d.circle));
    Circle_rotate(me->d.circle);

    if (Cbject_isTypeOf(me->d.circle, Circle))
    {
        printf("is circle\n");
    }

    // printf("type name = %s\n", Cbject_type((Cbject *) me->d.circle)->name);
}

static Fun(void, stackCircleExample, (void))
{
    printf("\n= StackCircle example:\n");
    Circle * stackCircle = Circle_createOnStack((Circle *)&(CircleContainer){}, (CircleParams){{2, 3}, 3});
    printf("radius = %d\n", Circle_radius(stackCircle));
    printf("Set radius to 4\n");
    Circle_radiusSet(stackCircle, 4);
    printf("radius = %d\n", Circle_radius(stackCircle));
}

static Fun(void, rectangleExample, (void))
{
    printf("\n= Rectangle example:\n");
    me->d.rectangle = Rectangle_getFromStaticPool((RectangleParams){{4, 5}, 1, 2});
    printf("width = %d\n", Rectangle_width(me->d.rectangle));
    printf("height = %d\n", Rectangle_height(me->d.rectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->d.rectangle, 2);
    Rectangle_heightSet(me->d.rectangle, 3);
    printf("width = %d\n", Rectangle_width(me->d.rectangle));
    printf("height = %d\n", Rectangle_height(me->d.rectangle));
    printf("area = %.2f\n", Shape_area(Cast(Shape, me->d.rectangle)));
    Shape_draw(Cast(Shape, me->d.rectangle));
    // printf("type name = %s\n", Cbject_type((Cbject *) me->d.rectangle)->name);
}

static Fun(void, stackRectangleExample, (void))
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

static Fun(void, heapRectangleExample, (void))
{
    printf("\n= HeapRectangle example:\n");
    me->d.heapRectangle = Rectangle_createOnHeap((RectangleParams){{12, 23}, 34, 2});
    printf("width = %d\n", Rectangle_width(me->d.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->d.heapRectangle));
    printf("Set width to 2 and height to 3\n");
    Rectangle_widthSet(me->d.heapRectangle, 2);
    Rectangle_heightSet(me->d.heapRectangle, 3);
    printf("width = %d\n", Rectangle_width(me->d.heapRectangle));
    printf("height = %d\n", Rectangle_height(me->d.heapRectangle));
}

static Fun(void, coloredCircleExample, (void))
{
    printf("\n= ColoredCircle example:\n");
    me->d.coloredCircle = ColoredCircle_getFromStaticPool((ColoredCircleParams){{12, 23}, 10, Color_red});
    printf("radius = %d\n", Circle_radius(Cast(Circle, me->d.coloredCircle)));
    printf("Set radius to 3\n");
    Circle_radiusSet(Cast(Circle, me->d.coloredCircle), 3);
    printf("radius = %d\n", Circle_radius(Cast(Circle, me->d.coloredCircle)));
    printf("area = %.2f\n", Shape_area(Cast(Shape, me->d.coloredCircle)));
    printf("origin.x = %d\n", Shape_origin(Cast(Shape, me->d.coloredCircle)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(Shape, me->d.coloredCircle)).y);
    printf("Set origin to {2, 3}\n");
    Shape_originSet(Cast(Shape, me->d.coloredCircle), (Point){2, 3});
    printf("origin.x = %d\n", Shape_origin(Cast(Shape, me->d.coloredCircle)).x);
    printf("origin.y = %d\n", Shape_origin(Cast(Shape, me->d.coloredCircle)).y);
    Shape_draw(Cast(Shape, me->d.coloredCircle));
    Circle_rotate(Cast(Circle, me->d.coloredCircle));
}

static Fun(void, polymorphismExample, (void))
{
    printf("\n= Polymorphism example:\n");

    Shape * const shapes[] = {
        Cast(Shape, me->d.circle),
        Cast(Shape, me->d.rectangle),
        Cast(Shape, me->d.heapRectangle),
        Cast(Shape, me->d.coloredCircle)};

    for (uint8 i = 0; i < Array_size(shapes); i++)
    {
        printf("shapes[%d].area() = %.2f\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].size() = %d\n", i, Cbject_size((Cbject *)shapes[i]));
    }
}

#undef Parent
#undef Type
