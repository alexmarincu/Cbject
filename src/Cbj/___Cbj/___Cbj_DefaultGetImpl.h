#ifndef ___CBJ_DEFAULTGETIMPL_H
#define ___CBJ_DEFAULTGETIMPL_H

#define ___Cbj_DefaultGetImpl(cbjType, propType, propName) \
    Get(propType, propName) { return me->props.propName; }

#endif // ___CBJ_DEFAULTGETIMPL_H
