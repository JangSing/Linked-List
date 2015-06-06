#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>
#include "createListElement.h"
#include "addList.h"

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


	

			
		
	
		
		
		
		
		
		
		
		
		
		
