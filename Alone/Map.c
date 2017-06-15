#include "Map.h"

Map* createMap(size_t key_s, size_t value_s, CompareFunction compare_gr, CompareFunction compare_eq) {
	Map* map = malloc(sizeof(Map));
	if (map == NULL, compare_gr == NULL || compare_eq == NULL)
		return NULL;
	map->pair = createShortedList(sizeof(Pair*),compare_gr,compare_eq);
	if (map->pair == NULL) {
		free(map);
		return NULL;
	}
	map->compare_equals = compare_eq;
	map->compare_greater = compare_gr;
	map->count = 0;
	map->key_size = key_s;
	map->value_size = value_s;
	map->subTree = NULL;
	return map;
}

int insertMapInternal(Map* map, Pair* pair, Map* new_map) {

}
//shorted list creado
//usarlo pa hacer el arbol del mapa
int insertMap(Map* map, void* key, void* value) {
	if (map == NULL || key == NULL || value == NULL)
		return 0;
	Pair* pair = malloc(sizeof(Pair));
	if (pair == NULL) 		
		return 0;
	pair->key = malloc(sizeof(map->key_size));
	memcpy(pair->key, key, map->key_size);
	if(pair->key == NULL){
		free(pair);
		return 0;
	}
	pair->value = malloc(sizeof(map->value_size));
	memcpy(pair->value, value, map->value_size);
	if (pair->value == NULL) {
		free(pair->key);
		free(pair);
		return 0;
	}
}

void* getFromMap(const Map* map, void* key);
int deleteFromMap(Map* map, void* key);
LinkedList* getValuesFromMap(const Map* map);
LinkedList* getKeysFromMap(const Map* map);