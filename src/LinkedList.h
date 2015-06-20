#ifndef LinkedList_H
#define LinkedList_H


// **** Linkedist Function start here **** \\

typedef struct ListElement_t{
  struct ListElement_t *next;
  int value;
}ListElement;

typedef struct {
  ListElement *head;
  ListElement *tail;
  int length;
}LinkedList;

ListElement *createListElement(int value);

LinkedList *createLinkedList();

void addList(ListElement *NewEle,LinkedList *List );

void stackAdd(LinkedList *stack,ListElement *NewElem);

ListElement *stackRemove(LinkedList *stack);

#endif // LinkedList_H
