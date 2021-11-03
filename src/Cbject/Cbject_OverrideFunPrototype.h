#ifndef CBJECT_OVERRIDEFUNPROTOTYPE_H
#define CBJECT_OVERRIDEFUNPROTOTYPE_H

#define Cbject_OverrideFunPrototype_case_paramsNone(typeName, returnType, funName, ...) \
    returnType typeName##_s_##funName(typeName * const me)

#define Cbject_OverrideFunPrototype_case_params(typeName, returnType, funName, ...) \
    returnType typeName##_s_##funName(typeName * const me, __VA_ARGS__)

#define Cbject_OverrideFunPrototype_switch(typeName, returnType, funName, case, ...) \
    Cbject_OverrideFunPrototype_case_##case (typeName, returnType, funName, __VA_ARGS__)

#define Cbject_OverrideFunPrototype_x(typeName, returnType, funName, ...) \
    Cbject_OverrideFunPrototype_switch(typeName, returnType, funName, __VA_ARGS__)

#define Cbject_OverrideFunPrototype(typeName, returnType, funName, params) \
    Cbject_OverrideFunPrototype_x(typeName, returnType, funName, Cbject_Utils_stripParentheses(params))

#endif // CBJECT_OVERRIDEFUNPROTOTYPE_H
