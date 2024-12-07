#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to new root node after rotation, or NULL if tree is NULL.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	/* Set the new root to be the right child of the current root */
	new_root = tree->right;

	/* Update the right child of the current root to the left child of new root */
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	/* Set the left child of the new root to the current root */
	new_root->left = tree;

	/* Update parent pointers */
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
