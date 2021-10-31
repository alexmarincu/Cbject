#ifndef CBJECT_TERMINATE_H
#define CBJECT_TERMINATE_H
#include "Cbject_TerminateFunImpl.h"

#define Cbject_Terminate(typeName, parent) \
    Cbject_TerminateFunImpl(typeName, parent)

#endif // CBJECT_TERMINATE_H
