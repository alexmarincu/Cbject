#include "Cbject.h"

static uint8 s_Cbject_size(Cbject const * const me);

struct Cbject
{
    CbjectClass const * c;
    CbjectProps p;
};

static uint8 s_Cbject_size(Cbject const * const me) { return sizeof(*me); }
uint8 Cbject_size(Cbject const * const me) { return me->c->vf.size(me); }
char const * Cbject_type(Cbject const * const me) { return me->c->type; }

CbjectClass const * const CbjectClass_instance()
{
    static CbjectClass const c = {
        .type = "Cbject",
        .vf = {.size = s_Cbject_size}};

    return &c;
}

void Cbject_classSet(Cbject * const me, CbjectClass const * const c) { me->c = c; }
CbjectClass const * Cbject_class(Cbject * const me) { return me->c; }
void Cbject_init(Cbject * const me, CbjectParams const * const params) { Cbject_classSet(me, CbjectClass_instance()); }
void Cbject_terminate(Cbject * const me) {}
