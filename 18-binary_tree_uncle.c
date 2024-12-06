#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: A pointer to the node to find the uncle.
 *
 * Return: A pointer to the uncle node, or NULL if no uncle exists.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if node or its parent or its grandparent is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* Check if parent is the left child of the grandparent*/
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	 /* Otherwise, parent is the right child of the grandparent */
	return (node->parent->parent->left);
}
