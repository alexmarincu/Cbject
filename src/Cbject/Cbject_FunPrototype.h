#ifndef CBJECT_FUNPROTOTYPE_H
#define CBJECT_FUNPROTOTYPE_H

#define Cbject_FunPrototype_case_(typeName, returnType, funName, ...) \
    returnType typeName##_##funName(typeName * const me)

#define Cbject_FunPrototype_case_params(typeName, returnType, funName, ...) \
    returnType typeName##_##funName(typeName * const me, __VA_ARGS__)

#define Cbject_FunPrototype_switch(typeName, returnType, funName, case, ...) \
    Cbject_FunPrototype_case_##case (typeName, returnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype_x(typeName, returnType, funName, ...) \
    Cbject_FunPrototype_switch(typeName, returnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype(typeName, returnType, funName, params) \
    Cbject_FunPrototype_x(typeName, returnType, funName, Cbject_Utils_stripParentheses(params))

#endif // CBJECT_FUNPROTOTYPE_H
