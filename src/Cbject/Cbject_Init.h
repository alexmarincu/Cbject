#ifndef CBJECT_INIT_H
#define CBJECT_INIT_H
#include "Cbject_InitFun.h"

#define Cbject_Init(typeName, superTypeName) \
    Cbject_InitFun_Impl(typeName, superTypeName)

#endif // CBJECT_INIT_H
