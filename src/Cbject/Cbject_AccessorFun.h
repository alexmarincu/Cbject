#ifndef CBJECT_ACCESSORFUN_H
#define CBJECT_ACCESSORFUN_H

/*
Cbject_AccessorFun_Setter_Prototype
*/
#define Cbject_AccessorFun_Setter_Prototype_x0(class, dataMemberType, dataMember) \
    void class##_##dataMember##Set(class * const me, dataMemberType const dataMember)

#define Cbject_AccessorFun_Setter_Prototype(class, dataMemberType, dataMember) \
    Cbject_AccessorFun_Setter_Prototype_x0(class, dataMemberType, dataMember)

/*
Cbject_AccessorFun_Setter_Impl
*/
#define Cbject_AccessorFun_Setter_Impl(class, dataMemberType, dataMember) \
    Cbject_AccessorFun_Setter_Prototype(class, dataMemberType, dataMember) { me->data.dataMember = dataMember; }

/*
Cbject_AccessorFun_Getter_Prototype
*/
#define Cbject_AccessorFun_Getter_Prototype_x0(class, dataMemberType, dataMember) \
    dataMemberType class##_##dataMember(class const * const me)

#define Cbject_AccessorFun_Getter_Prototype(class, dataMemberType, dataMember) \
    Cbject_AccessorFun_Getter_Prototype_x0(class, dataMemberType, dataMember)

/*
Cbject_AccessorFun_Getter_Impl
*/
#define Cbject_AccessorFun_Getter_Impl(class, dataMemberType, dataMember) \
    Cbject_AccessorFun_Getter_Prototype(class, dataMemberType, dataMember) { return me->data.dataMember; }

#endif // CBJECT_ACCESSORFUN_H
