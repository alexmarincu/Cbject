#ifndef _CBJ_TERMINATE_H
#define _CBJ_TERMINATE_H
#include "_Cbj_TerminateFunImpl.h"

#define _Cbj_Terminate(typeName, Cbj_ParentName) \
    _Cbj_TerminateFunImpl(typeName, Cbj_ParentName)

#endif // _CBJ_TERMINATE_H
