#ifndef ___CBJ_OBJECTSETUP_H
#define ___CBJ_OBJECTSETUP_H
#include "___Cbj_ObjectInstanceImpl.h"
#include "___Cbj_SizeImpl.h"
#include "___Cbj_TypeDef.h"
#include "___Cbj_TypeInstanceFunPrototype.h"
#include "___Cbj_TypeInstanceImpl.h"
#include "___Cbj_TypeTypeDef.h"
#include "___Cbj_Utils.h"

#define ___Cbj_ObjectSetup(cbjType, parent, bindSuperFuns) \
    ___Cbj_TypeTypeDef(cbjType, parent, withoutVirtFuns);  \
    ___Cbj_TypeDef(cbjType, parent);                       \
    ___Cbj_TypeInstanceFunPrototype(cbjType);              \
    ___Cbj_ObjectInstanceImpl(cbjType);                    \
    ___Cbj_SizeImpl(cbjType);                              \
    ___Cbj_TypeInstanceImpl(cbjType, parent, ___Cbj_Utils_stripParentheses(bindSuperFuns))

#endif // ___CBJ_OBJECTSETUP_H
