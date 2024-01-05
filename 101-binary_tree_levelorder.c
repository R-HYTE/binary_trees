#include "binary_trees.h"
/**
 * binary_tree_height - Measure the height of a binary tree.
 * @tree: The tree to measure.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * binary_tree_depth - Calculate the depth of a node from the root.
 * @tree: The node to calculate the depth.
 * Return: The depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Create a linked list node from depth level and node.
 * @head: The pointer to the head of the linked list.
 * @tree: The node to store.
 * @level: The depth of the node to store.
 * Return: Void
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new_node, *current;

	new_node = malloc(sizeof(link_t));
	if (!new_node)
		return;

	new_node->n = level;
	new_node->node = tree;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next)
			current = current->next;

		current->next = new_node;
	}
}

/**
 * recursion - Recursively traverse the binary tree and store each node
 * in a linked list.
 * @head: The pointer to the head of the linked list.
 * @tree: The node to check
 * Return: Void
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Print the nodes in a level-order traversal.
 * @tree: The root node.
 * @func: The function to apply to each node.
 * Return: Void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *current;
	size_t height = 0, count = 0;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	head = NULL;
	recursion(&head, tree);

	while (count <= height)
	{
		current = head;
		while (current)
		{
			if (count == current->n)
				func(current->node->n);

			current = current->next;
		}
		count++;
	}

	free_linked_list(head);
}
