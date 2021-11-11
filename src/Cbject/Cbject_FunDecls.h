#ifndef CBJECT_FUNDECLS_H
#define CBJECT_FUNDECLS_H
#include "Cbject_Utils.h"

/*
Cbject_FunDecls
*/
#define Cbject_FunDecls_caseXFuns_funDecl_caseFinal(funPrototypePack) \
    Fun funPrototypePack;

#define Cbject_FunDecls_caseXFuns_funDecl_caseOverride(funPrototypePack) \
    FunOverride funPrototypePack;

#define Cbject_FunDecls_caseXFuns_funDecl_casePure(funPrototypePack) \
    Fun funPrototypePack;

#define Cbject_FunDecls_caseXFuns_funDecl_caseImpl(funPrototypePack) \
    Fun funPrototypePack;                                            \
    FunOverride funPrototypePack;

#define Cbject_FunDecls_caseXFuns_funDecl_x1(funPrototypePack, funType) \
    Cbject_FunDecls_caseXFuns_funDecl_case##funType(funPrototypePack)

#define Cbject_FunDecls_caseXFuns_funDecl_x0(...) \
    Cbject_FunDecls_caseXFuns_funDecl_x1(__VA_ARGS__)

#define Cbject_FunDecls_caseXFuns_funDecl(funPrototypeWithFunTypePack) \
    Cbject_FunDecls_caseXFuns_funDecl_x0(Cbject_Utils_unpack(funPrototypeWithFunTypePack))

#define Cbject_FunDecls_caseNA(...)

#define Cbject_FunDecls_caseFuns(...) \
    Cbject_Utils_forEach(Cbject_FunDecls_caseXFuns_funDecl, __VA_ARGS__)

#define Cbject_FunDecls_caseVirtFuns(...) \
    Cbject_Utils_forEach(Cbject_FunDecls_caseXFuns_funDecl, __VA_ARGS__)

#define Cbject_FunDecls_x1(case, ...) \
    Cbject_FunDecls_case##case (__VA_ARGS__)

#define Cbject_FunDecls_x0(...) \
    Cbject_FunDecls_x1(__VA_ARGS__)

#define Cbject_FunDecls(funsPack) \
    Cbject_FunDecls_x0(Cbject_Utils_unpack(funsPack))

#endif // CBJECT_FUNDECLS_H
