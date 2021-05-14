#ifndef _CBJ_SIZEIMPL_H
#define _CBJ_SIZEIMPL_H

#define _Cbj_SizeImpl(m_cbjType) \
    static uint8 s_##m_cbjType##_size(m_cbjType const * const me) { return sizeof(*me); }

#endif // _CBJ_SIZEIMPL_H
