#ifndef CBJECT_STATICASSERT_H
#define CBJECT_STATICASSERT_H

#define Cbject_StaticAssert(condition, identifier) typedef char identifier[(!!(condition)) * 2 - 1]

#endif // CBJECT_STATICASSERT_H
