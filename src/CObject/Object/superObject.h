#ifndef SUPEROBJECT_H
#define SUPEROBJECT_H
#include "Object.h"

typedef struct ObjectClass
{
    char const * type;

    struct
    {
        uint8 (*size)(Object const * const me);
    } vf;
} ObjectClass;

struct Object
{
    ObjectClass const * c;
};

ObjectClass const * const ObjectClass_instance();
uint8 superObject_size(Object const * const me);

#endif // SUPEROBJECT_H
