#ifndef CBJECT_CONST_H
#define CBJECT_CONST_H

#define Cbject_Const_x(className, constType, constName) \
    constType const className##_##constName

#define Cbject_Const(className, constType, constName) \
    Cbject_Const_x(className, constType, constName)

#endif // CBJECT_CONST_H
