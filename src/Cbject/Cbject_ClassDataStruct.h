#ifndef CBJECT_CLASSDATASTRUCT_H
#define CBJECT_CLASSDATASTRUCT_H
#include "Cbject_Utils.h"

#define Cbject_ClassDataStruct_case(typeName, ...) \
    typedef char typeName##Data

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

#define Cbject_ClassDataStruct_caseData(typeName, ...)                            \
    typedef struct typeName##Data                                                 \
    {                                                                             \
        Cbject_Utils_forEach(Cbject_ClassDataStruct_caseData_member, __VA_ARGS__) \
    } typeName##Data

#define Cbject_ClassDataStruct_switch(typeName, case, ...) \
    Cbject_ClassDataStruct_case##case (typeName, __VA_ARGS__)

#define Cbject_ClassDataStruct_x(typeName, ...) \
    Cbject_ClassDataStruct_switch(typeName, __VA_ARGS__)

#define Cbject_ClassDataStruct(typeName, data) \
    Cbject_ClassDataStruct_x(typeName, Cbject_Utils_unpack(data))

#endif // CBJECT_CLASSDATASTRUCT_H
