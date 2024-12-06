#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to lowest common ancestor node, or NULL if no ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (first == NULL || second == NULL)
		return (NULL);

	/* Traverse up the tree for the first node */
	while (first)
	{
		temp = second;
		/* Traverse up the tree for the second node */
		while (temp)
		{
			/* If the nodes match, this is the common ancestor */
			if (first == temp)
				return ((binary_tree_t *)first);
			temp = temp->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
