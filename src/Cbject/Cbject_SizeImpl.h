#ifndef CBJECT_SIZEIMPL_H
#define CBJECT_SIZEIMPL_H

/*
Cbject_SizeImpl
*/
#define Cbject_SizeImpl(className) \
    static uint8 super_##className##_size(className const * const me) { return sizeof(*me); }

#endif // CBJECT_SIZEIMPL_H
