#include "Object.h"

static UInt8 super_Object_size(Object const * const me);

struct ObjectType
{
    Cbject_Settings_maxAlign align;
    char const * name;
    ObjectType * superType;
    ObjectVirtFuns virtFuns;
};

struct Object
{
    Cbject_Settings_maxAlign align;
    ObjectType * type;
};

static UInt8 super_Object_size(Object const * const me) { return sizeof(*me); }
UInt8 Object_size(Object const * const me) { return me->type->virtFuns.size(me); }

ObjectType const * const ObjectType_instance()
{
    static ObjectType type = {
        .name = "Object",
        .superType = NULL,
        .virtFuns = {.size = super_Object_size}};

    return &type;
}

ObjectType const * Object_type(Object * const me) { return me->type; }
void Object_init(Object * const me, ObjectParams const params) {}
void Object_terminate(Object * const me) {}
