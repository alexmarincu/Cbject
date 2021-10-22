#ifndef CBJECT_NEWONSTACKFUNPROTOTYPE_H
#define CBJECT_NEWONSTACKFUNPROTOTYPE_H

#define Cbject_NewOnStackFunPrototype(cbjType) \
    cbjType * cbjType##_newOnStack(cbjType * const me, cbjType##Params const * const params)
#endif // CBJECT_NEWONSTACKFUNPROTOTYPE_H
