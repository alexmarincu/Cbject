#ifndef _CBJ_GET_H
#define _CBJ_GET_H

#define ___Cbj_Get(cbjType, ...) \
    ___##cbjType##_get(__VA_ARGS__)

#endif // _CBJ_GET_H
