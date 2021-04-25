#ifndef CBJECTDEFAULTGETTERIMPL_H
#define CBJECTDEFAULTGETTERIMPL_H

#define CbjectDefaultGetterImpl(klassName, type, memberName) \
    Getter(type, memberName) { return me->m.memberName; }

#endif // CBJECTDEFAULTGETTERIMPL_H
