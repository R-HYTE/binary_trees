#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts number of nodes with children in a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The number of nodes with children in the tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  nodes = 0;

	if (tree != NULL)
	{
		nodes += (tree->left != NULL || tree->right != NULL) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}

	return (nodes);
}
