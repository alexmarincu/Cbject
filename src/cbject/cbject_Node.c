#include "cbject_Node.h"
#include "cbject_config.h"
#include "cbject_utils.h"

#define cbject_Class (cbject_Node, cbject_Object)
#if cbject_config_useStaticPool == true
cbject_utils_allocPool(cbject_config_nodePoolSize);
#endif

cbject_Node * cbject_Node_init(cbject_Node * const node, cbject_Object * const object) {
    cbject_utils_init(node);
    node->dataObject = object;
    node->previous = NULL;
    node->next = NULL;
    return node;
}

cbject_Object * cbject_Node_getDataObject(cbject_Node const * const node) {
    return node->dataObject;
}

cbject_Node * cbject_Node_getPrevious(cbject_Node const * const node) {
    return node->previous;
}

void cbject_Node_setPrevious(cbject_Node * const node, cbject_Node * const previousNode) {
    node->previous = previousNode;
}

cbject_Node * cbject_Node_getNext(cbject_Node const * const node) {
    return node->next;
}

void cbject_Node_setNext(cbject_Node * const node, cbject_Node * const nextNode) {
    node->next = nextNode;
}

cbject_NodeClass * cbject_NodeClass_instance(void) {
    static cbject_NodeClass klass;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&klass);
    }
    return &klass;
}

#undef cbject_Class