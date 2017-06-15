#include "BinaryTree.h"

BinaryTree* createBinaryTree(size_t key_s, size_t d_size, TreeCompareFunction compare_gr, TreeCompareFunction compare_eq) {
	BinaryTree* tree = malloc(sizeof(BinaryTree));
	if (tree == NULL)
		return NULL;
	tree->compare_equals = compare_eq;
	tree->compare_greater = compare_gr;
	tree->key_size = key_s;
	tree->data_size = d_size;
	tree->root = NULL;
	tree->count = 0;
	return tree;
}

BinaryTreeNode* createBinaryTreeNode(BinaryTree *tree, const key_type *key, const value_type *value) {
	if (tree == NULL || key == NULL)
		return NULL;
	BinaryTreeNode *node = malloc(sizeof(BinaryTreeNode));
	if (node == NULL)
		return NULL;
	node->pair = malloc(sizeof(Pair));
	if (node->pair == NULL) {
		free(node);
		return NULL;
	}
	node->pair->key = malloc(tree->key_size);
	if (node->pair->key == NULL) {
		free(node->pair);
		free(node);
		return NULL;
	}
	node->pair->value = malloc(tree->data_size);
	if (node->pair->value == NULL) {
		free(node->pair->key);
		free(node->pair);
		free(node);
		return NULL;
	}
	memcpy(node->pair->key, key, tree->key_size);
	if (value != NULL)
		memcpy(node->pair->value, value, tree->data_size);
	else
		node->pair->value = NULL;
	node->greater = NULL;
	node->lower = NULL;
	return node;
}
