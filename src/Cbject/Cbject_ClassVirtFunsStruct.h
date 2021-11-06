#ifndef CBJECT_CLASSVIRTFUNSSTRUCT_H
#define CBJECT_CLASSVIRTFUNSSTRUCT_H
#include "Cbject_VirtFunPtr.h"

#define Cbject_ClassVirtFunsStruct_case(typeName, ...) \
    typedef char typeName##VirtFuns

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_caseImplemented(funPrototype) \
    Cbject_VirtFunPtr funPrototype;

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_casePure(funPrototype) \
    Cbject_VirtFunPtr funPrototype;

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_switch(funPrototype, case) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_case##case (funPrototype)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x(...) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_switch(__VA_ARGS__)

#define Cbject_ClassVirtFunsStruct_caseVirtFuns_member(funPrototype) \
    Cbject_ClassVirtFunsStruct_caseVirtFuns_member_x(Cbject_Utils_unpack(funPrototype))

#define Cbject_ClassVirtFunsStruct_caseVirtFuns(typeName, ...)                            \
    typedef struct typeName##VirtFuns                                                     \
    {                                                                                     \
        Cbject_Utils_forEach(Cbject_ClassVirtFunsStruct_caseVirtFuns_member, __VA_ARGS__) \
    } typeName##VirtFuns

#define Cbject_ClassVirtFunsStruct_switch(typeName, case, ...) \
    Cbject_ClassVirtFunsStruct_case##case (typeName, __VA_ARGS__)

#define Cbject_ClassVirtFunsStruct_x(typeName, ...) \
    Cbject_ClassVirtFunsStruct_switch(typeName, __VA_ARGS__)

#define Cbject_ClassVirtFunsStruct(typeName, virtFuns) \
    Cbject_ClassVirtFunsStruct_x(typeName, Cbject_Utils_unpack(virtFuns))

#endif // CBJECT_CLASSVIRTFUNSSTRUCT_H
