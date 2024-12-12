#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: A pointer to the node containing a value equals to value of NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *current = tree;

	if (!tree)
		return (NULL);

	while (current)
	{
		if (value == current->n)
		{
			return ((void *)current);
		}

		else
		{
			if (value < current->n)
				current = current->left;
			else
				current = current->right;
		}
	}
	return (NULL);
}
