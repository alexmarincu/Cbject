#ifndef _CBJ_DELETEOBJECTFUNPROTOTYPE_H
#define _CBJ_DELETEOBJECTFUNPROTOTYPE_H

#define _Cbj_DeleteObjectFunPrototype(typeName) \
    typeName * Delete_##typeName(typeName * me)

#endif // _CBJ_DELETEOBJECTFUNPROTOTYPE_H
