#ifndef _CBJ_SIZEIMPL_H
#define _CBJ_SIZEIMPL_H

#define _Cbj_SizeImpl(typeName) \
    static uint8 s_##typeName##_size(typeName const * const me) { return sizeof(*me); }

#endif // _CBJ_SIZEIMPL_H
