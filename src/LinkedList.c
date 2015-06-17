#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>


/**
*This function is to initialize the linked list.
*Head and Tail has been declared.
*Head and Tail are pointing to NULL;
*
*/
struct LinkedList *createLinkedList(){
  struct LinkedList *list;
  list = malloc(sizeof(struct LinkedList));
		
  list -> head = NULL;
  list -> tail = NULL;
		
  return list;
		
}


/**
*This function is to create an new Element.
*Each element has the variable as below:
*   -value(an integer)
*   -next(a pointer)
*
*input:
*   -int value
*/

struct ListElement *createListElement(int value){
  
  struct ListElement *NewNode;
  
  NewNode = malloc(sizeof(struct ListElement));	
  NewNode -> value = value;
  NewNode -> next = NULL;

  return NewNode;
  
}


/**
*This function is to add an Element into the end of the Linked List.
*/
void addList(struct ListElement *NewEle,struct LinkedList *List ){
  
  if(List -> head == NULL){
    List -> head = NewEle;
    List -> tail = List -> head;
  }
  
  else {
    List -> tail = List -> head;
    
    
    while(List->tail-> next != NULL){
      List -> tail = List -> tail -> next;
    }
    
    List -> tail -> next = NewEle;

  }
  
}
