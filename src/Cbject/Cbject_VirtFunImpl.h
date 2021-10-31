#ifndef CBJECT_VIRTFUNIMPL_H
#define CBJECT_VIRTFUNIMPL_H
#include "Cbject_Utils.h"
#include "Cbject_VirtFunCall.h"

#define Cbject_VirtFunImpl(typeName, returnType, funName, params, callParams) \
    Fun(returnType, funName, params) { Cbject_VirtFunCall(typeName, funName, Cbject_Utils_stripParentheses(callParams)); }

#endif // CBJECT_VIRTFUNIMPL_H
