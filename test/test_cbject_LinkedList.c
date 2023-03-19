#include "CException.h"
#include "cbject.h"
#include "cbject_LinkedList.h"
#include "cbject_Node.h"
#include "cbject_Object.h"
#include "cbject_utils.h"
#include "unity.h"

TEST_FILE("cbject_LinkedList.c")
TEST_FILE("cbject_Node.c")
TEST_FILE("cbject_Object.c")

void setUp(void) {
}
void tearDown(void) {
}

/*************************************************************************************************** tag::test[]
= test_cbject_LinkedList_init
====
Test LinkedList initialization

.Steps
. Create a linked list
. Check class and members
. Terminate the linked list
====
end::test[] ***************************************************************************************/
void test_cbject_LinkedList_init(void) {
    cbject_LinkedList * linkedList = cbject_LinkedList_init(
        cbject_utils_stackAlloc(cbject_LinkedList),
        cbject_LinkedList_NodeSource_heap
    );
    TEST_ASSERT(cbject_utils_isOfClass(linkedList, cbject_LinkedList));
    TEST_ASSERT(cbject_LinkedList_getFirst(linkedList) == NULL);
    TEST_ASSERT(cbject_LinkedList_getLast(linkedList) == NULL);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 0);
    TEST_ASSERT(cbject_LinkedList_isEmpty(linkedList) == true);
    cbject_utils_terminate(linkedList);
}

/*************************************************************************************************** tag::test[]
= test_cbject_LinkedList_addFirst
====
Test adding elements at beginning of LinkedList

.Preconditions
. Define a DataClass which extends cbject_ObjectClass

.Steps
. Create a linked list and some data objects
. Add the objects to the list and check the state of the list and the nodes
. Terminate the linked list
====
end::test[] ***************************************************************************************/
#define cbject_Class (Data, cbject_Object)
typedef struct Data Data;
typedef struct DataClass DataClass;
struct Data {
    cbject_Object object;
};
cbject_utils_allocPool(1);
struct DataClass {
    cbject_ObjectClass objectClass;
};
Data * Data_init(Data * const data) {
    cbject_utils_init(data);
    return data;
}
cbject_ObjectClass * DataClass_instance(void) {
    static cbject_ObjectClass klass;
    cbject_utils_doOnce {
        cbject_ObjectClass_setup(&klass);
    }
    return &klass;
}
#undef cbject_Class
void test_cbject_LinkedList_addFirst(void) {
    cbject_LinkedList * linkedLists[2];
    linkedLists[0] = cbject_LinkedList_init(
        cbject_utils_stackAlloc(cbject_LinkedList),
        cbject_LinkedList_NodeSource_heap
    );
    linkedLists[1] = cbject_LinkedList_init(
        cbject_utils_stackAlloc(cbject_LinkedList),
        cbject_LinkedList_NodeSource_staticPool
    );
    for (uint8_t i = 0; i < cbject_utils_Array_length(linkedLists); i++) {
        cbject_Object * data1 = (cbject_Object *)Data_init(cbject_utils_stackAlloc(Data));
        cbject_Object * data2 = (cbject_Object *)Data_init(cbject_utils_stackAlloc(Data));
        cbject_Object * data3 = (cbject_Object *)Data_init(cbject_utils_alloc(Data));
        cbject_Object * data4 = (cbject_Object *)Data_init(cbject_utils_acquire(Data));
        cbject_LinkedList_addFirst(linkedLists[i], data1);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedLists[i])) == data1);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedLists[i])) == data1);
        TEST_ASSERT(cbject_LinkedList_getSize(linkedLists[i]) == 1);
        cbject_LinkedList_addFirst(linkedLists[i], data2);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedLists[i])) == data2);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedLists[i])) == data1);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedLists[i]))) == data1);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedLists[i]))) == data2);
        TEST_ASSERT(cbject_LinkedList_getSize(linkedLists[i]) == 2);
        cbject_LinkedList_addFirst(linkedLists[i], data3);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedLists[i])) == data3);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedLists[i])) == data1);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedLists[i]))) == data2);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedLists[i]))) == data2);
        TEST_ASSERT(cbject_LinkedList_getSize(linkedLists[i]) == 3);
        cbject_LinkedList_addFirst(linkedLists[i], data4);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedLists[i])) == data4);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedLists[i])) == data1);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedLists[i]))) == data3);
        TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedLists[i]))) == data2);
        TEST_ASSERT(cbject_LinkedList_getSize(linkedLists[i]) == 4);
        TEST_ASSERT(cbject_LinkedList_isEmpty(linkedLists[i]) == false);
        cbject_utils_terminate(linkedLists[i]);
    }
}

/*************************************************************************************************** tag::test[]
= test_cbject_LinkedList_addLast
====
Test adding elements at the end of LinkedList

.Steps
. Create a linked list and some objects
. Add the objects to the list and check the state of the list and the nodes
. Terminate the linked list
====
end::test[] ***************************************************************************************/
void test_cbject_LinkedList_addLast(void) {
    cbject_LinkedList * linkedList = cbject_LinkedList_init(
        cbject_utils_stackAlloc(cbject_LinkedList),
        cbject_LinkedList_NodeSource_heap
    );
    cbject_Object * object1 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object2 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object3 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object4 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_LinkedList_addLast(linkedList, object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object1);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 1);
    cbject_LinkedList_addLast(linkedList, object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedList))) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedList))) == object1);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 2);
    cbject_LinkedList_addLast(linkedList, object3);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object3);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedList))) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedList))) == object2);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 3);
    cbject_LinkedList_addLast(linkedList, object4);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object4);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedList))) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedList))) == object3);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 4);
    TEST_ASSERT(cbject_LinkedList_isEmpty(linkedList) == false);
    cbject_utils_terminate(linkedList);
}

