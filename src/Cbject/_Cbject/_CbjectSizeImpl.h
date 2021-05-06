#ifndef _CBJECTSIZEIMPL_H
#define _CBJECTSIZEIMPL_H

#define _CbjectSizeImpl(cbjectTypeName) \
    static uint8 s_##cbjectTypeName##_size(cbjectTypeName const * const me) { return sizeof(*me); }

#endif // _CBJECTSIZEIMPL_H
