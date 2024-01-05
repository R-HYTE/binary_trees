#include "binary_trees.h"
/**
 * create_node - Creates a new node in a linked_list.
 * @node: The binary tree node to be stored.
 * Return: The created linked list node.
 */
link_t *create_node(binary_tree_t *node)
{
	link_t *new_node;

	new_node =  malloc(sizeof(link_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees the nodes in the linked list.
 * @head: The head node of the linked list.
 */
void free_queue(link_t *head)
{
	link_t *temp_node;

	while (head)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}

/**
 * enqueue - Enqueues a node into the queue.
 * @node: The binary tree node to be enqueued.
 * @queue_head: The head of the queue.
 * @queue_tail: The tail of the queue.
 */
void enqueue(binary_tree_t *node, link_t **queue_head, link_t **queue_tail)
{
	link_t *new_node = create_node(node);

	if (new_node == NULL)
	{
		free_queue(*queue_head);
		exit(EXIT_FAILURE);
	}

	if (*queue_tail == NULL)
		*queue_head = *queue_tail = new_node;
	else
	{
		(*queue_tail)->next = new_node;
		*queue_tail = new_node;
	}
}

/**
 * dequeue - Dequeues a node from the queue.
 * @queue_head: The head of the queue.
 */
void dequeue(link_t **queue_head)
{
	link_t *temp_node = (*queue_head)->next;

	free(*queue_head);
	*queue_head = temp_node;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: The root of the binary tree.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *queue_head = NULL, *queue_tail = NULL;
	int flag = 0;

	if (tree == NULL)
		return (0);

	enqueue((binary_tree_t *)tree, &queue_head, &queue_tail);

	while (queue_head != NULL)
	{
		if (queue_head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(queue_head);
				return (0);
			}
			enqueue(queue_head->node->left, &queue_head, &queue_tail);
		}
		else
			flag = 1;

		if (queue_head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(queue_head);
				return (0);
			}
			enqueue(queue_head->node->right, &queue_head, &queue_tail);
		}
		else
			flag = 1;

		dequeue(&queue_head);
	}

	return (1);
}
