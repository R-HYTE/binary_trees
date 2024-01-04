#include "binary_trees.h"

/**
 * binary_tree_size - Calculates the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The size of tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, left_size = 0, right_size = 0;

	if (tree != NULL)
	{
		left_size = binary_tree_size(tree->left);
		right_size = binary_tree_size(tree->right);
		size = left_size + right_size + 1;
	}
	return (size);
}
