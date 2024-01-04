#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Checks if a node is a leaf (has no children).
 * @node: Pointer to the node to check.
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check if the node is not NULL and has no left or right child */
	return (node != NULL && node->left == NULL && node->right == NULL);
}
