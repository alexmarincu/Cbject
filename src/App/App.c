#include "App.h"
#include "../Circle/Circle.h"
#include "../Rectangle/Rectangle.h"
#include <stdio.h>

Void App_start()
{
    CircleInitParams p = {{2, 3}, 5};
    Circle circle = get_Circle(&p);
    RectangleInitParams rp = {{12,23},34,2};
    Rectangle rectangle = get_Rectangle(&rp);
    Shape shapes[] = {(Shape) circle, (Shape) rectangle};
    printf("circle.isInitialized() = %d\n", CObject_isInitialized((CObject) circle));

    {
        Point origin = Shape_getOrigin((Shape) circle);
        printf("circle.origin.x = %d\n", origin.x);
    }

    {
        Point origin = {3, 4};
        Shape_setOrigin((_Shape) circle, origin);
        printf("circle.origin.x = %d\n", origin.x);
    }

    printf("circle.area() = %d\n", Shape_area((Shape) circle));
    printf("rectangle.area() = %d\n", Shape_area((Shape) rectangle));

    for (_UInt8 i = 0; i < 2; i++)
    {
        printf("shapes[%d].area() = %d\n", i, Shape_area(shapes[i]));
        printf("shapes[%d].objectSize() = %d\n", i, CObject_objectSize((CObject) shapes[i]));
    }

    drop_Circle((__Circle) circle);
    drop_Rectangle((__Rectangle) rectangle);
}