/*************************************************************************************************** tag::test[]
= test_cbject_LinkedList_removeFirst
====
Test removing elements at the beginning of the list

.Steps
. Create a linked list and some objects
. Add the objects to the list, remove them from the list and check the state of the list and the nodes
. Terminate the linked list
====
end::test[] ***************************************************************************************/
void test_cbject_LinkedList_removeFirst(void) {
    cbject_LinkedList * linkedList = cbject_LinkedList_init(
        cbject_utils_stackAlloc(cbject_LinkedList),
        cbject_LinkedList_NodeSource_heap
    );
    cbject_Object * object1 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object2 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object3 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object4 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_LinkedList_addFirst(linkedList, object1);
    cbject_LinkedList_addFirst(linkedList, object2);
    cbject_LinkedList_addFirst(linkedList, object3);
    cbject_LinkedList_addFirst(linkedList, object4);
    cbject_LinkedList_removeFirst(linkedList);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object3);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedList))) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedList))) == object2);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 3);
    cbject_LinkedList_removeFirst(linkedList);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedList))) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedList))) == object2);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 2);
    cbject_LinkedList_removeFirst(linkedList);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object1);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 1);
    cbject_LinkedList_removeFirst(linkedList);
    TEST_ASSERT(cbject_LinkedList_getFirst(linkedList) == NULL);
    TEST_ASSERT(cbject_LinkedList_getLast(linkedList) == NULL);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 0);
    TEST_ASSERT(cbject_LinkedList_isEmpty(linkedList) == true);
    cbject_LinkedList_removeFirst(linkedList);
    cbject_utils_terminate(linkedList);
}

/*************************************************************************************************** tag::test[]
= test_cbject_LinkedList_removeLast
====
Test removing elements at the end of the list

.Steps
. Create a linked list and some objects
. Add the objects to the list, remove them from the list and check the state of the list and the nodes
. Terminate the linked list
====
end::test[] ***************************************************************************************/
void test_cbject_LinkedList_removeLast(void) {
    cbject_LinkedList * linkedList = cbject_LinkedList_init(
        cbject_utils_stackAlloc(cbject_LinkedList),
        cbject_LinkedList_NodeSource_heap
    );
    cbject_Object * object1 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object2 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object3 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object4 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_LinkedList_addLast(linkedList, object1);
    cbject_LinkedList_addLast(linkedList, object2);
    cbject_LinkedList_addLast(linkedList, object3);
    cbject_LinkedList_addLast(linkedList, object4);
    cbject_LinkedList_removeLast(linkedList);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object3);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedList))) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedList))) == object2);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 3);
    cbject_LinkedList_removeLast(linkedList);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getNext(cbject_LinkedList_getFirst(linkedList))) == object2);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_Node_getPrevious(cbject_LinkedList_getLast(linkedList))) == object1);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 2);
    cbject_LinkedList_removeLast(linkedList);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getFirst(linkedList)) == object1);
    TEST_ASSERT(cbject_Node_getDataObject(cbject_LinkedList_getLast(linkedList)) == object1);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 1);
    cbject_LinkedList_removeLast(linkedList);
    TEST_ASSERT(cbject_LinkedList_getFirst(linkedList) == NULL);
    TEST_ASSERT(cbject_LinkedList_getLast(linkedList) == NULL);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 0);
    TEST_ASSERT(cbject_LinkedList_isEmpty(linkedList) == true);
    cbject_LinkedList_removeLast(linkedList);
    cbject_utils_terminate(linkedList);
}

/*************************************************************************************************** tag::test[]
= test_cbject_LinkedList_clear
====
Test clearing elements from a list

.Steps
. Create a linked list and some objects
. Add the objects to the list, clear the list and check the state of the list and the nodes
. Terminate the linked list
====
end::test[] ***************************************************************************************/
void test_cbject_LinkedList_clear(void) {
    cbject_LinkedList * linkedList = cbject_LinkedList_init(
        cbject_utils_stackAlloc(cbject_LinkedList),
        cbject_LinkedList_NodeSource_heap
    );
    cbject_Object * object1 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object2 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object3 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_Object * object4 = cbject_utils_init(cbject_utils_stackAlloc(cbject_Object));
    cbject_LinkedList_addLast(linkedList, object1);
    cbject_LinkedList_addLast(linkedList, object2);
    cbject_LinkedList_addLast(linkedList, object3);
    cbject_LinkedList_addLast(linkedList, object4);
    cbject_LinkedList_clear(linkedList);
    TEST_ASSERT(cbject_LinkedList_getFirst(linkedList) == NULL);
    TEST_ASSERT(cbject_LinkedList_getLast(linkedList) == NULL);
    TEST_ASSERT(cbject_LinkedList_getSize(linkedList) == 0);
    TEST_ASSERT(cbject_LinkedList_isEmpty(linkedList) == true);
    cbject_utils_terminate(linkedList);
}