#ifndef CBJECT_CLASSVIRTFUNSSTRUCT_H
#define CBJECT_CLASSVIRTFUNSSTRUCT_H
#include "Cbject_VirtFun.h"

/*
Cbject_ClassVirtFunsStruct
*/
#define Cbject_ClassVirtFunsStruct_caseNA(class, ...)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_caseImpl(funPrototypePack) \
    Cbject_VirtFun_Ptr funPrototypePack;

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_casePure(funPrototypePack) \
    Cbject_VirtFun_Ptr funPrototypePack;

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x1(funPrototypePack, funType) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_case##funType(funPrototypePack)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x0(...) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x1(__VA_ARGS__)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member(funPrototypeWithFunTypePack) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x0(Cbject_Utils_unpack(funPrototypeWithFunTypePack))

#define Cbject_ClassVirtFunsStruct_caseVirtFuns(class, ...)                               \
    typedef struct class##VirtFuns                                                        \
    {                                                                                     \
        Cbject_Utils_forEach(Cbject_ClassVirtFunsStruct_caseVirtFuns_member, __VA_ARGS__) \
    } class##VirtFuns;                                                                    \
                                                                                          \
    Cbject_ClassVirtFunsGetter_Prototype(class)

#define Cbject_ClassVirtFunsStruct_x1(class, virtFunsCase, ...) \
    Cbject_ClassVirtFunsStruct_case##virtFunsCase(class, __VA_ARGS__)

#define Cbject_ClassVirtFunsStruct_x0(class, ...) \
    Cbject_ClassVirtFunsStruct_x1(class, __VA_ARGS__)

#define Cbject_ClassVirtFunsStruct(class, virtFunsPack) \
    Cbject_ClassVirtFunsStruct_x0(class, Cbject_Utils_unpack(virtFunsPack))

#endif // CBJECT_CLASSVIRTFUNSSTRUCT_H
