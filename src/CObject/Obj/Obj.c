#include "super_Obj.h"

UInt8 super_Obj_size(Obj const * const this_) { return sizeof(*this_); }
UInt8 Obj_size(Obj const * const this_) { return this_->class_->virtFun.objectSize(this_); }
char const * Obj_type(Obj const * const this_) { return this_->class_->type; }
UInt8 ObjClass_size() { return sizeof(Obj); }

ObjClass const * const ObjClass_instance()
{
    static ObjClass const class_ = {
        .type = "Obj",
        .virtFun = {.objectSize = super_Obj_size}};

    return &class_;
}

Void Obj_init(Obj * const this_) { this_->class_ = ObjClass_instance(); }
