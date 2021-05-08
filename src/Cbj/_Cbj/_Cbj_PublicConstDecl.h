#ifndef _CBJ_PUBLICCONSTDECL_H
#define _CBJ_PUBLICCONSTDECL_H

#define _Cbj_PublicConstDecl(typeName, type, constName) \
    extern type const typeName##_##constName

#endif // _CBJ_PUBLICCONSTDECL_H
