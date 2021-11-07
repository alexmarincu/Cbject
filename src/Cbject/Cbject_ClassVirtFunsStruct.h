#ifndef CBJECT_CLASSVIRTFUNSSTRUCT_H
#define CBJECT_CLASSVIRTFUNSSTRUCT_H
#include "Cbject_VirtFun.h"

/*
Cbject_ClassVirtFunsStruct
*/
#define Cbject_ClassVirtFunsStruct_caseNA(className, ...) \
    typedef char className##VirtFuns

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_caseImpl(funPrototype) \
    Cbject_VirtFun_Ptr funPrototype;

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_casePure(funPrototype) \
    Cbject_VirtFun_Ptr funPrototype;

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x1(funPrototype, case) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_case##case (funPrototype)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x0(...) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x1(__VA_ARGS__)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member(funPrototype) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x0(Cbject_Utils_unpack(funPrototype))

#define Cbject_ClassVirtFunsStruct_caseVirtFuns(className, ...)                           \
    typedef struct className##VirtFuns                                                    \
    {                                                                                     \
        Cbject_Utils_forEach(Cbject_ClassVirtFunsStruct_caseVirtFuns_member, __VA_ARGS__) \
    } className##VirtFuns

#define Cbject_ClassVirtFunsStruct_x1(className, case, ...) \
    Cbject_ClassVirtFunsStruct_case##case (className, __VA_ARGS__)

#define Cbject_ClassVirtFunsStruct_x0(className, ...) \
    Cbject_ClassVirtFunsStruct_x1(className, __VA_ARGS__)

#define Cbject_ClassVirtFunsStruct(className, virtFuns) \
    Cbject_ClassVirtFunsStruct_x0(className, Cbject_Utils_unpack(virtFuns))

#endif // CBJECT_CLASSVIRTFUNSSTRUCT_H
