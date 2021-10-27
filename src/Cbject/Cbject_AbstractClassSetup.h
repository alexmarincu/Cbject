#ifndef CBJECT_ABSTRACTCLASSSETUP_H
#define CBJECT_ABSTRACTCLASSSETUP_H
#include "Cbject_CastToSuperImpl.h"
#include "Cbject_CbjectTypeVirtFunsGetImpl.h"
#include "Cbject_SizeImpl.h"
#include "Cbject_TypeDef.h"
#include "Cbject_TypeInstanceImpl.h"
#include "Cbject_TypeTypeDef.h"
#include "Cbject_Utils.h"
#include "Cbject_VirtFunCalls.h"

#define Cbject_AbstractClassSetup(typeName, parent, virtFunCalls, bindSuperFuns)             \
    Cbject_TypeTypeDef(typeName, parent, withVirtFuns);                                      \
    Cbject_TypeDef(typeName, parent);                                                        \
    Cbject_SizeImpl(typeName);                                                               \
    Cbject_TypeInstanceImpl(typeName, parent, Cbject_Utils_stripParentheses(bindSuperFuns)); \
    Cbject_CastToSuperImpl(typeName, parent);                                                \
    Cbject_CastImpl(typeName);                                                               \
    Cbject_CbjectTypeVirtFunsGetImpl(typeName);                                              \
    Cbject_VirtFunCalls(Cbject_Utils_stripParentheses(virtFunCalls))

#endif // CBJECT_ABSTRACTCLASSSETUP_H
