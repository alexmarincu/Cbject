#ifndef CBJECT_ACCESSORFUNDECLS_H
#define CBJECT_ACCESSORFUNDECLS_H
#include "Cbject_AccessorFun.h"
#include "Cbject_Utils.h"

#define Cbject_AccessorFunDecls_case_data_case_Access_Read(typeName, dataType, dataName) \
    Cbject_AccessorFun_Getter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_case_data_case_Access_Write(typeName, dataType, dataName) \
    Cbject_AccessorFun_Setter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_case_data_case_Access_ReadWrite(typeName, dataType, dataName) \
    Cbject_AccessorFun_Getter_Prototype(typeName, dataType, dataName);                        \
    Cbject_AccessorFun_Setter_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorFunDecls_case_data_case_Access_None(typeName, dataType, dataName)

#define Cbject_AccessorFunDecls_case_data_switch(dataType, dataName, case) \
    Cbject_AccessorFunDecls_case_data_case_##case (Type, dataType, dataName)

#define Cbject_AccessorFunDecls_case_data_unpack_switch(...) \
    Cbject_AccessorFunDecls_case_data_switch(__VA_ARGS__)

#define Cbject_AccessorFunDecls_case_data_do_unpack_switch(dataPrototype, access) \
    Cbject_AccessorFunDecls_case_data_unpack_switch(Cbject_Utils_unpack(dataPrototype), access)

#define Cbject_AccessorFunDecls_case_data_unpack_do_unpack_switch(...) \
    Cbject_AccessorFunDecls_case_data_do_unpack_switch(__VA_ARGS__)

#define Cbject_AccessorFunDecls_case_data_do_unpack_do_unpack_switch(dataPrototypeWithAccess) \
    Cbject_AccessorFunDecls_case_data_unpack_do_unpack_switch(Cbject_Utils_unpack(dataPrototypeWithAccess))

#define Cbject_AccessorFunDecls_case_(...)

#define Cbject_AccessorFunDecls_case_data(...) \
    Cbject_Utils_forEach(Cbject_AccessorFunDecls_case_data_do_unpack_do_unpack_switch, __VA_ARGS__)

#define Cbject_AccessorFunDecls_switch(case, ...) \
    Cbject_AccessorFunDecls_case_##case (__VA_ARGS__)

#define Cbject_AccessorFunDecls_unpack_switch(...) \
    Cbject_AccessorFunDecls_switch(__VA_ARGS__)

#define Cbject_AccessorFunDecls(data) \
    Cbject_AccessorFunDecls_unpack_switch(Cbject_Utils_unpack(data))

#endif // CBJECT_ACCESSORFUNDECLS_H
