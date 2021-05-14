#ifndef CBJECT_H
#define CBJECT_H
#include "Cbj_PrimitiveTypes.h"
#include "Cbj_Settings.h"

typedef struct CbjectType CbjectType;
typedef struct Cbject Cbject;
typedef char CbjectParams;
typedef char CbjectProps;

typedef struct CbjectVirtFuns
{
    uint8 (*size)(Cbject const * const me);
} CbjectVirtFuns;

typedef union _CbjectType
{
    Cbj_Settings_maxAlign x_align;
    char x_data[sizeof(struct { Cbj_Settings_maxAlign x_align; char const * name; CbjectVirtFuns virtFuns; })];
} _CbjectType;

typedef union _Cbject
{
    Cbj_Settings_maxAlign x_align;
    char x_data[sizeof(struct { Cbj_Settings_maxAlign x_align; CbjectType * type; CbjectProps props; })];
} _Cbject;

CbjectType const * const CbjectType_instance();
void Cbject_init(Cbject * const me, CbjectParams const * const params);
void Cbject_terminate(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
// void Cbject_typeSet(Cbject * const me, CbjectType * const type);
CbjectType const * Cbject_type(Cbject * const me);
// CbjectVirtFuns * CbjectType_virtFuns(CbjectType * meType);
// void CbjectType_nameSet(CbjectType * const meType, char const * const name);
// char const * const CbjectType_name(CbjectType const * const meType);

#endif // CBJECT_H
