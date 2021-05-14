#ifndef _CBJ_DEFAULTGETIMPL_H
#define _CBJ_DEFAULTGETIMPL_H

#define _Cbj_DefaultGetImpl(m_cbjType, propType, propName) \
    Get(propType, propName) { return me->props.propName; }

#endif // _CBJ_DEFAULTGETIMPL_H
