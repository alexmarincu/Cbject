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

#define Cbject_AbstractClassSetup(cbjType, parent, virtFunCalls, bindSuperFuns)             \
    Cbject_TypeTypeDef(cbjType, parent, withVirtFuns);                                      \
    Cbject_TypeDef(cbjType, parent);                                                        \
    Cbject_SizeImpl(cbjType);                                                               \
    Cbject_TypeInstanceImpl(cbjType, parent, Cbject_Utils_stripParentheses(bindSuperFuns)); \
    Cbject_CastToSuperImpl(cbjType, parent);                                                \
    Cbject_CbjectTypeVirtFunsGetImpl(cbjType);                                              \
    Cbject_VirtFunCalls(Cbject_Utils_stripParentheses(virtFunCalls))

#endif // CBJECT_ABSTRACTCLASSSETUP_H
