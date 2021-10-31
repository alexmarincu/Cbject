#ifndef CBJECT_ABSTRACTCLASSSETUP_H
#define CBJECT_ABSTRACTCLASSSETUP_H
#include "Cbject_CastFun.h"
#include "Cbject_CbjectTypeVirtFunsGetImpl.h"
#include "Cbject_SizeImpl.h"
#include "Cbject_TypeDef.h"
#include "Cbject_TypeInstanceImpl.h"
#include "Cbject_TypeTypeDef.h"
#include "Cbject_Utils.h"
#include "Cbject_VirtFunCalls.h"

#define Cbject_AbstractClassSetup(typeName, parent, virtFunCalls, bindFuns)             \
    Cbject_TypeTypeDef(typeName, parent, withVirtFuns);                                 \
    Cbject_TypeDef(typeName, parent);                                                   \
    Cbject_SizeImpl(typeName);                                                          \
    Cbject_TypeInstanceImpl(typeName, parent, Cbject_Utils_stripParentheses(bindFuns)); \
    Cbject_CastFun_Impl(typeName);                                                      \
    Cbject_CbjectTypeVirtFunsGetImpl(typeName);                                         \
    Cbject_VirtFunCalls(Cbject_Utils_stripParentheses(virtFunCalls))

#endif // CBJECT_ABSTRACTCLASSSETUP_H
