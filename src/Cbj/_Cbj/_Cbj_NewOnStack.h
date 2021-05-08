#ifndef _CBJ_NEWONSTACK_H
#define _CBJ_NEWONSTACK_H

#define _Cbj_NewOnStack(cbjType, varName, ...)               \
    cbjType * const varName = (cbjType *) &((_##cbjType){}); \
    cbjType##_init((cbjType *) varName, __VA_ARGS__)

#endif // _CBJ_NEWONSTACK_H
