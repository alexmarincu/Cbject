/****************************************************************************** tag::DocOverview[]
== Cbject

[plantuml, target=CbjectDiagram, format=png]
....
hide circle
class CbjectType {
    max_align a - alignment enforcer
    ..
    char * name - type name
    ..
    CbjectVirtFuns vf - struct containing pointers to functions
}

class Cbject {
    max_align a - alignment enforcer
    ..
    CbjectType t - pointer to the type struct
}

class CustomClass {
    Cbject s - embedded super class
    ..
    CustomClassData d - struct containing the object fields
}

Cbject::type -> CbjectType::a
CustomClass -[hidden]u-> Cbject
....

******************************************************************************* end::DocOverview[] */
#ifndef CBJECT_H
#define CBJECT_H
#include "Cbject_Keywords.h"
#include "Cbject_PrimitiveTypes.h"
#include "Cbject_Settings.h"
#include "Cbject_StaticAssert.h"
#include <assert.h>

#define Cbject_isTypeOf(me, typeName) \
    (Cbject_type((Cbject *) (me)) == (CbjectType *) typeName##Type_instance())

typedef struct CbjectType CbjectType;
typedef struct Cbject Cbject;

typedef struct CbjectVirtFuns
{
    uint8 (*size)(Cbject const * const me);
} CbjectVirtFuns;

typedef union CbjectTypeContainer
{
    Cbject_Settings_maxAlign a;
    char c[sizeof(struct
        {
            Cbject_Settings_maxAlign a;
            char const * name;
            CbjectVirtFuns vf;
        })];
} CbjectTypeContainer;

typedef union CbjectContainer
{
    Cbject_Settings_maxAlign a;
    char c[sizeof(struct
        {
            Cbject_Settings_maxAlign a;
            CbjectType * t;
        })];
} CbjectContainer;

CbjectType const * const CbjectType_instance();
void Cbject_init(Cbject * const me);
void Cbject_terminate(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
CbjectType const * Cbject_type(Cbject * const me);

#endif // CBJECT_H
