#include "binary_trees.h"

/**
 * binary_tree_postorder - Applies a function to each node in
 * post-order traversal.
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to the function to apply to each node.
 * Return: Void.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	/* Recursively apply the function to the left and right subtrees */
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);

	/* Apply the function to the current node */
	func(tree->n);
}
