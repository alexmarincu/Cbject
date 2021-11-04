#ifndef CBJECT_SINGLETON_H
#define CBJECT_SINGLETON_H
#include "Cbject_ContainerTypeDef.h"
#include "Cbject_DataTypeDef.h"
#include "Cbject_InitFun.h"
#include "Cbject_ObjectInstanceFunPrototype.h"
#include "Cbject_ObjectInstanceImpl.h"
#include "Cbject_ParamsTypeDef.h"
#include "Cbject_SizeImpl.h"
#include "Cbject_TerminateFunPrototype.h"
#include "Cbject_TypeDecl.h"
#include "Cbject_TypeDef.h"
#include "Cbject_TypeInstanceFunPrototype.h"
#include "Cbject_TypeInstanceImpl.h"
#include "Cbject_TypeTypeDecl.h"
#include "Cbject_TypeTypeDef.h"
#include "Cbject_Utils.h"

#define Cbject_Singleton(typeName, parent, data) \
    Cbject_TypeTypeDecl(typeName);               \
    Cbject_TypeDecl(typeName);                   \
    Cbject_ParamsTypeDef(typeName, ());          \
    Cbject_DataTypeDef(typeName, data);          \
    Cbject_ContainerTypeDef(typeName, parent);   \
    Cbject_InitFun_Prototype(typeName);          \
    Cbject_TerminateFunPrototype(typeName);      \
    Cbject_ObjectInstanceFunPrototype(typeName)

#define Cbject_Singleton_Setup(typeName, parent, bindFuns) \
    Cbject_TypeTypeDef(typeName, parent, withoutVirtFuns); \
    Cbject_TypeDef(typeName, parent);                      \
    Cbject_TypeInstanceFunPrototype(typeName);             \
    Cbject_ObjectInstanceImpl(typeName);                   \
    Cbject_SizeImpl(typeName);                             \
    Cbject_TypeInstanceImpl(typeName, parent, bindFuns)
#endif // CBJECT_SINGLETON_H
