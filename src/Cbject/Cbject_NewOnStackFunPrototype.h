#ifndef CBJECT_NEWONSTACKFUNPROTOTYPE_H
#define CBJECT_NEWONSTACKFUNPROTOTYPE_H

#define Cbject_NewOnStackFunPrototype(typeName) \
    typeName * typeName##_createOnStack(typeName * const me, typeName##Params const params)
#endif // CBJECT_NEWONSTACKFUNPROTOTYPE_H
