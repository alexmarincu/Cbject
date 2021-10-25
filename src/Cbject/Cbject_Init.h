#ifndef CBJECT_INIT_H
#define CBJECT_INIT_H
#include "Cbject_InitImpl.h"

#define Cbject_Init(typeName, parent) \
    Cbject_InitImpl(typeName, parent)

#endif // CBJECT_INIT_H
