#ifndef _CBJECTENUMKLASS_H
#define _CBJECTENUMKLASS_H
#include "_CbjectEnumTypeDefinition.h"

#define _CbjectEnumClass(cbjectTypeName, ...) \
    _CbjectEnumTypeDefinition(cbjectTypeName, __VA_ARGS__)

#endif // _CBJECTENUMKLASS_H
