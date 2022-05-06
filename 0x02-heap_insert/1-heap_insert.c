#include "binary_trees.h"
#include <stdlib.h>

/**
 * binaryTreeSize - Calculates the size of a binary tree
 *
 * @root: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t binaryTreeSize(heap_t *root)
{
	if (root == NULL)
		return (0);

	return (binaryTreeSize(root->left) + binaryTreeSize(root->right) + 1);
}

/**
 * getNodeFromIndex - Finds the node at the given index
 *
 * @root: Pointer to the root node of the tree
 * @index: Index of the node to find
 *
 * Return: Pointer to the node at the given index
 */
heap_t *getNodeFromIndex(heap_t *root, int index)
{
	int parentIdx, direction;

	if (index == 0)
		return (root);

	parentIdx = (index - 1) / 2;
	direction = (index - 1) % 2;

	return (getNodeFromIndex(direction ? root->right : root->left, parentIdx));
}

/**
 * swap - Swaps the values of two nodes
 *
 * @src: Pointer to the source node
 * @dest: Pointer to the destination node
 */
void swap(heap_t *src, heap_t *dest)
{
	int tmp;

	tmp = dest->n;
	dest->n = src->n;
	src->n = tmp;
	src = dest;
	dest = src->parent;
}

/**
 * heap_insert - Insert a new node
 *
 * @root: Pointer to the root node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int idx, size;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	size = binaryTreeSize(*root);
	idx = (size - 1) / 2;
	parent = getNodeFromIndex(*root, idx);
	new_node->parent = parent;

	if (size % 2 == 0)
		parent->right = new_node;
	else
		parent->left = new_node;

	while (parent && parent->n < new_node->n)
		swap(new_node, parent);

	return (new_node);
}
