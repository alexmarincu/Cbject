#ifndef CBJECT_H
#define CBJECT_H
#include "CbjectKeywords.h"
// #include <stddef.h>

typedef struct Cbject Cbject;

typedef struct CbjectClassVirtualFunctions
{
    uint8 (*size)(Cbject const * const me);
} CbjectClassVirtualFunctions;

typedef struct CbjectClass
{
    char const * type;
    CbjectClassVirtualFunctions vf;
} CbjectClass;

typedef struct CbjectInitParams
{
} CbjectInitParams;

typedef struct CbjectMembers
{
    maxAlign a;
} CbjectMembers;

typedef union CbjectShell
{
    char d[sizeof(struct { CbjectClass * c; CbjectMembers m; })];
    maxAlign a;
} CbjectShell;

CbjectClass const * const CbjectClass_instance();
void Cbject_init(Cbject * const me, CbjectInitParams const * const params);
void Cbject_terminate(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
char const * Cbject_type(Cbject const * const me);
void Cbject_classSet(Cbject * const me, CbjectClass const * const c);
CbjectClass const * Cbject_class(Cbject * const me);

#endif // CBJECT_H
