/*************************************************************************************************** tag::overview[]
Linked list data structure

[plantuml, target=diag-linkedList]
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
    cbject_Object super;
    cbject_ObjectClass const * elementClass;
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
    cbject_LinkedList_NodeSource nodeSource;
};
----
Definition of struct cbject_LinkedList

.Members
* super - Parent
* elementClass - Class of the elements stored in the list
* first - Reference to the first node in the list
* last - Reference to the last node in the list
* size - Size of the list (number of elements)
* nodeSource - Source for node creation (heap/staticPool)
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_LinkedList)
object cbject_LinkedList {
    cbject_Object super;
    cbject_ObjectClass const * elementClass;
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
    cbject_LinkedList_NodeSource nodeSource;
}
@enduml *******************************************************************************************/
struct cbject_LinkedList {
    cbject_Object super;
    cbject_ObjectClass const * elementClass;
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    cbject_LinkedList_NodeSource nodeSource;
#endif
};

/*************************************************************************************************** tag::type[]
= struct cbject_LinkedListClass
====
----
struct cbject_LinkedListClass {
    cbject_ObjectClass super;
};
----
Definition of struct cbject_LinkedListClass

.Members
* super - Parent
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_LinkedListClass)
object cbject_LinkedListClass {
    cbject_ObjectClass super;
}
@enduml *******************************************************************************************/
struct cbject_LinkedListClass {
    cbject_ObjectClass super;
};

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_init()
====
----
cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const self,
    cbject_LinkedList_NodeSource const nodeSource
);
----
Initializes a LinkedList

.Params
* self - cbject_LinkedList reference
* nodeSource - Source for node creation (heap/staticPool)
.Return
Initialized and empty LinkedList
====
end::function[] ***********************************************************************************/
cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const self,
    cbject_ObjectClass const * const elementClass,
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    cbject_LinkedList_NodeSource const nodeSource
#endif
);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_isEmpty()
====
----
bool cbject_LinkedList_isEmpty(cbject_LinkedList const * const self);
----
Checks if list is empty

.Params
* self - cbject_LinkedList reference

.Return
* true - if list is empty
* false - if list is not empty
====
end::function[] ***********************************************************************************/
bool cbject_LinkedList_isEmpty(cbject_LinkedList const * const self);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_addLast()
====
----
void cbject_LinkedList_addLast(cbject_LinkedList * const self, cbject_Object * const object);
----
Adds an element to the end of the list

.Params
* self - cbject_LinkedList reference
* object - Object to be added in the list
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_addLast(cbject_LinkedList * const self, cbject_Object * const object);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_addFirst()
====
----
void cbject_LinkedList_addFirst(cbject_LinkedList * const self, cbject_Object * const object);
----
Adds an element at the beginning of the list

.Params
* self - cbject_LinkedList reference
* object - Object to be added in the list
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_addFirst(cbject_LinkedList * const self, cbject_Object * const object);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_removeLast()
====
----
void cbject_LinkedList_removeLast(cbject_LinkedList * const self);
----
Removes last element in the list

.Params
* self - cbject_LinkedList reference
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_removeLast(cbject_LinkedList * const self);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_removeFirst()
====
----
void cbject_LinkedList_removeFirst(cbject_LinkedList * const self);
----
Removes first element in the list

.Params
* self - cbject_LinkedList reference
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_removeFirst(cbject_LinkedList * const self);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_clear()
====
----
void cbject_LinkedList_clear(cbject_LinkedList * const self);
----
Removes all elements from the list

.Params
* self - cbject_LinkedList reference
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_clear(cbject_LinkedList * const self);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_getFirst()
====
----
cbject_Object * cbject_LinkedList_getFirst(cbject_LinkedList const * const self);
----
Gets the first element in the list

.Params
* self - cbject_LinkedList reference

.Return
First element in list
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_LinkedList_getFirst(cbject_LinkedList const * const self);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_getLast()
====
----
cbject_Object * cbject_LinkedList_getLast(cbject_LinkedList const * const self);
----
Gets the last element in the list

.Params
* self - cbject_LinkedList reference

.Return
Last element in list
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_LinkedList_getLast(cbject_LinkedList const * const self);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_get()
====
----
cbject_Object * cbject_LinkedList_get(cbject_LinkedList const * const self, uint64_t index);
----
Gets element at specified index

.Params
* self - cbject_LinkedList reference
* index - index of the element to return

.Return
Element at specified index
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_LinkedList_get(cbject_LinkedList const * const self, uint64_t index);

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_getSize()
====
----
uint64_t cbject_LinkedList_getSize(cbject_LinkedList const * const self);
----
Gets the size of the list (number of elements)

.Params
* self - cbject_LinkedList reference

.Return
Size of list (number of elements)
====
end::function[] ***********************************************************************************/
uint64_t cbject_LinkedList_getSize(cbject_LinkedList const * const self);

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
