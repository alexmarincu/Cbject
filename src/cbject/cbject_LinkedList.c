#include "cbject_LinkedList.h"
#if (cbject_config_useLinkedList == true)
#if (cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)
#include "cbject_internal.h"

#define cbject_Class (cbject_LinkedList, cbject_Object)
#if (cbject_config_useStaticPool == true)
cbject_allocPool(cbject_config_linkedListPoolSize);
#endif

cbject_LinkedList * cbject_LinkedList_init(
    cbject_LinkedList * const self,
    cbject_ObjectClass const * const elementClass,
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    cbject_LinkedList_NodeSource const nodeSource
#endif
) {
    cbject_init(self);
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

static cbject_Node * createNode(cbject_LinkedList * const self, cbject_Object * const object) {
    assert(cbject_isOfClass(object, self->elementClass));
    cbject_Node * node;
#if (cbject_config_useHeap == true) && (cbject_config_useStaticPool == true)
    if (self->nodeSource == cbject_LinkedList_NodeSource_staticPool) {
        node = cbject_acquire(cbject_Node);
    } else {
        node = cbject_alloc(cbject_Node);
    }
#elif (cbject_config_useStaticPool == true)
    node = cbject_acquire(cbject_Node);
#elif (cbject_config_useHeap == true)
    node = cbject_alloc(cbject_Node);
#endif
    node = cbject_Node_init(node, object);
    return node;
}

static cbject_Node * getNode(cbject_LinkedList const * const self, uint64_t index) {
    assert(index < self->size);
    cbject_Node * node;
    if (index <= self->size / 2) {
        node = self->first;
        for (uint64_t i = 0; i < index; i++) {
            node = cbject_Node_getNext(node);
        }
    } else {
        node = self->last;
        for (uint64_t i = self->size - 1; i > index; i--) {
            node = cbject_Node_getPrevious(node);
        }
    }
    return node;
}

void cbject_LinkedList_add(cbject_LinkedList * const self, uint64_t const index, cbject_Object * const object) {
    assert(index <= self->size);
    cbject_Node * newNode = createNode(self, object);
    if (self->size == 0) {
        self->first = newNode;
        self->last = newNode;
    } else {
        if (index == self->size) {
            cbject_Node * node = self->last;
            cbject_Node_setNext(node, newNode);
            cbject_Node_setPrevious(newNode, node);
            self->last = newNode;
        } else if (index == 0) {
            cbject_Node * node = self->first;
            cbject_Node_setNext(newNode, node);
            cbject_Node_setPrevious(node, newNode);
            self->first = newNode;
        } else {
            cbject_Node * node = getNode(self, index);
            cbject_Node_setNext(cbject_Node_getPrevious(node), newNode);
            cbject_Node_setPrevious(newNode, cbject_Node_getPrevious(node));
            cbject_Node_setNext(newNode, node);
            cbject_Node_setPrevious(node, newNode);
        }
    }
    self->size++;
}

void cbject_LinkedList_addFirst(cbject_LinkedList * const self, cbject_Object * const object) {
    cbject_LinkedList_add(self, 0, object);
}

void cbject_LinkedList_addLast(cbject_LinkedList * const self, cbject_Object * const object) {
    cbject_LinkedList_add(self, self->size, object);
}

void cbject_LinkedList_remove(cbject_LinkedList * const self, uint64_t const index) {
    assert(index < self->size);
    if (self->size == 1) {
        cbject_Node * node = self->first;
        cbject_release(node);
        self->first = NULL;
        self->last = NULL;
    } else {
        if (index == self->size - 1) {
            cbject_Node * node = self->last;
            self->last = cbject_Node_getPrevious(node);
            cbject_Node_setNext(self->last, NULL);
            cbject_release(node);
        } else if (index == 0) {
            cbject_Node * node = self->first;
            self->first = cbject_Node_getNext(node);
            cbject_Node_setPrevious(self->first, NULL);
            cbject_release(node);
        } else {
            cbject_Node * node = getNode(self, index);
            cbject_Node_setNext(cbject_Node_getPrevious(node), cbject_Node_getNext(node));
            cbject_Node_setPrevious(cbject_Node_getNext(node), cbject_Node_getPrevious(node));
            cbject_release(node);
        }
    }
    self->size--;
}

void cbject_LinkedList_removeFirst(cbject_LinkedList * const self) {
    cbject_LinkedList_remove(self, 0);
}

void cbject_LinkedList_removeLast(cbject_LinkedList * const self) {
    cbject_LinkedList_remove(self, self->size - 1);
}

void cbject_LinkedList_clear(cbject_LinkedList * const self) {
    while (self->size > 0) {
        cbject_LinkedList_removeLast(self);
    }
}

cbject_Object * cbject_LinkedList_getFirst(cbject_LinkedList const * const self) {
    return cbject_Node_getElement(self->first);
}

cbject_Object * cbject_LinkedList_getLast(cbject_LinkedList const * const self) {
    return cbject_Node_getElement(self->last);
}

cbject_Object * cbject_LinkedList_get(cbject_LinkedList const * const self, uint64_t index) {
    return cbject_Node_getElement(getNode(self, index));
}

uint64_t cbject_LinkedList_getSize(cbject_LinkedList const * const self) {
    return self->size;
}

static cbject_Object * terminate(cbject_Object * const self) {
    cbject_LinkedList_clear((cbject_LinkedList *)self);
    return cbject_invokeSuperMethod(cbject_Object, terminate, self);
}

cbject_LinkedListClass * cbject_LinkedListClass_instance(void) {
    static cbject_LinkedListClass self;
    cbject_doOnce {
        cbject_ObjectClass_setup(&self);
        ((cbject_ObjectClass *)&self)->terminate = terminate;
    }
    return &self;
}

#undef cbject_Class
#endif // (cbject_config_useHeap == true) || (cbject_config_useStaticPool == true)
#endif // (cbject_config_useLinkedList == true)