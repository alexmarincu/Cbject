#ifndef _CBJ_SIZEIMPL_H
#define _CBJ_SIZEIMPL_H

#define _Cbj_SizeImpl(cbjType) \
    static uint8 s_##cbjType##_size(cbjType const * const me) { return sizeof(*me); }

#endif // _CBJ_SIZEIMPL_H
