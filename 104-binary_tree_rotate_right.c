#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after rotation, or NULL on failure
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->left)
		return (NULL);

	new_root = tree->left; /* The left child becomes the new root */

	/* Reassign new root's right subtree to old root's left */
	tree->left = new_root->right;

	if (new_root->right) /* If there's a right subtree, update its parent */
		new_root->right->parent = tree;

	new_root->right = tree; /* Current root becomes the right child of new root */
	new_root->parent = tree->parent; /* Inherit parent of current root */
	tree->parent = new_root; /* Update parent of current root */

	return (new_root); /* Return the new root */
}
