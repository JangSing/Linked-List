#ifndef LinkedList_H
#define LinkedList_H

struct LinkedList{
	struct ListElement *head;
	struct ListElement *tail;
};

struct ListElement{
	struct ListElement *next;
	int value;
};

struct ListElement *createListElement(int value);

struct LinkedList *createLinkedList();

void addList(struct ListElement *NewEle,struct LinkedList *List );

#endif // LinkedList_H
