#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include<stdlib.h>
#include<string.h>
#include "LinkedList.h"

typedef void key_type;
typedef void value_type;

typedef int(*TreeCompareFunction) (const key_type* greater, const key_type* lower);

typedef struct {
	key_type* key;
	value_type* value;
}Pair;

typedef Pair TreePair;

typedef struct Binary_Tree_Node
{
	TreePair* pair;
	struct Binary_Tree_Node *lower;
	struct Binary_Tree_Node *greater;
} BinaryTreeNode;

typedef struct Binary_Tree
{
	unsigned int count;
	BinaryTreeNode *root;
	TreeCompareFunction compare_greater;
	TreeCompareFunction compare_equals;
	size_t key_size;
	size_t data_size;
}BinaryTree;

BinaryTree* createBinaryTree(size_t key_s, size_t d_size, TreeCompareFunction compare_gr, TreeCompareFunction compare_eq);
BinaryTree* createSubBinaryTree(const BinaryTree* tree, key_type* key);
BinaryTree* copyBinaryTree(const BinaryTree* tree);

int insertBinaryTree(BinaryTree* BinaryTree, const key_type* key, const value_type* value);

value_type* getFromBinaryTree(const BinaryTree* BinaryTree, key_type* key);
Pair* getLowestFromTree(BinaryTree* tree);
Pair* getLowestFromNode(BinaryTreeNode* tree_node);
Pair* getGreatestFromTree(BinaryTree* tree);
Pair* getGreatesFromNode(BinaryTreeNode* tree_node);

int deleteFromBinaryTree(BinaryTree* BinaryTree, key_type* key);

LinkedList* getValuesFromBinaryTree(const BinaryTree* BinaryTree);
LinkedList* getKeysFromBinaryTree(const BinaryTree* BinaryTree);
LinkedList* getPairsFromBinaryTree(const BinaryTree* BinaryTree);



#endif
