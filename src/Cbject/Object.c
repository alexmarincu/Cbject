#include "Object.h"

static uint8 Object_s_size(Object const * const me);

struct ObjectType
{
    Cbject_Settings_maxAlign a;
    char const * name;
    ObjectType * st;
    ObjectVirtFuns vf;
};

struct Object
{
    Cbject_Settings_maxAlign a;
    ObjectType * t;
};

static uint8 Object_s_size(Object const * const me) { return sizeof(*me); }
uint8 Object_size(Object const * const me) { return me->t->vf.size(me); }

ObjectType const * const ObjectType_instance()
{
    static ObjectType t = {
        .name = "Object",
        .st = NULL,
        .vf = {.size = Object_s_size}};

    return &t;
}

ObjectType const * Object_type(Object * const me) { return me->t; }
void Object_init(Object * const me, ObjectParams const p) {}
void Object_terminate(Object * const me) {}
