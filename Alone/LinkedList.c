#include "LinkedList.h"


LinkedList* createUnshortedList(size_t dsize) {
	LinkedList* list = malloc(sizeof(LinkedList));
	list->count = 0;
	list->first = NULL;
	list->last = NULL;
	list->size = dsize;
	list->shorted = 0;
	list->compare_equals = NULL;
	list->compare_greater = NULL;
	return list;
}

LinkedList* createShortedList(size_t size, CompareFunction compare_gr, CompareFunction compare_eq) {
	LinkedList* list = createUnshortedList(size);
	list->shorted = 1;
	list->compare_equals = compare_eq;
	list->compare_greater = compare_gr;
	return list;
}

int insertUnshortedListElementInternal(LinkedList* list, const Data* data, ListInsertMode mode) {
	LinkedListNode* node = malloc(sizeof(LinkedListNode));
	if (node == NULL)
		return 0;
	node->data = malloc(list->size);
	memcpy(node->data, data, list->size);
	list->count++;

	if (list->first == NULL) {
		node->next = NULL;
		node->prev = NULL;
		list->first = node;
		list->last = node;
		list->pointer = node;
		return 1;
	}
	else {
		LinkedListNode* aux;
		if (mode == LIST_AFTER_ELEMENT) {
			aux = list->pointer->next;
			list->pointer->next = node;
			node->prev = list->pointer;
			node->next = aux;
			if (aux != NULL)
				aux->prev = node;
			else
				list->last = node;
		}
		else {
			aux = list->pointer->prev;
			list->pointer->prev = node;
			node->next = list->pointer;
			node->prev = aux;
			if (aux != NULL)
				aux->next = node;
			else
				list->first = node;
		}		
	}
	list->pointer = node;
	return 1;
}

int insertUnshortedListElement(LinkedList* list, const Data* data) {
	return insertUnshortedListElementInternal(list, data, LIST_AFTER_ELEMENT);
}

int insertUnshortedListBeforeElement(LinkedList* list, const Data* data) {
	if (list == NULL || data == NULL)
		return -1;
	return insertUnshortedListElementInternal(list, data, LIST_BEFORE_ELEMENT);
}

int insertShortedListElement(LinkedList* list, const Data* data) {
	if (list->compare_greater(data,getLast(list))) {
		moveToLast(list);
		return insertUnshortedListElementInternal(list, data, LIST_AFTER_ELEMENT);
	}
	if (list->compare_greater(getFirst(list),data)) {
		moveToFirst(list);
		return insertUnshortedListElementInternal(list, data, LIST_BEFORE_ELEMENT);
	}
	moveToFirst(list);
	while (list->pointer != NULL) {
		if(list->compare_greater(getFromList(list),data))
			return insertUnshortedListElementInternal(list, data, LIST_BEFORE_ELEMENT);
		moveToNext(list);
	}		
	return 1;
}



int insertListElement(LinkedList* list, const Data* data) {
	if (list == NULL || data == NULL)
		return -1;
	return (!list->shorted || list->count == 0) ? insertUnshortedListElement(list, data) : insertShortedListElement(list, data);
}
int delete(LinkedList* list) {
	if (list == NULL || list->pointer == NULL)
		return 0;
	list->count--;
	if (list->first == list->last && list->first != NULL) {
		free(list->first->data);
		free(list->first);
		list->first = NULL;
		list->last = NULL;
		list->pointer = NULL;
	}
	else {
			LinkedListNode *aux_p, *aux_n;
			aux_n = list->pointer->next;
			aux_p = list->pointer->prev;
			free(list->pointer->data);
			free(list->pointer);
			if (aux_n != NULL) {
				aux_n->prev = aux_p;
				list->pointer = aux_n;
			}
			else {
				list->last = aux_p;
				list->pointer = aux_p;
			}
			if (aux_p != NULL) 
				aux_p->next = aux_n;
			else {
				list->first = aux_n;
				list->pointer = aux_n;
			}
	}
	return 1;
}
int findInList(LinkedList* list, const Data* data ) {
	if (list == NULL)
		return -1;	
	int position = 0;
	for (moveToFirst(list); list->pointer != NULL && memcmp(list->pointer->data, data, list->size) != 0; moveToNext(list))
		++position;
	if (list->pointer == NULL)
		position = -1;
	return position;
}
Data* getFromList(const LinkedList* list) {
	if (list == NULL || list->pointer == NULL)
		return NULL;
	return list->pointer->data;
}

