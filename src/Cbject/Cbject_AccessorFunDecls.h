#ifndef CBJECT_ACCESSORFUNDECLS_H
#define CBJECT_ACCESSORFUNDECLS_H
#include "Cbject_AccessorFun.h"
#include "Cbject_Utils.h"

#define Cbject_AccessorFunDecls_case_Data_case_PublicRead(typeName, dataType, dataName) \
    Cbject_AccessorFun_Getter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_case_Data_case_PublicWrite(typeName, dataType, dataName) \
    Cbject_AccessorFun_Setter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_case_Data_case_Public(typeName, dataType, dataName) \
    Cbject_AccessorFun_Getter_Prototype(typeName, dataType, dataName);              \
    Cbject_AccessorFun_Setter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_case_Data_case_Private(typeName, dataType, dataName)

#define Cbject_AccessorFunDecls_case_Data_switch(dataType, dataName, case) \
    Cbject_AccessorFunDecls_case_Data_case_##case (Type, dataType, dataName)

#define Cbject_AccessorFunDecls_case_Data_unpack_switch(...) \
    Cbject_AccessorFunDecls_case_Data_switch(__VA_ARGS__)

#define Cbject_AccessorFunDecls_case_Data_do_unpack_switch(dataPrototype, accessType) \
    Cbject_AccessorFunDecls_case_Data_unpack_switch(Cbject_Utils_unpack(dataPrototype), accessType)

#define Cbject_AccessorFunDecls_case_Data_unpack_do_unpack_switch(...) \
    Cbject_AccessorFunDecls_case_Data_do_unpack_switch(__VA_ARGS__)

#define Cbject_AccessorFunDecls_case_Data_do_unpack_do_unpack_switch(dataPrototypeWithAccess) \
    Cbject_AccessorFunDecls_case_Data_unpack_do_unpack_switch(Cbject_Utils_unpack(dataPrototypeWithAccess))

#define Cbject_AccessorFunDecls_case_(...)

#define Cbject_AccessorFunDecls_case_Data(...) \
    Cbject_Utils_forEach(Cbject_AccessorFunDecls_case_Data_do_unpack_do_unpack_switch, __VA_ARGS__)

#define Cbject_AccessorFunDecls_switch(case, ...) \
    Cbject_AccessorFunDecls_case_##case (__VA_ARGS__)

#define Cbject_AccessorFunDecls_unpack_switch(...) \
    Cbject_AccessorFunDecls_switch(__VA_ARGS__)

#define Cbject_AccessorFunDecls(data) \
    Cbject_AccessorFunDecls_unpack_switch(Cbject_Utils_unpack(data))

#endif // CBJECT_ACCESSORFUNDECLS_H
