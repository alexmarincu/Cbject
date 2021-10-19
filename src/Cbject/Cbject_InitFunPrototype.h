#ifndef CBJECT_INITFUNPROTOTYPE_H
#define CBJECT_INITFUNPROTOTYPE_H

#define Cbject_InitFunPrototype(cbjType) \
    void ___##cbjType##_init(cbjType * const me, cbjType##Params const * const params)

#endif // CBJECT_INITFUNPROTOTYPE_H
