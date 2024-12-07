#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *parent, *new_node;

	if (!tree)
		return (NULL);

	if (*tree == NULL) /* If tree is empty, create the root node */
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	while (current)
	{
		parent = current;
		if (value == current->n) /* Value already exists, ignore it */
			return (NULL);
		else if (value < current->n) /* Traverse left */
			current = current->left;
		else /* Traverse right */
			current = current->right;
	}

	/* Create the new node and attach it to the parent */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
