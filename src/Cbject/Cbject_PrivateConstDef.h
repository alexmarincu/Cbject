#ifndef CBJECT_PRIVATECONSTDEF_H
#define CBJECT_PRIVATECONSTDEF_H
#include "Cbject_ConstDef.h"

#define Cbject_PrivateConstDef(cbjType, constType, constNameAndValue) \
    static Cbject_ConstDef(cbjType, constType, constNameAndValue)

#endif // CBJECT_PRIVATECONSTDEF_H
