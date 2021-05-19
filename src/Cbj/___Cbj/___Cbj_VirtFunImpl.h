#ifndef ___CBJ_VIRTFUNIMPL_H
#define ___CBJ_VIRTFUNIMPL_H
#include "___Cbj_Utils.h"
#include "___Cbj_VirtFunCall.h"

#define ___Cbj_VirtFunImpl(cbjType, returnType, funName, args, params) \
    Fun(returnType, funName, args) { ___Cbj_VirtFunCall(cbjType, funName, ___Cbj_Utils_stripParentheses(params)); }

#endif // ___CBJ_VIRTFUNIMPL_H
