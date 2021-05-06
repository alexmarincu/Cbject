#ifndef _CBJECTDATAKLASS_H
#define _CBJECTDATAKLASS_H
#include "_CbjectDataTypeDefinition.h"

#define _CbjectDataClass(cbjectTypeName, ...) \
    _CbjectDataTypeDefinition(cbjectTypeName, __VA_ARGS__)

#endif // _CBJECTDATAKLASS_H
