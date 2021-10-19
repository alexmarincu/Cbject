#ifndef CBJECT_GETOBJECTFUNPROTOTYPE_H
#define CBJECT_GETOBJECTFUNPROTOTYPE_H

#define Cbject_GetObjectFunPrototype(cbjType) \
    cbjType * ___##cbjType##_get(cbjType##Params const * const params)

#endif // CBJECT_GETOBJECTFUNPROTOTYPE_H
