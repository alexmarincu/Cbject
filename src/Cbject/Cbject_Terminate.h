#ifndef CBJECT_TERMINATE_H
#define CBJECT_TERMINATE_H
#include "Cbject_TerminateFunImpl.h"

#define Cbject_Terminate(cbjType, parent) \
    Cbject_TerminateFunImpl(cbjType, parent)

#endif // CBJECT_TERMINATE_H
