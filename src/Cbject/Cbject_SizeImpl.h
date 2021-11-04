#ifndef CBJECT_SIZEIMPL_H
#define CBJECT_SIZEIMPL_H

#define Cbject_SizeImpl(typeName) \
    static uint8 super_##typeName##_size(typeName const * const me) { return sizeof(*me); }

#endif // CBJECT_SIZEIMPL_H
