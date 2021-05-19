#ifndef ___CBJ_DEFAULTSETIMPL_H
#define ___CBJ_DEFAULTSETIMPL_H

#define ___Cbj_DefaultSetImpl(cbjType, propType, propName) \
    Set(propType, propName) { me->props.propName = propName; }

#endif // ___CBJ_DEFAULTSETIMPL_H
