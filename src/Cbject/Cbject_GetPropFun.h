#ifndef CBJECT_GETPROPFUN_H
#define CBJECT_GETPROPFUN_H

#define Cbject_GetPropFun_Prototype(typeName, fieldType, fieldName) \
    fieldType typeName##_##fieldName(typeName const * const me)

#define Cbject_GetPropFun_DefaultImpl(typeName, fieldType, fieldName) \
    Cbject_GetPropFun_Prototype(typeName, fieldType, fieldName) { return me->data.fieldName; }

#endif // CBJECT_GETPROPFUN_H
