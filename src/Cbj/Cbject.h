#ifndef CBJECT_H
#define CBJECT_H
#include "Cbj_PrimitiveTypes.h"
#include "Cbj_Settings.h"

typedef struct Cbject Cbject;

typedef struct CbjectVirtFuns
{
    uint8 (*size)(Cbject const * const me);
} CbjectVirtFuns;

typedef struct CbjectClass
{
    char const * type;
    CbjectVirtFuns vf;
} CbjectClass;

typedef char CbjectParams;

typedef struct CbjectProps
{
    Cbj_Settings_maxAlign a;
} CbjectProps;

typedef union _Cbject
{
    char d[sizeof(struct { CbjectClass * c; CbjectProps p; })];
    Cbj_Settings_maxAlign a;
} _Cbject;

CbjectClass const * const CbjectClass_instance();
void Cbject_init(Cbject * const me, CbjectParams const * const params);
void Cbject_terminate(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
char const * Cbject_type(Cbject const * const me);
void Cbject_classSet(Cbject * const me, CbjectClass const * const c);
CbjectClass const * Cbject_class(Cbject * const me);

#endif // CBJECT_H
