#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_min - Finds the node with the minimum value in a BST.
 * @root: A pointer to the root of the subtree to search.
 *
 * Return: A pointer to the node with the minimum value, or NULL for root.
 */
bst_t *find_min(bst_t *root)
{
    /* Traverse to the leftmost node */
	while (root && root->left)
		root = root->left;

	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor;

	if (!root)
		return (NULL);

	/* Search for the node to remove */
	if (value < root->n)
		root->left = bst_remove(root->left, value); /* Recur on left subtree */
	else if (value > root->n)
		root->right = bst_remove(root->right, value); /* Recur on right subtree */
	else
	{
		/* Node with one or no children */
		if (!root->left || !root->right)
		{
			bst_t *temp = root->left ? root->left : root->right;

			if (temp) /* If there is a child */
				temp->parent = root->parent;

			free(root);
			return (temp);
		}

		/* Node with two children: find the in-order successor */
		successor = find_min(root->right);
		root->n = successor->n; /* Replace current node's value with successor's */
		root->right = bst_remove(root->right, successor->n); /* rm the successor */
	}

	return (root); /* Return the updated root */
}
