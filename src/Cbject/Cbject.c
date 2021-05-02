#include "Cbject.h"

static uint8 superCbject_size(Cbject const * const me);

struct Cbject
{
    CbjectKlass const * k;
    CbjectProperties p;
};

static uint8 superCbject_size(Cbject const * const me) { return sizeof(*me); }
uint8 Cbject_size(Cbject const * const me) { return me->k->vf.size(me); }
char const * Cbject_type(Cbject const * const me) { return me->k->type; }

CbjectKlass const * const CbjectKlass_instance()
{
    static CbjectKlass const k = {
        .type = "Cbject",
        .vf = {.size = superCbject_size}};

    return &k;
}

void Cbject_klassSet(Cbject * const me, CbjectKlass const * const k) { me->k = k; }
CbjectKlass const * Cbject_klass(Cbject * const me) { return me->k; }
void Cbject_init(Cbject * const me, CbjectParams const * const params) { Cbject_klassSet(me, CbjectKlass_instance()); }
void Cbject_terminate(Cbject * const me) {}
