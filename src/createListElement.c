#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>
#include "createListElement.h"
#include "addList.h"

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