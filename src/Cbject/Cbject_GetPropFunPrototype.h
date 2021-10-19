#ifndef CBJECT_GETPROPFUNPROTOTYPE_H
#define CBJECT_GETPROPFUNPROTOTYPE_H

#define Cbject_GetPropFunPrototype(cbjType, propType, propName) \
    propType cbjType##_##propName(cbjType const * const me)

#endif // CBJECT_GETPROPFUNPROTOTYPE_H