Data* getFirst(const LinkedList* list) {
	if (list == NULL || list->first == NULL)
		return NULL;
	return list->first->data;
}
Data* getLast(const LinkedList* list) {
	if (list == NULL || list->last == NULL)
		return NULL;
	return list->last->data;
}

void moveToFirst(LinkedList* list) {
	if (list == NULL)
		return;
	list->pointer = list->first;

}
void moveToLast(LinkedList* list) {
	if (list == NULL)
		return;
	list->pointer = list->last;

}
void moveToNext(LinkedList* list) {
	if (list == NULL || list->pointer == NULL)
		return;
	list->pointer = list->pointer->next;
}
void moveToPrev(LinkedList* list) {
	if (list == NULL || list->pointer == NULL)
		return;
	list->pointer = list->pointer->prev;
}
LinkedList* copyList(const LinkedList* list ) {
	if (list == NULL)
		return NULL; 
	LinkedList* new_list = (!list->shorted) ?
		createUnshortedList(list->size) :
		createShortedList(list->size, list->compare_greater, list->compare_equals);
	if (new_list == NULL)
		return NULL;
	LinkedListNode *node = list->first;
	while (node != NULL) {
		if (!insertListElement(new_list, node->data)) {
			deleteList(new_list);
			return NULL;
		}
		node = node->next;
	}
	return new_list;
}

void deleteList(LinkedList* list){
	moveToFirst(list);
	while (delete(list));
	free(list);
}

int insertList(LinkedList* list1, const LinkedList* list2) {
	if (list1 == NULL || list2 == NULL || list1->pointer == NULL)
		return 0;
	LinkedList *new_list = copyList(list2);
	if (new_list == NULL)
		return 0;
	new_list->last->next = list1->pointer->next;
	list1->pointer->next->prev = new_list->last;
	new_list->first->prev = list1->pointer;
	list1->pointer->next = new_list->first;
	list1->count += list2->count;
	free(new_list);
	return 1;
}

int moveToPosition(LinkedList* list, unsigned int position) {
	if (list == NULL || position > list->count)
		return 0;
	if (position < list->count / 2) {
		moveToFirst(list);
		for (unsigned int i = 0; i < position; ++i)
			moveToNext(list);
	}
	else {
		moveToLast(list);
		for (unsigned int i = list->count - 1; i > position; --i)
			moveToPrev(list);
		}
	return 1;
}

LinkedList* subList( const LinkedList* list, unsigned int pos1, unsigned int pos2) {
	if (list == NULL || (pos1 < 0 || pos1 > list->count) || (pos2 < 0 || pos2 > list->count))
		return NULL;
	LinkedList* new_list = (!list->shorted) ?
		createUnshortedList(list->size):
		createShortedList(list->size, list->compare_greater,list->compare_equals);
	if (new_list == NULL)
		return NULL;
	unsigned int min, max;
	LinkedListNode *aux;
	min =  (pos1 <= pos1) ? pos1: pos2;
	max = (pos1 > pos1) ? pos1 : pos2;
	if (min < list->count / 2) {
		aux = list->first;
		for (unsigned int i = 0; i < min; ++i) {
			aux = aux->next;
		}
	}
	else {
		aux = getLast(list);
		for (unsigned int i = list->count - 1; i > min; --i) {
			aux = aux->prev;
		}
	}
	for (unsigned int i = 0; i < max; ++i) {
		if (!insertListElement(new_list, aux->data)) {
			deleteList(new_list);
			return NULL;
		}
		aux = aux->next;
	}
	moveToFirst(new_list);
	return new_list;
}