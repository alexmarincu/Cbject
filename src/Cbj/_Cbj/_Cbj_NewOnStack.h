#ifndef _CBJ_NEWONSTACK_H
#define _CBJ_NEWONSTACK_H

#define _Cbj_NewOnStack(typeName, varName, ...)                 \
    typeName * const varName = (typeName *) &((_##typeName){}); \
    typeName##_init((typeName *) varName, __VA_ARGS__)

#endif // _CBJ_NEWONSTACK_H
