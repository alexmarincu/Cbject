#ifndef CBJECT_NEWOBJECTFUNPROTOTYPE_H
#define CBJECT_NEWOBJECTFUNPROTOTYPE_H

/*
Cbject_NewObjectFunPrototype
*/
#define Cbject_NewObjectFunPrototype(className) \
    className * className##_createOnHeap(className##Params const params)
#endif // CBJECT_NEWOBJECTFUNPROTOTYPE_H
