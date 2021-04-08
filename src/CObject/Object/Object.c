#include "superObject.h"

uint8 superObject_size(Object const * const me) { return sizeof(*me); }
uint8 Object_size(Object const * const me) { return me->c->vf.size(me); }
char const * Object_type(Object const * const me) { return me->c->type; }
ct_assert(ObjectClass_sizes == sizeof(Object), ObjectClassSizeVerification);

ObjectClass const * const ObjectClass_instance()
{
    static ObjectClass const c = {
        .type = "Object",
        .vf = {.size = superObject_size}};

    return &c;
}

void Object_init(Object * const me, ObjectParams const * const params) { me->c = ObjectClass_instance(); }
void Object_terminate(Object * const me) {}
