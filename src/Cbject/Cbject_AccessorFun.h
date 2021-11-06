#ifndef CBJECT_ACCESSORFUN_H
#define CBJECT_ACCESSORFUN_H

#define Cbject_AccessorFun_Setter_Prototype_x(className, fieldType, fieldName) \
    void className##_##fieldName##Set(className * const me, fieldType const fieldName)

#define Cbject_AccessorFun_Setter_Prototype(className, fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Prototype_x(className, fieldType, fieldName)

#define Cbject_AccessorFun_Setter_Impl(className, fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Prototype(className, fieldType, fieldName) { me->data.fieldName = fieldName; }

#define Cbject_AccessorFun_Getter_Prototype_x(className, fieldType, fieldName) \
    fieldType className##_##fieldName(className const * const me)

#define Cbject_AccessorFun_Getter_Prototype(className, fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Prototype_x(className, fieldType, fieldName)

#define Cbject_AccessorFun_Getter_Impl(className, fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Prototype(className, fieldType, fieldName) { return me->data.fieldName; }

#endif // CBJECT_ACCESSORFUN_H
