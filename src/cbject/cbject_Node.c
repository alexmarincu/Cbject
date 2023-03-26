#include "cbject_Node.h"
#if (cbject_config_useLinkedList == true) || (cbject_config_useNode == true)
#include "cbject_utils.h"

#define cbject_Class (cbject_Node, cbject_Object)
#if (cbject_config_useStaticPool == true)
cbject_utils_allocPool(cbject_config_nodePoolSize);
#endif

cbject_Node * cbject_Node_init(cbject_Node * const self, cbject_Object * const object) {
    cbject_utils_init(self);
    if (object) {
        cbject_utils_retain(object);
    }
    self->element = object;
    self->previous = NULL;
    self->next = NULL;
    return self;
}

cbject_Object * cbject_Node_getElement(cbject_Node const * const self) {
    return self->element;
}

cbject_Node * cbject_Node_getPrevious(cbject_Node const * const self) {
    return self->previous;
}

void cbject_Node_setPrevious(cbject_Node * const self, cbject_Node * const previousNode) {
    self->previous = previousNode;
}

cbject_Node * cbject_Node_getNext(cbject_Node const * const self) {
    return self->next;
}

void cbject_Node_setNext(cbject_Node * const self, cbject_Node * const nextNode) {
    self->next = nextNode;
}

static cbject_Object * terminate(cbject_Object * const self) {
    cbject_Node * node = (cbject_Node *)self;
    if (node->element) {
        cbject_utils_release(node->element);
    }
    return cbject_utils_invokeSuperMethod(cbject_Object, terminate, self);
}

cbject_NodeClass * cbject_NodeClass_instance(void) {
    static cbject_NodeClass self;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&self);
        ((cbject_ObjectClass *)&self)->terminate = terminate;
    }
    return &self;
}

#undef cbject_Class
#endif // (cbject_config_useLinkedList == true) || (cbject_config_useNode == true)