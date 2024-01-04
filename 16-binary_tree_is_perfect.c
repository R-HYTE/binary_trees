#include "binary_trees.h"
/**
 * tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * Return: The height of the tree if it is perfect, 0 otherwise.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left && tree->right)
	{
		left_height = tree_is_perfect(tree->left);
		right_height = tree_is_perfect(tree->right);

		if (left_height == right_height && left_height != 0)
			return (left_height + 1);

		return (0);
	}

	if (!tree->left && !tree->right)
	{
		return (1);
	}

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pinter to the root node of the tree.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return ((tree_is_perfect(tree) != 0));
}
