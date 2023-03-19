/*************************************************************************************************** tag::overview[]
[plantuml, target=diag-singleton]
.Context diagram
----
!include ../src/cbject/cbject_Singleton.h!cbject_Singleton
!include ../src/cbject/cbject_Singleton.h!cbject_SingletonClass
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_ObjectClass
cbject_Singleton -u-|> cbject_Object
cbject_Object -r-> cbject_SingletonClass
cbject_SingletonClass -u-|> cbject_ObjectClass
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
= cbject_SingletonClass
====
----
typedef struct cbject_SingletonClass cbject_SingletonClass;
----
Typedef for struct cbject_SingletonClass
====
end::type[] ***************************************************************************************/
typedef struct cbject_SingletonClass cbject_SingletonClass;

/*************************************************************************************************** tag::type[]
= struct cbject_Singleton
====
----
struct cbject_Singleton {
    cbject_Object object;

};
----
Definition of struct cbject_Singleton

.Members
* object - Parent
====
end::type[] ***************************************************************************************/
/******************************************************************** @startuml(id=cbject_Singleton)
object cbject_Singleton {
    cbject_Object object;
}
@enduml *******************************************************************************************/
struct cbject_Singleton {
    cbject_Object object;
};

/*************************************************************************************************** tag::type[]
= struct cbject_SingletonClass
====
----
struct cbject_SingletonClass {
    cbject_ObjectClass objectClass;
};
----
Definition of struct cbject_SingletonClass

.Members
* cbject_ObjectCLass - class of parent
====
end::type[] ***************************************************************************************/
/*************************************************************** @startuml(id=cbject_SingletonClass)
object cbject_SingletonClass {
    cbject_ObjectClass objectClass;
}
@enduml *******************************************************************************************/
struct cbject_SingletonClass {
    cbject_ObjectClass objectClass;
};

/*************************************************************************************************** tag::function[]
= cbject_Singleton_init()
====
----
cbject_Singleton * cbject_Singleton_init(cbject_Singleton * const singleton);
----
Initializes a singleton

.Params
* singleton - cbject_Singleton reference

.Return
Initialized singleton
====
end::function[] ***********************************************************************************/
cbject_Singleton * cbject_Singleton_init(cbject_Singleton * const singleton);

/*************************************************************************************************** tag::function[]
= cbject_SingletonClass_instance()
====
----
cbject_SingletonClass * cbject_SingletonClass_instance(void);
----
Gets cbject_SingletonClass instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_SingletonClass * cbject_SingletonClass_instance(void);

#endif // (cbject_config_useSingleton == true)
#endif // CBJECT_SINGLETON_H
