
int max(int a, int b) {
    return (a > b) ? a : b;
}

int BinaryTreeDepth(TreeNode *root) {
    if (root) {
        return 1+ max(BinaryTreeDepth(root->left),BinaryTreeDepth(root->right));
    }
    return 0;
}
