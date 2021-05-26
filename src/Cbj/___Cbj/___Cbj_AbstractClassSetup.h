#ifndef _CBJ_ABSTRACTCLASSSETUP_H
#define _CBJ_ABSTRACTCLASSSETUP_H
#include "___Cbj_CastToSuperImpl.h"
#include "___Cbj_CbjectTypeVirtFunsGetImpl.h"
#include "___Cbj_SizeImpl.h"
#include "___Cbj_TypeDef.h"
#include "___Cbj_TypeInstanceImpl.h"
#include "___Cbj_TypeTypeDef.h"
#include "___Cbj_Utils.h"
#include "___Cbj_VirtFunCalls.h"

#define ___Cbj_AbstractClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns)             \
    ___Cbj_TypeTypeDef(cbjType, parent, withVirtFuns);                                      \
    ___Cbj_TypeDef(cbjType, parent);                                                        \
    ___Cbj_SizeImpl(cbjType);                                                               \
    ___Cbj_TypeInstanceImpl(cbjType, parent, ___Cbj_Utils_stripParentheses(bindSuperFuns)); \
    ___Cbj_CastToSuperImpl(cbjType, parent);                                                \
    ___Cbj_CbjectTypeVirtFunsGetImpl(cbjType);                                              \
    ___Cbj_VirtFunCalls(___Cbj_Utils_stripParentheses(virtFunCalls))

#endif // _CBJ_ABSTRACTCLASSSETUP_H
