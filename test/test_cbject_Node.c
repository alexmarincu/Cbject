#include "CException.h"
#include "cbject.h"
#include "unity.h"

TEST_FILE("cbject_Node.c")
TEST_FILE("cbject_Object.c")

void setUp(void) {
}
void tearDown(void) {
}

/*************************************************************************************************** tag::test[]
= test_cbject_Node_init
====
Test Node initialization

.Steps
. Create an object and a node which takes the object as input
. Check node state
====
end::test[] ***************************************************************************************/
void test_cbject_Node_init(void) {
    cbject_Object * object = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Node * node = cbject_Node_init(cbject_utils_stackAlloc(cbject_Node), object);
    TEST_ASSERT(cbject_utils_isOfType(node, cbject_Node));
    TEST_ASSERT(cbject_Node_getElement(node) == object);
    TEST_ASSERT(cbject_Node_getPrevious(node) == NULL);
    TEST_ASSERT(cbject_Node_getNext(node) == NULL);
}

/*************************************************************************************************** tag::test[]
= test_cbject_Node_setters
====
Test Node setters

.Steps
. Create 3 nodes (node, previousNode, nextNode)
. Set previous and next nodes to the first node
. Check the node state
====
end::test[] ***************************************************************************************/
void test_cbject_Node_setters(void) {
    cbject_Node * node = cbject_Node_init(cbject_utils_stackAlloc(cbject_Node), NULL);
    cbject_Node * previousNode = cbject_Node_init(cbject_utils_stackAlloc(cbject_Node), NULL);
    cbject_Node * nextNode = cbject_Node_init(cbject_utils_stackAlloc(cbject_Node), NULL);
    TEST_ASSERT(cbject_Node_getPrevious(node) == NULL);
    cbject_Node_setPrevious(node, previousNode);
    TEST_ASSERT(cbject_Node_getPrevious(node) == previousNode);
    TEST_ASSERT(cbject_Node_getNext(node) == NULL);
    cbject_Node_setNext(node, nextNode);
    TEST_ASSERT(cbject_Node_getNext(node) == nextNode);
    cbject_utils_release(node);
}
