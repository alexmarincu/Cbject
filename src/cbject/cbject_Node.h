/*************************************************************************************************** tag::overview[]
Node data structure used in linked lists

[plantuml, target=diag-node]
.Context diagram
----
!include ../src/cbject/cbject_Node.h!cbject_Node
!include ../src/cbject/cbject_Node.h!cbject_Node_Class
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_Object_Class
cbject_Node -u-|> cbject_Object
cbject_Object -r-> cbject_Node_Class
cbject_Node_Class -u-|> cbject_Object_Class
----
end::overview[] ***********************************************************************************/
#ifndef CBJECT_NODE_H
#define CBJECT_NODE_H
#include "cbject_config.h"
#if (cbject_config_useLinkedList == true) || (cbject_config_useNode == true)
#include "cbject_Object.h"

/*************************************************************************************************** tag::type[]
= cbject_Node
====
----
typedef struct cbject_Node cbject_Node;
----
Typedef for struct cbject_Node
====
end::type[] ***************************************************************************************/
typedef struct cbject_Node cbject_Node;

/*************************************************************************************************** tag::type[]
= cbject_Node_Class
====
----
typedef struct cbject_Node_Class cbject_Node_Class;
----
Typedef for struct cbject_Node_Class
====
end::type[] ***************************************************************************************/
typedef struct cbject_Node_Class cbject_Node_Class;

/*************************************************************************************************** tag::type[]
= struct cbject_Node
====
----
struct cbject_Node {
    cbject_Object super;
    cbject_Object * element;
    cbject_Node * previous;
    cbject_Node * next;

};
----
Definition of struct cbject_Node

.Members
* super - Parent
* element - Reference to the element
* previous - Reference to the previous node
* next - Reference to the next node
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_Node)
object cbject_Node {
    cbject_Object super;
    cbject_Object * element;
    cbject_Node * previous;
    cbject_Node * next;
}
@enduml *******************************************************************************************/
struct cbject_Node {
    cbject_Object super;
    cbject_Object * element;
    cbject_Node * previous;
    cbject_Node * next;
};

/*************************************************************************************************** tag::type[]
= struct cbject_Node_Class
====
----
struct cbject_Node_Class {
    cbject_Object_Class klass;
};
----
Definition of struct cbject_Node_Class

.Members
* super - Parent
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_Node_Class)
object cbject_Node_Class {
    cbject_Object_Class super;
}
@enduml *******************************************************************************************/
struct cbject_Node_Class {
    cbject_Object_Class super;
};

/*************************************************************************************************** tag::function[]
= cbject_Node_init()
====
----
cbject_Node * cbject_Node_init(cbject_Node * const self, cbject_Object * const object);
----
Initializes a Node

.Params
* self - cbject_Node reference
* object - Object to store in the node

.Return
Initialized Node
====
end::function[] ***********************************************************************************/
cbject_Node * cbject_Node_init(cbject_Node * const self, cbject_Object * const object);

/*************************************************************************************************** tag::function[]
= cbject_Node_getElement()
====
----
cbject_Object * cbject_Node_getElement(cbject_Node const * const self);
----
Gets the data object contained in the node

.Params
* self - cbject_Node reference

.Return
Data object in the node
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Node_getElement(cbject_Node const * const self);

/*************************************************************************************************** tag::function[]
= cbject_Node_getPrevious()
====
----
cbject_Node * cbject_Node_getPrevious(cbject_Node const * const self);
----
Gets the previous node

.Params
* self - cbject_Node reference

.Return
The previous node
====
end::function[] ***********************************************************************************/
cbject_Node * cbject_Node_getPrevious(cbject_Node const * const self);

/*************************************************************************************************** tag::function[]
= cbject_Node_setPrevious()
====
----
void cbject_Node_setPrevious(cbject_Node * const self, cbject_Node * const previousNode);
----
Sets the previous node

.Params
* self - cbject_Node reference
* previousNode - cbject_Node reference
====
end::function[] ***********************************************************************************/
void cbject_Node_setPrevious(cbject_Node * const self, cbject_Node * const previousNode);

/*************************************************************************************************** tag::function[]
= cbject_Node_getNext()
====
----
cbject_Node * cbject_Node_getNext(cbject_Node const * const self);
----
Gets the next node

.Params
* self - cbject_Node reference

.Return
The next node
====
end::function[] ***********************************************************************************/
cbject_Node * cbject_Node_getNext(cbject_Node const * const self);

/*************************************************************************************************** tag::function[]
= cbject_Node_setNext()
====
----
void cbject_Node_setNext(cbject_Node * const self, cbject_Node * const nextNode);
----
Sets the next node

.Params
* self - cbject_Node reference
* nextNode - cbject_Node reference
====
end::function[] ***********************************************************************************/
void cbject_Node_setNext(cbject_Node * const self, cbject_Node * const nextNode);

/*************************************************************************************************** tag::function[]
= cbject_Node_Class_instance()
====
----
cbject_Node_Class * cbject_Node_Class_instance(void);
----
Gets cbject_Node_Class instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_Node_Class * cbject_Node_Class_instance(void);

#endif // (cbject_config_useLinkedList == true) || (cbject_config_useNode == true)
#endif // CBJECT_NODE_H
