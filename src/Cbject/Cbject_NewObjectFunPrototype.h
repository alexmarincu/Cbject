#ifndef CBJECT_NEWOBJECTFUNPROTOTYPE_H
#define CBJECT_NEWOBJECTFUNPROTOTYPE_H

#define Cbject_NewObjectFunPrototype(typeName) \
    typeName * typeName##_createOnHeap(typeName##Params const params)
#endif // CBJECT_NEWOBJECTFUNPROTOTYPE_H
