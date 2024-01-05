#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of
 * two nodes in a binary tree.
 * @first: First node.
 * @second: Second node.
 * Return: Pointer to the lowest common ancestor,
 * or NULL if no common ancestor is found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *parent_first, *parent_second;

	if (!first || !second)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	parent_first = first->parent;
	parent_second = second->parent;

	if (!parent_first || first == parent_second ||
			(!parent_first->parent && parent_second))
	{
		return (binary_trees_ancestor(first, parent_second));
	}
	else if (!parent_second || second == parent_first ||
			(!parent_second->parent && parent_first))
	{
		return (binary_trees_ancestor(parent_first, second));
	}
	return (binary_trees_ancestor(parent_first, parent_second));
}
