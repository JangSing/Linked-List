#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>

LinkedList *createLinkedList(){
  LinkedList *list;
  list = malloc(sizeof(LinkedList));
  assert(list != NULL);

  list -> head   = NULL;
  list -> tail   = NULL;
	list -> length = 0;

  return list;
}

ListElement *createListElement(int value){

  ListElement *NewNode= malloc(sizeof(ListElement));
  assert(NewNode != NULL);

  NewNode -> value = value;
  NewNode -> next = NULL;

  return NewNode;

}

void addList(ListElement *NewEle,LinkedList *List ){

  if(List -> head == NULL && List -> tail == NULL){
    List -> head = NewEle;
    List -> tail = List -> head;
    (List->length)++;
  }
  else if(List==NULL||NewEle==NULL){}

  else {
    List -> tail->next=NewEle;
    List -> tail =List -> tail->next;
    (List->length)++;
  }

}

void stackAdd(LinkedList *stack,ListElement *NewElem){


  if(stack->head==NULL && stack->tail==NULL){
    stack->head=NewElem;
    stack->tail=stack->head;
    (stack->length)++;
  }
  else if(stack==NULL||NewElem==NULL){}


  else{
    NewElem->next=stack->head;
    stack->head=NewElem;
    (stack->length)++;
  }
}

ListElement *stackRemove(LinkedList *stack){
  ListElement *ptr;

  if(stack->head==NULL && stack->tail==NULL){
    return NULL;
  }
  else if(stack->head->next==NULL){
    ptr=stack->head;
    stack->head=NULL;
    stack->tail=NULL;
    (stack->length)--;
  }
  else{
    ptr=stack->head;
    stack->head=stack->head->next;
    (stack->length)--;
  }

  ptr->next=NULL;
  return ptr;


}





