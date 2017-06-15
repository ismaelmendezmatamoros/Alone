#ifndef _LINKED_LIST
#define _LINKED_LIST

#include<stdlib.h>
#include<string.h>

typedef void Data;
typedef int(*CompareFunction) (const void* elem1, const void* elem2);
typedef struct linkedlistnode
{
	Data* data;
	struct linkedlistnode *next;
	struct linkedlistnode *prev;
} LinkedListNode;

typedef enum { LIST_BEFORE_ELEMENT = 0, LIST_AFTER_ELEMENT} ListInsertMode;

typedef struct linkedlist
{
	unsigned int count;
	struct linkedlistnode *first;
	struct linkedlistnode *pointer;
	struct linkedlistnode *last;
	int shorted;
	int(*compare_greater) (const void* greater, const void* lower);
	int(*compare_equals) (const void* elem1, const void* elem2);
	size_t size;
}LinkedList;

LinkedList* createUnshortedList(size_t size);
LinkedList* createShortedList(size_t size, CompareFunction compare_gr, CompareFunction compare_eq);

int insertListElement(LinkedList* list, Data* data );
int insertUnshortedListElement(LinkedList* list, Data* data);
int insertShortedListElement(LinkedList* list, Data* data);
int insertUnshortedListBeforeElement(LinkedList* list, Data* data);
int delete(LinkedList* list);

int findInList(LinkedList* list, Data* data);
Data* getFromList(const LinkedList* list);
Data* getFirst(const LinkedList* list);
Data* getLast(const LinkedList* list);
Data* getLast(const LinkedList* list);
void moveToFirst(LinkedList* list);
void moveToLast(LinkedList* list);
void moveToNext(LinkedList* list);
void moveToPrev(LinkedList* list);
int  moveToPosition(LinkedList* list, unsigned int position);
void deleteList(LinkedList*);
int insertList(LinkedList* list1, const LinkedList* list2);
LinkedList* copyList(const LinkedList* list);
LinkedList* subList(const LinkedList* list, unsigned int pos1, unsigned int pos2);


#endif