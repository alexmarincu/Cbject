#ifndef CBJECT_OBJECT_H
#define CBJECT_OBJECT_H
#include "Cbject_ContainerTypeDef.h"
#include "Cbject_InitFunPrototype.h"
#include "Cbject_ObjectInstanceFunPrototype.h"
#include "Cbject_ParamsTypeDef.h"
#include "Cbject_PropsTypeDef.h"
#include "Cbject_TerminateFunPrototype.h"
#include "Cbject_TypeDecl.h"
#include "Cbject_TypeTypeDecl.h"
#include "Cbject_Utils.h"

#define Cbject_Object(cbjType, parent, props)                           \
    Cbject_TypeTypeDecl(cbjType);                                       \
    Cbject_TypeDecl(cbjType);                                           \
    Cbject_ParamsTypeDef(cbjType, 0);                                   \
    Cbject_PropsTypeDef(cbjType, Cbject_Utils_stripParentheses(props)); \
    Cbject_ContainerTypeDef(cbjType, parent);                           \
    Cbject_InitFunPrototype(cbjType);                                   \
    Cbject_TerminateFunPrototype(cbjType);                              \
    Cbject_ObjectInstanceFunPrototype(cbjType)

#endif // CBJECT_OBJECT_H
