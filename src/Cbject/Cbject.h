#ifndef CBJECT_H
#define CBJECT_H
#include "Cbject_Keywords.h"
#include "Cbject_PrimitiveTypes.h"
#include "Cbject_Settings.h"
#include "Cbject_StaticAssert.h"
#include <assert.h>

#define Cbject_isTypeOf(me, cbjType) \
    (Cbject_type((Cbject *) (me)) == (CbjectType *) cbjType##Type_())

typedef struct CbjectType CbjectType;
typedef struct Cbject Cbject;
typedef char CbjectParams;
typedef char CbjectProps;

typedef struct CbjectVirtFuns
{
    uint8 (*size)(Cbject const * const me);
} CbjectVirtFuns;

typedef union ___CbjectType
{
    Cbject_Settings_maxAlign ___align;
    char ___data[sizeof(struct
        {
            Cbject_Settings_maxAlign ___align;
            char const * name;
            CbjectVirtFuns virtFuns;
        })];
} ___CbjectType;

typedef union ___Cbject
{
    Cbject_Settings_maxAlign ___align;
    char ___data[sizeof(struct
        {
            Cbject_Settings_maxAlign ___align;
            CbjectType * type;
            CbjectProps props;
        })];
} ___Cbject;

CbjectType const * const CbjectType_();
void ___Cbject_init(Cbject * const me, CbjectParams const * const params);
uint8 Cbject_size(Cbject const * const me);
CbjectType const * Cbject_type(Cbject * const me);

#endif // CBJECT_H
