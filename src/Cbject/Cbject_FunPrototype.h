#ifndef CBJECT_FUNPROTOTYPE_H
#define CBJECT_FUNPROTOTYPE_H

#define Cbject_FunPrototype_case(typeName, funReturnType, funName, ...) \
    funReturnType typeName##_##funName(typeName * const me)

#define Cbject_FunPrototype_caseParams(typeName, funReturnType, funName, ...) \
    funReturnType typeName##_##funName(typeName * const me, __VA_ARGS__)

#define Cbject_FunPrototype_switch(typeName, funReturnType, funName, case, ...) \
    Cbject_FunPrototype_case##case (typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype_x(typeName, funReturnType, funName, ...) \
    Cbject_FunPrototype_switch(typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype(typeName, funReturnType, funName, funParams) \
    Cbject_FunPrototype_x(typeName, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_FUNPROTOTYPE_H
