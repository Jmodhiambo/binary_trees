#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: The number nodes with at least 1 child. If tree is NULL, return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t cnt = 0;

	if (tree == NULL)
		return (0);

	/* Check if the current node has at least one child */
	if (tree->left != NULL || tree->right != NULL)
		cnt = 1;

	/* Add the counts from the left and right subtrees */
	return (cnt + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
