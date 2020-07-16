#include "super_CO.h"

UInt8 super_CO_objectSize(CO const * const _this) { return sizeof(*_this); }
UInt8 CO_objectSize(CO const * const _this) { return _this->_class->virtuals.objectSize(_this); }
char const * CO_classType(CO const * const _this) { return _this->_class->type; }
UInt8 CO_classSize() { return sizeof(CO); }

Void CO_init(CO * const _this)
{
    static COClass const _class = {
        .type = "CO",
        .virtuals = {.objectSize = super_CO_objectSize}};

    _this->_class = &_class;
}
