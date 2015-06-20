#include "unity.h"
#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>



void setUp(void)
{
}

void tearDown(void)
{
}

/**
 * Testing function LinkedList.
 *
 *    ptr---+-->head-----+
 *          |            |
 *          +-->tail-----+
 *                       |
 *                       v
 *                      NULL
 */
void test_function_createLinkedList()
{
  LinkedList *ptr;
  ptr = createLinkedList();

	TEST_ASSERT_NOT_NULL(ptr);
  TEST_ASSERT_NULL(ptr->head);
  TEST_ASSERT_NULL(ptr->tail);
  TEST_ASSERT_EQUAL(0,ptr->length);
}

/**
 * Testing function createListElement.
 *            ___________
 *   ptr---->|  value=1 |
 *           |__________|---->NULL
 *
 */
void test_function_createListElement()
{
  ListElement *NewNode;

  NewNode = createListElement(1);

  TEST_ASSERT_NOT_NULL(NewNode);
  TEST_ASSERT_EQUAL(1,NewNode->value);
  TEST_ASSERT_EQUAL(NULL,NewNode->next);
}


/**
 * Testing function stackAdd and addList when one element added to the LinkedList.
 *
 *                                   ___________
 *    addListPtr---+-->head-------->|  value=5 |
 *                 |                |__________|---->NULL
 *                 |                    ^
 *                 |                    |
 *                 +-->tail-------------+
 *
 *                                    ___________
 *    stackAddPtr---+-->head-------->|  value=5 |
 *                  |                |__________|---->NULL
 *                  |                    ^
 *                  |                    |
 *                  +-->tail-------------+
 */
void test_Adding_element_to_LinkedList_using_function_addList_and_stackAdd()
{
  LinkedList *addListPtr;
  LinkedList *stackAddPtr;

  addListPtr  = createLinkedList();
	stackAddPtr = createLinkedList();

  addList(createListElement(5),addListPtr);
	stackAdd(stackAddPtr,createListElement(5));

  TEST_ASSERT_EQUAL(5,addListPtr->head->value);
  TEST_ASSERT_NULL(addListPtr->head->next);
  TEST_ASSERT_EQUAL(5,addListPtr->tail->value);
  TEST_ASSERT_NULL(addListPtr->tail->next);
  TEST_ASSERT_EQUAL(1,addListPtr->length);

  TEST_ASSERT_EQUAL(5,stackAddPtr->head->value);
  TEST_ASSERT_NULL(stackAddPtr->head->next);
  TEST_ASSERT_EQUAL(5,stackAddPtr->tail->value);
  TEST_ASSERT_NULL(stackAddPtr->tail->next);
  TEST_ASSERT_EQUAL(1,stackAddPtr->length);
}


 /**
 * Testing function addList when two element added to the LinkedList.
 *
 *                      1st Ele         2nd Ele
 *                      _________      _________
 *    ptr---+-->head-->| value=1|     | value=2|
 *          |          |________|---->|________|---->NULL
 *          |                             ^
 *          |                             |
 *          +-->tail----------------------+
 *
 */
void test_Adding_two_element_to_LinkedList_using_function_addList()
{
  int i;
  LinkedList *ptr;
  ptr=createLinkedList();

  for(i=1;i<=2;i++){
    addList(createListElement(i),ptr);
  }

  TEST_ASSERT_EQUAL(1,ptr->head->value);
  TEST_ASSERT_EQUAL_PTR(ptr->tail,ptr->head->next);
  TEST_ASSERT_EQUAL(2,ptr->tail->value);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(2,ptr->length);
}

 /**
 * Testing function stackAdd when two element added to the LinkedList.
 *
 *                      2nd Ele         1st Ele
 *                      _________      _________
 *    ptr---+-->head-->| value=2|     | value=1|
 *          |          |________|---->|________|---->NULL
 *          |                             ^
 *          |                             |
 *          +-->tail----------------------+
 *
 */
void test_Adding_two_element_to_LinkedList_using_function_stackAdd()
{
  int i;
  LinkedList *ptr;

  ptr=createLinkedList();

  for(i=1;i<=2;i++){
    stackAdd(ptr,createListElement(i));
  }

  TEST_ASSERT_EQUAL(2,ptr->head->value);
  TEST_ASSERT_EQUAL_PTR(ptr->tail,ptr->head->next);
  TEST_ASSERT_EQUAL(1,ptr->tail->value);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(2,ptr->length);
}

 /**
 * Testing function addList when three element added to the LinkedList.
 *
 *                    1st Ele        2nd Ele        3rd Ele
 *                   _________      _________      _________
 * ptr---+-->head-->| value=1|     | value=2|     | value=3|
 *       |          |________|---->|________|---->|________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 */
void test_Adding_three_element_to_LinkedList_using_function_addList()
{
  int i;
  LinkedList *ptr;

  ptr=createLinkedList();

  for(i=1;i<=3;i++){
    addList(createListElement(i),ptr);
  }

  TEST_ASSERT_EQUAL(1,ptr->head->value);
  TEST_ASSERT_EQUAL_PTR(ptr->tail,ptr->head->next->next);
  TEST_ASSERT_EQUAL(3,ptr->tail->value);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(3,ptr->length);
}


 /**
 * Testing function stackAdd when three element added to the LinkedList.
 *
 *                    3rd Ele        2nd Ele        1st Ele
 *                   _________      _________      _________
 * ptr---+-->head-->| value=3|     | value=2|     | value=1|
 *       |          |________|---->|________|---->|________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 */
