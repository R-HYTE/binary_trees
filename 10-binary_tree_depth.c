#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a node from the root.
 * @tree: Pointer to the node for which to calculate the depth.
 * Return: The depth of the node or 0 if it is the root.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t current_depth = 0;

	if (tree != NULL && tree->parent != NULL)
	{
		current_depth = 1 + binary_tree_depth(tree->parent);
	}

	return (current_depth);
}
