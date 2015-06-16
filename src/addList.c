#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>
#include "createListElement.h"
#include "addList.h"
	
/**
*This function is to add an Element into the end of the Linked List.
*/

void addList(struct ListElement *NewEle,struct LinkedList *List ){
  
  if(List -> head == NULL){
    // List -> tail = NewEle;
    List -> head = NewEle;
  }
  
  else {
    
    List -> tail = List -> head;
    
    while(List->tail-> next != NULL){
      List -> tail = List -> tail -> next;
    }
    
    List -> tail -> next = NewEle;
  }
}