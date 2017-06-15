#include <SFML/Graphics.h>
#include<stdio.h>
#include "room.h"
#include"LinkedList.h"
#include "Map.h"
#include "BinaryTree.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int grea(const void* n, const void* p) {
	printf("grea big %i sml %i \n", *((int*)n), *((int*)p));
	return *((int*)n) > *((int*)p);
}

int eq(const void* n, const  void* p) {
	return *((int*)n) == *((int*)p);
}

int main()
{	
	int p = 1, k = 43, r = 7, e = -55;
	BinaryTree *tree = createBinaryTree(sizeof(int), grea, eq);
	int* q;
	free(q);
	/*
	
	LinkedList  *list = createShortedList(sizeof(int), grea, eq);
	insertListElement(list, &k);
	insertListElement(list, (void*)&p);
	insertListElement(list, (void*)&e);
	insertListElement(list, (void*)&r);
	unsigned int i = 0;
	moveToFirst(list);
	while (i < list->count ) {
		printf("%i\n", *(int*)getFromList(list));
		moveToNext(list);
		i++;
	}*/
	/*
	int p = 50;
	printf("%i", temporal );
	LinkedList *sub, *new_list,*list = createUnshortedList(sizeof(int));
	for (int i = 0; i < 200; insertListElement(list, &i))
		i++;
	sub = subList(list, 35, 28);
	int pos = findInList(list, (void*)&p);
	moveToPosition(list, pos);
	printf("   found  ++++ %i\n", *(int*)getFromList(list));
	delete(list);
	new_list = copyList(list);
	moveToFirst(list);
	while (list->count > 0) {		
		printf("%i\n", *(int*)getFromList(list));
		delete(list);
	}
	p = 20;
	findInList(new_list, (void*)&p);
	insertList(new_list, new_list);
	moveToFirst(new_list);
	while (new_list->count > 0) {
		printf("               %i\n",  *(int*)getFromList(new_list)) ;
		delete(new_list);
	}
	unsigned int f = 0;
	while (f++ < sub->count ) {
		printf(" SUB  ->  %i\n", *(int*)getFromList(sub));
		moveToNext(sub);
	}
	deleteList(sub);
	deleteList(new_list);
	deleteList(list);
	*/
	_CrtDumpMemoryLeaks();
	getchar();

	return 0;
}