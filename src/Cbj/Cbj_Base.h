#ifndef CBJ_BASE_H
#define CBJ_BASE_H
#include "Cbj_PrimitiveTypes.h"
#include "Cbj_Settings.h"

typedef struct Cbj_Base Cbj_Base;

typedef struct Cbj_BaseVirtFuns
{
    uint8 (*size)(Cbj_Base const * const me);
} Cbj_BaseVirtFuns;

typedef struct Cbj_BaseClass
{
    char const * type;
    Cbj_BaseVirtFuns vf;
} Cbj_BaseClass;

typedef char Cbj_BaseParams;

typedef struct Cbj_BaseProps
{
    Cbj_Settings_maxAlign a;
} Cbj_BaseProps;

typedef union _Cbj_Base
{
    char d[sizeof(struct { Cbj_BaseClass * c; Cbj_BaseProps p; })];
    Cbj_Settings_maxAlign a;
} _Cbj_Base;

Cbj_BaseClass const * const Cbj_BaseClass_instance();
void Cbj_Base_init(Cbj_Base * const me, Cbj_BaseParams const * const params);
void Cbj_Base_terminate(Cbj_Base * const me);
uint8 Cbj_Base_size(Cbj_Base const * const me);
char const * Cbj_Base_type(Cbj_Base const * const me);
void Cbj_Base_classSet(Cbj_Base * const me, Cbj_BaseClass const * const c);
Cbj_BaseClass const * Cbj_Base_class(Cbj_Base * const me);

#endif // CBJ_BASE_H
