#ifndef CBJECT_SETPROPFUNPROTOTYPE_H
#define CBJECT_SETPROPFUNPROTOTYPE_H

#define Cbject_SetPropFunPrototype(cbjType, propType, propName) \
    void cbjType##_##propName##Set(cbjType * const me, propType const propName)

#endif // CBJECT_SETPROPFUNPROTOTYPE_H
