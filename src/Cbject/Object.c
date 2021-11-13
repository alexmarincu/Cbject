#include "Object.h"

static uint8 superObject_size(Object const * const me);

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

static uint8 superObject_size(Object const * const me) { return sizeof(*me); }
uint8 Object_size(Object const * const me) { return me->type->virtFuns.size(me); }

ObjectType const * ObjectType_instance()
{
    static ObjectType type = {
        .name = "Object",
        .superType = NULL,
        .virtFuns = {.size = superObject_size}};

    return &type;
}

ObjectType const * Object_type(Object * const me) { return me->type; }
void Object_init(Object * const me, ObjectParams const * const params) {}
void Object_terminate(Object * const me) {}
Object * Object_toObject(Object * const me) { return me; }
char const * Object_typeName(Object const * const me) { return me->type->name; }
