#ifndef CBJECT_NEWOBJECTFUNPROTOTYPE_H
#define CBJECT_NEWOBJECTFUNPROTOTYPE_H

#define Cbject_NewObjectFunPrototype(cbjType) \
    cbjType * cbjType##_new(cbjType##Params const * const params)
#endif // CBJECT_NEWOBJECTFUNPROTOTYPE_H
