#ifndef CBJECT_GETPROPFUNPROTOTYPE_H
#define CBJECT_GETPROPFUNPROTOTYPE_H

#define Cbject_GetPropFunPrototype(typeName, fieldType, fieldName) \
    fieldType typeName##_##fieldName(typeName const * const me)

#endif // CBJECT_GETPROPFUNPROTOTYPE_H
