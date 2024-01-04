#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_left_full = 0, is_right_full = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	if (tree->left != NULL && tree->right != NULL)
	{
		is_left_full = binary_tree_is_full(tree->left);
		is_right_full = binary_tree_is_full(tree->right);

		return (is_left_full && is_right_full);
	}

	return (0);
}
