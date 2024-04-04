#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree from a given node.
 * @tree: Pointer to the root node of the tree to measure the height from.
 *
 * Description: A leaf node is considered to have a height of 0. The function
 * recursively finds the height of the tree by finding the max height of either
 * subtree and adding one for the current node.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_balance - Calculates the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Description: The balance factor is the height of the left subtree minus the
 * height of the right subtree. A subtree with no children has a height of -1.
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = tree->left ? (int)binary_tree_height(tree->left) : -1;
	right_height = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (left_height - right_height);
}
