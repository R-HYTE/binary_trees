#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0, left_leaves = 0, right_leaves = 0;

	if (tree != NULL)
	{
		left_leaves = binary_tree_leaves(tree->left);
		right_leaves = binary_tree_leaves(tree->right);
		leaves = left_leaves + right_leaves;

		return ((tree->left == NULL && tree->right == NULL) ? leaves + 1 : leaves);
	}

	return (0);
}
