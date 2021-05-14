#ifndef _CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H
#define _CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H

#define _Cbj_CbjectTypeVirtFunsGetFunPrototype(m_cbjType) \
    m_cbjType##VirtFuns * m_cbjType##Type_virtFuns(m_cbjType##Type * meType)

#endif // _CBJ_CBJECTTYPEVIRTFUNSGETFUNPROTOTYPE_H
