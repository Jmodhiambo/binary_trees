#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Initialize a queue to perform level-order traversal */
	binary_tree_t *queue[1024];
	int front = 0, rear = 0;
	bool found_null = false;

	/* Start with the root node */
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		/* Dequeue the front node */
		binary_tree_t *current = queue[front++];

		/* Check if we have encountered a NULL node previously */
		if (current == NULL)
		{
			found_null = true;
		}
		else
		{
			/* If we find a non-NULL node after a NULL node,
			the tree is not complete */
			if (found_null)
			return (0);

			/* Enqueue left and right children */
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	return (1);
}
