#ifndef _CBJECTENUMKLASS_H
#define _CBJECTENUMKLASS_H
#include "_CbjectEnumTypeDefinition.h"

#define _CbjectEnumKlass(klassName, ...) \
    _CbjectEnumTypeDefinition(klassName, __VA_ARGS__)

#endif // _CBJECTENUMKLASS_H
