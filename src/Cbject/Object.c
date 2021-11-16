#include "Object.h"

struct ObjectType
{
    Cbject_Settings_maxAlign align;
    uint64 size;
    char const * name;
    ObjectType * superType;
};

struct Object
{
    Cbject_Settings_maxAlign align;
    ObjectType * type;
};

uint8 Object_size(Object const * const me) { return me->type->size; }

ObjectType const * ObjectType_instance()
{
    static ObjectType type = {
        .size = sizeof(Object),
        .name = "Object",
        .superType = NULL};

    return &type;
}

ObjectType const * Object_type(Object * const me) { return me->type; }
void Object_init(Object * const me, ObjectParams const * const params) {}
void Object_terminate(Object * const me) {}
Object * Object_toObject(Object * const me) { return me; }
char const * Object_typeName(Object const * const me) { return me->type->name; }

bool Object_isTypeOf(Object const * const me, ObjectType const * const targetType)
{
    bool isTypeOf = true;
    Assert((me != NULL) && "NULL pointer in IsTypeOf");
    ObjectType const * type = (ObjectType *)me->type;
    Assert((type != NULL) && "IsTypeOf cannot be used if object is not initialized");

    while ((isTypeOf == true) && (type != targetType))
    {
        type = type->superType;

        if (type == NULL)
        {
            isTypeOf = false;
        }
    }

    return isTypeOf;
}