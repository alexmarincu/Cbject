#include "super_CO.h"

UInt8 super_CO_objectSize(CO const * const this_) { return sizeof(*this_); }
UInt8 CO_objectSize(CO const * const this_) { return this_->class_->virtFun.objectSize(this_); }
char const * CO_classType(CO const * const this_) { return this_->class_->type; }
UInt8 COClass_size() { return sizeof(CO); }

COClass const * const COClass_getInstance()
{
    static COClass const class_ = {
        .type = "CO",
        .virtFun = {.objectSize = super_CO_objectSize}};

    return &class_;
}

Void CO_init(CO * const this_) { this_->class_ = COClass_getInstance(); }
