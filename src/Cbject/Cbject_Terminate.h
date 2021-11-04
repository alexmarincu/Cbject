#ifndef CBJECT_TERMINATE_H
#define CBJECT_TERMINATE_H
#include "Cbject_TerminateFunImpl.h"

#define Cbject_Terminate(typeName, superTypeName) \
    Cbject_TerminateFunImpl(typeName, superTypeName)

#endif // CBJECT_TERMINATE_H
