#ifndef CBJECT_H
#define CBJECT_H
#include "_Cbject/_CbjectKeywords.h"
// #include <stddef.h>

typedef struct Cbject Cbject;

typedef struct CbjectKlassVirtualFunctions
{
    uint8 (*size)(Cbject const * const me);
} CbjectKlassVirtualFunctions;

typedef struct CbjectKlass
{
    char const * type;
    CbjectKlassVirtualFunctions vf;
} CbjectKlass;

typedef char CbjectParams;

typedef struct CbjectProperties
{
    CbjectSettings_maxAlign a;
} CbjectProperties;

typedef union _Cbject
{
    char d[sizeof(struct { CbjectKlass * k; CbjectProperties p; })];
    CbjectSettings_maxAlign a;
} _Cbject;

CbjectKlass const * const CbjectKlass_instance();
void Cbject_ctor(Cbject * const me, CbjectParams const * const params);
void Cbject_dtor(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
char const * Cbject_type(Cbject const * const me);
void Cbject_klassSet(Cbject * const me, CbjectKlass const * const k);
CbjectKlass const * Cbject_klass(Cbject * const me);

#endif // CBJECT_H
