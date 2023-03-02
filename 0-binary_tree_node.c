#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: the parent node
 * @value: the value to be placed inside the new node
 * Return: a pointer to the newly created node or NULL upon failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	if (parent == NULL)
		return (new);

	if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;
	return (new);
}
