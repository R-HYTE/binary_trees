#include "binary_trees.h"

/**
 * binary_tree_inorder - Applies a function to each node in in-order traversal.
 * @tree: Pinter to the root node of the tree.
 * @func: Pointer to the function to apply to each node.
 * Return: Void.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	/* Recursively apply the function to the left subtree */
	binary_tree_inorder(tree->left, func);

	/* Apply the function to the current node */
	func(tree->n);

	/* Recursively apply the function to the right subtree */
	binary_tree_inorder(tree->right, func);
}
