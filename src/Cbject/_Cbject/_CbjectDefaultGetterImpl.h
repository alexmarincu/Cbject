#ifndef _CBJECTDEFAULTGETTERIMPL_H
#define _CBJECTDEFAULTGETTERIMPL_H

#define _CbjectDefaultGetterImpl(klassName, type, memberName) \
    Getter(type, memberName) { return me->m.memberName; }

#endif // _CBJECTDEFAULTGETTERIMPL_H
