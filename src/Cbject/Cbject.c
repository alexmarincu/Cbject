#include "Cbject.h"

static uint8 superCbject_size(Cbject const * const me);

struct Cbject
{
    CbjectKlass const * c;
    CbjectProperties m;
};

static uint8 superCbject_size(Cbject const * const me) { return sizeof(*me); }
uint8 Cbject_size(Cbject const * const me) { return me->c->vf.size(me); }
char const * Cbject_type(Cbject const * const me) { return me->c->type; }

CbjectKlass const * const CbjectKlass_instance()
{
    static CbjectKlass const c = {
        .type = "Cbject",
        .vf = {.size = superCbject_size}};

    return &c;
}

void Cbject_klassSet(Cbject * const me, CbjectKlass const * const c) { me->c = c; }
CbjectKlass const * Cbject_klass(Cbject * const me) { return me->c; }
void Cbject_init(Cbject * const me, CbjectParams const * const params) { Cbject_klassSet(me, CbjectKlass_instance()); }
void Cbject_terminate(Cbject * const me) {}
