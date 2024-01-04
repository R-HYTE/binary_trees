#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a balanced tree
 * @tree: Trees to go through.
 * Return: The height of the tree.
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree != NULL)
	{
		left_height = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
		right_height = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
	}

	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: Tree to go through.
 * Return: Balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0, balance_factor = 0;

	if (tree != NULL)
	{
		left = (int)binary_tree_height_b(tree->left);
		right = (int)binary_tree_height_b(tree->right);
		balance_factor = left - right;
	}

	return (balance_factor);
}
