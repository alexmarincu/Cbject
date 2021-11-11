#ifndef CBJECT_ACCESSORFUNDECLS_H
#define CBJECT_ACCESSORFUNDECLS_H
#include "Cbject_AccessorFun.h"
#include "Cbject_Utils.h"

/*
Cbject_AccessorFunDecls
*/
#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublicRead(class, dataMemberType, dataMember) \
    Cbject_AccessorFun_Getter_Prototype(class, dataMemberType, dataMember);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublicWrite(class, dataMemberType, dataMember) \
    Cbject_AccessorFun_Setter_Prototype(class, dataMemberType, dataMember);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublic(class, dataMemberType, dataMember) \
    Cbject_AccessorFun_Getter_Prototype(class, dataMemberType, dataMember);                            \
    Cbject_AccessorFun_Setter_Prototype(class, dataMemberType, dataMember);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePrivate(class, dataMemberType, dataMember)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x3(accessType, dataMemberType, dataMember) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_case##accessType(Type, dataMemberType, dataMember)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x2(...) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x3(__VA_ARGS__)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x1(dataMemberPrototypePack, accessType) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x2(accessType, Cbject_Utils_unpack(dataMemberPrototypePack))

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x0(...) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x1(__VA_ARGS__)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl(dataMemberPrototypeWithAccessPack) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x0(Cbject_Utils_unpack(dataMemberPrototypeWithAccessPack))

#define Cbject_AccessorFunDecls_caseNA(...)

#define Cbject_AccessorFunDecls_caseData(...) \
    Cbject_Utils_forEach(Cbject_AccessorFunDecls_caseData_accessorFunDecl, __VA_ARGS__)

#define Cbject_AccessorFunDecls_x1(dataCase, ...) \
    Cbject_AccessorFunDecls_case##dataCase(__VA_ARGS__)

#define Cbject_AccessorFunDecls_x0(...) \
    Cbject_AccessorFunDecls_x1(__VA_ARGS__)

#define Cbject_AccessorFunDecls(dataPack) \
    Cbject_AccessorFunDecls_x0(Cbject_Utils_unpack(dataPack))

#endif // CBJECT_ACCESSORFUNDECLS_H
