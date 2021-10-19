#ifndef CBJECT_SIZEIMPL_H
#define CBJECT_SIZEIMPL_H

#define Cbject_SizeImpl(cbjType) \
    static uint8 super_##cbjType##_size(cbjType const * const me) { return sizeof(*me); }

#endif // CBJECT_SIZEIMPL_H
