/**
 * height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t height(const binary_tree_t *tree)
{
size_t left_height = 0, right_height = 0;

if (tree == NULL)
return (0);

left_height = tree->left ? 1 + height(tree->left) : 0;
right_height = tree->right ? 1 + height(tree->right) : 0;

return (left_height > right_height ? left_height : right_height);
}
