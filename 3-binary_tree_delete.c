#include "binary_trees.h"
/**
 * binary_tree_delete - Frees an entire binary tree using recursion.
 * It frees each node when its left and right children are NULL.
 * @tree: Pointer to the root node of the tree to be deleted.
 * Return: Void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree->left != NULL)
		{
			binary_tree_delete(tree->left);
		}
		if (tree->right != NULL)
		{
			binary_tree_delete(tree->right);
		}

		free(tree);
	}

}
