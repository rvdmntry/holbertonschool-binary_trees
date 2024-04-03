#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: The balance factor. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = tree->left ? (int)binary_tree_height(tree->left) : 0;
	int right_height = tree->right ? (int)binary_tree_height(tree->right) : 0;

	return (left_height - right_height);
}
