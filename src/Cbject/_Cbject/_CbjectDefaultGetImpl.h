#ifndef _CBJECTDEFAULTGETTERIMPL_H
#define _CBJECTDEFAULTGETTERIMPL_H

#define _CbjectDefaultGetImpl(cbjectTypeName, type, memberName) \
    Get(type, memberName) { return me->p.memberName; }

#endif // _CBJECTDEFAULTGETTERIMPL_H
