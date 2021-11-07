#ifndef CBJECT_FUNDECLS_H
#define CBJECT_FUNDECLS_H
#include "Cbject_Utils.h"

#define Cbject_FunDecls_caseXFuns_funDecl_caseFinal(funPrototype) \
    Fun funPrototype;

#define Cbject_FunDecls_caseXFuns_funDecl_caseOverride(funPrototype) \
    FunOverride funPrototype;

#define Cbject_FunDecls_caseXFuns_funDecl_casePure(funPrototype) \
    Fun funPrototype;

#define Cbject_FunDecls_caseXFuns_funDecl_caseImpl(funPrototype) \
    Fun funPrototype;                                            \
    FunOverride funPrototype;

#define Cbject_FunDecls_caseXFuns_funDecl_x1(funPrototype, case) \
    Cbject_FunDecls_caseXFuns_funDecl_case##case (funPrototype)

#define Cbject_FunDecls_caseXFuns_funDecl_x0(...) \
    Cbject_FunDecls_caseXFuns_funDecl_x1(__VA_ARGS__)

#define Cbject_FunDecls_caseXFuns_funDecl(funPrototype) \
    Cbject_FunDecls_caseXFuns_funDecl_x0(Cbject_Utils_unpack(funPrototype))

#define Cbject_FunDecls_case(...)

#define Cbject_FunDecls_caseFuns(...) \
    Cbject_Utils_forEach(Cbject_FunDecls_caseXFuns_funDecl, __VA_ARGS__)

#define Cbject_FunDecls_caseVirtFuns(...) \
    Cbject_Utils_forEach(Cbject_FunDecls_caseXFuns_funDecl, __VA_ARGS__)

#define Cbject_FunDecls_x1(case, ...) \
    Cbject_FunDecls_case##case (__VA_ARGS__)

#define Cbject_FunDecls_x0(...) \
    Cbject_FunDecls_x1(__VA_ARGS__)

#define Cbject_FunDecls(funs) \
    Cbject_FunDecls_x0(Cbject_Utils_unpack(funs))

#endif // CBJECT_FUNDECLS_H
