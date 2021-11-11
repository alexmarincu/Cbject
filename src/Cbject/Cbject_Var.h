#ifndef CBJECT_VAR_H
#define CBJECT_VAR_H

/*
Cbject_Var
*/
#define Cbject_Var_x0(class, varType, varName) \
    varType class##_##varName

#define Cbject_Var(class, varType, varName) \
    Cbject_Var_x0(class, varType, varName)

#endif // CBJECT_VAR_H
