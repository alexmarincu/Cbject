#ifndef CBJECT_ABSTRACTCLASS_H
#define CBJECT_ABSTRACTCLASS_H
#include "Cbject_CastToSuperFunPrototype.h"
#include "Cbject_CbjectTypeVirtFunsGetFunPrototype.h"
#include "Cbject_ContainerTypeDef.h"
#include "Cbject_InitFunPrototype.h"
#include "Cbject_ParamsTypeDef.h"
#include "Cbject_PropsTypeDef.h"
#include "Cbject_TypeContainerTypeDef.h"
#include "Cbject_TypeDecl.h"
#include "Cbject_TypeInstanceFunPrototype.h"
#include "Cbject_TypeTypeDecl.h"
#include "Cbject_Utils.h"
#include "Cbject_VirtFunsTypeDef.h"

#define Cbject_AbstractClass(cbjType, parent, params, props, virtFuns)        \
    Cbject_TypeTypeDecl(cbjType);                                             \
    Cbject_TypeDecl(cbjType);                                                 \
    Cbject_ParamsTypeDef(cbjType, Cbject_Utils_stripParentheses(params));     \
    Cbject_PropsTypeDef(cbjType, Cbject_Utils_stripParentheses(props));       \
    Cbject_VirtFunsTypeDef(cbjType, Cbject_Utils_stripParentheses(virtFuns)); \
    Cbject_TypeContainerTypeDef(cbjType, parent, withVirtFuns);               \
    Cbject_ContainerTypeDef(cbjType, parent);                                 \
    Cbject_InitFunPrototype(cbjType);                                         \
    Cbject_TypeInstanceFunPrototype(cbjType);                                 \
    Funs(Cbject_Utils_stripParentheses(virtFuns));                            \
    Cbject_CastToSuperFunPrototype(cbjType, parent);                          \
    Cbject_CbjectTypeVirtFunsGetFunPrototype(cbjType)

#endif // CBJECT_ABSTRACTCLASS_H
