#ifndef OBJECT_H
#define OBJECT_H
#include "CbjectKeywords.h"
// #include <stddef.h>

typedef union Cbject Cbject;
typedef struct CbjectClass
{
    char const * type;

    struct
    {
        uint8 (*size)(Cbject const * const me);
    } vf;
} CbjectClass;


typedef union CbjectShell 
{
    char d[sizeof(struct{CbjectClass * c;})];
    maxAlign a;
} CbjectShell;

enum{CbjectClass_sizes = sizeof(CbjectShell)};
typedef struct CbjectParams
{
} CbjectParams;

CbjectClass const * const CbjectClass_instance();
void Cbject_init(Cbject * const me, CbjectParams const * const params);
void Cbject_terminate(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
char const * Cbject_type(Cbject const * const me);
void Cbject_classSet(Cbject * const me, CbjectClass const * const c);
CbjectClass const * Cbject_class(Cbject * const me);

#endif // OBJECT_H
