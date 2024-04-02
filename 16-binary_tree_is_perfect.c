#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the node to measure from
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int left_is_perfect = binary_tree_is_perfect(tree->left);
	int right_is_perfect = binary_tree_is_perfect(tree->right);
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	int is_full = binary_tree_is_full(tree);
	int height_equal = (left_height == right_height);

	return (is_full && left_is_perfect && right_is_perfect && height_equal);
}
