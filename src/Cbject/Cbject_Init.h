#ifndef CBJECT_INIT_H
#define CBJECT_INIT_H
#include "Cbject_InitFun.h"

#define Cbject_Init(typeName, parent) \
    Cbject_InitFun_Impl(typeName, parent)

#endif // CBJECT_INIT_H
