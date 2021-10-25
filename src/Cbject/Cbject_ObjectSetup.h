#ifndef CBJECT_OBJECTSETUP_H
#define CBJECT_OBJECTSETUP_H
#include "Cbject_ObjectInstanceImpl.h"
#include "Cbject_SizeImpl.h"
#include "Cbject_TypeDef.h"
#include "Cbject_TypeInstanceFunPrototype.h"
#include "Cbject_TypeInstanceImpl.h"
#include "Cbject_TypeTypeDef.h"
#include "Cbject_Utils.h"

#define Cbject_ObjectSetup(typeName, parent, bindSuperFuns) \
    Cbject_TypeTypeDef(typeName, parent, withoutVirtFuns);  \
    Cbject_TypeDef(typeName, parent);                       \
    Cbject_TypeInstanceFunPrototype(typeName);              \
    Cbject_ObjectInstanceImpl(typeName);                    \
    Cbject_SizeImpl(typeName);                              \
    Cbject_TypeInstanceImpl(typeName, parent, Cbject_Utils_stripParentheses(bindSuperFuns))

#endif // CBJECT_OBJECTSETUP_H
