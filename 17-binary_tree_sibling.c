#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node.
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node, or NULL if no sibling exists.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if node or its parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if node is the left child */
	if (node->parent->left == node)
		return (node->parent->right);

	/* Otherwise, node is the right child */
	return (node->parent->left);
}
