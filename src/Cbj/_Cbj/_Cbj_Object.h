#ifndef _CBJ_OBJECT_H
#define _CBJ_OBJECT_H
#include "_Cbj_ContainerTypeDef.h"
#include "_Cbj_InitFunPrototype.h"
#include "_Cbj_ObjectInstanceFunPrototype.h"
#include "_Cbj_ParamsTypeDef.h"
#include "_Cbj_PropsTypeDef.h"
#include "_Cbj_TerminateFunPrototype.h"
#include "_Cbj_TypeDecl.h"
#include "_Cbj_Utils.h"

#define _Cbj_Object(cbjType, parent, props)                         \
    _Cbj_PropsTypeDef(cbjType, _Cbj_Utils_stripParentheses(props)); \
    _Cbj_ParamsTypeDef(cbjType, 0);                                 \
    _Cbj_TypeDecl(cbjType);                                         \
    _Cbj_ContainerTypeDef(cbjType, parent);                         \
    _Cbj_InitFunPrototype(cbjType);                                 \
    _Cbj_TerminateFunPrototype(cbjType);                            \
    _Cbj_ObjectInstanceFunPrototype(cbjType)

#endif // _CBJ_OBJECT_H
