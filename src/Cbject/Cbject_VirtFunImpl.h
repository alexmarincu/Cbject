#ifndef CBJECT_VIRTFUNIMPL_H
#define CBJECT_VIRTFUNIMPL_H
#include "Cbject_Utils.h"
#include "Cbject_VirtFunCall.h"

#define Cbject_VirtFunImpl(className, funReturnType, funName, funParams, funCallParams) \
    Fun(funReturnType, funName, funParams) { Cbject_VirtFunCall(className, funName, funCallParams); }

#endif // CBJECT_VIRTFUNIMPL_H
