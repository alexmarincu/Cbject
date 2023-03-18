/*************************************************************************************************** tag::overview[]
Node data structure used in linked lists

[plantuml]
.Context diagram
----
!include ../src/cbject/cbject_Node.h!cbject_Node
!include ../src/cbject/cbject_Node.h!cbject_NodeClass
!include ../src/cbject/cbject_Object.h!cbject_Object
!include ../src/cbject/cbject_Object.h!cbject_ObjectClass
cbject_Node -u-|> cbject_Object
cbject_Object -r-> cbject_NodeClass
cbject_NodeClass -u-|> cbject_ObjectClass
----
end::overview[] ***********************************************************************************/
#ifndef CBJECT_NODE_H
#define CBJECT_NODE_H
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
= cbject_NodeClass
====
----
typedef struct cbject_NodeClass cbject_NodeClass;
----
Typedef for struct cbject_NodeClass
====
end::type[] ***************************************************************************************/
typedef struct cbject_NodeClass cbject_NodeClass;

/*************************************************************************************************** tag::type[]
= struct cbject_Node
====
----
struct cbject_Node {
    cbject_Object object;
    cbject_Object * dataObject;
    cbject_Node * previous;
    cbject_Node * next;

};
----
Definition of struct cbject_Node

.Members
* object - Parent
* dataObject - Reference to the data object
* previous - Reference to the previous node
* next - Reference to the next node
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_Node)
object cbject_Node {
    cbject_Object object;
    cbject_Object * dataObject;
    cbject_Node * previous;
    cbject_Node * next;
}
@enduml *******************************************************************************************/
struct cbject_Node {
    cbject_Object object;
    cbject_Object * dataObject;
    cbject_Node * previous;
    cbject_Node * next;
};

/*************************************************************************************************** tag::type[]
= struct cbject_NodeClass
====
----
struct cbject_NodeClass {
    cbject_ObjectClass objectClass;
};
----
Definition of struct cbject_NodeClass

.Members
* cbject_ObjectCLass - class of parent
====
end::type[] ***************************************************************************************/
/*************************************************************************************************** @startuml(id=cbject_NodeClass)
object cbject_NodeClass {
    cbject_ObjectClass objectClass;
}
@enduml *******************************************************************************************/
struct cbject_NodeClass {
    cbject_ObjectClass objectClass;
};

/*************************************************************************************************** tag::function[]
= cbject_Node_init()
====
----
cbject_Node * cbject_Node_init(cbject_Node * const node, cbject_Object * const object);
----
Initializes a Node

.Params
* node - cbject_Node reference
* object - Object to store in the node

.Return
Initialized Node
====
end::function[] ***********************************************************************************/
cbject_Node * cbject_Node_init(cbject_Node * const node, cbject_Object * const object);

/*************************************************************************************************** tag::function[]
= cbject_Node_getDataObject()
====
----
cbject_Object * cbject_Node_getDataObject(cbject_Node const * const node);
----
Gets the data object contained in the node

.Params
* node - cbject_Node reference

.Return
Data object in the node
====
end::function[] ***********************************************************************************/
cbject_Object * cbject_Node_getDataObject(cbject_Node const * const node);

/*************************************************************************************************** tag::function[]
= cbject_Node_getPrevious()
====
----
cbject_Node * cbject_Node_getPrevious(cbject_Node const * const node);
----
Gets the previous node

.Params
* node - cbject_Node reference

.Return
The previous node
====
end::function[] ***********************************************************************************/
cbject_Node * cbject_Node_getPrevious(cbject_Node const * const node);

/*************************************************************************************************** tag::function[]
= cbject_Node_setPrevious()
====
----
void cbject_Node_setPrevious(cbject_Node * const node, cbject_Node * const previousNode);
----
Sets the previous node

.Params
* node - cbject_Node reference
* previousNode - cbject_Node reference
====
end::function[] ***********************************************************************************/
void cbject_Node_setPrevious(cbject_Node * const node, cbject_Node * const previousNode);

/*************************************************************************************************** tag::function[]
= cbject_Node_getNext()
====
----
cbject_Node * cbject_Node_getNext(cbject_Node const * const node);
----
Gets the next node

.Params
* node - cbject_Node reference

.Return
The next node
====
end::function[] ***********************************************************************************/
cbject_Node * cbject_Node_getNext(cbject_Node const * const node);

/*************************************************************************************************** tag::function[]
= cbject_Node_setNext()
====
----
void cbject_Node_setNext(cbject_Node * const node, cbject_Node * const nextNode);
----
Sets the next node

.Params
* node - cbject_Node reference
* nextNode - cbject_Node reference
====
end::function[] ***********************************************************************************/
void cbject_Node_setNext(cbject_Node * const node, cbject_Node * const nextNode);

/*************************************************************************************************** tag::function[]
= cbject_NodeClass_instance()
====
----
cbject_NodeClass * cbject_NodeClass_instance(void);
----
Gets cbject_NodeClass instance

.Return
Reference of the class instance
====
end::function[] ***********************************************************************************/
cbject_NodeClass * cbject_NodeClass_instance(void);

#endif // CBJECT_NODE_H
