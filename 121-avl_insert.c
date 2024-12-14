#include "binary_trees.h"
#include <stdlib.h>

/* Function prototypes */
avl_t *avl_insert_helper(avl_t **tree, int value);
void balance_tree(avl_t **tree, int value);

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to insert in the tree.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (!tree)
		return (NULL);

	node = avl_insert_helper(tree, value);
	balance_tree(tree, value);

	return (node);
}

/**
 * avl_insert_helper - Recursively inserts a value into the AVL tree.
 * @tree: Double pointer to the root node of the tree.
 * @value: Value to insert.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert_helper(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
		node = avl_insert_helper(&((*tree)->left), value);
		else
			(*tree)->left = node = binary_tree_node(*tree, value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			node = avl_insert_helper(&((*tree)->right), value);
		else
			(*tree)->right = node = binary_tree_node(*tree, value);
	}

	return (node);
}

/**
 * balance_tree - Balances an AVL tree after insertion.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value inserted, to help determine rotation type.
 */
void balance_tree(avl_t **tree, int value)
{
	if (binary_tree_balance(*tree) > 1 && value < (*tree)->left->n)
	{
		*tree = binary_tree_rotate_right(*tree);
		return;
	}

	if (binary_tree_balance(*tree) > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
		return;
	}

	if (binary_tree_balance(*tree) < -1 && value > (*tree)->right->n)
	{
		*tree = binary_tree_rotate_left(*tree);
		return;
	}

	if (binary_tree_balance(*tree) < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}
