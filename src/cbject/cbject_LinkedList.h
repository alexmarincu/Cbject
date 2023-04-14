/*************************************************************************************************** tag::overview[]
Linked list data structure

[plantuml, target=diag-linkedList]
.Context diagram
----
!include ../src/cbject/cbject_LinkedList.h!cbject_LinkedList
!include ../src/cbject/cbject_LinkedList.h!cbject_LinkedList_Class
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_Object_Class
cbject_LinkedList -u-|> cbject_Object
cbject_Object -r-> cbject_LinkedList_Class
cbject_LinkedList_Class -u-|> cbject_Object_Class
----
end::overview[] ***********************************************************************************/
#ifndef CBJECT_LINKEDLIST_H
#define CBJECT_LINKEDLIST_H
#include "cbject_config.h"
#if (                                                                             \
    (cbject_config_useLinkedList == true) /**/                                    \
    && ((cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)) \
)
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
= cbject_LinkedList_Class
====
----
typedef struct cbject_LinkedList_Class cbject_LinkedList_Class;
----
Typedef for struct cbject_LinkedList_Class
====
end::type[] ***************************************************************************************/
typedef struct cbject_LinkedList_Class cbject_LinkedList_Class;

/*************************************************************************************************** tag::type[]
= struct cbject_LinkedList
====
----
struct cbject_LinkedList {
    cbject_Object super;
    cbject_Object_Class const * elementClass;
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
#if ((cbject_config_useHeap == true) && (cbject_config_useStaticPool == true))
    cbject_Object_Source nodeSource;
#endif
};
----
Definition of struct cbject_LinkedList

.Members
* super - Parent
* elementClass - Class of the elements stored in the list
* first - Reference to the first node in the list
* last - Reference to the last node in the list
* size - Size of the list (number of elements)
* nodeSource - Source for node creation (see cbject_Object_Source - only heap/staticPool is allowed)
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_LinkedList)
object cbject_LinkedList {
    cbject_Object super;
    cbject_Object_Class const * elementClass;
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
#if ((cbject_config_useHeap == true) && (cbject_config_useStaticPool == true))
    cbject_Object_Source nodeSource;
#endif
}
@enduml *******************************************************************************************/
struct cbject_LinkedList {
    cbject_Object super;
    cbject_Object_Class const * elementClass;
    cbject_Node * first;
    cbject_Node * last;
    uint64_t size;
#if ((cbject_config_useHeap == true) && (cbject_config_useStaticPool == true))
    cbject_Object_Source nodeSource;
#endif
};

/*************************************************************************************************** tag::type[]
= struct cbject_LinkedList_Class
====
----
struct cbject_LinkedList_Class {
    cbject_Object_Class super;
};
----
Definition of struct cbject_LinkedList_Class

.Members
* super - Parent
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_LinkedList_Class)
object cbject_LinkedList_Class {
    cbject_Object_Class super;
}
@enduml *******************************************************************************************/
struct cbject_LinkedList_Class {
    cbject_Object_Class super;
};

/*************************************************************************************************** tag::function[]
= cbject_LinkedList_init()
====
----
cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const self, cbject_Object_Class const * const elementClass,
#if ((cbject_config_useHeap == true) && (cbject_config_useStaticPool == true))
    cbject_Object_Source const nodeSource
#endif
);
----
Initializes a LinkedList

.Params
* self - cbject_LinkedList reference
* elementClass - Class of the elements stored in the list
* nodeSource - Memory source for node creation
                (see cbject_Object_Source - only heap/staticPool is allowed)

.Return
Initialized and empty LinkedList
====
end::function[] ***********************************************************************************/
cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const self, cbject_Object_Class const * const elementClass,
#if ((cbject_config_useHeap == true) && (cbject_config_useStaticPool == true))
    cbject_Object_Source const nodeSource
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
= cbject_LinkedList_add()
====
----
void cbject_LinkedList_add(
    cbject_LinkedList * const self, uint64_t const index, cbject_Object * const object
);
----
Adds an element to the end of the list

.Params
* self - cbject_LinkedList reference
* index - Index in the list where to add the object
* object - Object to be added in the list
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_add(
    cbject_LinkedList * const self, uint64_t const index, cbject_Object * const object
);

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
= cbject_LinkedList_remove()
====
----
void cbject_LinkedList_remove(cbject_LinkedList * const self, uint64_t const index);
----
Removes last element in the list at provided index

.Params
* self - cbject_LinkedList reference
* index - Index in the list from where to remove the object
====
end::function[] ***********************************************************************************/
void cbject_LinkedList_remove(cbject_LinkedList * const self, uint64_t const index);

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
= cbject_LinkedList_Class_instance()
====
----
cbject_LinkedList_Class * cbject_LinkedList_Class_instance(void);
----
Gets cbject_LinkedList_Class instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_LinkedList_Class * cbject_LinkedList_Class_instance(void);
#endif
#endif // CBJECT_LINKEDLIST_H
