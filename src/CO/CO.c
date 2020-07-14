#include "super_CO.h"

UInt8 super_CO_objectSize(CO const * const _this) { return sizeof(*_this); }
UInt8 CO_objectSize(CO const * const _this) { return _this->_class->objectSize(_this); }

Void CO_init(CO * const _this)
{
    static COClass const _class = {.objectSize = super_CO_objectSize};
    _this->_class = &_class;
}
