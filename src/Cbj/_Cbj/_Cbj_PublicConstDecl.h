#ifndef _CBJ_PUBLICCONSTDECL_H
#define _CBJ_PUBLICCONSTDECL_H

#define _Cbj_PublicConstDecl(cbjType, constType, constName) \
    extern constType const cbjType##_##constName

#endif // _CBJ_PUBLICCONSTDECL_H
