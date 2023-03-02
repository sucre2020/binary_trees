#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes wit at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the amount of inner nodes of the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (nodes);

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		nodes += 1;
	return (nodes);
}
