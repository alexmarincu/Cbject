#ifndef CBJECT_VAR_H
#define CBJECT_VAR_H

/*
Cbject_Var
*/
#define Cbject_Var_x0(className, varType, varName) \
    varType className##_##varName

#define Cbject_Var(className, varType, varName) \
    Cbject_Var_x0(className, varType, varName)

#endif // CBJECT_VAR_H
