#ifndef CBJECT_GETOBJECTFUNPROTOTYPE_H
#define CBJECT_GETOBJECTFUNPROTOTYPE_H

#define Cbject_GetObjectFunPrototype(className) \
    className * className##_getFromStaticPool(className##Params const params)

#endif // CBJECT_GETOBJECTFUNPROTOTYPE_H
