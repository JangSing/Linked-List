#ifndef createListElement_H
#define createListElement_H



struct ListElement{
	struct ListElement *next;
	int value;
};

struct ListElement *createListElement(int value);

#endif // createListElement_H