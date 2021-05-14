#ifndef _CBJ_PUBLICCONSTDECL_H
#define _CBJ_PUBLICCONSTDECL_H

#define _Cbj_PublicConstDecl(m_cbjType, constType, constName) \
    extern constType const m_cbjType##_##constName

#endif // _CBJ_PUBLICCONSTDECL_H
