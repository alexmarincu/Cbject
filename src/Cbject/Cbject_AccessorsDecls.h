#ifndef CBJECT_ACCESSORSDECLS_H
#define CBJECT_ACCESSORSDECLS_H
#include "Cbject_GetPropFun.h"
#include "Cbject_SetPropFun.h"
#include "Cbject_Utils.h"

#define Cbject_AccessorsDecls_case_data_case_Access_Read(typeName, dataType, dataName) \
    Cbject_GetPropFun_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorsDecls_case_data_case_Access_Write(typeName, dataType, dataName) \
    Cbject_SetPropFun_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorsDecls_case_data_case_Access_ReadWrite(typeName, dataType, dataName) \
    Cbject_GetPropFun_Prototype(typeName, dataType, dataName);                              \
    Cbject_SetPropFun_Prototype(typeName, dataType, dataName);

#define Cbject_AccessorsDecls_case_data_case_Access_None(typeName, dataType, dataName)

#define Cbject_AccessorsDecls_case_data_switch(dataType, dataName, case) \
    Cbject_AccessorsDecls_case_data_case_##case (Type, dataType, dataName)

#define Cbject_AccessorsDecls_case_data_unpack_switch(...) \
    Cbject_AccessorsDecls_case_data_switch(__VA_ARGS__)

#define Cbject_AccessorsDecls_case_data_do_unpack_switch(dataPrototype, access) \
    Cbject_AccessorsDecls_case_data_unpack_switch(Cbject_Utils_unpack(dataPrototype), access)

#define Cbject_AccessorsDecls_case_data_unpack_do_unpack_switch(...) \
    Cbject_AccessorsDecls_case_data_do_unpack_switch(__VA_ARGS__)

#define Cbject_AccessorsDecls_case_data_do_unpack_do_unpack_switch(dataPrototypeWithAccess) \
    Cbject_AccessorsDecls_case_data_unpack_do_unpack_switch(Cbject_Utils_unpack(dataPrototypeWithAccess))

#define Cbject_AccessorsDecls_case_(...)

#define Cbject_AccessorsDecls_case_data(...) \
    Cbject_Utils_forEach(Cbject_AccessorsDecls_case_data_do_unpack_do_unpack_switch, __VA_ARGS__)

#define Cbject_AccessorsDecls_switch(case, ...) \
    Cbject_AccessorsDecls_case_##case (__VA_ARGS__)

#define Cbject_AccessorsDecls_unpack_switch(...) \
    Cbject_AccessorsDecls_switch(__VA_ARGS__)

#define Cbject_AccessorsDecls(data) \
    Cbject_AccessorsDecls_unpack_switch(Cbject_Utils_unpack(data))

#endif // CBJECT_ACCESSORSDECLS_H
