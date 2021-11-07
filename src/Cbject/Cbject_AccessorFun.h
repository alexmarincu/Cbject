#ifndef CBJECT_ACCESSORFUN_H
#define CBJECT_ACCESSORFUN_H

/*
Cbject_AccessorFun_Setter_Prototype
*/
#define Cbject_AccessorFun_Setter_Prototype_x0(className, fieldType, fieldName) \
    void className##_##fieldName##Set(className * const me, fieldType const fieldName)

#define Cbject_AccessorFun_Setter_Prototype(className, fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Prototype_x0(className, fieldType, fieldName)

/*
Cbject_AccessorFun_Setter_Impl
*/
#define Cbject_AccessorFun_Setter_Impl(className, fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Prototype(className, fieldType, fieldName) { me->data.fieldName = fieldName; }

/*
Cbject_AccessorFun_Getter_Prototype
*/
#define Cbject_AccessorFun_Getter_Prototype_x0(className, fieldType, fieldName) \
    fieldType className##_##fieldName(className const * const me)

#define Cbject_AccessorFun_Getter_Prototype(className, fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Prototype_x0(className, fieldType, fieldName)

/*
Cbject_AccessorFun_Getter_Impl
*/
#define Cbject_AccessorFun_Getter_Impl(className, fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Prototype(className, fieldType, fieldName) { return me->data.fieldName; }

#endif // CBJECT_ACCESSORFUN_H
