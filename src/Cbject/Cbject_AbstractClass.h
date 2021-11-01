#ifndef CBJECT_ABSTRACTCLASS_H
#define CBJECT_ABSTRACTCLASS_H
#include "Cbject_CastFun.h"
#include "Cbject_ContainerTypeDef.h"
#include "Cbject_DataTypeDef.h"
#include "Cbject_Funs.h"
#include "Cbject_InitFun.h"
#include "Cbject_ParamsTypeDef.h"
#include "Cbject_SizeImpl.h"
#include "Cbject_TerminateFunPrototype.h"
#include "Cbject_TypeContainerTypeDef.h"
#include "Cbject_TypeDecl.h"
#include "Cbject_TypeDef.h"
#include "Cbject_TypeInstanceFunPrototype.h"
#include "Cbject_TypeInstanceImpl.h"
#include "Cbject_TypeTypeDecl.h"
#include "Cbject_TypeTypeDef.h"
#include "Cbject_Utils.h"
#include "Cbject_VirtFunCalls.h"
#include "Cbject_VirtFunsGetter.h"
#include "Cbject_VirtFunsTypeDef.h"

#define Cbject_AbstractClass(typeName, parent, params, data, virtFuns)         \
    Cbject_TypeTypeDecl(typeName);                                             \
    Cbject_TypeDecl(typeName);                                                 \
    Cbject_ParamsTypeDef(typeName, Cbject_Utils_stripParentheses(params));     \
    Cbject_DataTypeDef(typeName, Cbject_Utils_stripParentheses(data));         \
    Cbject_VirtFunsTypeDef(typeName, Cbject_Utils_stripParentheses(virtFuns)); \
    Cbject_TypeContainerTypeDef(typeName, parent, withVirtFuns);               \
    Cbject_ContainerTypeDef(typeName, parent);                                 \
    Cbject_InitFun_Prototype(typeName);                                        \
    Cbject_TerminateFunPrototype(typeName);                                    \
    Cbject_TypeInstanceFunPrototype(typeName);                                 \
    Cbject_Funs(Cbject_Utils_stripParentheses(virtFuns));                      \
    Cbject_CastFun_Prototype(typeName);                                        \
    Cbject_VirtFunsGetter_Prototype(typeName)

#define Cbject_AbstractClass_Setup(typeName, parent, virtFunCalls, bindFuns)            \
    Cbject_TypeTypeDef(typeName, parent, withVirtFuns);                                 \
    Cbject_TypeDef(typeName, parent);                                                   \
    Cbject_SizeImpl(typeName);                                                          \
    Cbject_TypeInstanceImpl(typeName, parent, Cbject_Utils_stripParentheses(bindFuns)); \
    Cbject_CastFun_Impl(typeName);                                                      \
    Cbject_VirtFunsGetter_Impl(typeName);                                               \
    Cbject_VirtFunCalls(Cbject_Utils_stripParentheses(virtFunCalls))

#endif // CBJECT_ABSTRACTCLASS_H
