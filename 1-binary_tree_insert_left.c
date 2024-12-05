#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts an node a the left-child of another node.
 * @parent: Pointer to the node to insert the left child in.
 * @value: Value to store in the new node.
 *
 * Return: A pointer to the left child.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left; /* Point to the current left child */
	new_node->right = NULL;

	/* Update the parent's left pointer to point to the new node */
	parent->left = new_node;

	/* If there was an old left child, update its parent to the new node */
	if (new_node->left != NULL)
	{
		new_node->left->parent = new_node;
	}

	return (new_node);
}