void test_Adding_three_element_to_LinkedList_using_function_stackAdd()
{
  int i;
  LinkedList *ptr;

  ptr=createLinkedList();

  for(i=1;i<=3;i++){
    stackAdd(ptr,createListElement(i));
  }

  TEST_ASSERT_EQUAL(3,ptr->head->value);
  TEST_ASSERT_EQUAL_PTR(ptr->tail,ptr->head->next->next);
  TEST_ASSERT_EQUAL(1,ptr->tail->value);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(3,ptr->length);

}

 /**
 * the following test is to prevent the situation below not happening.
 * Which is the NULL element is adding to the LinkedList.
 *                   _________                     _________
 * ptr---+-->head-->| value=3 |                   | value=1|
 *       |          |________|---->NULL           |________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 */
void test_stackAdd_and_addList_given_Element_equal_NULL_Should_do_nothing()
{
  int i;
  LinkedList *addListPtr;
  LinkedList *stackAddPtr;

  stackAddPtr=createLinkedList();
  addListPtr=createLinkedList();

  stackAdd(stackAddPtr,createListElement(1));
  stackAdd(stackAddPtr,NULL);
  stackAdd(stackAddPtr,createListElement(3));

  TEST_ASSERT_EQUAL(3,stackAddPtr->head->value);
  TEST_ASSERT_EQUAL_PTR(stackAddPtr->tail,stackAddPtr->head->next);
  TEST_ASSERT_EQUAL(1,stackAddPtr->tail->value);
  TEST_ASSERT_NULL(stackAddPtr->tail->next);
  TEST_ASSERT_EQUAL(2,stackAddPtr->length);

  addList(createListElement(1),addListPtr);
  addList(NULL,addListPtr);
  addList(createListElement(3),addListPtr);

  TEST_ASSERT_EQUAL(1,addListPtr->head->value);
  TEST_ASSERT_EQUAL_PTR(addListPtr->tail,addListPtr->head->next);
  TEST_ASSERT_EQUAL(3,addListPtr->tail->value);
  TEST_ASSERT_NULL(addListPtr->tail->next);
  TEST_ASSERT_EQUAL(2,addListPtr->length);
}

 /**
 * Testing function addList when five element added to the LinkedList
 *
 *                     1st Ele                          5th Ele
 *                   ____________                     ____________
 * ptr---+-->head-->| value=95  |                    | value=123 |
 *       |          |___________|----> * * * * *---->|___________|---->NULL
 *       |                                                 ^
 *       |                                                 |
 *       +-->tail------------------------------------------+
 *
 */
void test_Five_Element_Added_to_the_List_using_addList()
{
  LinkedList *ptr;
  ptr = createLinkedList();

  addList(createListElement(95),ptr);
  TEST_ASSERT_EQUAL(95 , ptr -> tail->value);

  addList(createListElement(100),ptr);
  TEST_ASSERT_EQUAL(100 , ptr -> tail->value);

  addList(createListElement(14),ptr);
  TEST_ASSERT_EQUAL(14 , ptr -> tail->value);

  addList(createListElement(111),ptr);
  TEST_ASSERT_EQUAL(111 , ptr -> tail->value);

  addList(createListElement(123),ptr);
  TEST_ASSERT_EQUAL(123 , ptr -> tail->value);
	TEST_ASSERT_EQUAL(95 		, ptr -> head-> value );
	TEST_ASSERT_EQUAL(100		, ptr -> head-> next-> value );
	TEST_ASSERT_EQUAL(14		, ptr -> head-> next->next->value);
	TEST_ASSERT_EQUAL(111		, ptr -> head-> next->next->next->value);
	TEST_ASSERT_EQUAL(123		, ptr -> head-> next->next->next->next->value);
	TEST_ASSERT_EQUAL(0			, ptr -> head-> next->next->next->next->next);
}

 /**
 * Testing function stackAdd when five element added to the LinkedList
 *
 *                     5th Ele                      1st Ele
 *                   _________                     _________
 * ptr---+-->head-->| value=5|                    | value=1|
 *       |          |________|----> * * * * *---->|________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 */
void test_stackAdd_adding_five_element_into_LinkedList()
{
  LinkedList *ptr;
  ListElement *RemoveEle;
  int i;

  ptr=createLinkedList();

  for(i=1;i<=5;i++){
    stackAdd(ptr,createListElement(i));
  }

  TEST_ASSERT_EQUAL(5,ptr->head->value);
  TEST_ASSERT_EQUAL(4,ptr->head->next->value);
  TEST_ASSERT_EQUAL(3,ptr->head->next->next->value);
  TEST_ASSERT_EQUAL(2,ptr->head->next->next->next->value);
  TEST_ASSERT_EQUAL(1,ptr->head->next->next->next->next->value);
  TEST_ASSERT_NULL(ptr->head->next->next->next->next->next);
  TEST_ASSERT_EQUAL(5,ptr->length);
}

