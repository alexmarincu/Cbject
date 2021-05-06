#include "Cbject.h"

static uint8 sCbject_size(Cbject const * const me);

struct Cbject
{
    CbjectClass const * k;
    CbjectProperties p;
};

static uint8 sCbject_size(Cbject const * const me) { return sizeof(*me); }
uint8 Cbject_size(Cbject const * const me) { return me->k->vf.size(me); }
char const * Cbject_type(Cbject const * const me) { return me->k->type; }

CbjectClass const * const CbjectClass_instance()
{
    static CbjectClass const k = {
        .type = "Cbject",
        .vf = {.size = sCbject_size}};

    return &k;
}

void Cbject_CbjectTypeSet(Cbject * const me, CbjectClass const * const k) { me->k = k; }
CbjectClass const * Cbject_CbjectType(Cbject * const me) { return me->k; }
void Cbject_init(Cbject * const me, CbjectParams const * const params) { Cbject_CbjectTypeSet(me, CbjectClass_instance()); }
void Cbject_terminate(Cbject * const me) {}
