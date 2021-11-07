#ifndef CBJECT_ACCESSORFUNDECLS_H
#define CBJECT_ACCESSORFUNDECLS_H
#include "Cbject_AccessorFun.h"
#include "Cbject_Utils.h"

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublicRead(className, dataType, dataName) \
    Cbject_AccessorFun_Getter_Prototype(className, dataType, dataName);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublicWrite(className, dataType, dataName) \
    Cbject_AccessorFun_Setter_Prototype(className, dataType, dataName);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublic(className, dataType, dataName) \
    Cbject_AccessorFun_Getter_Prototype(className, dataType, dataName);                            \
    Cbject_AccessorFun_Setter_Prototype(className, dataType, dataName);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePrivate(className, dataType, dataName)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x3(dataType, dataName, case) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_case##case (Type, dataType, dataName)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x2(...) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x3(__VA_ARGS__)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x1(dataPrototype, accessType) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x2(Cbject_Utils_unpack(dataPrototype), accessType)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x0(...) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x1(__VA_ARGS__)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl(dataPrototypeWithAccess) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x0(Cbject_Utils_unpack(dataPrototypeWithAccess))

#define Cbject_AccessorFunDecls_case(...)

#define Cbject_AccessorFunDecls_caseData(...) \
    Cbject_Utils_forEach(Cbject_AccessorFunDecls_caseData_accessorFunDecl, __VA_ARGS__)

#define Cbject_AccessorFunDecls_x1(case, ...) \
    Cbject_AccessorFunDecls_case##case (__VA_ARGS__)

#define Cbject_AccessorFunDecls_x0(...) \
    Cbject_AccessorFunDecls_x1(__VA_ARGS__)

#define Cbject_AccessorFunDecls(data) \
    Cbject_AccessorFunDecls_x0(Cbject_Utils_unpack(data))

#endif // CBJECT_ACCESSORFUNDECLS_H
