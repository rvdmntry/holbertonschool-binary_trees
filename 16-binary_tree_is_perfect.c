#include "binary_trees.h"

static size_t tree_height(const binary_tree_t *tree);
static size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t height = tree_height(tree);
	size_t expected_nodes = (1 << height) - 1;

	size_t actual_nodes = binary_tree_size(tree);

	return (expected_nodes == actual_nodes);
}

static size_t tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	size_t left_height = tree_height(tree->left);
	size_t right_height = tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);

}

/**
 * binary_tree_size - Measures the size of a binary tree (number of nodes)
 * @tree: pointer to the root node of the tree to measure the size
 * Return: The size of the tree. If tree is NULL, return 0.
 */
static size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}
