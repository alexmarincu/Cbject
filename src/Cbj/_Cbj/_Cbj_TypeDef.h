#ifndef _CBJ_TYPEDEF_H
#define _CBJ_TYPEDEF_H

#define _Cbj_TypeDef(m_cbjType, mParent) \
    struct m_cbjType                    \
    {                                 \
        _##mParent s;                  \
        m_cbjType##Props props;             \
    }

#endif // _CBJ_TYPEDEF_H
