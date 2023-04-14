/*************************************************************************************************** tag::overview[]
[plantuml, target=diag-singleton]
.Context diagram
----
!include ../src/cbject/cbject_Singleton.h!cbject_Singleton
!include ../src/cbject/cbject_Singleton.h!cbject_Singleton_Class
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_Object_Class
cbject_Singleton -u-|> cbject_Object
cbject_Object -r-> cbject_Singleton_Class
cbject_Singleton_Class -u-|> cbject_Object_Class
----
end::overview[] ***********************************************************************************/
#ifndef CBJECT_SINGLETON_H
#define CBJECT_SINGLETON_H
#include "cbject_config.h"
#if (cbject_config_useSingleton == true)
#include "cbject_Object.h"

/*************************************************************************************************** tag::type[]
= cbject_Singleton
====
----
typedef struct cbject_Singleton cbject_Singleton;
----
Typedef for struct cbject_Singleton
====
end::type[] ***************************************************************************************/
typedef struct cbject_Singleton cbject_Singleton;

/*************************************************************************************************** tag::type[]
= cbject_Singleton_Class
====
----
typedef struct cbject_Singleton_Class cbject_Singleton_Class;
----
Typedef for struct cbject_Singleton_Class
====
end::type[] ***************************************************************************************/
typedef struct cbject_Singleton_Class cbject_Singleton_Class;

/*************************************************************************************************** tag::type[]
= struct cbject_Singleton
====
----
struct cbject_Singleton {
    cbject_Object super;

};
----
Definition of struct cbject_Singleton

.Members
* super - Parent
====
end::type[] ***************************************************************************************/
/******************************************************************** @startuml(id=cbject_Singleton)
object cbject_Singleton {
    cbject_Object super;
}
@enduml *******************************************************************************************/
struct cbject_Singleton {
    cbject_Object super;
};

/*************************************************************************************************** tag::type[]
= struct cbject_Singleton_Class
====
----
struct cbject_Singleton_Class {
    cbject_Object_Class super;
};
----
Definition of struct cbject_Singleton_Class

.Members
* super - Parent
====
end::type[] ***************************************************************************************/
/*************************************************************** @startuml(id=cbject_Singleton_Class)
object cbject_Singleton_Class {
    cbject_Object_Class super;
}
@enduml *******************************************************************************************/
struct cbject_Singleton_Class {
    cbject_Object_Class super;
};

/*************************************************************************************************** tag::function[]
= cbject_Singleton_init()
====
----
cbject_Singleton * cbject_Singleton_init(cbject_Singleton * const self);
----
Initializes a singleton

.Params
* self - cbject_Singleton reference

.Return
Initialized singleton
====
end::function[] ***********************************************************************************/
cbject_Singleton * cbject_Singleton_init(cbject_Singleton * const self);

/*************************************************************************************************** tag::function[]
= cbject_Singleton_Class_instance()
====
----
cbject_Singleton_Class * cbject_Singleton_Class_instance(void);
----
Gets cbject_Singleton_Class instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_Singleton_Class * cbject_Singleton_Class_instance(void);

#endif
#endif // CBJECT_SINGLETON_H
