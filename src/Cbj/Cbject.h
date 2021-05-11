#ifndef CBJECT_H
#define CBJECT_H
#include "Cbj_PrimitiveTypes.h"
#include "Cbj_Settings.h"

typedef struct Cbject Cbject;

typedef struct CbjectVirtFuns
{
    uint8 (*size)(Cbject const * const me);
} CbjectVirtFuns;

typedef struct CbjectType
{
    char const * name;
    CbjectVirtFuns vf;
} CbjectType;

typedef char CbjectParams;

typedef struct CbjectProps
{
    Cbj_Settings_maxAlign a;
} CbjectProps;

typedef union _Cbject
{
    Cbj_Settings_maxAlign a;
    char d[sizeof(struct { CbjectType * t; CbjectProps p; })];
} _Cbject;

CbjectType const * const CbjectType_instance();
void Cbject_init(Cbject * const me, CbjectParams const * const params);
void Cbject_terminate(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
void Cbject_typeSet(Cbject * const me, CbjectType const * const t);
CbjectType const * Cbject_type(Cbject * const me);

#endif // CBJECT_H
