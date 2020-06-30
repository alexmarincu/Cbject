#include "ShapeSuper.h"
#include <stdio.h>

default_set(Point, origin);
default_get(Point, origin);

default_fun(_UInt32, area)
{
    (Void) me;
    return 0;
}

default_fun(Void, draw)
{
    (Void) me;
    printf("Shape draw\n");
}

abstract_class_init()
{
    CObject_init((_CObject) me);

    _Boolean isVtSetupDone = false;

    if (isVtSetupDone)
    {
        isVtSetupDone = true;

        static _ShapeVT vT;
        vT.super = *(((CObject) me)->vT);
        vT.super.objectSize = (_UInt8(ptr)(CObject me)) override_CObject_objectSize;
        vT.area = super_Shape_area;
        vT.draw = super_Shape_draw;
        ((_CObject) me)->vT = (CObjectVT ptr) &vT;
    }

    /*
    bind_virtual_functions(
        super_Shape_area,
        super_Shape_draw);
*/
    me->origin = params->origin;
}
