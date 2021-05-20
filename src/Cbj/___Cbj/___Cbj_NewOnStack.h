#ifndef _CBJ_NEWONSTACK_H
#define _CBJ_NEWONSTACK_H

#define ___Cbj_NewOnStack(cbjType, ...) \
    ___##cbjType##_newOnStack((cbjType *) &((___##cbjType){}), __VA_ARGS__)

#endif // _CBJ_NEWONSTACK_H
