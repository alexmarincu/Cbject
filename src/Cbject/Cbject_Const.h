#ifndef CBJECT_CONST_H
#define CBJECT_CONST_H

/*
Cbject_Const
*/
#define Cbject_Const_x0(class, constType, constName) \
    constType const class##_##constName

#define Cbject_Const(class, constType, constName) \
    Cbject_Const_x0(class, constType, constName)

#endif // CBJECT_CONST_H
