#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 * Description: Recursively traverses the binary tree using post-order
 * traversal (left, right, root) to ensure that child nodes are deleted
 * before their parent node. This prevents dangling pointers.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);

	binary_tree_delete(tree->right);

	free(tree);
}
