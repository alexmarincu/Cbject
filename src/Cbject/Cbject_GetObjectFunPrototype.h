#ifndef CBJECT_GETOBJECTFUNPROTOTYPE_H
#define CBJECT_GETOBJECTFUNPROTOTYPE_H

#define Cbject_GetObjectFunPrototype(typeName) \
    typeName * typeName##_getFromStaticPool(typeName##Params const params)

#endif // CBJECT_GETOBJECTFUNPROTOTYPE_H
