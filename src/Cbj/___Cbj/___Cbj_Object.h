#ifndef ___CBJ_OBJECT_H
#define ___CBJ_OBJECT_H
#include "___Cbj_ContainerTypeDef.h"
#include "___Cbj_InitFunPrototype.h"
#include "___Cbj_ObjectInstanceFunPrototype.h"
#include "___Cbj_ParamsTypeDef.h"
#include "___Cbj_PropsTypeDef.h"
#include "___Cbj_TerminateFunPrototype.h"
#include "___Cbj_TypeDecl.h"
#include "___Cbj_TypeTypeDecl.h"
#include "___Cbj_Utils.h"

#define ___Cbj_Object(cbjType, parent, props)                           \
    ___Cbj_TypeTypeDecl(cbjType);                                       \
    ___Cbj_TypeDecl(cbjType);                                           \
    ___Cbj_ParamsTypeDef(cbjType, 0);                                   \
    ___Cbj_PropsTypeDef(cbjType, ___Cbj_Utils_stripParentheses(props)); \
    ___Cbj_ContainerTypeDef(cbjType, parent);                           \
    ___Cbj_InitFunPrototype(cbjType);                                   \
    ___Cbj_TerminateFunPrototype(cbjType);                              \
    ___Cbj_ObjectInstanceFunPrototype(cbjType)

#endif // ___CBJ_OBJECT_H
