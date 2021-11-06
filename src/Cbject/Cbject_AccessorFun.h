#ifndef CBJECT_ACCESSORFUN_H
#define CBJECT_ACCESSORFUN_H

#define Cbject_AccessorFun_Setter_Prototype_do(typeName, fieldType, fieldName) \
    void typeName##_##fieldName##Set(typeName * const me, fieldType const fieldName)

#define Cbject_AccessorFun_Setter_Prototype(typeName, fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Prototype_do(typeName, fieldType, fieldName)

#define Cbject_AccessorFun_Setter_Impl(typeName, fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Prototype(typeName, fieldType, fieldName) { me->data.fieldName = fieldName; }

#define Cbject_AccessorFun_Getter_Prototype_do(typeName, fieldType, fieldName) \
    fieldType typeName##_##fieldName(typeName const * const me)

#define Cbject_AccessorFun_Getter_Prototype(typeName, fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Prototype_do(typeName, fieldType, fieldName)

#define Cbject_AccessorFun_Getter_Impl(typeName, fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Prototype(typeName, fieldType, fieldName) { return me->data.fieldName; }

#endif // CBJECT_ACCESSORFUN_H
