#ifndef CBJECT_SETPROPFUNPROTOTYPE_H
#define CBJECT_SETPROPFUNPROTOTYPE_H

#define Cbject_SetPropFunPrototype(typeName, fieldType, fieldName) \
    void typeName##_##fieldName##Set(typeName * const me, fieldType const fieldName)

#endif // CBJECT_SETPROPFUNPROTOTYPE_H
