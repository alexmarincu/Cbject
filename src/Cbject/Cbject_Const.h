#ifndef CBJECT_CONST_H
#define CBJECT_CONST_H

#define Cbject_Const_do(typeName, constType, constNameAndValue) \
    constType const typeName##_##constNameAndValue

#define Cbject_Const(typeName, constType, constNameAndValue) \
    Cbject_Const_do(typeName, constType, constNameAndValue)

#endif // CBJECT_CONST_H
