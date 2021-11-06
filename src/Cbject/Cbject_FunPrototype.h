#ifndef CBJECT_FUNPROTOTYPE_H
#define CBJECT_FUNPROTOTYPE_H

#define Cbject_FunPrototype_case_(typeName, funReturnType, funName, ...) \
    funReturnType typeName##_##funName(typeName * const me)

#define Cbject_FunPrototype_case_Params(typeName, funReturnType, funName, ...) \
    funReturnType typeName##_##funName(typeName * const me, __VA_ARGS__)

#define Cbject_FunPrototype_switch(typeName, funReturnType, funName, case, ...) \
    Cbject_FunPrototype_case_##case (typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype_x1(typeName, funReturnType, funName, ...) \
    Cbject_FunPrototype_switch(typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype(typeName, funReturnType, funName, funParams) \
    Cbject_FunPrototype_x1(typeName, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_FUNPROTOTYPE_H
