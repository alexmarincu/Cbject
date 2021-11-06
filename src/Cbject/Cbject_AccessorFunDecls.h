#ifndef CBJECT_ACCESSORFUNDECLS_H
#define CBJECT_ACCESSORFUNDECLS_H
#include "Cbject_AccessorFun.h"
#include "Cbject_Utils.h"

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublicRead(typeName, dataType, dataName) \
    Cbject_AccessorFun_Getter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublicWrite(typeName, dataType, dataName) \
    Cbject_AccessorFun_Setter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePublic(typeName, dataType, dataName) \
    Cbject_AccessorFun_Getter_Prototype(typeName, dataType, dataName);                            \
    Cbject_AccessorFun_Setter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_casePrivate(typeName, dataType, dataName)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_switch(dataType, dataName, case) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_case##case (Type, dataType, dataName)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x3(...) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_switch(__VA_ARGS__)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x2(dataPrototype, accessType) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x3(Cbject_Utils_unpack(dataPrototype), accessType)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl_x(...) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x2(__VA_ARGS__)

#define Cbject_AccessorFunDecls_caseData_accessorFunDecl(dataPrototypeWithAccess) \
    Cbject_AccessorFunDecls_caseData_accessorFunDecl_x(Cbject_Utils_unpack(dataPrototypeWithAccess))

#define Cbject_AccessorFunDecls_case(...)

#define Cbject_AccessorFunDecls_caseData(...) \
    Cbject_Utils_forEach(Cbject_AccessorFunDecls_caseData_accessorFunDecl, __VA_ARGS__)

#define Cbject_AccessorFunDecls_switch(case, ...) \
    Cbject_AccessorFunDecls_case##case (__VA_ARGS__)

#define Cbject_AccessorFunDecls_x(...) \
    Cbject_AccessorFunDecls_switch(__VA_ARGS__)

#define Cbject_AccessorFunDecls(data) \
    Cbject_AccessorFunDecls_x(Cbject_Utils_unpack(data))

#endif // CBJECT_ACCESSORFUNDECLS_H
