#ifndef ___CBJ_SIZEIMPL_H
#define ___CBJ_SIZEIMPL_H

#define ___Cbj_SizeImpl(cbjType) \
    static uint8 super_##cbjType##_size(cbjType const * const me) { return sizeof(*me); }

#endif // ___CBJ_SIZEIMPL_H
