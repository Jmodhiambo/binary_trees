#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree, or -1 if the tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);
	return (1 + (height(tree->left) > height(tree->right) ?
		height(tree->left) : height(tree->right)));
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowable value for the node.
 * @max: Maximum allowable value for the node.
 *
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Helper function to check if a binary tree is an AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * @height_diff: Pointer to store the height difference of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0.
 */
int is_avl_helper(const binary_tree_t *tree, int *height_diff)
{
	int left_height = 0, right_height = 0;

	if (!tree)
	{
		*height_diff = 0;
		return (1);
	}

	if (!is_avl_helper(tree->left, &left_height) ||
	    !is_avl_helper(tree->right, &right_height))
		return (0);

	*height_diff = 1 + (left_height > right_height ? left_height : right_height);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_diff = 0;

	if (!tree)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl_helper(tree, &height_diff));
}
