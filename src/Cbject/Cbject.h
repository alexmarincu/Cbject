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

#define Cbject_cast(me, typeName) \
    Cbject_to##typeName((Cbject *) me)

typedef struct CbjectType CbjectType;
typedef struct Cbject Cbject;
typedef char CbjectParams;

typedef enum CbjectTypeId
{
    CbjectTypeId_Cbject,
    CbjectTypeId_Application,
    CbjectTypeId_Circle,
    CbjectTypeId_ColoredCircle,
    CbjectTypeId_Shape,
    CbjectTypeId_Rectangle,
} CbjectTypeId;

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
            CbjectTypeId id;
            CbjectType * st;
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
void Cbject_init(Cbject * const me, CbjectParams const params);
void Cbject_terminate(Cbject * const me);
uint8 Cbject_size(Cbject const * const me);
CbjectType const * Cbject_type(Cbject * const me);

#endif // CBJECT_H
