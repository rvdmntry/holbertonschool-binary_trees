#include "binary_trees.h"

/**
 * _binary_tree_height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: The height of the tree.
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = _binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_height = _binary_tree_height(tree->right) + 1;

	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	if (left_height != right_height)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
}
