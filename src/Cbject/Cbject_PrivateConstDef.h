#ifndef CBJECT_PRIVATECONSTDEF_H
#define CBJECT_PRIVATECONSTDEF_H
#include "Cbject_ConstDef.h"

#define Cbject_PrivateConstDef(typeName, constType, constNameAndValue) \
    static Cbject_ConstDef(typeName, constType, constNameAndValue)

#endif // CBJECT_PRIVATECONSTDEF_H
