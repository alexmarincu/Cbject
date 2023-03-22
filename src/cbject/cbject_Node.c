#include "cbject_Node.h"
#if (cbject_config_useLinkedList == true) || (cbject_config_useNode == true)
#include "cbject_utils.h"

#define cbject_Class (cbject_Node, cbject_Object)
#if (cbject_config_useStaticPool == true)
cbject_utils_allocPool(cbject_config_nodePoolSize);
#endif

cbject_Node * cbject_Node_init(cbject_Node * const node, cbject_Object * const object) {
    cbject_utils_init(node);
    node->element = object;
    node->previous = NULL;
    node->next = NULL;
    return node;
}

cbject_Object * cbject_Node_getElement(cbject_Node const * const node) {
    return node->element;
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

static cbject_Object * terminate(cbject_Object * const object) {
    cbject_Node * node = (cbject_Node *)object;
#if (cbject_config_useStaticPool == true) || (cbject_config_useHeap == true)
    switch (node->element->source) {
#if (cbject_config_useHeap == true)
        case cbject_Object_Source_heap:
            cbject_utils_dealloc(node->element);
            break;
#endif
#if (cbject_config_useStaticPool == true)
        case cbject_Object_Source_staticPool:
            cbject_utils_dispose(node->element);
            break;
#endif
        case cbject_Object_Source_stack:
        default:
            break;
    }
#endif
    return cbject_utils_invokeSuperMethod(cbject_Object, terminate, object);
}

cbject_NodeClass * cbject_NodeClass_instance(void) {
    static cbject_NodeClass klass;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&klass);
        klass.objectClass.terminate = terminate;
    }
    return &klass;
}

#undef cbject_Class
#endif // (cbject_config_useLinkedList == true) || (cbject_config_useNode == true)