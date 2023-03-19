/*************************************************************************************************** tag::overview[]
Linked list data structure

[plantuml]
.Context diagram
----
!include ../src/cbject/cbject_LinkedList.h!cbject_LinkedList
!include ../src/cbject/cbject_LinkedList.h!cbject_LinkedListClass
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_ObjectClass
cbject_LinkedList -u-|> cbject_Object
cbject_Object -r-> cbject_LinkedListClass
cbject_LinkedListClass -u-|> cbject_ObjectClass
----
end::overview[] ***********************************************************************************/
#ifndef CBJECT_LINKEDLIST_H
#define CBJECT_LINKEDLIST_H
#include "cbject_config.h"
#if (cbject_config_useLinkedList == true)
#if (cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)
#include "cbject_Node.h"
#include "cbject_Object.h"

/*************************************************************************************************** tag::type[]
= cbject_LinkedList
====
----
typedef struct cbject_LinkedList cbject_LinkedList;
----
Typedef for struct cbject_LinkedList
====
end::type[] ***************************************************************************************/
typedef struct cbject_LinkedList cbject_LinkedList;

/*************************************************************************************************** tag::type[]
= cbject_LinkedListClass
====
----
typedef struct cbject_LinkedListClass cbject_LinkedListClass;
----
Typedef for struct cbject_LinkedListClass
====
end::type[] ***************************************************************************************/
typedef struct cbject_LinkedListClass cbject_LinkedListClass;

/*************************************************************************************************** tag::type[]
= cbject_LinkedList_NodeSource
====
----
typedef enum {
    cbject_LinkedList_NodeSource_heap,
    cbject_LinkedList_NodeSource_staticPool
} cbject_LinkedList_NodeSource;
----
Typedef and struct definition for cbject_LinkedList_NodeSource

.Remark
Used for linked list functionality

.Values
* heap
* staticPool
====
end::type[] ***************************************************************************************/
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
typedef enum {
    cbject_LinkedList_NodeSource_heap,
    cbject_LinkedList_NodeSource_staticPool
} cbject_LinkedList_NodeSource;
#endif

/*************************************************************************************************** tag::type[]
= struct cbject_LinkedList
====
----
struct cbject_LinkedList {
    cbject_Object object;
    cbject_LinkedList_NodeSource nodeSource;
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
};
----
Definition of struct cbject_LinkedList

.Members
* object - Parent
* nodeSource - Source for node creation (heap/staticPool)
* first - Reference to the first node in the list
* last - Reference to the last node in the list
* size - Size of the list (number of elements)
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_LinkedList)
object cbject_LinkedList {
    cbject_Object object;
    cbject_LinkedList_NodeSource nodeSource;
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
}
@enduml *******************************************************************************************/
struct cbject_LinkedList {
    cbject_Object object;
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    cbject_LinkedList_NodeSource nodeSource;
#endif
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
};

/*************************************************************************************************** tag::type[]
= struct cbject_LinkedListClass
====
----
struct cbject_LinkedListClass {
    cbject_ObjectClass objectClass;
};
----
Definition of struct cbject_LinkedListClass

.Members
* cbject_ObjectCLass - class of parent
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_LinkedListClass)
object cbject_LinkedListClass {
    cbject_ObjectClass objectClass;
}
@enduml *******************************************************************************************/
struct cbject_LinkedListClass {
    cbject_ObjectClass objectClass;
};

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_init()
====
----
cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const linkedList,
    cbject_LinkedList_NodeSource const nodeSource
);
----
Initializes a LinkedList

.Params
* linkedList - cbject_LinkedList reference
* nodeSource - Source for node creation (heap/staticPool)
.Return
Initialized and empty LinkedList
====
end::function[] ***********************************************************************************/
cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const linkedList,
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    cbject_LinkedList_NodeSource const nodeSource
#endif
);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_isEmpty()
====
----
bool cbject_LinkedList_isEmpty(cbject_LinkedList const * const linkedList);
----
Checks if list is empty

.Params
* linkedList - cbject_LinkedList reference

.Return
* true - if list is empty
* false - if list is not empty
====
end::function[] ***********************************************************************************/
bool cbject_LinkedList_isEmpty(cbject_LinkedList const * const linkedList);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_addLast()
====
----
void cbject_LinkedList_addLast(cbject_LinkedList * const linkedList, cbject_Object * const object);
----
Adds an element to the end of the list

.Params
* linkedList - cbject_LinkedList reference
* object - Object to be added in the list
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_addLast(cbject_LinkedList * const linkedList, cbject_Object * const object);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_addFirst()
====
----
void cbject_LinkedList_addFirst(cbject_LinkedList * const linkedList, cbject_Object * const object);
----
Adds an element at the beginning of the list

.Params
* linkedList - cbject_LinkedList reference
* object - Object to be added in the list
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_addFirst(cbject_LinkedList * const linkedList, cbject_Object * const object);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_removeLast()
====
----
void cbject_LinkedList_removeLast(cbject_LinkedList * const linkedList);
----
Removes last element in the list

.Params
* linkedList - cbject_LinkedList reference
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_removeLast(cbject_LinkedList * const linkedList);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_removeFirst()
====
----
void cbject_LinkedList_removeFirst(cbject_LinkedList * const linkedList);
----
Removes first element in the list

.Params
* linkedList - cbject_LinkedList reference
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_removeFirst(cbject_LinkedList * const linkedList);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_clear()
====
----
void cbject_LinkedList_clear(cbject_LinkedList * const linkedList);
----
Removes all elements from the list

.Params
* linkedList - cbject_LinkedList reference
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_clear(cbject_LinkedList * const linkedList);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_getFirst()
====
----
cbject_Node * cbject_LinkedList_getFirst(cbject_LinkedList const * const linkedList);
----
Gets the first element in the list

.Params
* linkedList - cbject_LinkedList reference

.Return
First element in list
====
end::function[] ***********************************************************************************/
cbject_Node * cbject_LinkedList_getFirst(cbject_LinkedList const * const linkedList);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_getLast()
====
----
cbject_Node * cbject_LinkedList_getLast(cbject_LinkedList const * const linkedList);
----
Gets the last element in the list

.Params
* linkedList - cbject_LinkedList reference

.Return
Last element in list
====
end::function[] ***********************************************************************************/
cbject_Node * cbject_LinkedList_getLast(cbject_LinkedList const * const linkedList);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_getSize()
====
----
uint64_t cbject_LinkedList_getSize(cbject_LinkedList const * const linkedList);
----
Gets the size of the list (number of elements)

.Params
* linkedList - cbject_LinkedList reference

.Return
Size of list (number of elements)
====
end::function[] ***********************************************************************************/
uint64_t cbject_LinkedList_getSize(cbject_LinkedList const * const linkedList);

/*************************************************************************************************** tag::function[]
= cbject_LinkedListClass_instance()
====
----
cbject_LinkedListClass * cbject_LinkedListClass_instance(void);
----
Gets cbject_LinkedListClass instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_LinkedListClass * cbject_LinkedListClass_instance(void);
#endif // (cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)
#endif // (cbject_config_useLinkedList == true)
#endif // CBJECT_LINKEDLIST_H
