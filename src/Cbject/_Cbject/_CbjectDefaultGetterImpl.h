#ifndef _CBJECTDEFAULTGETTERIMPL_H
#define _CBJECTDEFAULTGETTERIMPL_H

#define _CbjectDefaultGetterImpl(klassName, type, memberName) \
    Getter(type, memberName) { return me->p.memberName; }

#endif // _CBJECTDEFAULTGETTERIMPL_H
