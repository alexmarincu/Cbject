#ifndef _CBJ_NEWONSTACK_H
#define _CBJ_NEWONSTACK_H
#include <string.h>

#define _Cbj_NewOnStack(m_cbjType, varName, ...)               \
    m_cbjType * const varName = (m_cbjType *) &((_##m_cbjType){}); \
    memset(varName, 0, sizeof(_##m_cbjType));                  \
    m_cbjType##_init((m_cbjType *) varName, __VA_ARGS__)

#endif // _CBJ_NEWONSTACK_H
