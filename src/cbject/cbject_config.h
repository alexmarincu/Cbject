/*************************************************************************************************** tag::overview[]
Cbject configuration
end::overview[] ***********************************************************************************/
#ifndef CBJECT_CONFIG_H
#define CBJECT_CONFIG_H

#ifdef TEST
#include "test_cbject_config.h"
#else

/*************************************************************************************************** tag::macro[]
= cbject_config_useHeap
====
----
#define cbject_config_useHeap configValue
----
Heap config

.Values
* true
* false
====
end::macro[] **************************************************************************************/
#define cbject_config_useHeap true

/*************************************************************************************************** tag::macro[]
= cbject_config_useStaticPool
====
----
#define cbject_config_useStaticPool configValue
----
Heap config

.Values
* true
* false
====
end::macro[] **************************************************************************************/
#define cbject_config_useStaticPool true

/*************************************************************************************************** tag::macro[]
= cbject_config_useLinkedList
====
----
#define cbject_config_useLinkedList configValue
----
Heap config

.Values
* true
* false
====
end::macro[] **************************************************************************************/
#define cbject_config_useLinkedList true

/*************************************************************************************************** tag::macro[]
= cbject_config_linkedListPoolSize
====
----
#define cbject_config_linkedListPoolSize configValue
----
Heap config

.Values
* >= 0
====
end::macro[] **************************************************************************************/
#if (cbject_config_useStaticPool == true)
#define cbject_config_linkedListPoolSize 0
#endif

/*************************************************************************************************** tag::macro[]
= cbject_config_useNode
====
----
#define cbject_config_useNode configValue
----
Heap config

.Values
* true
* false
====
end::macro[] **************************************************************************************/
#define cbject_config_useNode true

/*************************************************************************************************** tag::macro[]
= cbject_config_nodePoolSize
====
----
#define cbject_config_nodePoolSize configValue
----
Heap config

.Values
* >= 0
====
end::macro[] **************************************************************************************/
#if (cbject_config_useStaticPool == true)
#define cbject_config_nodePoolSize 0
#endif

/*************************************************************************************************** tag::macro[]
= cbject_config_useSingleton
====
----
#define cbject_config_useSingleton configValue
----
Heap config

.Values
* true
* false
====
end::macro[] **************************************************************************************/
#define cbject_config_useSingleton true

#endif // CBJECT_CONFIG_H
#endif