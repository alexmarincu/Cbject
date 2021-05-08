#include "Cbj_Base.h"

static uint8 s_Cbj_Base_size(Cbj_Base const * const me);

struct Cbj_Base
{
    Cbj_BaseClass const * c;
    Cbj_BaseProps p;
};

static uint8 s_Cbj_Base_size(Cbj_Base const * const me) { return sizeof(*me); }
uint8 Cbj_Base_size(Cbj_Base const * const me) { return me->c->vf.size(me); }
char const * Cbj_Base_type(Cbj_Base const * const me) { return me->c->type; }

Cbj_BaseClass const * const Cbj_BaseClass_instance()
{
    static Cbj_BaseClass const c = {
        .type = "Cbj_Base",
        .vf = {.size = s_Cbj_Base_size}};

    return &c;
}

void Cbj_Base_classSet(Cbj_Base * const me, Cbj_BaseClass const * const c) { me->c = c; }
Cbj_BaseClass const * Cbj_Base_class(Cbj_Base * const me) { return me->c; }
void Cbj_Base_init(Cbj_Base * const me, Cbj_BaseParams const * const params) { Cbj_Base_classSet(me, Cbj_BaseClass_instance()); }
void Cbj_Base_terminate(Cbj_Base * const me) {}
