#include "super_CO.h"

UInt8 super_CO_objectSize(CO const * const _this) { return sizeof(*_this); }
UInt8 CO_objectSize(CO const * const _this) { return _this->_class->virtuals.objectSize(_this); }
char const * CO_classType(CO const * const _this) { return _this->_class->type; }
UInt8 COClass_size() { return sizeof(CO); }

COClass const * const COClass_getInstance()
{
    static COClass const _class = {
        .type = "CO",
        .virtuals = {.objectSize = super_CO_objectSize}};

    return &_class;
}

Void CO_init(CO * const _this) { _this->_class = COClass_getInstance(); }
