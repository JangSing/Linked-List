#include "unity.h"
#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>
#include "createListElement.h"
#include "addList.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_LinkedList_Head_and_Tail(void)
{
  struct LinkedList *ptr;
  ptr = createLinkedList();
	
  TEST_ASSERT_EQUAL( 0, ptr->head);
  TEST_ASSERT_EQUAL( 0, ptr->tail);
}


void test_Create_List_Element_for_Single_Element(void)
{
  struct ListElement *ptr;
	
  ptr = createListElement(5);
	
  TEST_ASSERT_EQUAL( 5, ptr->value);
  TEST_ASSERT_EQUAL( 0, ptr->next);
}

void test_Add_Element_to_the_Head(void)
{
  struct LinkedList *ptr;
  struct ListElement *ptr1;
	
  ptr = createLinkedList();
  ptr1 = createListElement(5);
	
  addList(ptr1,ptr);
	
  TEST_ASSERT_EQUAL( 5, ptr->head->value);
  TEST_ASSERT_EQUAL( 0, ptr->head->next);
}

void test_Five_Element_Added_to_the_List(void)
{
  struct LinkedList *ptr;
  ptr = createLinkedList();
	
  addList(createListElement(95),ptr);
  TEST_ASSERT_EQUAL(95 , ptr -> tail->value);
  
  addList(createListElement(100),ptr);
  TEST_ASSERT_EQUAL(100 , ptr -> tail->next->value);
  
  addList(createListElement(14),ptr);
  TEST_ASSERT_EQUAL(14 , ptr -> tail->next->value);
  
  addList(createListElement(111),ptr);
  TEST_ASSERT_EQUAL(111 , ptr -> tail->next->value);
  
  addList(createListElement(123),ptr);
  TEST_ASSERT_EQUAL(123 , ptr -> tail->next->value);
	
	// TEST_ASSERT_EQUAL(95 		, ptr -> head-> value );
	// TEST_ASSERT_EQUAL(100		, ptr -> head-> next-> value );
	// TEST_ASSERT_EQUAL(14		, ptr -> head-> next->next->value);
	// TEST_ASSERT_EQUAL(111		, ptr -> head-> next->next->next->value);
	// TEST_ASSERT_EQUAL(123		, ptr -> head-> next->next->next->next->value);
	// TEST_ASSERT_EQUAL(0			, ptr -> head-> next->next->next->next->next);

}
	



