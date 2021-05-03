#ifndef _CBJECTSIZEIMPL_H
#define _CBJECTSIZEIMPL_H

#define _CbjectSizeImpl(klassName) \
    static uint8 s##klassName##_size(klassName const * const me) { return sizeof(*me); }

#endif // _CBJECTSIZEIMPL_H
