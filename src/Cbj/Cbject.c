#include "Cbject.h"

static uint8 super_Cbject_size(Cbject const * const me);

struct CbjectType
{
    Cbj_Settings_maxAlign ___align;
    char const * name;
    CbjectVirtFuns virtFuns;
};

struct Cbject
{
    Cbj_Settings_maxAlign ___align;
    CbjectType * type;
    CbjectProps props;
};

static uint8 super_Cbject_size(Cbject const * const me) { return sizeof(*me); }
uint8 Cbject_size(Cbject const * const me) { return me->type->virtFuns.size(me); }

CbjectType const * const CbjectType_()
{
    static CbjectType type = {
        .name = "Cbject",
        .virtFuns = {.size = super_Cbject_size}};

    return &type;
}

CbjectType const * Cbject_type(Cbject * const me) { return me->type; }
void ___Cbject_init(Cbject * const me, CbjectParams const * const params) {}
void ___Cbject_terminate(Cbject * const me) {}
