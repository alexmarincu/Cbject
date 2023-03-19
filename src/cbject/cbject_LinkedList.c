#include "cbject_LinkedList.h"
#if (cbject_config_useLinkedList == true)
#if (cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)
#include "cbject_utils.h"

#define cbject_Class (cbject_LinkedList, cbject_Object)
#if (cbject_config_useStaticPool == true)
cbject_utils_allocPool(cbject_config_linkedListPoolSize);
#endif

cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const linkedList,
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    cbject_LinkedList_NodeSource const nodeSource
#endif
) {
    cbject_utils_init(linkedList);
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    linkedList->nodeSource = nodeSource;
#endif
    linkedList->size = 0;
    linkedList->first = NULL;
    linkedList->last = NULL;
    return linkedList;
}

bool cbject_LinkedList_isEmpty(cbject_LinkedList const * const linkedList) {
    return linkedList->size == 0;
}

static cbject_Node * cbject_LinkedList_createNode(cbject_LinkedList * const linkedList, cbject_Object * const object) {
    cbject_Node * node;
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    if (linkedList->nodeSource == cbject_LinkedList_NodeSource_staticPool) {
        node = cbject_utils_acquire(cbject_Node);
    } else {
        node = cbject_utils_alloc(cbject_Node);
    }
#elif (cbject_config_useStaticPool == true)
    node = cbject_utils_acquire(cbject_Node);
#elif (cbject_config_useHeap == true)
    node = cbject_utils_alloc(cbject_Node);
#endif
    node = cbject_Node_init(node, object);
    return node;
}

static void * cbject_LinkedList_destroyNode(cbject_LinkedList * const linkedList, cbject_Node * const node) {
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    if (linkedList->nodeSource == cbject_LinkedList_NodeSource_staticPool) {
        cbject_utils_release(node);
    } else {
        cbject_utils_dealloc(node);
    }
#elif (cbject_config_useStaticPool == true)
    cbject_utils_release(node);
#elif (cbject_config_useHeap == true)
    cbject_utils_dealloc(node);
#endif
    return NULL;
}

void cbject_LinkedList_addLast(cbject_LinkedList * const linkedList, cbject_Object * const object) {
    cbject_Node * node = cbject_LinkedList_createNode(linkedList, object);
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
    cbject_Node * node = cbject_LinkedList_createNode(linkedList, object);
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
    if (linkedList->size != 0) {
        cbject_Node * node = linkedList->last;
        linkedList->last = cbject_Node_getPrevious(node);
        if (linkedList->last != NULL) {
            cbject_Node_setNext(linkedList->last, NULL);
        } else {
            linkedList->first = NULL;
        }
        linkedList->size--;
        cbject_LinkedList_destroyNode(linkedList, node);
    }
}

void cbject_LinkedList_removeFirst(cbject_LinkedList * const linkedList) {
    if (linkedList->size != 0) {
        cbject_Node * node = linkedList->first;
        linkedList->first = cbject_Node_getNext(node);
        if (linkedList->first != NULL) {
            cbject_Node_setPrevious(linkedList->first, NULL);
        } else {
            linkedList->last = NULL;
        }
        linkedList->size--;
        cbject_LinkedList_destroyNode(linkedList, node);
    }
}

void cbject_LinkedList_clear(cbject_LinkedList * const linkedList) {
    while (linkedList->last != NULL) {
        cbject_LinkedList_removeLast(linkedList);
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
#endif // (cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)
#endif // (cbject_config_useLinkedList == true)