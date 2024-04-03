#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (!tree || (!tree->left && !tree->right))
        return (0);
    size_t left_height = binary_tree_height(tree->left) + 1;
    size_t right_height = binary_tree_height(tree->right) + 1;

    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (!tree)
        return (1);
    if (!tree->left != !tree->right)
        return (0);
    return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);
    
    if (left_height == right_height && binary_tree_is_full(tree))
        return (1);
    return (0);
}
