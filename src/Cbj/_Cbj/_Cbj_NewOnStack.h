#ifndef _CBJ_NEWONSTACK_H
#define _CBJ_NEWONSTACK_H
#include <string.h>

#define _Cbj_NewOnStack(cbjType, varName, ...)               \
    cbjType * const varName = (cbjType *) &((_##cbjType){}); \
    memset(varName, 0, sizeof(_##cbjType));                  \
    cbjType##_init((cbjType *) varName, __VA_ARGS__)

#endif // _CBJ_NEWONSTACK_H
