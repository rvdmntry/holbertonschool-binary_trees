#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree from a node
 * @tree: pointer to the node to measure the height from
 *
 * Return: The height of the tree from the node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	int right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (left_height - right_height);
}
