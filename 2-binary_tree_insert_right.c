#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as right-child of another node.
 * @parent: Pointer to the node to insert right-child in.
 * @value: The value to store in the new node.
 *
 * Return: Returns a pointer to the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = parent->right; /* Points to the right-child of parent. */
	new_node->left = NULL;

	/* Updates parent right-child to the new_node. */
	parent->right = new_node;

	/* Updates the parent of the initial right-child to new_node. */
	if (new_node->right != NULL)
		new_node->right->parent = new_node;

	return (new_node);
}
