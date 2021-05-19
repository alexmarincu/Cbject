#ifndef ___CBJ_NEWONSTACK_H
#define ___CBJ_NEWONSTACK_H
#include <string.h>

#define ___Cbj_NewOnStack(cbjType, varName, ...)               \
    cbjType * const varName = (cbjType *) &((___##cbjType){}); \
    memset(varName, 0, sizeof(___##cbjType));                  \
    cbjType##_init((cbjType *) varName, __VA_ARGS__)

#endif // ___CBJ_NEWONSTACK_H
