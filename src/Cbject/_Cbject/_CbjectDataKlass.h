#ifndef _CBJECTDATAKLASS_H
#define _CBJECTDATAKLASS_H
#include "_CbjectDataTypeDefinition.h"

#define _CbjectDataKlass(klassName, ...) \
    _CbjectDataTypeDefinition(klassName, __VA_ARGS__)

#endif // _CBJECTDATAKLASS_H
