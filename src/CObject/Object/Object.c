#include "Object.h"

static uint8 superObject_size(Object const * const me);

union Object
{
    struct
    {
        ObjectClass const * c;
    } s;

    maxAlign a;
};

static uint8 superObject_size(Object const * const me) { return sizeof(*me); }
uint8 Object_size(Object const * const me) { return me->s.c->vf.size(me); }
char const * Object_type(Object const * const me) { return me->s.c->type; }

ct_assert(ObjectClass_sizes == sizeof(Object), ObjectClassSizeVerification);
ct_assert(sizeof(ObjectShell) == sizeof(Object), ObjectShellVerification);

ObjectClass const * const ObjectClass_instance()
{
    static ObjectClass const c = {
        .type = "Object",
        .vf = {.size = superObject_size}};

    return &c;
} 

void Object_classSet(Object * const me, ObjectClass const * const c) 
{ 
me->s.c = c;
 }

void Object_init(Object * const me, ObjectParams const * const params) { Object_classSet(me, ObjectClass_instance()); }
void Object_terminate(Object * const me) {}
