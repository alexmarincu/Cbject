#ifndef CBJECT_OBJECTSETUP_H
#define CBJECT_OBJECTSETUP_H
#include "Cbject_ObjectInstanceImpl.h"
#include "Cbject_SizeImpl.h"
#include "Cbject_TypeDef.h"
#include "Cbject_TypeInstanceFunPrototype.h"
#include "Cbject_TypeInstanceImpl.h"
#include "Cbject_TypeTypeDef.h"
#include "Cbject_Utils.h"

#define Cbject_ObjectSetup(cbjType, parent, bindSuperFuns) \
    Cbject_TypeTypeDef(cbjType, parent, withoutVirtFuns);  \
    Cbject_TypeDef(cbjType, parent);                       \
    Cbject_TypeInstanceFunPrototype(cbjType);              \
    Cbject_ObjectInstanceImpl(cbjType);                    \
    Cbject_SizeImpl(cbjType);                              \
    Cbject_TypeInstanceImpl(cbjType, parent, Cbject_Utils_stripParentheses(bindSuperFuns))

#endif // CBJECT_OBJECTSETUP_H
