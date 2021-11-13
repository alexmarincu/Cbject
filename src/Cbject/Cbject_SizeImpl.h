#ifndef CBJECT_SIZEIMPL_H
#define CBJECT_SIZEIMPL_H

/*
Cbject_SizeImpl
*/
#define Cbject_SizeImpl(class) \
    static uint8 super##class##_size(class const * const me) { return sizeof(*me); }

#endif // CBJECT_SIZEIMPL_H
