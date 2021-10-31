#ifndef CBJECT_OBJECT_H
#define CBJECT_OBJECT_H
#include "Cbject_ContainerTypeDef.h"
#include "Cbject_DataTypeDef.h"
#include "Cbject_InitFun.h"
#include "Cbject_ObjectInstanceFunPrototype.h"
#include "Cbject_ParamsTypeDef.h"
#include "Cbject_TerminateFunPrototype.h"
#include "Cbject_TypeDecl.h"
#include "Cbject_TypeTypeDecl.h"
#include "Cbject_Utils.h"

#define Cbject_Object(typeName, parent, data)                          \
    Cbject_TypeTypeDecl(typeName);                                     \
    Cbject_TypeDecl(typeName);                                         \
    Cbject_ParamsTypeDef(typeName, void);                              \
    Cbject_DataTypeDef(typeName, Cbject_Utils_stripParentheses(data)); \
    Cbject_ContainerTypeDef(typeName, parent);                         \
    Cbject_InitFun_Prototype(typeName);                                \
    Cbject_TerminateFunPrototype(typeName);                            \
    Cbject_ObjectInstanceFunPrototype(typeName)

#endif // CBJECT_OBJECT_H
