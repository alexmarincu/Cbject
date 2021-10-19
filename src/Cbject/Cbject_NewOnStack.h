#ifndef CBJECT_NEWONSTACK_H
#define CBJECT_NEWONSTACK_H

#define Cbject_NewOnStack(cbjType, ...) \
    ___##cbjType##_newOnStack((cbjType *) &((___##cbjType){}), __VA_ARGS__)

#endif // CBJECT_NEWONSTACK_H
