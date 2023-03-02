#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height, left, right;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left < right)
		height = right + 1;
	else
		height = left + 1;
	return (height);
}

/**
 * p_check - runs through a tree checking for perfection
 * @tree: pointer to the root node of the tree
 * @h: height of the tree
 * @l: level of the node
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int p_check(const binary_tree_t *tree, size_t h, size_t l)
{
	if (tree->left == NULL && tree->right == NULL)
		return (h == l);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (p_check(tree->left, h, l + 1) && p_check(tree->right, h, l + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h, level = 0;

	if (tree == NULL)
		return (0);

	h = binary_tree_height(tree);

	return (p_check(tree, h, level));
}
