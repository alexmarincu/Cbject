#ifndef CBJECT_SETPROPFUN_H
#define CBJECT_SETPROPFUN_H

#define Cbject_SetPropFun_Prototype(typeName, fieldType, fieldName) \
    void typeName##_##fieldName##Set(typeName * const me, fieldType const fieldName)

#define Cbject_SetPropFun_DefaultImpl(typeName, fieldType, fieldName) \
    Cbject_SetPropFun_Prototype(typeName, fieldType, fieldName) { me->data.fieldName = fieldName; }

#endif // CBJECT_SETPROPFUN_H
