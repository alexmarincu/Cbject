#ifndef _CBJ_NEW_H
#define _CBJ_NEW_H

#define ___Cbj_New(cbjType, ...) \
    ___##cbjType##_new(__VA_ARGS__)

#endif // _CBJ_NEW_H
