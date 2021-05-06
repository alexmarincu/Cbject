#ifndef CBJECT_H
#define CBJECT_H
#include "_Cbject/_CbjectKeywords.h"
// #include <stddef.h>

typedef struct Cbject Cbject;

typedef struct CbjectClassVirtualFuns
{
    uint8 (*size)(Cbject const * const me);
} CbjectClassVirtualFuns;

typedef struct CbjectClass
{
    char const * type;
    CbjectClassVirtualFuns vf;
} CbjectClass;

typedef char CbjectParams;

typedef struct CbjectProperties
{
    CbjectSettings_maxAlign a;
} CbjectProperties;

typedef union _Cbject
{
    char d[sizeof(struct { CbjectClass * k; CbjectProperties p; })];
    CbjectSettings_maxAlign a;
} _Cbject;

CbjectClass const * const CbjectClass_instance();
void Cbject_init(Cbject * const me, CbjectParams const * const params);
void Cbject_terminate(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
char const * Cbject_type(Cbject const * const me);
void Cbject_CbjectTypeSet(Cbject * const me, CbjectClass const * const k);
CbjectClass const * Cbject_CbjectType(Cbject * const me);

#endif // CBJECT_H
