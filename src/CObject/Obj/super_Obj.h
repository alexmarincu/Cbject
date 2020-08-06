#ifndef SUPER_OBJ_H
#define SUPER_OBJ_H
#include "Obj.h"

typedef struct ObjClass
{
    char const * type;

    struct
    {
        UInt8 (*objectSize)(Obj const * const this_);
    } virtFun;
} ObjClass;

struct Obj
{
    ObjClass const * class_;
};

ObjClass const * const ObjClass_instance();
UInt8 super_Obj_size(Obj const * const this_);

#endif // SUPER_OBJ_H
