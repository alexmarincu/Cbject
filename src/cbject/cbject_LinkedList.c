#include "cbject_LinkedList.h"
#if (cbject_config_useLinkedList == true)
#if (cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)
#include "cbject_utils.h"

#define cbject_Class (cbject_LinkedList, cbject_Object)
#if (cbject_config_useStaticPool == true)
cbject_utils_allocPool(cbject_config_linkedListPoolSize);
#endif

cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const self,
    cbject_ObjectClass const * const elementClass,
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    cbject_LinkedList_NodeSource const nodeSource
#endif
) {
    cbject_utils_init(self);
    self->elementClass = elementClass;
    self->size = 0;
    self->first = NULL;
    self->last = NULL;
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    self->nodeSource = nodeSource;
#endif
    return self;
}

bool cbject_LinkedList_isEmpty(cbject_LinkedList const * const self) {
    return self->size == 0;
}

static cbject_Node * cbject_LinkedList_createNode(cbject_LinkedList * const self, cbject_Object * const object) {
    assert(cbject_Object_isOfType(object, self->elementClass));
    cbject_Node * node;
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    if (self->nodeSource == cbject_LinkedList_NodeSource_staticPool) {
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

void cbject_LinkedList_addLast(cbject_LinkedList * const self, cbject_Object * const object) {
    cbject_Node * node = cbject_LinkedList_createNode(self, object);
    if (self->last != NULL) {
        cbject_Node_setNext(self->last, node);
        cbject_Node_setPrevious(node, self->last);
        self->last = node;
    } else {
        self->first = node;
        self->last = node;
    }
    self->size++;
}

void cbject_LinkedList_addFirst(cbject_LinkedList * const self, cbject_Object * const object) {
    cbject_Node * node = cbject_LinkedList_createNode(self, object);
    if (self->first != NULL) {
        cbject_Node_setPrevious(self->first, node);
        cbject_Node_setNext(node, self->first);
        self->first = node;
    } else {
        self->first = node;
        self->last = node;
    }
    self->size++;
}

void cbject_LinkedList_removeLast(cbject_LinkedList * const self) {
    if (self->size != 0) {
        cbject_Node * node = self->last;
        self->last = cbject_Node_getPrevious(node);
        if (self->last != NULL) {
            cbject_Node_setNext(self->last, NULL);
        } else {
            self->first = NULL;
        }
        self->size--;
        cbject_utils_release(node);
    }
}

void cbject_LinkedList_removeFirst(cbject_LinkedList * const self) {
    if (self->size != 0) {
        cbject_Node * node = self->first;
        self->first = cbject_Node_getNext(node);
        if (self->first != NULL) {
            cbject_Node_setPrevious(self->first, NULL);
        } else {
            self->last = NULL;
        }
        self->size--;
        cbject_utils_release(node);
    }
}

void cbject_LinkedList_clear(cbject_LinkedList * const self) {
    while (self->last != NULL) {
        cbject_LinkedList_removeLast(self);
    }
}

cbject_Object * cbject_LinkedList_getFirst(cbject_LinkedList const * const self) {
    assert(self->first);
    return cbject_Node_getElement(self->first);
}

cbject_Object * cbject_LinkedList_getLast(cbject_LinkedList const * const self) {
    assert(self->first);
    return cbject_Node_getElement(self->last);
}

cbject_Object * cbject_LinkedList_get(cbject_LinkedList const * const self, uint64_t index) {
    assert(index < self->size);
    cbject_Node * node = self->first;
    for (uint64_t i = 0; i < index; i++) {
        node = cbject_Node_getNext(node);
    }
    return cbject_Node_getElement(node);
}

uint64_t cbject_LinkedList_getSize(cbject_LinkedList const * const self) {
    return self->size;
}

static cbject_Object * terminate(cbject_Object * const self) {
    cbject_LinkedList_clear((cbject_LinkedList *)self);
    return cbject_utils_invokeSuperMethod(cbject_Object, terminate, self);
}

cbject_LinkedListClass * cbject_LinkedListClass_instance(void) {
    static cbject_LinkedListClass self;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&self);
        ((cbject_ObjectClass *)&self)->terminate = terminate;
    }
    return &self;
}

#undef cbject_Class
#endif // (cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)
#endif // (cbject_config_useLinkedList == true)