#include "cbject_LinkedList.h"
#include "cbject_config.h"
#include "cbject_utils.h"
#include <stdint.h>

#define cbject_Class (cbject_LinkedList, cbject_Object)
#if cbject_config_useStaticPool == true
cbject_utils_allocPool(cbject_config_linkedListPoolSize);
#endif

cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const linkedList,
    cbject_Object * (*nodeConstruct)(cbject_ObjectClass * const objectClass),
    void * (*nodeDestruct)(cbject_Object * const object)
) {
    cbject_utils_init(linkedList);
    linkedList->nodeConstruct = nodeConstruct;
    linkedList->nodeDestruct = nodeDestruct;
    linkedList->size = 0;
    linkedList->first = NULL;
    linkedList->last = NULL;
    return linkedList;
}

bool cbject_LinkedList_isEmpty(cbject_LinkedList const * const linkedList) {
    return linkedList->size == 0;
}

void cbject_LinkedList_addLast(cbject_LinkedList * const linkedList, cbject_Object * const object) {
    cbject_Node * node = cbject_Node_init(
        (cbject_Node *)linkedList->nodeConstruct((cbject_ObjectClass *)cbject_NodeClass_instance()),
        object
    );
    if (linkedList->last != NULL) {
        cbject_Node_setNext(linkedList->last, node);
        cbject_Node_setPrevious(node, linkedList->last);
        linkedList->last = node;
    } else {
        linkedList->first = node;
        linkedList->last = node;
    }
    linkedList->size++;
}

void cbject_LinkedList_addFirst(cbject_LinkedList * const linkedList, cbject_Object * const object) {
    cbject_Node * node = cbject_Node_init(
        (cbject_Node *)linkedList->nodeConstruct((cbject_ObjectClass *)cbject_NodeClass_instance()),
        object
    );
    if (linkedList->first != NULL) {
        cbject_Node_setPrevious(linkedList->first, node);
        cbject_Node_setNext(node, linkedList->first);
        linkedList->first = node;
    } else {
        linkedList->first = node;
        linkedList->last = node;
    }
    linkedList->size++;
}

void cbject_LinkedList_removeLast(cbject_LinkedList * const linkedList) {
    cbject_Node * node = linkedList->last;
    if (linkedList->last != linkedList->first) {
        linkedList->last = cbject_Node_getPrevious(linkedList->last);
        cbject_Node_setNext(linkedList->last, NULL);
    } else {
        linkedList->first = NULL;
        linkedList->last = NULL;
    }
    linkedList->size--;
    linkedList->nodeDestruct((cbject_Object *)node);
}

void cbject_LinkedList_removeFirst(cbject_LinkedList * const linkedList) {
    cbject_Node * node = linkedList->first;
    if (linkedList->first != linkedList->last) {
        linkedList->first = cbject_Node_getNext(linkedList->first);
        cbject_Node_setPrevious(linkedList->first, NULL);
    } else {
        linkedList->first = NULL;
        linkedList->last = NULL;
    }
    linkedList->size--;
    linkedList->nodeDestruct((cbject_Object *)node);
}

void cbject_LinkedList_clear(cbject_LinkedList * const linkedList) {
    if (linkedList->size != 0) {
        cbject_Node * currentNode = linkedList->first;
        while (cbject_Node_getNext(currentNode) != NULL) {
            cbject_Node * node = currentNode;
            currentNode = cbject_Node_getNext(currentNode);
            linkedList->nodeDestruct((cbject_Object *)node);
        }
        linkedList->size = 0;
        linkedList->first = NULL;
        linkedList->last = NULL;
    }
}

cbject_Node * cbject_LinkedList_getFirst(cbject_LinkedList const * const linkedList) {
    return linkedList->first;
}

cbject_Node * cbject_LinkedList_getLast(cbject_LinkedList const * const linkedList) {
    return linkedList->last;
}

uint64_t cbject_LinkedList_getSize(cbject_LinkedList const * const linkedList) {
    return linkedList->size;
}

static cbject_Object * terminate(cbject_Object * const object) {
    cbject_LinkedList_clear((cbject_LinkedList *)object);
    return cbject_utils_invokeSuperMethod(cbject_Object, terminate, object);
}

cbject_LinkedListClass * cbject_LinkedListClass_instance(void) {
    static cbject_LinkedListClass klass;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&klass);
        klass.objectClass.terminate = terminate;
    }
    return &klass;
}

#undef cbject_Class