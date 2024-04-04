#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * 
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * 
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth_left, depth_right;

	if (!tree)
		return (0);

	depth_left = tree->left ? binary_tree_is_perfect(tree->left) : 0;
	depth_right = tree->right ? binary_tree_is_perfect(tree->right) : 0;

	if (depth_left == -1 || depth_right == -1 || depth_left != depth_right)
		return (0);

	return (depth_left + 1);
}

/**
 * depth - utility function to calculate depth of leftmost node
 * @tree: pointer to the root node
 * 
 * Return: depth of the tree
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;
	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return d;
}

/**
 * is_perfect_recursive - recursive helper to check if tree is perfect
 * @tree: pointer to the root node
 * @d: depth of the tree
 * @level: current level in the tree
 * 
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (d == level + 1);

	if (!tree->left || !tree->right)
		return (0);

	return is_perfect_recursive(tree->left, d, level + 1) && is_perfect_recursive(tree->right, d, level + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * 
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = depth(tree);
	return is_perfect_recursive(tree, d, 0);
}
