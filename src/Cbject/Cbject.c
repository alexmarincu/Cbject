#include "Cbject.h"

static uint8 super_Cbject_size(Cbject const * const me);

struct CbjectType
{
    Cbject_Settings_maxAlign a;
    char const * name;
    CbjectTypeId id;
    CbjectType * s;
    CbjectVirtFuns vf;
};

struct Cbject
{
    Cbject_Settings_maxAlign a;
    CbjectType * t;
};

static uint8 super_Cbject_size(Cbject const * const me) { return sizeof(*me); }
uint8 Cbject_size(Cbject const * const me) { return me->t->vf.size(me); }

CbjectType const * const CbjectType_instance()
{
    static CbjectType type = {
        .name = "Cbject",
        .id = CbjectTypeId_Cbject,
        .s = NULL,
        .vf = {.size = super_Cbject_size}};

    return &type;
}

CbjectType const * Cbject_type(Cbject * const me) { return me->t; }
void Cbject_init(Cbject * const me, CbjectParams const params) {}
void Cbject_terminate(Cbject * const me) {}
