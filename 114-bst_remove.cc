#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: A pointer to the node containing a value equals to value or NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);

		tree = (value < tree->n) ? tree->left : tree->right;
	}
	return (NULL);
}

bst_t *find_min(bst_t *root)
{
	while (root && root->left)
	{
		root = root->left;
	}
	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *current = root;
	bst_t *node, *new_node;

	node = bst_search(current, value);
	if (!node && !node->left && !node->right)
	{
		free(node);
		free(new_node);
		return (root);
	}
	if (node->right)
	{
		new_node = find_min(node->right);
	}
	else
	{
		while (node)
		{
			if (node->left)
				new_node = node->left;
			node = node->parent;
		}
	}

}
