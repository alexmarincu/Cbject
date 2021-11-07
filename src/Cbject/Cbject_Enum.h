#ifndef CBJECT_ENUM_H
#define CBJECT_ENUM_H
#include "Cbject_Utils.h"

/*
Cbject_Enum
*/
#define Cbject_Enum_member_x1(className, member) \
    className##_##member,

#define Cbject_Enum_member_x0(className, member) \
    Cbject_Enum_member_x1(className, member)

#define Cbject_Enum_member(member) \
    Cbject_Enum_member_x0(Type, member)

#define Cbject_Enum(className, ...)                           \
    typedef enum className                                    \
    {                                                         \
        Cbject_Utils_forEach(Cbject_Enum_member, __VA_ARGS__) \
    } className

#endif // CBJECT_ENUM_H
