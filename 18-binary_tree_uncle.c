#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to evaluate
 * Return: a pointer to the uncle of the node or NULL if it couldn't be found.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;

	if (parent->parent->left == NULL || parent->parent->right == NULL)
		return (NULL);

	if (parent->parent->left == parent)
		return (parent->parent->right);

	return (parent->parent->left);
}
