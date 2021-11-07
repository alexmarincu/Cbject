#ifndef CBJECT_NEWONSTACKFUNPROTOTYPE_H
#define CBJECT_NEWONSTACKFUNPROTOTYPE_H

/*
Cbject_NewOnStackFunPrototype
*/
#define Cbject_NewOnStackFunPrototype(className) \
    className * className##_createOnStack(className * const me, className##Params const params)

#endif // CBJECT_NEWONSTACKFUNPROTOTYPE_H
