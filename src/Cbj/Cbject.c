#include "Cbject.h"

static uint8 s_Cbject_size(Cbject const * const me);

struct CbjectType
{
    Cbj_Settings_maxAlign x_align;
    char const * name;
    CbjectVirtFuns virtFuns;
};

struct Cbject
{
    Cbj_Settings_maxAlign x_align;
    CbjectType * type;
    CbjectProps props;
};

static uint8 s_Cbject_size(Cbject const * const me) { return sizeof(*me); }
uint8 Cbject_size(Cbject const * const me) { return me->type->virtFuns.size(me); }

CbjectType const * const CbjectType_instance()
{
    static CbjectType type = {
        .name = "Cbject",
        .virtFuns = {.size = s_Cbject_size}};

    return &type;
}

// void Cbject_typeSet(Cbject * const me, CbjectType * const type)
// {
//     if (me->type == NULL) { me->type = type; }
// }

CbjectType const * Cbject_type(Cbject * const me) { return me->type; }
void Cbject_init(Cbject * const me, CbjectParams const * const params) {}
void Cbject_terminate(Cbject * const me) {}
/*
CbjectVirtFuns * CbjectType_virtFuns(CbjectType * meType)
{
    CbjectVirtFuns * virtFuns = NULL;

    if (meType->name == NULL)
    {
        virtFuns = &meType->virtFuns;
    }

    return virtFuns;
}*/

// char const * const CbjectType_name(CbjectType const * const meType) { return meType->name; }
// void CbjectType_nameSet(CbjectType * const meType, char const * const name)
// {
//     if (meType->name == NULL) { meType->name = name; }
// }
