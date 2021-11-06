#ifndef CBJECT_CLASSDATASTRUCT_H
#define CBJECT_CLASSDATASTRUCT_H
#include "Cbject_Utils.h"

#define Cbject_ClassDataStruct_case(className, ...) \
    typedef char className##Data

#define Cbject_ClassDataStruct_caseData_member_caseX_addSemicolon(dataType, dataName) \
    Cbject_Utils_addSemicolon(dataType dataName)

#define Cbject_ClassDataStruct_caseData_member_caseX_x(...) \
    Cbject_ClassDataStruct_caseData_member_caseX_addSemicolon(__VA_ARGS__)

#define Cbject_ClassDataStruct_caseData_member_caseX(dataPrototype) \
    Cbject_ClassDataStruct_caseData_member_caseX_x(Cbject_Utils_unpack(dataPrototype))

#define Cbject_ClassDataStruct_caseData_member_switch(dataPrototype, case) \
    Cbject_ClassDataStruct_caseData_member_caseX(dataPrototype)

#define Cbject_ClassDataStruct_caseData_member_x(...) \
    Cbject_ClassDataStruct_caseData_member_switch(__VA_ARGS__)

#define Cbject_ClassDataStruct_caseData_member(dataPrototypeWithType) \
    Cbject_ClassDataStruct_caseData_member_x(Cbject_Utils_unpack(dataPrototypeWithType))

#define Cbject_ClassDataStruct_caseData(className, ...)                           \
    typedef struct className##Data                                                \
    {                                                                             \
        Cbject_Utils_forEach(Cbject_ClassDataStruct_caseData_member, __VA_ARGS__) \
    } className##Data

#define Cbject_ClassDataStruct_switch(className, case, ...) \
    Cbject_ClassDataStruct_case##case (className, __VA_ARGS__)

#define Cbject_ClassDataStruct_x(className, ...) \
    Cbject_ClassDataStruct_switch(className, __VA_ARGS__)

#define Cbject_ClassDataStruct(className, data) \
    Cbject_ClassDataStruct_x(className, Cbject_Utils_unpack(data))

#endif // CBJECT_CLASSDATASTRUCT_H
