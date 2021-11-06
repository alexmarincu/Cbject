#ifndef CBJECT_FUNDECLS_H
#define CBJECT_FUNDECLS_H
#include "Cbject_Utils.h"

#define Cbject_FunDecls_stripParenthesesAndApplyFun_case_Final(funPrototype) \
    Fun funPrototype;

#define Cbject_FunDecls_stripParenthesesAndApplyFun_case_Override(funPrototype) \
    OverrideFun funPrototype;

#define Cbject_FunDecls_stripParenthesesAndApplyFun_case_Pure(funPrototype) \
    Fun funPrototype;

#define Cbject_FunDecls_stripParenthesesAndApplyFun_case_Implemented(funPrototype) \
    Fun funPrototype;                                                              \
    OverrideFun funPrototype;

#define Cbject_FunDecls_stripParenthesesAndApplyFun_switch(funPrototype, case) \
    Cbject_FunDecls_stripParenthesesAndApplyFun_case_##case (funPrototype)

#define Cbject_FunDecls_stripParenthesesAndApplyFun_x1(...) \
    Cbject_FunDecls_stripParenthesesAndApplyFun_switch(__VA_ARGS__)

#define Cbject_FunDecls_stripParenthesesAndApplyFun(funPrototype) \
    Cbject_FunDecls_stripParenthesesAndApplyFun_x1(Cbject_Utils_stripParentheses(funPrototype))

#define Cbject_FunDecls_case_(...)

#define Cbject_FunDecls_case_funs(...) \
    Cbject_Utils_forEach(Cbject_FunDecls_stripParenthesesAndApplyFun, __VA_ARGS__)

#define Cbject_FunDecls_case_virtFuns(...) \
    Cbject_Utils_forEach(Cbject_FunDecls_stripParenthesesAndApplyFun, __VA_ARGS__)

#define Cbject_FunDecls_switch(case, ...) \
    Cbject_FunDecls_case_##case (__VA_ARGS__)

#define Cbject_FunDecls_x1(...) \
    Cbject_FunDecls_switch(__VA_ARGS__)

#define Cbject_FunDecls(funs) \
    Cbject_FunDecls_x1(Cbject_Utils_stripParentheses(funs))

#endif // CBJECT_FUNDECLS_H
