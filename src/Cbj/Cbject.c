#include "Cbject.h"

static uint8 s_Cbject_size(Cbject const * const me);

struct Cbject
{
    CbjectType const * t;
    CbjectProps p;
};

static uint8 s_Cbject_size(Cbject const * const me) { return sizeof(*me); }
uint8 Cbject_size(Cbject const * const me) { return me->t->vf.size(me); }

CbjectType const * const CbjectType_instance()
{
    static CbjectType const t = {
        .name = "Cbject",
        .vf = {.size = s_Cbject_size}};

    return &t;
}

void Cbject_typeSet(Cbject * const me, CbjectType const * const t)
{
    if (me->t == NULL) { me->t = t; }
}

CbjectType const * Cbject_type(Cbject * const me) { return me->t; }
void Cbject_init(Cbject * const me, CbjectParams const * const params) {}
void Cbject_terminate(Cbject * const me) {}
