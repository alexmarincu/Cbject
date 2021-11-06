#ifndef CBJECT_CONST_H
#define CBJECT_CONST_H

#define Cbject_Const_do(className, constType, constNameAndValue) \
    constType const className##_##constNameAndValue

#define Cbject_Const(className, constType, constNameAndValue) \
    Cbject_Const_do(className, constType, constNameAndValue)

#endif // CBJECT_CONST_H
