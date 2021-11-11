#ifndef CBJECT_ENUM_H
#define CBJECT_ENUM_H
#include "Cbject_Utils.h"

/*
Cbject_Enum
*/
#define Cbject_Enum_member_x1(class, member) \
    class##_##member,

#define Cbject_Enum_member_x0(class, member) \
    Cbject_Enum_member_x1(class, member)

#define Cbject_Enum_member(member) \
    Cbject_Enum_member_x0(Type, member)

#define Cbject_Enum(class, ...)                               \
    typedef enum class                                        \
    {                                                         \
        Cbject_Utils_forEach(Cbject_Enum_member, __VA_ARGS__) \
    } class

#endif // CBJECT_ENUM_H
