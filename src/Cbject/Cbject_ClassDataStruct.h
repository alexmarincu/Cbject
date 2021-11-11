#ifndef CBJECT_CLASSDATASTRUCT_H
#define CBJECT_CLASSDATASTRUCT_H
#include "Cbject_Utils.h"

/*
Cbject_ClassDataStruct
*/
#define Cbject_ClassDataStruct_caseNA(class, ...) \
    typedef char class##Data

#define Cbject_ClassDataStruct_caseData_member_caseX_addSemicolon(dataMemberType, dataMember) \
    Cbject_Utils_addSemicolon(dataMemberType dataMember)

#define Cbject_ClassDataStruct_caseData_member_caseX_x0(...) \
    Cbject_ClassDataStruct_caseData_member_caseX_addSemicolon(__VA_ARGS__)

#define Cbject_ClassDataStruct_caseData_member_caseX(dataMemberPrototypePack) \
    Cbject_ClassDataStruct_caseData_member_caseX_x0(Cbject_Utils_unpack(dataMemberPrototypePack))

#define Cbject_ClassDataStruct_caseData_member_x1(dataMemberPrototypePack, accessType) \
    Cbject_ClassDataStruct_caseData_member_caseX(dataMemberPrototypePack)

#define Cbject_ClassDataStruct_caseData_member_x0(...) \
    Cbject_ClassDataStruct_caseData_member_x1(__VA_ARGS__)

#define Cbject_ClassDataStruct_caseData_member(dataMemberPrototypeWithAccessPack) \
    Cbject_ClassDataStruct_caseData_member_x0(Cbject_Utils_unpack(dataMemberPrototypeWithAccessPack))

#define Cbject_ClassDataStruct_caseData(class, ...)                               \
    typedef struct class##Data                                                    \
    {                                                                             \
        Cbject_Utils_forEach(Cbject_ClassDataStruct_caseData_member, __VA_ARGS__) \
    } class##Data

#define Cbject_ClassDataStruct_x1(class, case, ...) \
    Cbject_ClassDataStruct_case##case (class, __VA_ARGS__)

#define Cbject_ClassDataStruct_x0(class, ...) \
    Cbject_ClassDataStruct_x1(class, __VA_ARGS__)

#define Cbject_ClassDataStruct(class, dataPack) \
    Cbject_ClassDataStruct_x0(class, Cbject_Utils_unpack(dataPack))

#endif // CBJECT_CLASSDATASTRUCT_H