// Testing function stackRemove when there are no element in LinkedList.
void test_stackRemove_given_no_element_in_LinkedList_should_remove_nothing()
{
  LinkedList *ptr;
  ListElement *RemovedEle;

  ptr=createLinkedList();
  RemovedEle=stackRemove(ptr);

  TEST_ASSERT_NULL(RemovedEle);
  TEST_ASSERT_NULL(ptr->head);
  TEST_ASSERT_NULL(ptr->tail);
}

/**
 * Testing function stackRemove when there are only one element in LinkedList.
 *
 *                            ___________
 *    ptr---+-->head-------> |  value=1 |
 *          |                |__________|---->NULL
 *          |                    ^
 *          |                    |
 *          +-->tail-------------+
 *
 *                       ||
 *                       ||
 *                      \ /
 *                                ___________
 *    ptr---+-->head-----+       |  value=1 |
 *          |            |       |__________|----->NULL
 *          +-->tail-----+
 *                       |
 *                       v
 *                      NULL
 */
void test_stackRemove_given_one_element_in_LinkedList_should_remove_head_Element()
{
  LinkedList *ptr;
  ListElement *RemovedEle;

  ptr=createLinkedList();
  stackAdd(ptr,createListElement(1));
  RemovedEle=stackRemove(ptr);

  TEST_ASSERT_EQUAL(1,RemovedEle->value);
  TEST_ASSERT_NULL(RemovedEle->next);

  TEST_ASSERT_NULL(ptr->head);
  TEST_ASSERT_NULL(ptr->tail);
  TEST_ASSERT_EQUAL(0,ptr->length);
}


 /**
 * Testing function stackRemove when there are three element in LinkedList.
 *
 *
 *                   _________      _________      _________
 * ptr---+-->head-->| value=3|     | value=2|     | value=1|
 *       |          |________|---->|________|---->|________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 *                            ||
 *                            ||
 *                           \ /
 *
 *            +-------------------------------+
 *            |      _________            ____v____      _________
 * ptr---+-->head   | value=3|           | value=2|     | value=1|
 *       |          |________|--->NULL   |________|---->|________|---->NULL
 *       |                                                    ^
 *       |                                                    |
 *       +-->tail---------------------------------------------+
 *
 */
void test_stackRemove_given_three_element_in_LinkedList_should_remove_head_Element()
{
  int i;
  LinkedList *ptr;
  ListElement *RemovedEle;

  ptr=createLinkedList();

  for(i=1;i<=3;i++){
    stackAdd(ptr,createListElement(i));
  }

  RemovedEle=stackRemove(ptr);

  TEST_ASSERT_EQUAL(3,RemovedEle->value);
  TEST_ASSERT_NULL(RemovedEle->next);

  TEST_ASSERT_EQUAL(2,ptr->head->value);
  TEST_ASSERT_EQUAL(1,ptr->head->next->value);
  TEST_ASSERT_EQUAL(2,ptr->length);
}


//test whether after removing are able to stackAdd again
void test_Add_and_Remove_Element_to_LinkedList()
{
  int i;
  LinkedList *ptr;
  ListElement *RemovedEle;

  ptr=createLinkedList();

  for(i=1;i<=3;i++){
    stackAdd(ptr,createListElement(i));
  }

  RemovedEle=stackRemove(ptr);

  stackAdd(ptr,createListElement(5));

  TEST_ASSERT_EQUAL(3,RemovedEle->value);
  TEST_ASSERT_NULL(RemovedEle->next);

  TEST_ASSERT_EQUAL(5,ptr->head->value);
  TEST_ASSERT_EQUAL(2,ptr->head->next->value);
  TEST_ASSERT_EQUAL(1,ptr->head->next->next->value);
  TEST_ASSERT_NULL(ptr->head->next->next->next);
  TEST_ASSERT_EQUAL(3,ptr->length);
}

/**
 * Testing function stackAdd and addList in one single LinkedList
 *
 * ptr---+-->head--->5--->3--->1--->2--->4--->NULL
 *       |                               ^
 *       |                               |
 *       +-->tail------------------------+
 *
 */
void test_function_stackAdd_and_addList_in_one_single_LinkedList()
{
  int i;
  LinkedList *ptr;
  ptr=createLinkedList();

  addList(createListElement(1),ptr);
  addList(createListElement(2),ptr);
  stackAdd(ptr,createListElement(3));
  addList(createListElement(4),ptr);
  stackAdd(ptr,createListElement(5));

  TEST_ASSERT_EQUAL(5,ptr->head->value);
  TEST_ASSERT_EQUAL(3,ptr->head->next->value);
  TEST_ASSERT_EQUAL(1,ptr->head->next->next->value);
  TEST_ASSERT_EQUAL(2,ptr->head->next->next->next->value);
  TEST_ASSERT_EQUAL(4,ptr->head->next->next->next->next->value);
  TEST_ASSERT_NULL(ptr->head->next->next->next->next->next);

  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(5,ptr->length);
}