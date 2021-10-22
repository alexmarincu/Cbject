#ifndef CBJECT_VIRTFUNIMPL_H
#define CBJECT_VIRTFUNIMPL_H
#include "Cbject_Utils.h"
#include "Cbject_VirtFunCall.h"

#define Cbject_VirtFunImpl(cbjType, returnType, funName, args, params) \
    Fun(returnType, funName, args) { Cbject_VirtFunCall(cbjType, funName, Cbject_Utils_stripParentheses(params)); }

#endif // CBJECT_VIRTFUNIMPL_H
