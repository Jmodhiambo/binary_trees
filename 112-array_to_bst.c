#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *tree = NULL;

	if (!array || size == 0)
		return (NULL);

	while (i < size)
	{
		bst_insert(&tree, array[i]);
		i++;
	}

	return (tree);
}
