#ifndef _MAP
#define _MAP

#include"LinkedList.h"
#define MAX_ELEMENTS_PER_SEGMENT 16

//typedef enum Node_Type {TREE_NOT_LEAF, TREE_LEAF} NodeType;

typedef struct {
	void* key;	
	void* value;	
}Pair;


typedef struct Map_{
	int count;
	size_t value_size;
	size_t key_size;
	int(*compare_greater) (void* greater, void* lower);
	int(*compare_equals) (void* elem1, void* elem2);	
	LinkedList* pair;
	struct Map_* subTree;
 } Map;


Map* createMap(size_t key_s, size_t value_s, CompareFunction compare_gr, CompareFunction compare_eq);
int insertMap(Map* map, void* key, void* value);
void* getFromMap(const Map* map, void* key);
int deleteFromMap(Map* map, void* key);
LinkedList* getValuesFromMap(const Map* map);
LinkedList* getKeysFromMap(const Map* map);

#endif
