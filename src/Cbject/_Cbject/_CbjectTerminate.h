#ifndef _CBJECTTERMINATE_H
#define _CBJECTTERMINATE_H
#include "_CbjectTerminateFunImpl.h"

#define _CbjectTerminate(cbjectTypeName, parentName) \
    _CbjectTerminateFunImpl(cbjectTypeName, parentName)

#endif // _CBJECTTERMINATE_H
