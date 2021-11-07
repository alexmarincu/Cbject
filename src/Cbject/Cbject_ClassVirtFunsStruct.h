#ifndef CBJECT_CLASSVIRTFUNSSTRUCT_H
#define CBJECT_CLASSVIRTFUNSSTRUCT_H
#include "Cbject_VirtFunPtr.h"

#define Cbject_ClassVirtFunsStruct_case(className, ...) \
    typedef char className##VirtFuns

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_caseImpl(funPrototype) \
    Cbject_VirtFunPtr funPrototype;

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_casePure(funPrototype) \
    Cbject_VirtFunPtr funPrototype;

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_switch(funPrototype, case) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_case##case (funPrototype)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x(...) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_switch(__VA_ARGS__)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member(funPrototype) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x(Cbject_Utils_unpack(funPrototype))

#define Cbject_ClassVirtFunsStruct_caseVirtFuns(className, ...)                           \
    typedef struct className##VirtFuns                                                    \
    {                                                                                     \
        Cbject_Utils_forEach(Cbject_ClassVirtFunsStruct_caseVirtFuns_member, __VA_ARGS__) \
    } className##VirtFuns

#define Cbject_ClassVirtFunsStruct_switch(className, case, ...) \
    Cbject_ClassVirtFunsStruct_case##case (className, __VA_ARGS__)

#define Cbject_ClassVirtFunsStruct_x(className, ...) \
    Cbject_ClassVirtFunsStruct_switch(className, __VA_ARGS__)

#define Cbject_ClassVirtFunsStruct(className, virtFuns) \
    Cbject_ClassVirtFunsStruct_x(className, Cbject_Utils_unpack(virtFuns))

#endif // CBJECT_CLASSVIRTFUNSSTRUCT_H
